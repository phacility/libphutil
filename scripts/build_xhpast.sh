#!/bin/sh

set -e

ROOT=`dirname $0`"/../support/xhpast"

echo
echo "Building XHPAST..."
echo

cd $ROOT
make clean all install

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
