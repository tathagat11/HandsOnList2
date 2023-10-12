/*
============================================================================
Name : 32c_d.c
Author : Tathagata Talukdar
Description : Write a program to implement semaphore to protect any critical 
section.    
(c) protect shared memory from concurrent write access.
(d) remove the created semaphore.
Date: 12th October 2023
============================================================================
*/

#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>

#define NUM_RESOURCES 2

int resource[NUM_RESOURCES];
sem_t semaphore;

void* useResource(void* arg) {
    int resource_id = *(int*)arg;

    sem_wait(&semaphore); // Wait for a resource to be available

    // Access and use resource
    printf("Using resource %d.\n", resource_id);
    resource[resource_id] = 0;

    sem_post(&semaphore); // Release the resource

    pthread_exit(NULL);
}

int main() {
    pthread_t threads[NUM_RESOURCES];

    sem_init(&semaphore, 0, NUM_RESOURCES);

    for (int i = 0; i < NUM_RESOURCES; ++i) {
        resource[i] = 1; // Resource is initially available
        pthread_create(&threads[i], NULL, useResource, (void*)&i);
    }

    for (int i = 0; i < NUM_RESOURCES; ++i) {
        pthread_join(threads[i], NULL);
    }

    sem_destroy(&semaphore); 

    return 0;
}