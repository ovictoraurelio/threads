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

void *threadBeautiful(void *arg){
    threadData *data = (threadData*) arg;

    printf("Hi I'm a thread, my ID is %d and i have to say:  %s \n", data->id, data->message);
    pthread_exit(NULL);
}
/***
  ** Thread Join is useful to make a thread wait for another thread finished to continue or start your execution.
  ** So you see, that our code below, works as sequence normal code.
***/
int main (int argc, char *argv[]){
    pthread_t thread[THREADS_COUNT];
    threadData data[THREADS_COUNT];

    for(int i=0; i<THREADS_COUNT; i++){
        //threads parameters
        strcpy(data[i].message, "Why you so serious?");
        data[i].id = i;
        printf("At main building the thread: %d\n", i);
        //call thread
        if( pthread_create(&thread[i], NULL,  threadBeautiful, (void*) &data[i])  ){
            printf("Something wrong! The system failed to creat our thread");
            exit(-1);
        }
        pthread_join(thread[i], NULL);
        printf("Thread %d has come back\n",i);
    }

    pthread_exit(NULL);
}