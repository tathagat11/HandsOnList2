/*
============================================================================
Name : 22.c
Author : Tathagata Talukdar
Description : Write a program to wait 10 sec for a write into fifo using 
select.
Date: 12th October 2023
============================================================================
*/

#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<fcntl.h>
#include<sys/types.h>
#include <sys/time.h>

void main(void) {
    fd_set fds;
    struct timeval tv;
    int value;
    FD_ZERO(&fds);
    FD_SET(0, &fds);
    tv.tv_sec = 10;
    tv.tv_usec = 0;
    value = select(1, &fds, NULL, NULL, &tv);
    if (value == -1) {
        perror("select()");
        exit(EXIT_FAILURE);
    } else if (value) {
        printf("Received data within 10 seconds\n");
    } else {
        printf("No data received within 10 seconds\n");
        exit(EXIT_SUCCESS);
    }
}