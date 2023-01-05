#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <sys/stat.h>

int main() {
	// Create a file
	int fd = creat("test.txt", 0644);
	if (fd < 0) {
		perror("Error creating file");
		return 1;
	}

	// Write some data to the file
	char* data = "Hello, world!";
	ssize_t bytes_written = write(fd, data, strlen(data));
	if (bytes_written < strlen(data)) {
		perror("Error writing to file");
		return 1;
	}

	// Get the file's stats
	struct stat file_stat;
	int stat_result = fstat(fd, &file_stat);
	if (stat_result < 0) {
		perror("Error getting file stats");
		return 1;
	}

	printf("File size: %ld bytes\n", file_stat.st_size);

	// Seek to the beginning of the file
	off_t offset = lseek(fd, 0, SEEK_SET);
	if (offset < 0) {
		perror("Error seeking in file");
		return 1;
	}

	// Read the file's contents
	char buffer[256];
	ssize_t bytes_read = read(fd, buffer, sizeof(buffer));
	if (bytes_read < 0) {
		perror("Error reading from file");
		return 1;
	}
	buffer[bytes_read] = '\0'; // Null-terminate the string
	printf("File contents: %s\n", buffer);

	// Close the file
	int close_result = close(fd);
	if (close_result < 0) {
		perror("Error closing file");
		return 1;
	}

	return 0;
}
