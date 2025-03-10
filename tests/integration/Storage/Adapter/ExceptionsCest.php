<?php

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

declare(strict_types=1);

namespace Phalcon\Tests\Integration\Storage\Adapter;

use IntegrationTester;
use Phalcon\Storage\Adapter\Redis;
use Phalcon\Storage\Adapter\Stream;
use Phalcon\Storage\Exception as StorageException;
use Phalcon\Storage\SerializerFactory;
use Phalcon\Support\Exception as HelperException;

use function array_merge;
use function file_put_contents;
use function getOptionsRedis;
use function is_dir;
use function mkdir;
use function outputDir;
use function sleep;
use function uniqid;

class ExceptionsCest
{
    /**
     * Tests Phalcon\Storage\Adapter\Redis :: get() - wrong index
     *
     * @param IntegrationTester $I
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-09-09
     */
    public function storageAdapterRedisGetSetWrongIndex(IntegrationTester $I)
    {
        $I->wantToTest('Storage\Adapter\Redis - get()/set() - wrong index');

        $I->checkExtensionIsLoaded('redis');

        $I->expectThrowable(
            new StorageException('Redis server selected database failed'),
            function () {
                $serializer = new SerializerFactory();
                $adapter    = new Redis(
                    $serializer,
                    array_merge(
                        getOptionsRedis(),
                        [
                            'index' => 99,
                        ]
                    )
                );

                $adapter->get('test');
            }
        );
    }

    /**
     * Tests Phalcon\Storage\Adapter\Redis :: get() - failed auth
     *
     * @param IntegrationTester $I
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-09-09
     */
    public function storageAdapterRedisGetSetFailedAuth(IntegrationTester $I)
    {
        $I->wantToTest('Storage\Adapter\Redis - get()/set() - failed auth');

        $I->checkExtensionIsLoaded('redis');

        $I->expectThrowable(
            new StorageException('Failed to authenticate with the Redis server'),
            function () {
                $serializer = new SerializerFactory();
                $adapter    = new Redis(
                    $serializer,
                    array_merge(
                        getOptionsRedis(),
                        [
                            'auth' => 'something',
                        ]
                    )
                );

                $adapter->get('test');
            }
        );
    }

    /**
     * Tests Phalcon\Storage\Adapter\Redis :: get() - failed ssl
     *
     * @param IntegrationTester $I
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-09-09
     */
    public function storageAdapterRedisGetSetFailedSslLocalhost(IntegrationTester $I)
    {
        $I->wantToTest('Storage\Adapter\Redis - get()/set() - failed ssl');

        $I->checkExtensionIsLoaded('redis');

        /**
         * Trying a different exception catch because Codeception does not
         * like empty messages
         */
        $thrown = false;
        try {
            $serializer      = new SerializerFactory();
            $options         = getOptionsRedis();
            $options['host'] = 'tls://127.0.0.1';
            $options['ssl']  = [
                'verify_peer_name' => '127.0.0.1',
                'verify_peer'      => false,
            ];

            $adapter = new Redis($serializer, $options);

            $adapter->get('test');
        } catch (StorageException $ex) {
            $thrown = true;
        }

        $I->assertTrue($thrown);
    }

    /**
     * Tests Phalcon\Storage\Adapter\Stream :: get() - errors
     *
     * @param IntegrationTester $I
     *
     * @throws HelperException
     * @throws StorageException
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-09-09
     */
    public function storageAdapterStreamGetErrors(IntegrationTester $I)
    {
        $I->wantToTest('Storage\Adapter\Stream - get() - errors');

        if (version_compare(PHP_VERSION, '8.3.0', '>=')) {
            $I->markTestSkipped('Invalid `unserialize()` will generate warning but still works.');
        }

        $serializer = new SerializerFactory();
        $adapter    = new Stream(
            $serializer,
            [
                'storageDir' => outputDir(),
            ]
        );

        $target = outputDir() . 'ph-strm/te/st/-k/';
        if (true !== is_dir($target)) {
            mkdir($target, 0777, true);
        }

        // Unknown key
        $expected = 'test';
        $actual   = $adapter->get(uniqid(), 'test');
        $I->assertSame($expected, $actual);

        // Invalid stored object
        $actual = file_put_contents(
            $target . 'test-key',
            '{'
        );
        $I->assertNotFalse($actual);

        $expected = 'test';
        $actual   = $adapter->get('test-key', 'test');
        $I->assertSame($expected, $actual);

        // Expiry
        $data = 'Phalcon Framework';

        $actual = $adapter->set('test-key', $data, 1);
        $I->assertTrue($actual);

        sleep(2);

        $expected = 'test';
        $actual   = $adapter->get('test-key', 'test');
        $I->assertSame($expected, $actual);

        $I->safeDeleteFile($target . 'test-key');
    }
}
