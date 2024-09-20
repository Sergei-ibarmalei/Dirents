#include <dirent.h>
#include <stdio.h>

int main(int argc, char** argv)
{
    char* directory = argc > 1 ? argv[1] : ".";
    printf("The directory: %s\n", directory);
    DIR* dir = NULL;
    struct dirent* entry = NULL;

    dir = opendir(directory);
    if (!dir)
    {
        printf("Cannot open directory %s\n", directory);
        return -1;
    }
    while ((entry = readdir(dir)) != NULL)
    {
        // type 4 means subdir
        // we show files only
        if (entry->d_type == 4) continue;
        printf("%s\n", entry->d_name);
    }
    closedir(dir);
    return 0;
}
