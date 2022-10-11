# factorial of number
#!/bin/bash
num=$1
fact=1
for ((i = 2; i <= num; i++)); do
	echo "$fact * $i = $((fact*i))"
	fact=$((fact * i))
done
echo Factorial is $fact
