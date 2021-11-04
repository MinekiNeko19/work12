#include <unistd.h>
#include <sys/stat.h>
#include <dirent.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <string.h>
#include <errno.h>

int main(int argc, char *argv[]) {
    printf("argc: %d argv[0]: %s argv[1]: %s\n", argc, argv[0], argv[1]);

    // getting input
    char buffer[100];
    read(STDIN_FILENO,buffer, 1);
    // if (buffer==NULL) printf("Please enter a directory: ");

    // printing the meta data
    struct stat sb;
    stat(buffer, &sb);
    if (sb.st_mode == 0) {
        printf("directory %s not found\nerror %d: %s\n", buffer, errno, strerror(errno));
    } else {
    printf("Statistics for directory: %s\n",buffer);
    printf("Total Directory Size: %lu bytes\n", sb.st_size);

    // listing the items
    DIR *d;
    struct dirent *dp;

    d = opendir(buffer);
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
}