# Replace whitespace with tabspace
#!/bin/bash
echo "Enter a sentence: "
read n
echo $n | tr [:space:] '\t'
