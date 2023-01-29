#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define FRAME_SIZE 4
#define NUM_PAGES 8
#define NUM_FRAMES 4

int main() {
    int pages[NUM_PAGES] = {1, 2, 3, 4, 2, 1, 5, 6};
    int frames[NUM_FRAMES];
    int page_faults = 0;
    int i, j, k, flag;

    // Initialize frames to -1
    for (i = 0; i < NUM_FRAMES; i++) {
        frames[i] = -1;
    }

    // Iterate through pages
    for (i = 0; i < NUM_PAGES; i++) {
        flag = 0;

        // Check if page is already in a frame
        for (j = 0; j < NUM_FRAMES; j++) {
            if (frames[j] == pages[i]) {
                flag = 1;
                break;
            }
        }

        // If page is not in a frame
        if (!flag) {
            page_faults++;

            // Find the optimal frame to replace
            int replace = 0;
            int max_distance = 0;
            for (j = 0; j < NUM_FRAMES; j++) {
                int distance = NUM_PAGES;
                for (k = i + 1; k < NUM_PAGES; k++) {
                    if (frames[j] == pages[k]) {
                        distance = k - i;
                        break;
                    }
                }
                if (distance > max_distance) {
                    replace = j;
                    max_distance = distance;
                }
            }

            // Replace the frame
            frames[replace] = pages[i];
        }
    }

    printf("Number of page faults: %d\n", page_faults);

    return 0;
}
