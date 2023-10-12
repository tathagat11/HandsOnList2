/*
============================================================================
Name : 30b.c
Author : Tathagata Talukdar
Description : Write a program to create a shared memory. 
(b) attach with O_RDONLY and check whether you are able to overwrite.
Date: 12th October 2023
============================================================================
*/

#include<stdio.h>
#include<unistd.h>
#include<sys/shm.h>

void main() {
    int key = ftok("file", 97);
    int sh_mem_id = shmget(key, 1024, 0);
    char* data=(char *)shmat(sh_mem_id, NULL, SHM_RDONLY);
    printf("Shared memory input : %s\n", data);
}