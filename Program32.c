#include <stdio.h>

int main() {
    int pages[20], frames[10], page_faults = 0, m, n, s, flag, flag1, i, j;

    printf("Enter the number of pages: ");
    scanf("%d", &m);

    printf("Enter the number of frames: ");
    scanf("%d", &n);

    printf("Enter the pages: ");
    for (i = 0; i < m; i++) {
        scanf("%d", &pages[i]);
    }

    for (i = 0; i < n; i++) {
        frames[i] = -1;
    }

    for (i = 0; i < m; i++) {
        flag1 = 0;
        flag = 0;
        for (j = 0; j < n; j++) {
            if (frames[j] == pages[i]) {
                flag = 1;
                flag1 = 1;
                break;
            }
        }

        if (flag == 0) {
            for (j = 0; j < n; j++) {
                if (frames[j] == -1) {
                    frames[j] = pages[i];
                    flag1 = 1;
                    page_faults++;
                    break;
                }
            }
        }

        if (flag1 == 0) {
            for (j = 0; j < n; j++) {
                frames[j] = -1;
            }
            frames[0] = pages[i];
            page_faults++;
        }

        printf("\n");

        for (j = 0; j < n; j++) {
            printf("%d\t", frames[j]);
        }
    }

    printf("\nTotal Page Faults: %d\n", page_faults);

    return 0;
}
