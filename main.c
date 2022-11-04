#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

int thread_count; //Variable global: accesible a todos los hilos

void *Hello(void* rank); //Funciòn del hilo

int main(int argc, char* argv[]){
    long thread; //long en caso de sistemas de 64 bits
    pthread_t* thread_handles;

    thread_count=strtol(argv[1], NULL, 10); //Obtiene el número de hilos de la línea de comandos

    thread_handles= malloc(thread_count*sizeof(pthread_t));

    for(thread=0;thread<thread_count; thread++)
        pthread_join(thread_handles[thread], NULL);

    free(thread_handles);
    return 0;


}//main

void *Hello(void* rank){
    long my_rank= (long) rank; //long en caso de sistemas de 64 bits
    printf("Saludos del hilo %ld de %d\n", my_rank, thread_count);
    return NULL;
}//Hello

