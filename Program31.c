#include <stdio.h>
#define MAX_PAGES 100

int main() {
    int pages[MAX_PAGES];
    int current_pages = 0;
    int page_fault_count = 0;
    int capacity;

    printf("Enter the capacity of the memory: ");
    scanf("%d", &capacity);

    printf("Enter the page reference string: ");
    while (scanf("%d", &pages[current_pages]) == 1) {
        current_pages++;
    }

    int memory[capacity];
    int memory_count = 0;
    int i, j, page_fault;
    for (i = 0; i < current_pages; i++) {
        page_fault = 1;
        for (j = 0; j < memory_count; j++) {
            if (memory[j] == pages[i]) {
                page_fault = 0;
                break;
            }
        }

        if (page_fault) {
            page_fault_count++;
            if (memory_count < capacity) {
                memory[memory_count] = pages[i];
                memory_count++;
            } else {
                for (j = 0; j < capacity - 1; j++) {
                    memory[j] = memory[j + 1];
                }
                memory[capacity - 1] = pages[i];
            }
        }
    }
    printf("Number of page faults: %d", page_fault_count);
    return 0;
}
