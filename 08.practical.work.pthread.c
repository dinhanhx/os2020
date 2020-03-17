// gcc 08.practical.work.pthread.c -o 08.practical.work.pthread.o -lpthread

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

void *printPrim(void *v_value)
{
  int i,fact,j;
  for(i=1; i<=1000000; i++)
  {
    fact=0;
    for(j=1; j<=1000000; j++)
    {
      if(i%j==0) fact++;
    }
      if(fact==2) printf("(%d) " ,i);
  }
}

void *printFibo(void *v_value)
{
  int t1 = 0, t2 = 1, nextTerm = 0;
  printf("[%d] ", t1);
  printf("[%d] ", t2);
  nextTerm = t1 + t2;
  while (nextTerm <= 1000000)
  {
    printf("[%d] ", nextTerm);
    t1 = t2;
    t2 = nextTerm;
    nextTerm = t1 + t2;
  }
}


int main(void)
{
  printf("(prim_num)\n[fibo_num]\n");
  pthread_t tid_1, tid_2;
  pthread_create(&tid_1, NULL, printPrim, NULL);
  pthread_join(tid_1, NULL);
  pthread_create(&tid_2, NULL, printFibo, NULL);
  pthread_join(tid_2, NULL);
  return 0;
}
