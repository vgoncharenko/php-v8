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

#include "php_v8_callback_info.h"
#include "php_v8_return_value.h"
#include "php_v8_value.h"
#include "php_v8.h"


zend_class_entry *php_v8_callback_info_class_entry;
#define this_ce php_v8_callback_info_class_entry

static zend_object_handlers php_v8_callback_info_object_handlers;


static PHP_METHOD(CallbackInfo, getIsolate) {
    zval rv;
    zval *tmp;

    if (zend_parse_parameters_none() == FAILURE) {
        return;
    }

    tmp = zend_read_property(this_ce, getThis(), ZEND_STRL("isolate"), 0, &rv);
    ZVAL_COPY(return_value, tmp);
}

static PHP_METHOD(CallbackInfo, getContext) {
    zval rv;
    zval *tmp;

    if (zend_parse_parameters_none() == FAILURE) {
        return;
    }

    tmp = zend_read_property(this_ce, getThis(), ZEND_STRL("context"), 0, &rv);
    ZVAL_COPY(return_value, tmp);
}

static PHP_METHOD(CallbackInfo, this) {
    zval rv;
    zval *tmp;

    if (zend_parse_parameters_none() == FAILURE) {
        return;
    }

    tmp = zend_read_property(this_ce, getThis(), ZEND_STRL("this"), 0, &rv);
    ZVAL_COPY(return_value, tmp);
}

static PHP_METHOD(CallbackInfo, holder) {
    zval rv;
    zval *tmp;

    if (zend_parse_parameters_none() == FAILURE) {
        return;
    }

    tmp = zend_read_property(this_ce, getThis(), ZEND_STRL("holder"), 0, &rv);
    ZVAL_COPY(return_value, tmp);
}

static PHP_METHOD(CallbackInfo, getReturnValue) {
    zval rv;
    zval *tmp;

    if (zend_parse_parameters_none() == FAILURE) {
        return;
    }

    tmp = zend_read_property(this_ce, getThis(), ZEND_STRL("return_value"), 0, &rv);
    ZVAL_COPY(return_value, tmp);
}

PHP_V8_ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_callback_info_getIsolate, ZEND_RETURN_VALUE, 0, V8\\Isolate, 0)
ZEND_END_ARG_INFO()

PHP_V8_ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_callback_info_getContext, ZEND_RETURN_VALUE, 0, V8\\Context, 0)
ZEND_END_ARG_INFO()

PHP_V8_ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_callback_info_this, ZEND_RETURN_VALUE, 0, V8\\ObjectValue, 0)
ZEND_END_ARG_INFO()

PHP_V8_ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_callback_info_holder, ZEND_RETURN_VALUE, 0, V8\\ObjectValue, 0)
ZEND_END_ARG_INFO()

PHP_V8_ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_callback_info_getReturnValue, ZEND_RETURN_VALUE, 0, V8\\ReturnValue, 0)
ZEND_END_ARG_INFO()

static const zend_function_entry php_v8_callback_info_methods[] = {
        PHP_ME(CallbackInfo, this, arginfo_callback_info_this, ZEND_ACC_PUBLIC)
        PHP_ME(CallbackInfo, holder, arginfo_callback_info_holder, ZEND_ACC_PUBLIC)
        PHP_ME(CallbackInfo, getIsolate, arginfo_callback_info_getIsolate, ZEND_ACC_PUBLIC)
        PHP_ME(CallbackInfo, getContext, arginfo_callback_info_getContext, ZEND_ACC_PUBLIC)
        PHP_ME(CallbackInfo, getReturnValue, arginfo_callback_info_getReturnValue, ZEND_ACC_PUBLIC)
        PHP_FE_END
};

PHP_MINIT_FUNCTION (php_v8_callback_info) {
    zend_class_entry ce;

    INIT_NS_CLASS_ENTRY(ce, PHP_V8_NS, "CallbackInfo", php_v8_callback_info_methods);
    this_ce = zend_register_internal_class(&ce);

    memcpy(&php_v8_callback_info_object_handlers, zend_get_std_object_handlers(), sizeof(zend_object_handlers));

    zend_declare_property_null(this_ce, ZEND_STRL("isolate"), ZEND_ACC_PRIVATE);
    zend_declare_property_null(this_ce, ZEND_STRL("context"), ZEND_ACC_PRIVATE);
    zend_declare_property_null(this_ce, ZEND_STRL("this"), ZEND_ACC_PRIVATE);
    zend_declare_property_null(this_ce, ZEND_STRL("holder"), ZEND_ACC_PRIVATE);
    zend_declare_property_null(this_ce, ZEND_STRL("return_value"), ZEND_ACC_PRIVATE);

    return SUCCESS;
}
