#!/bin/sh

set -e

ROOT=`dirname $0`"/../support/xhpast"

echo
echo "Building XHPAST..."
echo

(cd $ROOT && make clean all install)

echo
echo "Build successful!"
echo
