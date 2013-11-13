#!/bin/bash

FLEX=`which flex35 2>/dev/null || which flex 2>/dev/null`
if [ $? -ne 0 ]
then
  echo "ERROR: 'flex' is not installed on this system." 1>&2;
  exit 1;
fi

FLEXVERSION=`"$FLEX" --version`

if [[ $FLEXVERSION == "flex 2.5.4" ]]
then
  echo "ERROR: the version of flex on this system is too old." 1>&2
  echo "Upgrade to at least 2.5.35 (which is NEWER than 2.5.4)." 1>&2
  exit 1;
fi

if [ "$FLEXVERSION" != "flex 2.5.35" -a "$FLEXVERSION" != "flex35 2.5.35" ]
then
  echo "WARNING: the version of flex on this system may be incorrect." 1>&2
  echo "If you receive errors, try upgrading to 2.5.35 or newer." 1>&2
fi

echo $FLEX
