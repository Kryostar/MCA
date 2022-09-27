# sum of digits of number
# !/bin/bash
num=$1
temp=$num
sum=0
while [ $num -gt 0 ]; do
	rem=$(($num % 10))
	num=$(($num / 10))
	sum=$(($sum + $rem))
done
echo "Sum of digits of $temp is : $sum"
