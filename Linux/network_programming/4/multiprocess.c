#include <stdio.h>
#include <stdlib.h>

#define MAXTHREAD 2

void *func(char *title, int cnt, void *data)
{
    int *count = (int *)data;
    int tmp;
    int thread_id = getpid();
    
    while(1){
        printf("%lu[%s %d] count = %d\n", (unsigned long)thread_id, title, cnt, *count);
        (*count)++;
        sleep(1 + cnt);
    }
}

int main()
{
    int thread_id[MAXTHREAD];
    int i = 0;
    int count = 0;
    
    for(i = 0; i < MAXTHREAD; i++){
        int pid = fork();
        
        if(pid == -1){
            perror("fork");
            exit(0);
        }
        
        else if(pid == 0){
            func("Child process", i, &count);
            usleep(5000);
        }
    }
    func("Main thread", 2, &count);
    return 0;
}