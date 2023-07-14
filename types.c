#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>

int main(int argc, char *argv[])
{
    if (argc < 2){printf("usage: path1 [path2 ...]\n");} 
    else {
        for (int i = 1; i < argc; i++){
            printf("%s: ",argv[i]);
            struct stat stats;

            if (lstat(argv[i],&stats) == 0){
                if(S_ISREG(stats.st_mode)) printf("regular file");
                else if(S_ISDIR(stats.st_mode)) printf("directory");
                else if(S_ISBLK(stats.st_mode)) printf("block device");
                else if(S_ISCHR(stats.st_mode)) printf("character special file");
                else if(S_ISFIFO(stats.st_mode)) printf("named pipe");
                else if(S_ISLNK(stats.st_mode)) printf("symbolic link");
                else if(S_ISSOCK(stats.st_mode)) printf("socket");
                else printf("other");
                
            } else {
                printf("path error");
            }
            printf("\n");
        }
    }
    
}
