/*
============================================================================
Name : 30c.c
Author : Tathagata Talukdar
Description : Write a program to create a shared memory. 
(c) detach the shared memory.
Date: 12th October 2023
============================================================================
*/

#include<stdio.h>
#include<unistd.h>
#include<sys/shm.h>

void main() {
    key_t key = ftok("file", 97);
    int shmid = shmget(key, 1024, 0);
    char *buffer = (char *)shmat(shmid, (void *)0, 0);
    printf("Data : %s\n", buffer);
    shmdt(buffer);
    printf("Shared memory detached...\n");
}

