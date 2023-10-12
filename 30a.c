/*
============================================================================
Name : 30a.c
Author : Tathagata Talukdar
Description : Write a program to create a shared memory. 
(a) write some data to the shared memory.
Date: 12th October 2023
============================================================================
*/

#include<stdio.h>
#include<unistd.h>
#include<sys/shm.h>

void main() {
    int key=ftok("file", 97);
    int sh_mem_id = shmget(key, 1024, IPC_CREAT | 0744);
    char* data=(char *)shmat(sh_mem_id, NULL, 0);
    printf("Enter input : ");
    scanf("%s", data);
}