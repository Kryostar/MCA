# List all (only?) files in a directory
#!/bin/bash
ls -p $1 | grep -v /

# find . -maxdepth 1 -type f