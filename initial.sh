#!/bin/sh
#author sww

#Create the Directory
#Create Makefile and the source file
dir=${1}
name=${2}
if [ -d $dir ]; then
	echo "cd $dir"
	cd $dir
	sh initial.sh $name
else
	echo "directory $dir does not exit!"
fi
