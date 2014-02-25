#!/bin/bash

set -e

ROOT=`dirname $0`"/../support/xhpast"

USE_GMAKE=1
command -v gmake >/dev/null 2>&1 || USE_GMAKE=0

echo
echo "Building XHPAST..."
echo

cd $ROOT
if [ $USE_GMAKE -eq 1 ]; then
    gmake clean all install
else
    make clean all install
fi

echo
echo "Testing xhpast works"
echo
if ! ./xhpast --version
then
  echo
  echo >&2 "xhpast is broken :("
  echo >&2 "Maybe try \`STATIC=1 ./build_xhpast.sh\` if the error"
  echo >&2 "is linker-related?"
  echo
  exit 2
fi

echo
echo "Build successful!"
echo
