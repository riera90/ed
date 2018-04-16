#!/bin/bash
#	script for the creation of the temporal fyles for the makefile
for file in $*; do
	directory=$(echo $file | sed -rn 's/^(\.[\/A-Za-z\_]*)\/[A-Za-z\_]*$/\1/p')
	if [[ -d $directory ]]; then
		echo "[already created] " $directory
	else
		if [[ "" != $directory ]]; then
			mkdir -p $directory
		fi
	fi
done
