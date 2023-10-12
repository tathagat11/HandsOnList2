/*
============================================================================
Name : 27.c
Author : Tathagata Talukdar
Description : Write a program to receive messages from the message queue.    
a. with 0 as a flag    b. with IPC_NOWAIT as a flag
Date: 12th October 2023
============================================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <string.h>
#include <sys/ipc.h>
#include <sys/msg.h>

#define MAX 10
struct msg_buffer {
    long msg_type;
    char msg_text[100];
}message;

int main() {

    key_t key = ftok("progfile", 65);

    int message_ID = msgget(key, 0666 | IPC_CREAT);
    
    strcpy(message.msg_text, "0");
    message.msg_type = 1;

    msgsnd(message_ID, &message, sizeof(message), 0);


    msgrcv(message_ID, &message, sizeof(message), 1, 0);
    printf("Received message (0 flag): %s\n", message.msg_text);

    strcpy(message.msg_text, "IPC_NOWAIT");
    message.msg_type = 1;

    msgsnd(message_ID, &message, sizeof(message), 0);

    if (msgrcv(message_ID, &message, sizeof(message), 1, IPC_NOWAIT) == -1) {
        perror("msgrcv (IPC_NOWAIT)");
        exit(EXIT_FAILURE);
    } else {
        printf("Received message (IPC_NOWAIT flag): %s\n", message.msg_text);
    }

    msgctl(message_ID, IPC_RMID, NULL);

    return 0;
}