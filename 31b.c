/*
============================================================================
Name : 31b.c
Author : Tathagata Talukdar
Description : Write a program to create a semaphore and initialize value to 
the semaphore.    
(b) create a counting semaphore.
Date: 12th October 2023
============================================================================
*/

#include <stdio.h>
#include <semaphore.h>
#include <unistd.h>

int main() {
    sem_t count_sem;

    sem_init(&count_sem, 0, 5);

    printf("Counting semaphore created and initialized.\n");

    sem_destroy(&count_sem);

    sleep(2);

    printf("Counting semaphore created and destroyed.\n");

    return 0;
}