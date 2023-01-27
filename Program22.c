#include <stdio.h> 

#define MAX 100 

int main() 
{ 
    int fragment[MAX], b[MAX], p[MAX], i, j, m, n, temp, blockSize[MAX]; 

    // input for number of blocks and number of processes 
    printf("Enter number of blocks: "); 
    scanf("%d", &m); 
    printf("Enter number of processes: "); 
    scanf("%d", &n); 

    // input for block size 
    printf("Enter the size of the blocks:-\n"); 
    for (i = 1; i <= m; i++) { 
        printf("Block no. %d: ", i); 
        scanf("%d", &blockSize[i]); 
    } 

    // input for process size 
    printf("Enter the size of the processes :-\n"); 
    for (i = 1; i <= n; i++) { 
        printf("Process no. %d: ", i); 
        scanf("%d", &p[i]); 
    } 

    // initializing the block array 
    for (i = 1; i <= m; i++) 
        b[i] = blockSize[i]; 

    // sorting block array in ascending order 
    for (i = 1; i <= m; i++) { 
        for (j = 1; j <= m - i; j++) { 
            if (b[j] > b[j + 1]) { 
                temp = b[j]; 
                b[j] = b[j + 1]; 
                b[j + 1] = temp; 
            } 
        } 
    } 

    // allocating the blocks to the processes 
    for (i = 1; i <= n; i++) { 
        for (j = 1; j <= m; j++) { 
            if (b[j] >= p[i]) { 
                fragment[i] = b[j] - p[i]; 
                b[j] = 0; 
                break; 
            } 
        } 
    } 

    // printing the result 
    printf("\nProcess Number\tProcess Size\tBlock no.\tFragment"); 
    for (i = 1; i <= n; i++) { 
        printf("\n%d\t\t%d\t\t", i, p[i]); 
        for (j = 1; j <= m; j++) { 
            if (blockSize[j] == p[i] + fragment[i]) { 
                printf("%d\t\t%d", j, fragment[i]); 
                break; 
            } 
        } 
    } 

    return 0; 
}
