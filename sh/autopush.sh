#!/bin/sh

git add *

if [$# -eq 1];
  then
	git commit -m $1;
  else
	git commit -m "updated with autoupdate.sh";
fi

git push
