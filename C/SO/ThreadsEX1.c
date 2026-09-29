#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include "timer.h"


#define NTHREADS 10


void *PrintHello(void *args){
   int *idThread = (int*) args;
   printf("Ola Mundo (pt-br)%d\n", *idThread);
   free(args);
   pthread_exit(NULL);


}


int main(){
   pthread_t tid_sistema[NTHREADS];
   int *args;
   for (int i = 0; i < NTHREADS; i++){
       //printf("oi eu nasci (%d)\n", i+1);
       args = malloc(sizeof(int));
       *args = i+1;
       if (pthread_create(&tid_sistema[i], NULL, PrintHello, (void*) args)){
           printf("--Erro: pthread_create()\n");
           exit(-1);
       }
   }
   for (int i = 0; i < NTHREADS; i++){
       //printf("oi eu morri (%d)\n", i+1);
       if (pthread_join(tid_sistema[i], NULL)){
           printf("--ERRO: phtread_join()\n");
           exit(-1);
       }
   }
}
