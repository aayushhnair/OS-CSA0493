#include <stdio.h>

#define MAX_BLOCKS 50
#define BLOCK_SIZE 100

int main() {
    int memory[MAX_BLOCKS * BLOCK_SIZE]; // simulated memory
    int blocks[MAX_BLOCKS]; // block sizes
    int process_size;
    int i, j;

    // initialize memory blocks
    for (i = 0; i < MAX_BLOCKS; i++) {
        blocks[i] = BLOCK_SIZE;
    }

    // get process size from user
    printf("Enter process size: ");
    scanf("%d", &process_size);

    // first fit algorithm
    for (i = 0; i < MAX_BLOCKS; i++) {
        if (blocks[i] >= process_size) {
            blocks[i] -= process_size;
            printf("Allocated memory in block %d\n", i);
            break;
        }
    }

    if (i == MAX_BLOCKS) {
        printf("No suitable block found\n");
    }

    return 0;
}
