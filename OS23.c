
#include<stdio.h>
#include<semaphore.h>
#include<pthread.h>
#include<unistd.h>

sem_t mutexA, mutexB;

void *func_A(void* arg)
{
char* msg=(char*)arg;
sem_wait(&mutexA);
printf("INTO FUNCTION A BY THREAD %s\n",msg);
sleep(3);
printf("FINISHED FUNCTION A BY THREAD %s\n",msg);
sem_post(&mutexA);
}

void *func_B(void* arg)
{
char* msg=(char*)arg;
sem_wait(&mutexB);
printf("INTO FUNCTION B BY THREAD %s\n",msg);
sleep(3);
printf("FINISHED FUNCTION B BY THREAD %s\n",msg);
sem_post(&mutexB);
}

int main()
{
pthread_t t1,t2,t3,t4;
char* msg1="THREAD 1";
char* msg2="THREAD 2";
char* msg3="THREAD 3";
char* msg4="THREAD 4";

sem_init(&mutexA,0,1);
sem_init(&mutexB,0,1);

pthread_create(&t1,NULL,func_A,msg1);
pthread_create(&t2,NULL,func_A,msg2);
pthread_create(&t3,NULL,func_B,msg3);
pthread_create(&t4,NULL,func_B,msg4);

pthread_join(t1,NULL);
pthread_join(t2,NULL);
pthread_join(t3,NULL);
pthread_join(t4,NULL);

}


