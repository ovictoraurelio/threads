/***
	*
	* @author victoraurelio.com
	* @since 13/04/17
	*
***/
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

// Outra thread criada
void *threadDOIS(void *threadid){
    printf("Olá, mundo!\n");
    pthread_exit(NULL);// Saindo da thread  threadDOIS
}

// O Main, naturalmente é uma thread
int main (int argc, char *argv[]){
    pthread_t thread;

    if( pthread_create(&thread, NULL, threadDOIS, NULL)  ){
        printf("ERRO! O sistema não pode criar a thread");
        exit(-1);
    }

    pthread_exit(NULL);// Saindo da thread main
}