
#ifdef HAVE_CONFIG_H
#include "../../../../ext_config.h"
#endif

#include <php.h>
#include "../../../../php_ext.h"
#include "../../../../ext.h"

#include <Zend/zend_operators.h>
#include <Zend/zend_exceptions.h>
#include <Zend/zend_interfaces.h>

#include "kernel/main.h"
#include "kernel/memory.h"
#include "kernel/fcall.h"
#include "kernel/array.h"
#include "kernel/object.h"
#include "ext/spl/spl_exceptions.h"
#include "kernel/exception.h"


/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */
/**
 * Phalcon\Mvc\Model\MetaData\Libmemcached
 *
 * Stores model meta-data in the Memcache.
 *
 * By default meta-data is stored for 48 hours (172800 seconds)
 */
ZEPHIR_INIT_CLASS(Phalcon_Mvc_Model_MetaData_Libmemcached)
{
	ZEPHIR_REGISTER_CLASS_EX(Phalcon\\Mvc\\Model\\MetaData, Libmemcached, phalcon, mvc_model_metadata_libmemcached, phalcon_mvc_model_metadata_ce, phalcon_mvc_model_metadata_libmemcached_method_entry, 0);

	return SUCCESS;
}

/**
 * Phalcon\Mvc\Model\MetaData\Libmemcached constructor
 *
 * @param array options
 */
PHP_METHOD(Phalcon_Mvc_Model_MetaData_Libmemcached, __construct)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval options;
	zval *factory, factory_sub, *options_param = NULL, _0, _1, _2, _3, _4, _5, _6;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&factory_sub);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_6);
	ZVAL_UNDEF(&options);
	ZEND_PARSE_PARAMETERS_START(1, 2)
		Z_PARAM_OBJECT_OF_CLASS(factory, phalcon_cache_adapterfactory_ce)
		Z_PARAM_OPTIONAL
		Z_PARAM_ARRAY(options)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 1, 1, &factory, &options_param);
	if (!options_param) {
		ZEPHIR_INIT_VAR(&options);
		array_init(&options);
	} else {
	ZEPHIR_OBS_COPY_OR_DUP(&options, options_param);
	}
	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, "persistentId");
	ZEPHIR_INIT_VAR(&_2);
	ZVAL_STRING(&_2, "ph-mm-mcid-");
	ZEPHIR_CALL_METHOD(&_0, this_ptr, "getarrval", NULL, 0, &options, &_1, &_2);
	zephir_check_call_status();
	zephir_array_update_string(&options, SL("persistentId"), &_0, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_STRING(&_1, "prefix");
	ZEPHIR_INIT_NVAR(&_2);
	ZVAL_STRING(&_2, "ph-mm-memc-");
	ZEPHIR_CALL_METHOD(&_3, this_ptr, "getarrval", NULL, 0, &options, &_1, &_2);
	zephir_check_call_status();
	zephir_array_update_string(&options, SL("prefix"), &_3, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_STRING(&_1, "lifetime");
	ZVAL_LONG(&_5, 172800);
	ZEPHIR_CALL_METHOD(&_4, this_ptr, "getarrval", NULL, 0, &options, &_1, &_5);
	zephir_check_call_status();
	zephir_array_update_string(&options, SL("lifetime"), &_4, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_STRING(&_1, "libmemcached");
	ZEPHIR_CALL_METHOD(&_6, factory, "newinstance", NULL, 0, &_1, &options);
	zephir_check_call_status();
	zephir_update_property_zval(this_ptr, ZEND_STRL("adapter"), &_6);
	ZEPHIR_MM_RESTORE();
}

/**
 * Flush Memcache data and resets internal meta-data in order to regenerate it
 */
PHP_METHOD(Phalcon_Mvc_Model_MetaData_Libmemcached, reset)
{
	zval _0;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);

	zephir_read_property(&_0, this_ptr, ZEND_STRL("adapter"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(NULL, &_0, "clear", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_PARENT(NULL, phalcon_mvc_model_metadata_libmemcached_ce, getThis(), "reset", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();
}

