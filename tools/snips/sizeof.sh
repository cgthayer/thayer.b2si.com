#!/bin/bash

if [ -z "$*" ]; then
    set bool char short int long "long long" float double "long double" "void*"
fi

o=/tmp/sizeof.cc
echo "#include <stdio.h>" > $o
echo "int main() {" >> $o
for n in "$@"; do echo "  printf(\"$n=%d\n\", sizeof($n));" >> $o; done
echo "  return 0; }" >> $o

g++ $o -o /tmp/sizeof
/tmp/sizeof
