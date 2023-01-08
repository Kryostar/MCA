#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#define buff 1024

int main(int argc, char* argv[])
{
	int fd1, fd2;
	char buffer[buff];
	long int n1;

	if (((fd1 = open(argv[1], O_RDONLY)) == -1) || ((fd2 = open(argv[2], O_CREAT | O_WRONLY | O_TRUNC, 0700)) == -1)) {
		perror("file problem");
		exit(1);
	}

	while ((n1 = read(fd1, buffer, buff)) > 0) {
		if (write(fd2, buffer, n1) != n1) {
			perror("writing problem ");
			exit(3);
		}
	}
	close(fd1);
	close(fd2);
}