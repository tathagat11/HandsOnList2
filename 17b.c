/*
============================================================================
Name : 17b.c
Author : Tathagata Talukdar
Description : Write a program to execute ls -l | wc using (b) dup2.
Date: 9th October 2023
============================================================================
*/

#include <stdio.h>
#include <unistd.h>

int main(){
    int fd[2];
    pipe(fd);
    if(fork() == 0){
        close(fd[0]);
        dup2(fd[1], STDOUT_FILENO);
        close(fd[1]);
        execlp("ls", "ls", "-l", NULL);
    } else {
        close(fd[1]);
        dup2(fd[0], STDIN_FILENO);
        close(fd[0]);
        execlp("wc", "wc", NULL);
    }
    return 0;
}