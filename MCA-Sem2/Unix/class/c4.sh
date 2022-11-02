# check for odd or even
#!/bin/bash
if [ $(($1 % 2)) -ne 0 ]; then
	echo "Odd"
else
	echo "Even"
fi
