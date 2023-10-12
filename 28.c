/*
============================================================================
Name : 28.c
Author : Tathagata Talukdar
Description : Write a program to change the exiting message queue permission. 
(use msqid_ds structure)
Date: 12th October 2023
============================================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>

struct message {
    long msg_type;
    char msg_text[100];
} message;

int main() {
    struct msqid_ds msq_info;

    key_t key = ftok("progfile", 65);

    int message_ID = msgget(key, 0666 | IPC_CREAT);

    msgctl(message_ID, IPC_STAT, &msq_info);

    printf("Current permissions: %o\n", msq_info.msg_perm.mode);

    msq_info.msg_perm.mode = 0644;

    msgctl(message_ID, IPC_SET, &msq_info);

    printf("Permissions changed to %o\n", msq_info.msg_perm.mode);

    msgctl(message_ID, IPC_RMID, NULL);

    return 0;
}