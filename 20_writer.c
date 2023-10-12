/*
============================================================================
Name : 20_writer.c
Author : Tathagata Talukdar
Description : Write a program so both can communicate using fifo (one way).
Date: 12th October 2023
============================================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>
#include <sys/stat.h>

int main(){
    mkfifo("fifo20a", 0666);

    int fd = open("fifo20a", O_WRONLY);
    write(fd, "hello", sizeof("hello"));
    printf("Sent: %s\n", "hello");
    close(fd);
    return 0;
}