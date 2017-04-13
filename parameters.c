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

typedef struct p {
    int age;
    char name[20];
} person;

// Another thread that will be called
void *threadPARAMETER(void *arg){
    person *me = (person*) arg;

    printf("Hi! My name is %s and I have %d years old\n", me->name, me->age);
    pthread_exit(NULL);
}

// The main, is by default our first thread.
// Remember our program is a Process, that may contain a lot of threads.
int main (int argc, char *argv[]){
    pthread_t thread;
    person me;
    me.age = 19;
    strcpy(me.name, "Victor Aurelio");

    if( pthread_create(&thread, NULL, threadPARAMETER, (void*) &me)  ){
        printf("Something wrong! The system failed to creat our thread");
        exit(-1);
    }

    pthread_exit(NULL);
}