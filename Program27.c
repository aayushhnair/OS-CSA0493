#include <stdio.h>
#include <dirent.h>

int main(int argc, char* argv[]) {
    DIR* dir;
    struct dirent* ent;

    if (argc < 2) {
        // If no directory is specified, use the current directory
        dir = opendir(".");
    } else {
        dir = opendir(argv[1]);
    }

    if (dir != NULL) {
        while ((ent = readdir(dir)) != NULL) {
            printf("%s\n", ent->d_name);
        }
        closedir(dir);
    } else {
        // Could not open directory
        printf("Could not open directory\n");
        return 1;
    }

    return 0;
}
