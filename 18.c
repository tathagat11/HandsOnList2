/*
============================================================================
Name : 18.c
Author : Tathagata Talukdar
Description : Write a program to execute ls -l | grep ^d | wc using (c) fcntl.
Date: 10th October 2023
============================================================================
*/


#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/types.h>
int main(void)
{
    int fd1[2], fd2[2];
    pid_t pid1, pid2;
    if(pipe(fd1) < 0 || pipe(fd2) < 0) {
        perror("Pipe");
        exit(EXIT_FAILURE);
    }
    if((pid1=fork()) < 0) {
        perror("Fork Error!");
        exit(EXIT_FAILURE);
    }
    if (!pid1) {
        dup2(fd1[1], 1);
        close(fd2[0]);
        close(fd2[1]);
        close(fd1[0]);
        execlp("ls","ls", "-l", NULL);
    } else {
        if((pid2=fork()) < 0) {
            perror("Fork Error!");
            exit(EXIT_FAILURE);
        }
        if (!pid2) {
            dup2(fd1[0], 0);
            dup2(fd2[1], 1);
            close(fd1[1]);
            close(fd2[0]);
            execlp("grep", "grep", "^d", NULL);
            
        } else {
            sleep(2);
            dup2(fd2[0], 0);
            close(fd2[1]);
            close(fd1[0]);
            close(fd1[1]);
            execlp("wc", "wc", NULL);
        }
    }
}