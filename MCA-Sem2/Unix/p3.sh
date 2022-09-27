#!/bin/bash
if [ $# -lt 2 ]; then
	echo -e "Insufficient Arguements (min 2)\nUsage: \"bash p3.sh text1.txt text2.txt\""
else
	wordfile="$1"
	wordlist=($(cat "$wordfile" | tr -s [:space:] \\n <$wordfile | sort | uniq))
	shift
	for file in "$@"; do
		for word in "${wordlist[@]}"; do
			echo "$file: $word:" $(grep -io "\b${word}\b" "$file" | wc -l)
		done
	done
fi
