#include <stdio.h>

void FCFS(int queue[], int head, int size) {
    int i, seek_count = 0, distance;
    int temp[size];

    // Copy queue to temp and add head position
    for (i = 0; i < size; i++) {
        temp[i] = queue[i];
    }
    temp[size] = head;

    // Sort temp in ascending order
    for (i = 0; i <= size; i++) {
        for (int j = 0; j <= size; j++) {
            if (temp[i] < temp[j]) {
                int temp_swap = temp[i];
                temp[i] = temp[j];
                temp[j] = temp_swap;
            }
        }
    }

    // Find head position in temp
    for (i = 0; i <= size; i++) {
        if (temp[i] == head) {
            break;
        }
    }

    // Calculate total seek count
    for (int j = i; j < size; j++) {
        distance = abs(temp[j + 1] - temp[j]);
        seek_count += distance;
    }

    printf("Total seek count: %d\n", seek_count);
}

int main() {
    int queue[] = {98, 183, 37, 122, 14, 124, 65, 67};
    int head = 53, size = sizeof(queue) / sizeof(queue[0]);

    FCFS(queue, head, size);

    return 0;
}
