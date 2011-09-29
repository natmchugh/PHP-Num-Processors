dnl
dnl 
dnl 

PHP_ARG_ENABLE(num_procs, whether to enable the num procs extension,
[  --enable-num_procs       Enable num procs support])

if test "$PHP_NUM_PROCS" != "no"; then
  PHP_NEW_EXTENSION(num_procs, num_procs.c, $ext_shared)
fi
