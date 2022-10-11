# a. print lines that do not contain vowel
# b. count characters, words and lines in a file
#!/bin/bash
v=$(grep -cv "[AEIOUaeiou]" $1)
c=$(wc <$1 -m)
w=$(wc <$1 -w)
l=$(wc <$1 -l)
echo -e "$1 has:\n$c characters\n$w words\n$l lines\n$v lines w/o vowels"
