dnl config.m4 for extension find_duplicates

dnl Comments in this file start with the string 'dnl'.
dnl Remove where necessary.

dnl If your extension references something external, use 'with':

dnl PHP_ARG_WITH([find_duplicates],
dnl   [for find_duplicates support],
dnl   [AS_HELP_STRING([--with-find_duplicates],
dnl     [Include find_duplicates support])])

dnl Otherwise use 'enable':

PHP_ARG_ENABLE([find_duplicates],
  [whether to enable find_duplicates support],
  [AS_HELP_STRING([--enable-find_duplicates],
    [Enable find_duplicates support])],
  [no])

if test "$PHP_FIND_DUPLICATES" != "no"; then
  dnl Write more examples of tests here...

  dnl Remove this code block if the library does not support pkg-config.
  dnl PKG_CHECK_MODULES([LIBFOO], [foo])
  dnl PHP_EVAL_INCLINE($LIBFOO_CFLAGS)
  dnl PHP_EVAL_LIBLINE($LIBFOO_LIBS, FIND_DUPLICATES_SHARED_LIBADD)

  dnl If you need to check for a particular library version using PKG_CHECK_MODULES,
  dnl you can use comparison operators. For example:
  dnl PKG_CHECK_MODULES([LIBFOO], [foo >= 1.2.3])
  dnl PKG_CHECK_MODULES([LIBFOO], [foo < 3.4])
  dnl PKG_CHECK_MODULES([LIBFOO], [foo = 1.2.3])

  dnl Remove this code block if the library supports pkg-config.
  dnl --with-find_duplicates -> check with-path
  dnl SEARCH_PATH="/usr/local /usr"     # you might want to change this
  dnl SEARCH_FOR="/include/find_duplicates.h"  # you most likely want to change this
  dnl if test -r $PHP_FIND_DUPLICATES/$SEARCH_FOR; then # path given as parameter
  dnl   FIND_DUPLICATES_DIR=$PHP_FIND_DUPLICATES
  dnl else # search default path list
  dnl   AC_MSG_CHECKING([for find_duplicates files in default path])
  dnl   for i in $SEARCH_PATH ; do
  dnl     if test -r $i/$SEARCH_FOR; then
  dnl       FIND_DUPLICATES_DIR=$i
  dnl       AC_MSG_RESULT(found in $i)
  dnl     fi
  dnl   done
  dnl fi
  dnl
  dnl if test -z "$FIND_DUPLICATES_DIR"; then
  dnl   AC_MSG_RESULT([not found])
  dnl   AC_MSG_ERROR([Please reinstall the find_duplicates distribution])
  dnl fi

  dnl Remove this code block if the library supports pkg-config.
  dnl --with-find_duplicates -> add include path
  dnl PHP_ADD_INCLUDE($FIND_DUPLICATES_DIR/include)

  dnl Remove this code block if the library supports pkg-config.
  dnl --with-find_duplicates -> check for lib and symbol presence
  dnl LIBNAME=FIND_DUPLICATES # you may want to change this
  dnl LIBSYMBOL=FIND_DUPLICATES # you most likely want to change this

  dnl If you need to check for a particular library function (e.g. a conditional
  dnl or version-dependent feature) and you are using pkg-config:
  dnl PHP_CHECK_LIBRARY($LIBNAME, $LIBSYMBOL,
  dnl [
  dnl   AC_DEFINE(HAVE_FIND_DUPLICATES_FEATURE, 1, [ ])
  dnl ],[
  dnl   AC_MSG_ERROR([FEATURE not supported by your find_duplicates library.])
  dnl ], [
  dnl   $LIBFOO_LIBS
  dnl ])

  dnl If you need to check for a particular library function (e.g. a conditional
  dnl or version-dependent feature) and you are not using pkg-config:
  dnl PHP_CHECK_LIBRARY($LIBNAME, $LIBSYMBOL,
  dnl [
  dnl   PHP_ADD_LIBRARY_WITH_PATH($LIBNAME, $FIND_DUPLICATES_DIR/$PHP_LIBDIR, FIND_DUPLICATES_SHARED_LIBADD)
  dnl   AC_DEFINE(HAVE_FIND_DUPLICATES_FEATURE, 1, [ ])
  dnl ],[
  dnl   AC_MSG_ERROR([FEATURE not supported by your find_duplicates library.])
  dnl ],[
  dnl   -L$FIND_DUPLICATES_DIR/$PHP_LIBDIR -lm
  dnl ])
  dnl
  dnl PHP_SUBST(FIND_DUPLICATES_SHARED_LIBADD)

  dnl In case of no dependencies
  AC_DEFINE(HAVE_FIND_DUPLICATES, 1, [ Have find_duplicates support ])

  PHP_NEW_EXTENSION(find_duplicates, find_duplicates.c, $ext_shared)
fi
