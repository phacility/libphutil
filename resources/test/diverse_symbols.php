<?php

// This file has diverse symbol declarations and requirements, and can be used
// to test changes to phutil_symbols.php.

/**
 * @phutil-external-symbol function ext_func
 * @phutil-external-symbol class ExtClass
 * @phutil-external-symbol interface ExtInterface
 */
ext_func();
new ExtClass();
class L implements ExtInterface {}

function f() {}

(function () {
  // Anonymous function.
});

g();
$g();
$$g();

X::f();
call_user_func();
call_user_func('h');
call_user_func($var);

class A {}
class C extends B {}
class D extends C {}

new U();
V::m();
W::$n;
P::CONST;

interface ILocal extends IForeign {}
class CLocal extends INonlocal {}

strtoupper('');


// Various magic things.

exit($x);
empty($x);
isset($x);
echo $x;
print($x);
exit($x);
include $x;
include_once $x;
require $x;
require_once $x;
