# accepts 2 files as arguments,
# Compares contents, if same deletes second file
#!/bin/bash
if cmp -s "$1" "$2"; then
	echo -e "The files match\nDeleting $2"
	rm -f $2
else
	echo "The files are different"
fi
