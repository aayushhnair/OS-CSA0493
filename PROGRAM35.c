#include <stdio.h>
#include <stdlib.h>

#define BLOCK_SIZE 4096
#define NUM_BLOCKS 100

int index_block[NUM_BLOCKS];
char data_blocks[NUM_BLOCKS][BLOCK_SIZE];

void init_file_system() {
    int i;
    for (i = 0; i < NUM_BLOCKS; i++) {
        index_block[i] = -1;
    }
}

int allocate_block() {
    int i;
    for (i = 0; i < NUM_BLOCKS; i++) {
        if (index_block[i] == -1) {
            index_block[i] = i;
            return i;
        }
    }
    return -1;
}

void write_file(int file_id, char* data) {
    int i, block_id, data_len = strlen(data);
    for (i = 0; i < data_len; i += BLOCK_SIZE) {
        block_id = allocate_block();
        if (block_id == -1) {
            printf("Error: Not enough space in file system.\n");
            return;
        }
        strncpy(data_blocks[block_id], data + i, BLOCK_SIZE);
    }
}

void read_file(int file_id) {
    int i;
    for (i = 0; i < NUM_BLOCKS; i++) {
        if (index_block[i] == file_id) {
            printf("%s", data_blocks[i]);
        }
    }
}

int main() {
    init_file_system();
    write_file(1, "This is a test file.");
    read_file(1);
    return 0;
}
