/*
============================================================================
Name : 21.c
Author : Tathagata Talukdar
Description : Write a program so both can communicate using fifo (two way).
Date: 12th October 2023
============================================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>

int main() {
    int fd;
    char buffer[1024];

    mkfifo("fifo21", 0666);

    while (1) {
        fd = open("fifo21", O_RDWR);

        if (fd == -1) {
            perror("open");
            exit(EXIT_FAILURE);
        }
        printf("Enter a message to send (or type 'exit' to quit): ");
        fgets(buffer, sizeof(buffer), stdin);

        if (strcmp(buffer, "exit") == 0) {
            close(fd);
            exit(EXIT_SUCCESS);
        }

        write(fd, buffer, strlen(buffer) + 1);
        
        read(fd,buffer,strlen(buffer));
        printf("Reader's response : %s\n",buffer);
        close(fd);
    }

    return 0;
}