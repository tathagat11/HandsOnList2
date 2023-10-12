/*
============================================================================
Name : 23.c
Author : Tathagata Talukdar
Description : Write a program to print the maximum number of files can be 
opened within a process and size of a pipe (circular buffer). 
Date: 12th October 2023
============================================================================
*/

#include <stdio.h>
#include <unistd.h>
#include <sys/resource.h>
#include <fcntl.h>

int main() {
    long max_pipe, num_files;
    max_pipe = pathconf(".",_PC_PIPE_BUF);
    num_files = sysconf(_SC_OPEN_MAX);
    printf("The maximum number of files can be opened within a process is %ld.\n", num_files);
    printf("The size of a pipe (circular buffer) is %ld bytes.\n", max_pipe);
}