#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>
#include <dirent.h>

int main() {
    int fd;
    struct stat fileStat;
    DIR *dir;
    struct dirent *dirEntry;

    // Open a file using fcntl
    fd = open("example.txt", O_RDONLY);

    // Get file information using stat
    fstat(fd, &fileStat);

    printf("File size: %ld bytes\n", fileStat.st_size);

    // Change file offset using lseek
    lseek(fd, 10, SEEK_SET);

    // Read from the file
    char buffer[100];
    read(fd, buffer, 100);
    printf("File contents: %s\n", buffer);

    // Close the file
    close(fd);

    // Open a directory using opendir
    dir = opendir(".");

    // Read directory entries using readdir
    while ((dirEntry = readdir(dir)) != NULL) {
        printf("%s\n", dirEntry->d_name);
    }

    // Close the directory
    closedir(dir);

    return 0;
}
