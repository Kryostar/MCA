#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>

int main(int argc, char* argv[])
{
	if (argc != 2)
	{
		printf("Usage: %s <file_name>\n", argv[0]);
		return 1;
	}

	int fd = open(argv[1], O_CREAT | O_WRONLY, S_IRUSR | S_IWUSR);
	if (fd == -1)
	{
		perror("Error creating file");
		return 1;
	}
	else { printf("Create is successful\n"); }

	const char* message = "Hello, world!\n";
	ssize_t bytes_written = write(fd, message, strlen(message));
	if (bytes_written == -1)
	{
		perror("Error writing to file");
		return 1;
	}
	else { printf("Write is successful\n"); }
	if (close(fd) == -1)
	{
		perror("Error closing file");
		return 1;
	}
	else { printf("closing is successful\n"); }
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
	{
		perror("Error opening file");
		return 1;
	}
	else {
		printf("opening is successful\n");

		printf("The contents written in the file are: %s", message);
	}
	struct stat file_stats;
	if (fstat(fd, &file_stats) == -1)
	{
		perror("Error getting file stats");
		return 1;
	}
	printf("st_mode=%o \n", file_stats.st_mode);

	printf("File size: %ld bytes\n", file_stats.st_size);

	if (close(fd) == -1)
	{
		perror("Error closing file");
		return 1;
	}

	return 0;
}