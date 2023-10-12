/*
============================================================================
Name : 20_reader.c
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

int main(){
    int fd = open("fifo20a", O_RDONLY);
    char buffer[100];
    read(fd, buffer, sizeof(buffer));
    printf("Received: %s\n", buffer);
    close(fd);
    return 0;
}