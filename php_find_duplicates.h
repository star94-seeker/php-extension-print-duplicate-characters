/* find_duplicates extension for PHP */

#ifndef PHP_FIND_DUPLICATES_H
# define PHP_FIND_DUPLICATES_H

extern zend_module_entry find_duplicates_module_entry;
# define phpext_find_duplicates_ptr &find_duplicates_module_entry

# define PHP_FIND_DUPLICATES_VERSION "0.1.0"

# if defined(ZTS) && defined(COMPILE_DL_FIND_DUPLICATES)
ZEND_TSRMLS_CACHE_EXTERN()
# endif

#endif	/* PHP_FIND_DUPLICATES_H */
