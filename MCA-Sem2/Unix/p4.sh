#!/bin/bash
if [ $# -lt 2 ]; then
	echo -e "Insufficient Arguments (min 2)\nUsage: \"bash p3.sh -u text1.txt\"\n-u : uppercase\n-l : lowercase"
else
	option="${1}"
	shift
	for file in $@; do
		if [ ! -f $file ]; then
			echo "Filename $file doesn't exist"
			shift
		else
			case ${option} in
			-u)
				tr '[a-z]' '[A-Z]' <$file
				;;
			-l)
				tr '[A-Z]' '[a-z]' <$file
				;;
			esac
		fi
	done
fi
