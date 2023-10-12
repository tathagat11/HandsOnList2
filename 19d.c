/*
============================================================================
Name : 19d.c
Author : Tathagata Talukdar
Description : Create a FIFO file using (d) mknod system call.
Date: 12th October 2023
============================================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>

int main() {
    if (mknod("my_fifo_mknod",__S_IFIFO | 0666, 0) == -1) {
        perror("mknod");
        exit(EXIT_FAILURE);
    }

    printf("FIFO file created named 'my_fifo_mknod'\n");
    return 0;
}