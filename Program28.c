#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <pattern>\n", argv[0]);
        return 1;
    }

    char *pattern = argv[1];
    char line[1024];

    while (fgets(line, sizeof(line), stdin)) {
        if (strstr(line, pattern) != NULL) {
            printf("%s", line);
        }
    }

    return 0;
}
