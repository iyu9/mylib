#!/bin/sh

if [ $# -eq 1 ];

then
	ping -c 10 $1;

	if [$? -eq 0];
			then
			#OK 
			echo "working"

	else
			#NG: mail etc
			echo "not working"
	fi
else
	echo "arg error"
fi
