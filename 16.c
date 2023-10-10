/*
============================================================================
Name : 16.c
Author : Tathagata Talukdar
Description : Write a program to send data from parent to child process and
and vice versa using two way communication.
Date: 9th October 2023
============================================================================
*/

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(){
    int ctop[2], ptoc[2];
    pipe(ptoc);
    pipe(ctop);
    pid_t pid = fork();
    if(pid == 0){
        close(ptoc[1]);
        close(ctop[0]);
        char buffer[1024];
        if(read(ptoc[0], buffer, sizeof(buffer))){
            printf("Child received: %s\n", buffer);
        }

        buffer[0] = '\0';
        printf("Child sent: ");
        fgets(buffer, sizeof(buffer), stdin);
        write(ctop[1], buffer, sizeof(buffer));
        close(ptoc[0]);
        close(ctop[1]);
        return EXIT_SUCCESS;
    }
    
    else {
        close(ptoc[0]);
        close(ctop[1]);
        char buffer[1024];
        printf("Parent sent: ");
        fgets(buffer, sizeof(buffer), stdin);
        write(ptoc[1], buffer, sizeof(buffer));

        buffer[0] = '\0';
        if(read(ctop[0], buffer, sizeof(buffer))){
            printf("Parent received: %s\n", buffer);
        }

        close(ptoc[1]);
        wait(NULL);
    }
    return EXIT_SUCCESS;
}