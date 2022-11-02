# List of all users who are currently logged in
#!/bin/bash
who | cut -d' ' -f1 | sort | uniq