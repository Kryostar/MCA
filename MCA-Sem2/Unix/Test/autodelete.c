#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <dirent.h>
#include <string.h>

#define CHECK_INTERVAL_SECONDS 60 // Check for files every 60 seconds

int main(int argc, char* argv[]) {
	if (argc < 2) {
		printf("Usage: %s <directory>\n", argv[0]);
		return 1;
	}

	// Open the specified directory
	DIR* dir = opendir(argv[1]);
	if (dir == NULL) {
		perror("Error opening directory");
		return 1;
	}

	// Loop forever, checking for and deleting .exe files every CHECK_INTERVAL_SECONDS seconds
	while (1) {
		// Read the directory entries
		struct dirent* entry;
		while ((entry = readdir(dir)) != NULL) {
			// Check if the entry is an .exe file
			if (entry->d_type == DT_REG && strcmp(entry->d_name + strlen(entry->d_name) - 4, ".exe") == 0) {
				// Construct the full path of the file
				char path[256];
				snprintf(path, sizeof(path), "%s/%s", argv[1], entry->d_name);

				// Delete the file
				int delete_result = unlink(path);
				if (delete_result < 0) {
					perror("Error deleting file");
				}
			}
		}
		// Reset the directory stream so that we can read the entries again
		rewinddir(dir);

		// Sleep for the specified interval before checking again
		sleep(CHECK_INTERVAL_SECONDS);
	}

	// Close the directory
	closedir(dir);

	return 0;
}
