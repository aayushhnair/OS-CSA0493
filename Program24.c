#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int main() {
    int fd;
    char *file = "example.txt";

    // Create a new file with read and write permissions for the owner
    fd = creat(file, S_IRUSR | S_IWUSR);
    if (fd < 0) {
        printf("Error creating file\n");
        return 1;
    }

    // Write to the file
    write(fd, "Hello, world!", 14);

    // Close the file
    close(fd);

    // Open the file for reading
    fd = open(file, O_RDONLY);
    if (fd < 0) {
        printf("Error opening file for reading\n");
        return 1;
    }

    // Read from the file
    char buffer[14];
    read(fd, buffer, 14);
    printf("Content of the file: %s\n", buffer);

    // Close the file
    close(fd);

    // Remove the file
    unlink(file);

    return 0;
}
