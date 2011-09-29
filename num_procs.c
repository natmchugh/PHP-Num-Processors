/*
   +----------------------------------------------------------------------+
   | PHP Version 5                                                        |
   +----------------------------------------------------------------------+
   | Copyright (c) 1997-2010 The PHP Group                                |
   +----------------------------------------------------------------------+
   | This source file is subject to version 3.0 of the PHP license,       |
   | that is bundled with this package in the file LICENSE, and is        |
   | available through the world-wide-web at the following url:           |
   | http://www.php.net/license/3_0.txt.                                  |
   | If you did not receive a copy of the PHP license and are unable to   |
   | obtain it through the world-wide-web, please send a note to          |
   | license@php.net so we can mail you a copy immediately.               |
   +----------------------------------------------------------------------+
   | Author: Nathaniel McHugh <nat@fishtrap.co.uk>                   |
   +----------------------------------------------------------------------+
 */

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include "php.h"

#include "num_procs.h"

/* {{{ proto resource num_processors_available()
   Returns the number of processors */
PHP_FUNCTION(num_processors_available)
{
   long nprocs = -1;
#ifdef _WIN32
    #ifndef _SC_NPROCESSORS_ONLN
        SYSTEM_INFO info;
        GetSystemInfo(&info);
        #define sysconf(a) info.dwNumberOfProcessors
        #define _SC_NPROCESSORS_ONLN
    #endif
#endif
#ifdef _SC_NPROCESSORS_ONLN
  nprocs = sysconf(_SC_NPROCESSORS_ONLN);
#endif
	RETURN_LONG(nprocs);
}
/* }}} */


/* {{{ proto resource num_processors_configured()
   Returns the number of processors */
PHP_FUNCTION(num_processors_configured)
{
  long nprocs_max = -1;
#ifdef _WIN32
    #ifndef _SC_NPROCESSORS_CONF
        SYSTEM_INFO info;
        GetSystemInfo(&info);
        #define sysconf(a) info.dwNumberOfProcessors
        #define _SC_NPROCESSORS_CONF
    #endif
#endif
#ifdef _SC_NPROCESSORS_CONF
  nprocs_max = sysconf(_SC_NPROCESSORS_CONF);
#endif
	RETURN_LONG(nprocs_max);
}
/* }}} */

ZEND_BEGIN_ARG_INFO_EX(num_procs_online_args, 0, 0, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(num_procs_conf_args, 0, 0, 0)
ZEND_END_ARG_INFO()

static function_entry num_procs_functions[] = {
	PHP_FE(num_processors_available, num_procs_online_args)
	PHP_FE(num_processors_configured, num_procs_conf_args)

	/* End of functions */
	{NULL, NULL, NULL}
};

PHP_MINFO_FUNCTION(num_procs)
{
	php_info_print_table_start();
	php_info_print_table_header(2, "num_procs support", "enabled");
	php_info_print_table_row(2, "version", NUM_PROCS_VERSION);
	php_info_print_table_end();
}

zend_module_entry num_procs_module_entry = {
	STANDARD_MODULE_HEADER,
	"num_procs",
	num_procs_functions,
	NULL,
	NULL,
	NULL,	
	NULL,
	PHP_MINFO(num_procs),
	NUM_PROCS_VERSION,
	STANDARD_MODULE_PROPERTIES
};

#ifdef COMPILE_DL_NUM_PROCS
ZEND_GET_MODULE(num_procs)
#endif

/*
 * Local variables:
 * c-basic-offset: 4
 * tab-width: 4
 * End:
 * vim600: fdm=marker
 * vim: sw=4 ts=4 noet
 */
