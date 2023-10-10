/*
============================================================================
Name : 14.c
Author : Tathagata Talukdar
Description : Write a program to crate a pipe, write to the pipe, read from 
the pipe and display on the monitor.
Date: 9th October 2023
============================================================================
*/

#include <sys/types.h>
#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

int main(int argc, char* argv[]){
    char buffer[100];
    int fd_pipe[2];
    if(pipe(fd_pipe) == -1){
        printf("Pipe Error!");
        return EXIT_FAILURE;
    }
    write(fd_pipe[1],argv[1],strlen(argv[1]));
    read(fd_pipe[0], buffer, strlen(argv[1]));
    write(2, buffer, strlen(buffer));
    write(2, "\n", 1);

    return 0;
}