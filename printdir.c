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
    char input[100];
    int i = 0;
    read(STDIN_FILENO, buffer, 100);
    printf("buffer: %s\n",buffer);
    while(buffer[i] != 0) {
        i++;
    }
    strncpy(input,buffer,i-1);


    // printing the meta data
    if (errno) {
        printf("directory %s not found\nerror %d: %s\n", buffer, errno, strerror(errno));
    } else {
    struct stat sb;
    stat(input, &sb);
    printf("Statistics for directory: %s\n",input);
    printf("Total Directory Size: %lu bytes\n", sb.st_size);

    // listing the items
    DIR *d;
    struct dirent *dp;

    d = opendir(input);
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