# Shell script to display list of file names
# having read, Write and Execute permission
#!/bin/bash
echo "The name of all files having all permissions :"
echo find * -perm -700 | ls -l