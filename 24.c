/*
============================================================================
Name : 24.c
Author : Tathagata Talukdar
Description : Write a program to create a message queue and print the key
and message queue id. 
Date: 12th October 2023
============================================================================
*/

#include<stdio.h>
#include<unistd.h>
#include<sys/ipc.h>
#include<sys/msg.h>
#include<sys/types.h>

void main(void) {
    key_t key = ftok(".", 97);
    int message_QID = msgget(key, IPC_CREAT | 0744);
    printf("Key = %d\nMessage queue id = %d\n", key, message_QID);
}