#!/bin/sh

git add *

if [$# -eq 1];
  then
	git commit ~/mylib -m $1
  else
	git commit ~/mylib -m "auto updated"
fi

git push
