/*
============================================================================
Name : 32a.c
Author : Tathagata Talukdar
Description : Write a program to implement semaphore to protect any critical 
section.    
(a) rewrite the ticket number creation program using semaphore.
Date: 12th October 2023
============================================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <semaphore.h>

int ticket_counter = 1;
sem_t mutex;

void* sellTicket(void* arg) {

    while (1) {
        sem_wait(&mutex); // Wait for the semaphore
        if (ticket_counter <= 20) {
            ticket_counter++;
            printf("Ticket %d sold.\n", ticket_counter);
        }
        sem_post(&mutex); // Release the semaphore

        if (ticket_counter > 20) break;
    }

    pthread_exit(NULL);
}

int main() {
    pthread_t seller1, seller2;

    sem_init(&mutex, 0, 1);

    pthread_create(&seller1, NULL, sellTicket, NULL);
    pthread_create(&seller2, NULL, sellTicket, NULL);

    pthread_join(seller1, NULL);
    pthread_join(seller2, NULL);

    sem_destroy(&mutex);

    return 0;
}