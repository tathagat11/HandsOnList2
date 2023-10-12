/*
============================================================================
Name : 31a.c
Author : Tathagata Talukdar
Description : Write a program to create a semaphore and initialize value to 
the semaphore.    
(a) create a binary semaphore.
Date: 12th October 2023
============================================================================
*/

#include <stdio.h>
#include <semaphore.h>
#include <unistd.h>


int main() {
    sem_t bin_sem;
    sem_init(&bin_sem, 0, 1);
    printf("Binary semaphore created.\n");
    sleep(2);
    sem_destroy(&bin_sem);
    printf("Binary semaphore destroyed.\n");
    return 0;
}