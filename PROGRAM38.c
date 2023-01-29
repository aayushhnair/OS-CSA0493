#include <stdio.h>
#include <stdlib.h>

// Function to simulate SCAN disk scheduling algorithm
void scan(int queue[], int head, int max)
{
    int i, j, seek = 0, diff;
    int left[max];
    int right[max];
    int left_size, right_size;
    int seek_sequence[max];

    // Divide requests in left and right of head
    for (i = 0; i < max; i++)
    {
        if (queue[i] < head)
        {
            left[i] = queue[i];
            left_size++;
        }
        else if (queue[i] > head)
        {
            right[i] = queue[i];
            right_size++;
        }
    }

    // Sort left and right requests
    for (i = 0; i < left_size - 1; i++)
    {
        for (j = i + 1; j < left_size; j++)
        {
            if (left[i] > left[j])
            {
                int temp = left[i];
                left[i] = left[j];
                left[j] = temp;
            }
        }
    }
    for (i = 0; i < right_size - 1; i++)
    {
        for (j = i + 1; j < right_size; j++)
        {
            if (right[i] > right[j])
            {
                int temp = right[i];
                right[i] = right[j];
                right[j] = temp;
            }
        }
    }

    // Serve requests in left-to-right order
    for (i = 0; i < left_size; i++)
    {
        diff = abs(head - left[i]);
        seek += diff;
        seek_sequence[i] = left[i];
        head = left[i];
    }

    // Serve requests in right-to-left order
    for (i = 0; i < right_size; i++)
    {
        diff = abs(head - right[i]);
        seek += diff;
        seek_sequence[i + left_size] = right[i];
        head = right[i];
    }

    printf("Total seek time is %d\n", seek);

    printf("Seek Sequence is: ");
    for (i = 0; i < max; i++)
        printf("%d ", seek_sequence[i]);
}

int main()
{
    int queue[] = {98, 183, 37, 122, 14, 124, 65, 67};
    int head = 53;
    int max = sizeof(queue) / sizeof(queue[0]);

    scan(queue, head, max);

    return 0;
}
