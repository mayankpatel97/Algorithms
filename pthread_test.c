#include <stdio.h> 
#include <stdlib.h> 
#include <unistd.h>  //Header file for sleep(). man 3 sleep for details. 
#include <pthread.h> 
  
// A normal C function that is executed as a thread  
// when its name is specified in pthread_create() 

pthread_mutex_t lock;
int counter;

void *thread1_task(void *vargp) 
{ 
    while(1)
    {
        sleep(0.1); 
        pthread_mutex_lock(&lock);

        printf("Printing from thread1 task. %d\n", ++counter); 
        pthread_mutex_unlock(&lock);
    }
    return NULL; 
} 

void *thread2_task(void *vargp) 
{ 
    while(1)
    {
        sleep(0.1); 
        pthread_mutex_lock(&lock);
        printf("Printing from thread2 task. %d\n", ++counter); 
        pthread_mutex_unlock(&lock);
    }
    return NULL; 
} 
   
int main(void) 
{ 
    pthread_t thread1,thread2; 
    printf("Before Thread\n"); 
    pthread_create(&thread1, NULL, thread1_task, NULL); 
    pthread_create(&thread2, NULL, thread2_task, NULL); 
    pthread_join(thread1, NULL); 
    pthread_join(thread2, NULL); 
    printf("After Thread\n"); 
    exit(0); 
}
