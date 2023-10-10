/*
============================================================================
Name : 17c.c
Author : Tathagata Talukdar
Description : Write a program to execute ls -l | wc using (c) fcntl.
Date: 10th October 2023
============================================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>

int main(){
    int fd[2];
    pid_t pid;
    pipe(fd);
    if((pid = fork()) < 0){
        printf("Fork Error!!");
        return EXIT_FAILURE;
    }
    if(pid == 0){
        close(fd[1]);
        close(0);
        fcntl(fd[0], F_DUPFD, 0);
        char *args[] = {"wc", NULL};
        execv("/bin/wc", args);
        close(fd[0]);
        return EXIT_SUCCESS;
    } else {
        close(fd[0]);
        close(1);
        fcntl(fd[1], F_DUPFD, 1);
        char *args[] = {"ls", "-l", NULL};
        execv("/bin/ls", args);
        close(fd[1]);
    }
    return EXIT_SUCCESS;
}
