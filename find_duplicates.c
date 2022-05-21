/* find_duplicates extension for PHP */

#ifdef HAVE_CONFIG_H
# include "config.h"
#endif

#include "php.h"
#include "ext/standard/info.h"
#include "php_find_duplicates.h"

/* For compatibility with older PHP versions */
#ifndef ZEND_PARSE_PARAMETERS_NONE
#define ZEND_PARSE_PARAMETERS_NONE() \
	ZEND_PARSE_PARAMETERS_START(0, 0) \
	ZEND_PARSE_PARAMETERS_END()
#endif

/* {{{ void find_duplicates_test1()
 */
PHP_FUNCTION(find_duplicates_test1)
{
	ZEND_PARSE_PARAMETERS_NONE();

	php_printf("The extension %s is loaded and working!\r\n", "find_duplicates");
}
/* }}} */

/* {{{ string find_duplicates_test2( [ string $var ] )
 */
PHP_FUNCTION(find_duplicates_test2)
{
	char *var = "World";
	size_t var_len = sizeof("World") - 1;
	zend_string *retval;

	ZEND_PARSE_PARAMETERS_START(0, 1)
		Z_PARAM_OPTIONAL
		Z_PARAM_STRING(var, var_len)
	ZEND_PARSE_PARAMETERS_END();

	retval = strpprintf(0, "Hello %s", var);

	RETURN_STR(retval);
}

PHP_FUNCTION(find_duplicates)
{
	char *str;
	size_t var_len;
	int i, j, count, len;

	zend_string *retval;

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STRING(str, var_len)
	ZEND_PARSE_PARAMETERS_END();

	for(i=0; i<var_len;i++)
	{
		count = 1;
		for(j=i+1; j<var_len;j++)
		{
			if(str[i]==str[j] && str[i]!=' ')
			{
				count++;
				str[j] = '0';
			}
		}

		if(count>1 && str[i]!='0')
		{
		}else
		{
			str[i] = '0';
		}
	}
   len = var_len;
	   	
  	for(int i = 0; i < len; i++)
	{
		if(str[i] == '0')
		{
			for(int j = i; j < len; j++)
			{
				str[j] = str[j + 1];
			}
			len--;
			i--;	
		} 
	} 
	retval = strpprintf(0, str);

	RETURN_STR(retval);
}


/* }}}*/

/* {{{ PHP_RINIT_FUNCTION
 */
PHP_RINIT_FUNCTION(find_duplicates)
{
#if defined(ZTS) && defined(COMPILE_DL_FIND_DUPLICATES)
	ZEND_TSRMLS_CACHE_UPDATE();
#endif

	return SUCCESS;
}
/* }}} */

/* {{{ PHP_MINFO_FUNCTION
 */
PHP_MINFO_FUNCTION(find_duplicates)
{
	php_info_print_table_start();
	php_info_print_table_header(2, "find_duplicates support", "enabled");
	php_info_print_table_end();
}
/* }}} */

/* {{{ arginfo
 */
ZEND_BEGIN_ARG_INFO(arginfo_find_duplicates_test1, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO(arginfo_find_duplicates_test2, 0)
	ZEND_ARG_INFO(0, str)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO(arginfo_find_duplicates, 0)
	ZEND_ARG_INFO(0, str)
ZEND_END_ARG_INFO()	
/* }}} */

/* {{{ find_duplicates_functions[]
 */
static const zend_function_entry find_duplicates_functions[] = {
	PHP_FE(find_duplicates_test1,		arginfo_find_duplicates_test1)
	PHP_FE(find_duplicates_test2,		arginfo_find_duplicates_test2)
	PHP_FE(find_duplicates, arginfo_find_duplicates)
	PHP_FE_END
};
/* }}} */

/* {{{ find_duplicates_module_entry
 */
zend_module_entry find_duplicates_module_entry = {
	STANDARD_MODULE_HEADER,
	"find_duplicates",					/* Extension name */
	find_duplicates_functions,			/* zend_function_entry */
	NULL,							/* PHP_MINIT - Module initialization */
	NULL,							/* PHP_MSHUTDOWN - Module shutdown */
	PHP_RINIT(find_duplicates),			/* PHP_RINIT - Request initialization */
	NULL,							/* PHP_RSHUTDOWN - Request shutdown */
	PHP_MINFO(find_duplicates),			/* PHP_MINFO - Module info */
	PHP_FIND_DUPLICATES_VERSION,		/* Version */
	STANDARD_MODULE_PROPERTIES
};
/* }}} */

#ifdef COMPILE_DL_FIND_DUPLICATES
# ifdef ZTS
ZEND_TSRMLS_CACHE_DEFINE()
# endif
ZEND_GET_MODULE(find_duplicates)
#endif
