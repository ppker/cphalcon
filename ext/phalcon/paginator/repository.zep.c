
#ifdef HAVE_CONFIG_H
#include "../../ext_config.h"
#endif

#include <php.h>
#include "../../php_ext.h"
#include "../../ext.h"

#include <Zend/zend_operators.h>
#include <Zend/zend_exceptions.h>
#include <Zend/zend_interfaces.h>

#include "kernel/main.h"
#include "ext/json/php_json.h"
#include "kernel/concat.h"
#include "kernel/memory.h"
#include "kernel/string.h"
#include "kernel/fcall.h"
#include "kernel/object.h"
#include "kernel/operators.h"
#include "kernel/array.h"


/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */
/**
 * Phalcon\Paginator\Repository
 *
 * Repository of current state Phalcon\Paginator\AdapterInterface::paginate()
 */
ZEPHIR_INIT_CLASS(Phalcon_Paginator_Repository)
{
	ZEPHIR_REGISTER_CLASS(Phalcon\\Paginator, Repository, phalcon, paginator_repository, phalcon_paginator_repository_method_entry, 0);

	/**
	 * @var array
	 */
	zend_declare_property_null(phalcon_paginator_repository_ce, SL("aliases"), ZEND_ACC_PROTECTED);
	/**
	 * @var array
	 */
	zend_declare_property_null(phalcon_paginator_repository_ce, SL("properties"), ZEND_ACC_PROTECTED);
	phalcon_paginator_repository_ce->create_object = zephir_init_properties_Phalcon_Paginator_Repository;

	zend_class_implements(phalcon_paginator_repository_ce, 1, phalcon_paginator_repositoryinterface_ce);
	zend_class_implements(phalcon_paginator_repository_ce, 1, php_json_serializable_ce);
	return SUCCESS;
}

/**
 * {@inheritdoc}
 */
PHP_METHOD(Phalcon_Paginator_Repository, __get)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *property_param = NULL, method, _0, _1, _2, _3;
	zval property;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&property);
	ZVAL_UNDEF(&method);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(property)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 1, 0, &property_param);
	zephir_get_strval(&property, property_param);
	ZEPHIR_INIT_VAR(&_0);
	ZEPHIR_CALL_METHOD(&_1, this_ptr, "getrealnameproperty", NULL, 0, &property);
	zephir_check_call_status();
	zephir_camelize(&_0, &_1, NULL );
	ZEPHIR_INIT_VAR(&method);
	ZEPHIR_CONCAT_SV(&method, "get", &_0);
	if ((zephir_method_exists(this_ptr, &method)  == SUCCESS)) {
		ZEPHIR_RETURN_CALL_METHOD_ZVAL(this_ptr, &method, NULL, 0);
		zephir_check_call_status();
		RETURN_MM();
	}
	ZEPHIR_INIT_VAR(&_2);
	zephir_get_class(&_2, this_ptr, 0);
	ZEPHIR_INIT_VAR(&_3);
	ZEPHIR_CONCAT_SVSV(&_3, "Access to undefined property ", &_2, "::", &property);
	ZEPHIR_CALL_FUNCTION(NULL, "trigger_error", NULL, 7, &_3);
	zephir_check_call_status();
	RETURN_MM_NULL();
}

/**
 * {@inheritdoc}
 */
PHP_METHOD(Phalcon_Paginator_Repository, getAliases)
{

	RETURN_MEMBER(getThis(), "aliases");
}

/**
 * {@inheritdoc}
 */
PHP_METHOD(Phalcon_Paginator_Repository, getCurrent)
{
	zval _0, _1;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);

	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "current");
	ZVAL_LONG(&_1, 0);
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "getproperty", NULL, 0, &_0, &_1);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * {@inheritdoc}
 */
PHP_METHOD(Phalcon_Paginator_Repository, getFirst)
{
	zval _0, _1;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);

	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "first");
	ZVAL_LONG(&_1, 0);
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "getproperty", NULL, 0, &_0, &_1);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * {@inheritdoc}
 */
PHP_METHOD(Phalcon_Paginator_Repository, getItems)
{
	zval _0, _1;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);

	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "items");
	ZVAL_NULL(&_1);
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "getproperty", NULL, 0, &_0, &_1);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * {@inheritdoc}
 */
PHP_METHOD(Phalcon_Paginator_Repository, getLast)
{
	zval _0, _1;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);

	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "last");
	ZVAL_LONG(&_1, 0);
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "getproperty", NULL, 0, &_0, &_1);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * {@inheritdoc}
 */
PHP_METHOD(Phalcon_Paginator_Repository, getLimit)
{
	zval _0, _1;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);

	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "limit");
	ZVAL_LONG(&_1, 0);
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "getproperty", NULL, 0, &_0, &_1);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * {@inheritdoc}
 */
