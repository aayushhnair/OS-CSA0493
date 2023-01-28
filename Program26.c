#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *file;
    char fileName[] = "example.txt";
    char data[] = "This is a test file.";
    
    // Creating a new file
    file = fopen(fileName, "w");
    if (file == NULL) {
        printf("Error creating file!\n");
        exit(1);
    }
    
    // Writing data to the file
    fprintf(file, "%s", data);
    
    // Closing the file
    fclose(file);
    
    // Reading data from the file
    file = fopen(fileName, "r");
    if (file == NULL) {
        printf("Error opening file!\n");
        exit(1);
    }
    char readData[100];
    fscanf(file, "%s", readData);
    printf("Data from file: %s\n", readData);
    fclose(file);
    
    // Removing the file
    if (remove(fileName) != 0) {
        printf("Error deleting file!\n");
    } else {
        printf("File successfully deleted.\n");
    }
    
    return 0;
}
