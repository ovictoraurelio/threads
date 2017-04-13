/***
	*
	* @author victoraurelio.com
	* @since 13/04/17
	*
***/
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

// Another thread that will be called
void *threadHello(void *threadid){
    printf("Hello World!\n");
    pthread_exit(NULL);
}

// The main, is by default our first thread.
// Remember our program is a Process, that may contain a lot of threads.
int main (int argc, char *argv[]){
    pthread_t thread;

    if( pthread_create(&thread, NULL, threadHello, NULL)  ){
        printf("Something wrong! The system failed to creat our thread");
        exit(-1);
    }

    pthread_exit(NULL);
}