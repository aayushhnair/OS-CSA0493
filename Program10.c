#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>

#define MAX_SIZE 128

struct message {
    long type;
    char text[MAX_SIZE];
};

int main() {
    key_t key;
    int msgid;
    struct message msg;

    key = ftok("keyfile.txt", 1);
    msgid = msgget(key, 0666 | IPC_CREAT);

    pid_t pid = fork();
    if (pid == 0) { // child process
        // receive message
        msgrcv(msgid, &msg, MAX_SIZE, 0, 0);
        printf("Child process received message: %s\n", msg.text);
    } else { // parent process
        // send message
        msg.type = 1;
        strcpy(msg.text, "Hello, child process!");
        msgsnd(msgid, &msg, sizeof(msg.text), 0);
    }

    msgctl(msgid, IPC_RMID, NULL);
    return 0;
}
