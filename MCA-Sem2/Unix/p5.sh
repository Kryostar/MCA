# 'grep' command to select lines from a file with exactly 2 characters
#!/bin/bash
if [ $# -lt 2 ]; then
	echo -e "Insufficient Arguements (min 2)\nUsage: \"bash p3.sh text1.txt 2\""
else
	# main
	echo -e "1. Lines having characters of length $2:"
	grep -w '\w\{'$2'\}' $1
	echo -e "2. Lines having more than one whitespace:"
	grep "  " $1
fi
