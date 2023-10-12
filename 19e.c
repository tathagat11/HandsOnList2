/*
============================================================================
Name : 19e.c
Author : Tathagata Talukdar
Description : Create a FIFO file using (e) mkfifo function.
Date: 12th October 2023
============================================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
    if (mkfifo("my_fifo_mkfifo", 0666) == -1) {
        perror("mkfifo");
        exit(EXIT_FAILURE);
    }

    printf("FIFO file my_fifo_mkfifo created.\n");
    return 0;
}
