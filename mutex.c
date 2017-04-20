#include <pthread.h>
#include <stdio.h>

#define LIMIT 10000

int counterUsedWithMutex=0, counterUsedWithoutMutex=0;

pthread_mutex_t mutexThreadsExample = PTHREAD_MUTEX_INITIALIZER;

void *threadA(void *threadid){
    int i=10000000;
    while(i--){
        pthread_mutex_lock(&mutexThreadsExample);
        //printf("THREAD A %d\n", counter++);
        counterUsedWithMutex++;
        pthread_mutex_unlock(&mutexThreadsExample);
    }
}
void *threadB(void *threadid){
    int i = 10000000;
    while(i--){
        pthread_mutex_lock(&mutexThreadsExample);
        //printf("THREAD B %d\n", counter--);
        counterUsedWithMutex--;
        pthread_mutex_unlock(&mutexThreadsExample);
    }
}

void *threadAWithoutMutex(void *threadid){
    int i = 10000000;
    while(i--) counterUsedWithoutMutex++;
}
void *threadBWithoutMutex(void *threadid){
    int i = 10000000;
    while(i--) counterUsedWithoutMutex--;
}


int main (int argc, char *argv[]){
    pthread_t t1, t2,t3,t4;
    pthread_create(&t1, NULL, threadA, NULL);
    pthread_create(&t2, NULL, threadB, NULL);
    pthread_create(&t3, NULL, threadAWithoutMutex, NULL);
    pthread_create(&t4, NULL, threadAWithoutMutex, NULL);

    pthread_join(t1, NULL);
    pthread_join(t2, NULL);
    pthread_join(t3, NULL);
    pthread_join(t4, NULL);

    printf("Finished! Value of counter, working with mutex: %d\n", counterUsedWithMutex);
    printf("See that without mutex you have some troubles on racecondition for resource counter!\nValue of counter without mutex: %d\n", counterUsedWithoutMutex);
    pthread_exit(NULL);
}