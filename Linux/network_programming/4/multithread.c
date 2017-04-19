#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

#define MAXTHREAD 2

void *func(void *data)
{
    long *ptr = (long *)data;
    int index = (int)ptr[0];
    long *count = (long *)ptr[1];
    int tmp;
    
    pthread_t thread_id = pthread_self();
    
    while(1){
        printf("[%lu] index = %d count = %ld\n", thread_id, index, *count);
        (*count)++;
        sleep(1 + index);
    }
}

int main()
{
    pthread_t thread_id[MAXTHREAD];
    long i = 0;
    long count = 0;
    long *vars[2];
    
    for(i = 0; i < MAXTHREAD; i++){
        vars[0] = (long *)i;
        vars[1] = &count;
        pthread_create(&thread_id[i], NULL, func, (void *)vars);
        usleep(5000);
        
    }

    while(1){
        printf("Main thread count = %ld\n", count);
        sleep(2);
    }
    
    for(i = 0; i < MAXTHREAD; i++){
        pthread_join(thread_id[i], NULL);
    }
    
    return 0;
}