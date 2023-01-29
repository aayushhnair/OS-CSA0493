#include <stdio.h>

#define MAX_QUEUE_SIZE 100

int queue[MAX_QUEUE_SIZE];
int front = 0, rear = -1;
int current_track = 0;

void enqueue(int track_number) {
    if (rear == MAX_QUEUE_SIZE - 1) {
        printf("Error: Queue is full\n");
    } else {
        queue[++rear] = track_number;
    }
}

int dequeue() {
    if (front > rear) {
        printf("Error: Queue is empty\n");
        return -1;
    } else {
        return queue[front++];
    }
}

void sort_queue() {
    int i, j, temp;
    for (i = front; i <= rear; i++) {
        for (j = i + 1; j <= rear; j++) {
            if (queue[i] > queue[j]) {
                temp = queue[i];
                queue[i] = queue[j];
                queue[j] = temp;
            }
        }
    }
}

int main() {
    int i, n, track_number;
    printf("Enter the number of track requests: ");
    scanf("%d", &n);

    printf("Enter the track numbers: ");
    for (i = 0; i < n; i++) {
        scanf("%d", &track_number);
        enqueue(track_number);
    }

    printf("Enter the current track number: ");
    scanf("%d", &current_track);

    sort_queue();

    int total_distance = 0;
    while (front <= rear) {
        int next_track = dequeue();
        if(next_track>=current_track){
            total_distance += next_track - current_track;
        }else{
            total_distance += current_track - next_track;
            current_track = 0;
            while(front <= rear){
                next_track = dequeue();
                total_distance += next_track;
            }
        }
        current_track = next_track;
    }

    printf("Total distance (C-SCAN): %d\n", total_distance);

    return 0;
}
