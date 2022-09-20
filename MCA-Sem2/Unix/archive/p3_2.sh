if [ $# -lt 2 ]; then
	echo "Use atleast 2 arguements!"
else
	// Tr is translating the spaces in the file to new lines.
	tr " " "
" <$1 >temp
	sort temp | uniq
	shift
	for i in $@; do
		tr " " "
" <$i >temp1
		sort temp1
		j=1
		y=$(wc -l <temp)

		while [ $y -ge $j ]; do
			x=$(head -n $j temp | tail -1)
			c=$(grep -c "$x" temp1)
			echo $x $c
			j=$(expr $j + 1)
		done
	done
fi
