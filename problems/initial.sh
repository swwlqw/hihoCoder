#!/bin/sh
#author sww

#Create the Directory
#Create Makefile and the source file
name=${1}
if [ -e $name ]; then
	echo "file $name exits!"
else
	mkdir $name
	cd $name
	time=`date '+%Y-%m-%d %H:%M:%S'`
	echo '
//============================================================================
// Name        : '$name'.c
// Author      : sww
// Version     : 1.0
// Time	       : '$time'
//===========================================================================

#include <stdio.h>

int main() {

	return 0;
}
'		> ${name}.c

	echo '
bin= '${name}'
$(bin): $(bin).c
	gcc -o $@ $^
clean:
	rm $(bin)

'		> Makefile

	echo "project $name initialized successfully!"
fi
