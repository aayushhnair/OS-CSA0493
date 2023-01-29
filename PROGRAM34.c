#include <stdio.h>
#include <stdlib.h>

struct File {
    char data[100];
    struct File *next;
};

struct File *head = NULL;

void insertRecord(char *record) {
    struct File newFile = (struct File) malloc(sizeof(struct File));
    strcpy(newFile->data, record);
    newFile->next = NULL;

    if (head == NULL) {
        head = newFile;
        return;
    }

    struct File *temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newFile;
}

void readRecord(int index) {
    if (head == NULL) {
        printf("No records found.\n");
        return;
    }

    struct File *temp = head;
    for (int i = 0; i < index; i++) {
        if (temp == NULL) {
            printf("Record not found.\n");
            return;
        }
        temp = temp->next;
    }
    printf("Record: %s\n", temp->data);
}

int main() {
    insertRecord("Record 1");
    insertRecord("Record 2");
    insertRecord("Record 3");
    insertRecord("Record 4");

    readRecord(2); // Prints "Record 3"
    return 0;
}
