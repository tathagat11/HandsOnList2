/*
============================================================================
Name : 17a.c
Author : Tathagata Talukdar
Description : Write a program to execute ls -l | wc using (a) dup.
Date: 9th October 2023
============================================================================
*/

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>

int main(){
    int fd[2];
    pid_t pid;
    if(pipe(fd)<0){
        printf("Pipe Error!");
        return EXIT_FAILURE;
    }
    if((pid = fork()) < 0){
        printf("Fork Error!");
        return EXIT_FAILURE;
    }
    if(pid == 0){
        close(fd[0]);
        close(1);
        dup(fd[1]);
        char *args[] = {"ls", "-l", NULL};
        execv("/bin/ls", args);
        close(fd[1]);
        return 0;
    } else {
        close(fd[1]);
        close(0);
        dup(fd[0]);
        char *args[] = {"wc", NULL};
        execv("/bin/wc", args);
        close(fd[0]);
    }
    return 0;
}