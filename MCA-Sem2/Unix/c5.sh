# greatest of all numbers
#!/bin/bash
greatest=$1
shift
for num in $@; do
	if [ $greatest -lt $num ]; then
		greatest=$num
	fi
done
echo "Greatest number: $greatest"
