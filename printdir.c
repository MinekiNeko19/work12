#include <unistd.h>
#include <sys/stat.h>
#include <dirent.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

int main() {
    DIR *d;
    struct dirent *dp;

    d = opendir("./");
    dp = readdir(d);

    // printf("Total Directory Size: %d bytes\n", );
    printf("files in this folder:\n");
    while(dp) {
        printf("\t%s\n",dp->d_name);
        dp = readdir(d);
    }
    closedir(d);
}