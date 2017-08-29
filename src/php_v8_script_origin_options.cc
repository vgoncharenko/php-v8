/*
 * This file is part of the pinepain/php-v8 PHP extension.
 *
 * Copyright (c) 2015-2017 Bogdan Padalko <pinepain@gmail.com>
 *
 * Licensed under the MIT license: http://opensource.org/licenses/MIT
 *
 * For the full copyright and license information, please view the
 * LICENSE file that was distributed with this source or visit
 * http://opensource.org/licenses/MIT
 */

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include "php_v8_script_origin_options.h"
#include "php_v8.h"

zend_class_entry* php_v8_script_origin_options_class_entry;
#define this_ce php_v8_script_origin_options_class_entry


void php_v8_create_script_origin_options(zval * return_value, v8::ScriptOriginOptions options) {
    object_init_ex(return_value, this_ce);

    zend_update_property_bool(this_ce, return_value, ZEND_STRL("is_shared_cross_origin"), static_cast<zend_bool>(options.IsSharedCrossOrigin()));
    zend_update_property_bool(this_ce, return_value, ZEND_STRL("is_opaque"), static_cast<zend_bool>(options.IsOpaque()));
    zend_update_property_bool(this_ce, return_value, ZEND_STRL("is_wasm"), static_cast<zend_bool>(options.IsWasm()));
    zend_update_property_bool(this_ce, return_value, ZEND_STRL("is_module"), static_cast<zend_bool>(options.IsModule()));
}


static PHP_METHOD(ScriptOriginOptions, __construct) {
    zend_bool is_shared_cross_origin = '\0';
    zend_bool is_opaque = '\0';
    zend_bool is_wasm = '\0';
    zend_bool is_module = '\0';

    if (zend_parse_parameters(ZEND_NUM_ARGS(), "|bbbb",
                              &is_shared_cross_origin, &is_opaque, &is_wasm, &is_module) == FAILURE) {
        return;
    }

    zend_update_property_bool(this_ce, getThis(), ZEND_STRL("is_shared_cross_origin"), is_shared_cross_origin);
    zend_update_property_bool(this_ce, getThis(), ZEND_STRL("is_opaque"), is_opaque);
}


static PHP_METHOD(ScriptOriginOptions, isSharedCrossOrigin) {
    zval rv;

    if (zend_parse_parameters_none() == FAILURE) {
        return;
    }

    RETVAL_ZVAL(zend_read_property(this_ce, getThis(), ZEND_STRL("is_shared_cross_origin"), 0, &rv), 1, 0);
}

static PHP_METHOD(ScriptOriginOptions, isOpaque) {
    zval rv;

    if (zend_parse_parameters_none() == FAILURE) {
        return;
    }

    RETVAL_ZVAL(zend_read_property(this_ce, getThis(), ZEND_STRL("is_opaque"), 0, &rv), 1, 0);
}

static PHP_METHOD(ScriptOriginOptions, isWasm) {
    zval rv;

    if (zend_parse_parameters_none() == FAILURE) {
        return;
    }

    RETVAL_ZVAL(zend_read_property(this_ce, getThis(), ZEND_STRL("is_wasm"), 0, &rv), 1, 0);
}

static PHP_METHOD(ScriptOriginOptions, isModule) {
    zval rv;

    if (zend_parse_parameters_none() == FAILURE) {
        return;
    }

    RETVAL_ZVAL(zend_read_property(this_ce, getThis(), ZEND_STRL("is_module"), 0, &rv), 1, 0);
}


ZEND_BEGIN_ARG_INFO_EX(arginfo_script_origin_options___construct, ZEND_SEND_BY_VAL, ZEND_RETURN_VALUE, 0)
                ZEND_ARG_TYPE_INFO(0, is_shared_cross_origin, _IS_BOOL, 0)
                ZEND_ARG_TYPE_INFO(0, is_opaque, _IS_BOOL, 0)
                ZEND_ARG_TYPE_INFO(0, is_wasm, _IS_BOOL, 0)
                ZEND_ARG_TYPE_INFO(0, is_module, _IS_BOOL, 0)
ZEND_END_ARG_INFO()


PHP_V8_ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_script_origin_options_isSharedCrossOrigin, ZEND_RETURN_VALUE, 0, _IS_BOOL, 0)
ZEND_END_ARG_INFO()

PHP_V8_ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_script_origin_options_isOpaque, ZEND_RETURN_VALUE, 0, _IS_BOOL, 0)
ZEND_END_ARG_INFO()

PHP_V8_ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_script_origin_options_isWasm, ZEND_RETURN_VALUE, 0, _IS_BOOL, 0)
ZEND_END_ARG_INFO()

PHP_V8_ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_script_origin_options_isModule, ZEND_RETURN_VALUE, 0, _IS_BOOL, 0)
ZEND_END_ARG_INFO()


static const zend_function_entry php_v8_script_origin_options_methods[] = {
        PHP_ME(ScriptOriginOptions, __construct, arginfo_script_origin_options___construct, ZEND_ACC_PUBLIC | ZEND_ACC_CTOR)

        PHP_ME(ScriptOriginOptions, isSharedCrossOrigin, arginfo_script_origin_options_isSharedCrossOrigin, ZEND_ACC_PUBLIC)
        PHP_ME(ScriptOriginOptions, isOpaque, arginfo_script_origin_options_isOpaque, ZEND_ACC_PUBLIC)
        PHP_ME(ScriptOriginOptions, isWasm, arginfo_script_origin_options_isWasm, ZEND_ACC_PUBLIC)
        PHP_ME(ScriptOriginOptions, isModule, arginfo_script_origin_options_isModule, ZEND_ACC_PUBLIC)

        PHP_FE_END
};


PHP_MINIT_FUNCTION(php_v8_script_origin_options) {
    zend_class_entry ce;
    INIT_NS_CLASS_ENTRY(ce, PHP_V8_NS, "ScriptOriginOptions", php_v8_script_origin_options_methods);
    this_ce = zend_register_internal_class(&ce);

    zend_declare_property_bool(this_ce, ZEND_STRL("is_shared_cross_origin"), static_cast<zend_bool>(false), ZEND_ACC_PRIVATE);
    zend_declare_property_bool(this_ce, ZEND_STRL("is_opaque"), static_cast<zend_bool>(false), ZEND_ACC_PRIVATE);
    zend_declare_property_bool(this_ce, ZEND_STRL("is_wasm"), static_cast<zend_bool>(false), ZEND_ACC_PRIVATE);
    zend_declare_property_bool(this_ce, ZEND_STRL("is_module"), static_cast<zend_bool>(false), ZEND_ACC_PRIVATE);

    return SUCCESS;
}
