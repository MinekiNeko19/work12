#include <unistd.h>
#include <sys/stat.h>
#include <dirent.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

int main(int argc, char *argv[]) {
    // printing the meta data
    struct stat sb;
    stat(argv[1], &sb);
    printf("Statistics for directory: %s\n", argv[1]);
    printf("Total Directory Size: %lu bytes\n", sb.st_size);

    // listing the items
    DIR *d;
    struct dirent *dp;

    d = opendir(argv[1]);
    dp = readdir(d);

    printf("In this directory:\n");
    printf("Directories:\n");
    while(dp && dp->d_type == DT_DIR) {
        printf("\t%s\n",dp->d_name);
        dp = readdir(d);
    }
    printf("Normal files:\n");
    while(dp) {
        printf("\t%s\n",dp->d_name);
        dp = readdir(d);
    }
    closedir(d);
}