#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include "timer.h"
#include <unistd.h> // para usar a funcao sysconf
#include <windows.h> // para achar o num de CPUs


int nThreads, tamVet;
int *vet, *somaVet;


void *somaVetor(void *arg){
    int i, soma = 0;
    unsigned int j, nop = 0; // unsigned so permite numeros positivos
    int *idThread = (int*) arg;

    for (i = *idThread; i<tamVet; i += nThreads){
        soma += vet[i];
        for (j=0; j<1000000; j++) nop; // so pra gastar tempo do sistema
    }

   somaVet[*idThread] = soma;
   free(arg);
   pthread_exit(NULL);
}


int main(){
    pthread_t *tid_sistema;
    int *args;
    int t; //contador
    double inicio, fim, delta1, delta2, delta3;
    

    //descobre o n° de processadores
    //int numCPU = sysconf(_SC_NPROCESSORS_ONLN); <- PARA LINUX

    SYSTEM_INFO sysinfo; // <- PARA WINDOWS
    GetSystemInfo(&sysinfo);
    int numCPU = sysinfo.dwNumberOfProcessors;
    printf("Numero de processadores: %d\n", numCPU);

    printf("Digite o tamanho do vetor: \n");
    scanf("%d", &tamVet);
    printf("Digite o numero de threads: \n");
    scanf("%d", &nThreads);

    GET_TIME(inicio);

    tid_sistema = (pthread_t*) malloc(sizeof(pthread_t) * nThreads);
    somaVet = malloc(sizeof(int) * nThreads); // cria o vetor para cada thread botar a soma final
    vet = malloc(sizeof(int) * tamVet);

    for (t=0; t<tamVet; t++){
        vet[t] = 1; // vetor unitario, a soma vai ser equivalente ao tamanho do vetor
    }

    GET_TIME(fim);

    delta1 = fim - inicio; // descobre o tempo gasto inicializando e alocando vetores

    GET_TIME(inicio);

    for (int i = 0; i < nThreads; i++){
        //printf("oi eu nasci (%d)\n", i+1);
        args = malloc(sizeof(int));
        *args = i;
        if (pthread_create(&tid_sistema[i], NULL, somaVetor, (void*) args)){
            printf("--Erro: pthread_create()\n");
            exit(-1);
        }
    }
    for (int i = 0; i < nThreads; i++){
        //printf("oi eu morri (%d)\n", i+1);
        if (pthread_join(tid_sistema[i], NULL)){
            printf("--ERRO: phtread_join()\n");
            exit(-1);
        }
    }

    GET_TIME(fim);

    delta2 = fim - inicio; // descobre o tempo gasto criando as threads

    GET_TIME(inicio);

    int S = 0;
    for (t = 0; t<nThreads; t++){
        printf("%d ", somaVet[t]);
        S += somaVet[t];
    }
    printf("\n SOMA = %d \n", S);
    free(vet);
    free(somaVet);
    free(tid_sistema);

    GET_TIME(fim);

    delta3 = fim - inicio; // descobre o tempo para finalizar a soma

    printf("\nTempo inicial: %f ", delta1);
    printf("\nTempo da metade: %f ", delta2);
    printf("\nTempo parte final: %f ", delta3);
}
