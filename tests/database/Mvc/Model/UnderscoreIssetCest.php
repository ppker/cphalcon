<?php

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Tests\Database\Mvc\Model;

use DatabaseTester;
use Phalcon\Tests\Fixtures\Migrations\CustomersMigration;
use Phalcon\Tests\Fixtures\Traits\DiTrait;
use Phalcon\Tests\Models;

class UnderscoreIssetCest
{
    use DiTrait;

    public function _before(DatabaseTester $I)
    {
        $this->setNewFactoryDefault();
        $this->setDatabase($I);
    }

    public function _after(DatabaseTester $I)
    {
        $this->container['db']->close();
    }

    /**
     * Tests Phalcon\Mvc\Model :: __isset()
     *
     * @author Sid Roberts <https://github.com/SidRoberts>
     * @since  2019-05-22
     *
     * @group  mysql
     * @group  pgsql
     * @group  sqlite
     */
    public function mvcModelUnderscoreIsset(DatabaseTester $I)
    {
        $I->wantToTest("Mvc\Model - __isset()");
        /** @var \PDO $connection */
        $connection = $I->getConnection();

        $customersMigration = new CustomersMigration($connection);
        $customersMigration->insert(1, 1, 'test_firstName_1', 'test_lastName_1');

        /**
         * Belongs-to relationship
         */
        $customerSnap = Models\CustomersKeepSnapshots::findFirst();

        $I->assertTrue(
            isset($customerSnap->invoices)
        );

        $I->assertFalse(
            isset($customerSnap->nonExistentRelation)
        );
    }
}