PHP_METHOD(Phalcon_Paginator_Repository, getNext)
{
	zval _0, _1;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);

	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "next");
	ZVAL_LONG(&_1, 0);
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "getproperty", NULL, 0, &_0, &_1);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * {@inheritdoc}
 */
PHP_METHOD(Phalcon_Paginator_Repository, getPrevious)
{
	zval _0, _1;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);

	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "previous");
	ZVAL_LONG(&_1, 0);
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "getproperty", NULL, 0, &_0, &_1);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * {@inheritdoc}
 */
PHP_METHOD(Phalcon_Paginator_Repository, getTotalItems)
{
	zval _0, _1;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);

	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "total_items");
	ZVAL_LONG(&_1, 0);
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "getproperty", NULL, 0, &_0, &_1);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * See [jsonSerialize](https://php.net/manual/en/jsonserializable.jsonserialize.php)
 */
PHP_METHOD(Phalcon_Paginator_Repository, jsonSerialize)
{

	RETURN_MEMBER(getThis(), "properties");
}

/**
 * {@inheritdoc}
 */
PHP_METHOD(Phalcon_Paginator_Repository, setAliases)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *aliases_param = NULL;
	zval aliases;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&aliases);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_ARRAY(aliases)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 1, 0, &aliases_param);
	zephir_get_arrval(&aliases, aliases_param);
	zephir_update_property_zval(this_ptr, ZEND_STRL("aliases"), &aliases);
	RETURN_THIS();
}

/**
 * {@inheritdoc}
 */
PHP_METHOD(Phalcon_Paginator_Repository, setProperties)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *properties_param = NULL;
	zval properties;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&properties);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_ARRAY(properties)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 1, 0, &properties_param);
	zephir_get_arrval(&properties, properties_param);
	zephir_update_property_zval(this_ptr, ZEND_STRL("properties"), &properties);
	RETURN_THIS();
}

/**
 * Gets value of property by name
 */
PHP_METHOD(Phalcon_Paginator_Repository, getProperty)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *property_param = NULL, *defaultValue = NULL, defaultValue_sub, __$null, value, _0;
	zval property;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&property);
	ZVAL_UNDEF(&defaultValue_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&value);
	ZVAL_UNDEF(&_0);
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 2)
		Z_PARAM_STR(property)
		Z_PARAM_OPTIONAL
		Z_PARAM_ZVAL_OR_NULL(defaultValue)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 1, 1, &property_param, &defaultValue);
	zephir_get_strval(&property, property_param);
	if (!defaultValue) {
		defaultValue = &defaultValue_sub;
		defaultValue = &__$null;
	}
	zephir_memory_observe(&value);
	zephir_read_property(&_0, this_ptr, ZEND_STRL("properties"), PH_NOISY_CC | PH_READONLY);
	if (!(zephir_array_isset_fetch(&value, &_0, &property, 0))) {
		ZEPHIR_CPY_WRT(&value, defaultValue);
	}
	RETURN_CCTOR(&value);
}

/**
 * Resolve alias property name
 */
PHP_METHOD(Phalcon_Paginator_Repository, getRealNameProperty)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *property_param = NULL, aliases, _0$$3;
	zval property;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&property);
	ZVAL_UNDEF(&aliases);
	ZVAL_UNDEF(&_0$$3);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(property)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 1, 0, &property_param);
	zephir_get_strval(&property, property_param);
	ZEPHIR_CALL_METHOD(&aliases, this_ptr, "getaliases", NULL, 0);
	zephir_check_call_status();
	if (zephir_array_isset(&aliases, &property)) {
		zephir_array_fetch(&_0$$3, &aliases, &property, PH_NOISY | PH_READONLY, "phalcon/Paginator/Repository.zep", 181);
		RETURN_CTOR(&_0$$3);
	}
	RETURN_CTOR(&property);
}

zend_object *zephir_init_properties_Phalcon_Paginator_Repository(zend_class_entry *class_type)
{
		zval _0, _2, _1$$3, _3$$4;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
		ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_3$$4);
	

		ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
		zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	
	{
		zval local_this_ptr, *this_ptr = &local_this_ptr;
		ZEPHIR_CREATE_OBJECT(this_ptr, class_type);
		zephir_read_property_ex(&_0, this_ptr, ZEND_STRL("properties"), PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&_0) == IS_NULL) {
			ZEPHIR_INIT_VAR(&_1$$3);
			array_init(&_1$$3);
			zephir_update_property_zval_ex(this_ptr, ZEND_STRL("properties"), &_1$$3);
		}
		zephir_read_property_ex(&_2, this_ptr, ZEND_STRL("aliases"), PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&_2) == IS_NULL) {
			ZEPHIR_INIT_VAR(&_3$$4);
			array_init(&_3$$4);
			zephir_update_property_zval_ex(this_ptr, ZEND_STRL("aliases"), &_3$$4);
		}
		ZEPHIR_MM_RESTORE();
		return Z_OBJ_P(this_ptr);
	}
}

