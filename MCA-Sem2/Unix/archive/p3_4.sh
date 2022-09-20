clear
echo " Enter the number of files::"
read n
echo "Enter the "n" files ::"
read fn
set $fn
for i in $(cat $1); do
	echo -e " word = $i"
	echo -e "------------"
	grep -c "$i" $*
	echo -e "------------"
done
