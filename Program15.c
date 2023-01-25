#include <stdio.h>
#include <string.h>

#define MAX_FILES 10
#define MAX_SUBDIRECTORIES 5
#define MAX_FILENAME_LENGTH 20

struct file {
    char name[MAX_FILENAME_LENGTH];
    int size;
};

struct subdirectory {
    struct file files[MAX_FILES];
    int num_files;
    char name[MAX_FILENAME_LENGTH];
};

struct directory {
    struct subdirectory subdirectories[MAX_SUBDIRECTORIES];
    int num_subdirectories;
};

void init_directory(struct directory *dir) {
    dir->num_subdirectories = 0;
}

int add_subdirectory(struct directory *dir, char name[]) {
    if (dir->num_subdirectories >= MAX_SUBDIRECTORIES) {
        return -1; /* return -1 if directory is full */
    }
    strcpy(dir->subdirectories[dir->num_subdirectories].name, name);
    dir->subdirectories[dir->num_subdirectories].num_files = 0;
    dir->num_subdirectories++;
    return 0;
}

int add_file(struct directory *dir, char subdir_name[], char file_name[], int size) {
    int i, subdir_index = -1;
    for (i = 0; i < dir->num_subdirectories; i++) {
        if (strcmp(dir->subdirectories[i].name, subdir_name) == 0) {
            subdir_index = i;
            break;
        }
    }
    if (subdir_index == -1) {
        return -1; /* return -1 if subdirectory not found */
    }
    if (dir->subdirectories[subdir_index].num_files >= MAX_FILES) {
        return -1; /* return -1 if subdirectory is full */
    }
    strcpy(dir->subdirectories[subdir_index].files[dir->subdirectories[subdir_index].num_files].name, file_name);
    dir->subdirectories[subdir_index].files[dir->subdirectories[subdir_index].num_files].size = size;
    dir->subdirectories[subdir_index].num_files++;
    return 0;
}

void list_files(struct directory dir) {
    int i, j;
    for (i = 0; i < dir.num_subdirectories; i++) {
        printf("Subdirectory %s:\n", dir.subdirectories[i].name);
        for (j = 0; j < dir.subdirectories[i].num_files; j++) {
            printf("\t%s (size: %d bytes)\n", dir.subdirectories[i].files[j].name, dir.subdirectories[i].files[j].size);
        }
    }
}
