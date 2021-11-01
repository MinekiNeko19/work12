#include <unistd.h>
#include <sys/stat.h>
#include <dirent.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

int main() {
    // printing the meta data
    struct stat sb;
    stat(".", &sb);

    printf("Statistics for directory: .\n");
    printf("Total Directory Size: %lu bytes\n", sb.st_size);

    // listing the items
    DIR *d;
    struct dirent *dp;

    d = opendir("./");
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