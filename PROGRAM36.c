#include <stdio.h>
#include <stdlib.h>

struct block {
    int data;
    struct block *next;
};

struct file {
    char name[20];
    struct block *first;
    struct block *last;
};

struct directory {
    struct file files[10];
    int num_files;
};

void create_file(struct directory *dir, char *name) {
    int i = dir->num_files++;
    strcpy(dir->files[i].name, name);
    dir->files[i].first = NULL;
    dir->files[i].last = NULL;
}

void add_block(struct file *file, int data) {
    struct block *new_block = (struct block *) malloc(sizeof(struct block));
    new_block->data = data;
    new_block->next = NULL;
    if (file->first == NULL) {
        file->first = new_block;
    } else {
        file->last->next = new_block;
    }
    file->last = new_block;
}

void delete_file(struct directory *dir, char *name) {
    int i;
    for (i = 0; i < dir->num_files; i++) {
        if (strcmp(dir->files[i].name, name) == 0) {
            break;
        }
    }
    if (i < dir->num_files) {
        struct file *file = &dir->files[i];
        struct block *curr = file->first;
        while (curr != NULL) {
            struct block *next = curr->next;
            free(curr);
            curr = next;
        }
        memmove(&dir->files[i], &dir->files[i + 1], (dir->num_files - i - 1) * sizeof(struct file));
        dir->num_files--;
    }
}

int main() {
    struct directory dir;
    dir.num_files = 0;

    create_file(&dir, "file1");
    add_block(&dir.files[0], 1);
    add_block(&dir.files[0], 2);
    add_block(&dir.files[0], 3);

    create_file(&dir, "file2");
    add_block(&dir.files[1], 4);
    add_block(&dir.files[1], 5);

    delete_file(&dir, "file1");

    return 0;
}
