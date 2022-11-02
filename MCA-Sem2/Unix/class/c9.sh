# check whether number is prime
#!/bin/bash
num=$1
for ((i = 2; i < num / 2; i++)); do
	if [ $((num % i)) -eq 0 ]; then
		echo $num is Composite number
		exit
	fi
done
echo $num is prime