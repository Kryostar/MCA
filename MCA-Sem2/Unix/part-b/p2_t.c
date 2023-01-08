#include<unistd.h>
#include<stdio.h>
#include<fcntl.h>
#define buff 50

int main() {
	int fd, wr;
	char buffer[buff];
	char msg[50] = "Hello world!";
	fd = open("b.txt", O_RDWR | O_CREAT, 0642);
	printf("fd = %d\n", fd);
	if (fd != -1) {
		printf("b.txt is open\n");
		if (wr = write(fd, msg, buff) < 0) {
			perror("Error writing");
		}
		lseek(fd, 0, SEEK_SET);
		read(fd, buffer, buff);
		printf("\"%s\" was written to the file\n", buffer);
		close(fd);
	}
	return 0;
}