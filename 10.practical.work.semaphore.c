// gcc 10.practical.work.semaphore.c -o 10.practical.work.semaphore.o -lpthread

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>

sem_t mutex;

void *printPrim(void *v_value)
{
  int i,fact,j;
  for(i=1; i<=1000; i++)
  {
    fact=0;
    for(j=1; j<=1000; j++)
    {
      if(i%j==0) fact++;
    }
      if(fact==2)
      {
        sem_wait(&mutex);
        printf("(%d) " ,i);
        sem_post(&mutex);
      }
  }
}

void *printFibo(void *v_value)
{

  int t1 = 0, t2 = 1, nextTerm = 0;
  printf("[%d] ", t1);
  printf("[%d] ", t2);
  nextTerm = t1 + t2;
  while (nextTerm <= 1000)
  {
    sem_wait(&mutex);
    printf("[%d] ", nextTerm);
    sem_post(&mutex);
    t1 = t2;
    t2 = nextTerm;
    nextTerm = t1 + t2;
  }

}


int main(void)
{
  sem_init(&mutex, 0, 1);
  printf("(prim_num)\n[fibo_num]\n");
  pthread_t tid_1, tid_2;
  pthread_create(&tid_1, NULL, printPrim, NULL);
  pthread_create(&tid_2, NULL, printFibo, NULL);
  pthread_join(tid_1, NULL);
  pthread_join(tid_2, NULL);
  sem_destroy(&mutex);
  printf("\n");
  return 0;
}
