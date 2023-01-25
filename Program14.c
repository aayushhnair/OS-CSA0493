#include <stdio.h>
#include <string.h>

#define MAX_FILES 10
#define MAX_FILENAME_LENGTH 20

struct file {
    char name[MAX_FILENAME_LENGTH];
    int size;
};

struct directory {
    struct file files[MAX_FILES];
    int num_files;
};

void init_directory(struct directory *dir) {
    dir->num_files = 0;
}

int add_file(struct directory *dir, char name[], int size) {
    if (dir->num_files >= MAX_FILES) {
        return -1; /* return -1 if directory is full */
    }
    strcpy(dir->files[dir->num_files].name, name);
    dir->files[dir->num_files].size = size;
    dir->num_files++;
    return 0;
}

void list_files(struct directory dir) {
    int i;
    for (i = 0; i < dir.num_files; i++) {
        printf("%s (size: %d bytes)\n", dir.files[i].name, dir.files[i].size);
    }
}

int main() {
    struct directory dir;
    init_directory(&dir);
    add_file(&dir, "file1.txt", 100);
    add_file(&dir, "file2.txt", 200);
    add_file(&dir, "file3.txt", 300);
    list_files(dir);
    return 0;
}
