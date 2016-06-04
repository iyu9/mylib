#!/bin/sh

if [ $# -eq 1 ];

then
	ping $1
else
	echo "arg error"
fi
