wordfile="$1"
wordlist=($(cat "$wordfile"))
shift

echo "Word Count program : "
for file in "$@"; do
	for word in "${wordlist[@]}"; do
		echo "$file: $word:" $(grep -o "\b${word}\b" "$file" | wc -l) # My way
		# echo "$file: $word:" $(tr ' ' '\n' <"$file" | grep -c "$word")   # Your way
	done
done
