/*
============================================================================
Name : 26.c
Author : Tathagata Talukdar
Description : Write a program to send messages to the message queue. 
Check $ipcs -q.
Date: 12th October 2023
============================================================================
*/

#include<stdio.h>
#include<unistd.h>
#include<sys/ipc.h>
#include<sys/msg.h>

struct message {
    long msg_type;
    char msg_text[100];
}message1;

void main(void) {
    key_t key = ftok(".", 97);
    int message_ID  = msgget(key, 0666 | IPC_CREAT);
    message1.msg_type = 1;
    printf("Enter Data : ");
    fgets(message1.msg_text, 10, stdin);
    msgsnd(message_ID, &message1, sizeof(message1), 0);
    printf("Data sent to the message queue : %s \n", message1.msg_text);
    execlp("ipcs", "ipcs", "-q", NULL);
}