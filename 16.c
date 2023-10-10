/*
============================================================================
Name : 16.c
Author : Tathagata Talukdar
Description : Write a program to send data from parent to child process and
and vice versa using two way communication.
Date: 9th October 2023
============================================================================
*/

#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<string.h>
#include<sys/types.h>
#include <sys/wait.h>

int main() {
    int ptc[2], ctp[2];
    pipe(ptc);
    pipe(ctp);
    pid_t pid = fork();
    if (!pid) {
        //child
        close(ptc[1]);
        close(ctp[0]);
        char buffer[1024];
        int n = read(ptc[0], buffer, sizeof(buffer));
        if (n > 0) {
            printf("Child received: %s\n", buffer);
        }
// ------------------------------------------------------------------------
        buffer[0]='\0';
        printf("Parent msg: ");
        fgets(buffer, sizeof(buffer), stdin);
        n=write(ctp[1], buffer, strlen(buffer));
        close(ptc[0]);
        close(ctp[1]);
        exit(EXIT_SUCCESS);
    } else {
        //parent
        close(ptc[0]);
        close(ctp[1]);
        char buffer[1024];
        printf("Child msg: ");
        fgets(buffer, sizeof(buffer), stdin);
        int n = write(ptc[1], buffer, strlen(buffer));
// ------------------------------------------------------------------------
        buffer[0]='\0';
        n=read(ctp[0], buffer, sizeof(buffer));
        if (n > 0) {
            printf("Parent received: %s\n", buffer);
        }

        close(ptc[1]);
        wait(NULL);
    }

    return 0;
}

// #include <stdio.h>
// #include <unistd.h>
// #include <stdlib.h>
// #include <string.h>
// #include <sys/types.h>
// #include <sys/wait.h>

// int main(){
//     int cpipe[2], ppipe[2];
//     pipe(ppipe);
//     pipe(cpipe);
//     pid_t pid = fork();
//     if(pid == 0){

//         close(ppipe[1]);
//         close(cpipe[0]);
//         char buffer[100];
//         if(read(ppipe[0], buffer, sizeof(buffer))){
//             printf("Child process received: %s\n", buffer);
//         }

//         buffer[0] = '\0';
//         printf("Parent sent: ");
//         read(0, buffer, sizeof(buffer));
//         write(cpipe[1], buffer, sizeof(buffer));
//         close(ppipe[0]);
//         close(cpipe[1]);
//         return EXIT_SUCCESS;
//     }
    
//     else {
//         close(ppipe[0]);
//         close(cpipe[1]);
//         char buffer[100];
//         printf("Child sent: ");
//         read(0, buffer, sizeof(buffer));
//         write(ppipe[1], buffer, sizeof(buffer));

//         buffer[0] = '\0';
//         if(read(cpipe[0], buffer, sizeof(buffer))){
//             printf("Parent received: %s\n", buffer);
//         }

//         close(ppipe[1]);
//         wait(NULL);
//     }
//     return EXIT_SUCCESS;
// }