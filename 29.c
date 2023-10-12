/*
============================================================================
Name : 29.c
Author : Tathagata Talukdar
Description : Write a program to remove the message queue.
Date: 12th October 2023
============================================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>

int main() {
    key_t key = ftok("progfile", 65);
    int message_ID = msgget(key, 0666 | IPC_CREAT);

    printf("Message queue id = %d\n", message_ID);

    if (msgctl(message_ID, IPC_RMID, NULL) == -1) {
        perror("msgctl");
        exit(EXIT_FAILURE);
    }
    printf("Message queue removed.\n");
    return 0;
}