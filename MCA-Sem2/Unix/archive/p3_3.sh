#!/bin/bash
# Direct the script to use bash shell for its execution

# Check to see if enough arguments are passed

if [ $# -lt 2 ]; then
	echo "Usage: ./05countwords.sh <search_file> <file_name> [<file_name> ...]"
	exit 1
fi

search_file=$1 # Read the search file name

# Loop through each file supplied as argument to the command

for file_name in "$@"; do

	# First file contains search words, so skip it

	if [ "$file_name" = "$1" ]; then

		continue

	fi

	# Display the file name

	echo "--------------------"

	echo $file_name

	echo "--------------------"

	# Check if the text file exists

	if [ ! -f $file_name ]; then

		echo "File \"$file_name\" does not exist"

		exit 2

	fi

	# Loop through the search file reading one word per line

	while read search_word; do

		# Count the frequency of current search word in current file.

		# To do that, first replace all tabs (011) and spaces (040) with

		# newlines (012). Then remove all the characters except a-z, A-Z

		# 0-9, - and newlines. Finally frequency of current search word

		word_freq=$(tr "[\011\040]" "[\012\012]" <$file_name |
			tr -cd "[a-zA-Z0-9-\012]" |
			grep -c "$search_word")

		# Display the word and its frequency

		echo $search_word $word_freq

	done <$search_file

done
