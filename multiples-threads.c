/***
	*
	* @author victoraurelio.com
	* @since 13/04/17
	*
***/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>
#define THREADS_COUNT 100

typedef struct threadData {
    int id;
    char message[20];
} threadData;

// Another thread that will be called
void *threadPARAMETER(void *arg){
    threadData *data = (threadData*) arg;

    printf("Hi I'm a thread, my ID is %d and i have to say:  %s \n", data->id, data->message);
    pthread_exit(NULL);
}

// The main, is by default our first thread.
// Remember our program is a Process, that may contain a lot of threads.
int main (int argc, char *argv[]){
    pthread_t thread[THREADS_COUNT];
    threadData data[THREADS_COUNT];

    for(int i=0; i<THREADS_COUNT; i++){
        //threads parameters
        data[i].id = i;
        strcpy(data[i].message, "Be Happy!");
        printf("At main building the thread: %d\n", i);
        //call thread
        if( pthread_create(&thread[i], NULL,  threadPARAMETER, (void*) &data[i])  ){
            printf("Something wrong! The system failed to creat our thread");
            exit(-1);
        }
    }

    pthread_exit(NULL);
}