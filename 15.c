/*
============================================================================
Name : 15.c
Author : Tathagata Talukdar
Description : Write a program to send data from parent to child process.
Date: 9th October 2023
============================================================================
*/

#include<sys/types.h>
#include<sys/wait.h>
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>

int main(int argc, char *argv[]){
    int fd_pipe[2];
    pid_t pid;
    char buffer;

    if(pipe(fd_pipe) == -1){
        printf("Pipe Error!");
        return EXIT_FAILURE;
    }
    
    pid = fork();
    
    if(pid == 0){
        close(fd_pipe[1]);
        while(read(fd_pipe[0], &buffer, 1) > 0) write(2, &buffer, 1);
        write(2, "\n", 1);
        close(fd_pipe[0]);
        return EXIT_SUCCESS;
    }

    else {
        close(fd_pipe[0]);
        write(fd_pipe[1], argv[1], strlen(argv[1]));
        close(fd_pipe[1]);
        wait(NULL);
        return EXIT_SUCCESS;
    }
}