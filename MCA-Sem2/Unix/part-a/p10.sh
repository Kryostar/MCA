# Taking the command line arguments and merging them into one file.
#!/bin/bash
for file in $@; do
	cat $file >>mergedFile.txt
done

# alternatively, you can use one line command
# cat $1 $2 $3 > mergedFile.txt