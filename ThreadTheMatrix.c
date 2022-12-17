#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <math.h>
#include <pthread.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <sys/wait.h>
#include <pthread.h>
#include <unistd.h>
#include <ctype.h>
#include <fcntl.h>
#include <sys/stat.h>

#define MAX_TAMANHO 8   //tamanho maximo da matriz
#define MAX_THREAD MAX_TAMANHO //numero de threads varia com o tamanho da matriz

// Código desenvolvido na disciplina de Sistemas Operacionais (Informática Biomédica - 2021), como exemplificação prática para o relatório II.
// Alunos: Andréia M. Ferreira e João V. Fernandes

int matrizA[MAX_TAMANHO][MAX_TAMANHO];
int matrizB[MAX_TAMANHO][MAX_TAMANHO];
int matrizC[MAX_TAMANHO][MAX_TAMANHO];
int step_i = 0;

void* multiplicacao(void* arg)
{
    int i, j, k;

    // Each thread computes 1/4th of matrix multiplication
    for (i = 0; i < MAX_THREAD; i++)
        for (j = 0; j < MAX_THREAD; j++)
            for (k = 0; k < MAX_THREAD; k++)
                matrizC[i][j] += matrizA[i][k] * matrizB[k][j];
}

// Driver Code
int main (int argc, char** argv)
{
    pthread_t threads[MAX_THREAD];
	int *pstatus;
    int i, j;

    //Povoando a matriz A
  //  printf("Digite valores para os elementos da matriz A");
//CANCELADO pois matriz longa
    for (i = 0; i < MAX_TAMANHO; i++) {
        for (j = 0; j < MAX_TAMANHO; j++) {
            matrizA[i][j] = rand() % (200 + 1 - 0) + 0; //numeros gerados vao de 0 a 200
        }
    }

    //Mostrando a matriz A
    printf("\n--------------MATRIZ A--------------\n");
     for (i = 0; i < MAX_TAMANHO; i++) {
        for (j = 0; j < MAX_TAMANHO; j++) {
            printf("| %d", matrizA[i][j]);
        }
        printf("| \n");
    }

    //Povoando a matriz B
    //printf("Digite valores para os elementos da matriz B");

    for (i = 0; i < MAX_TAMANHO; i++) {
        for (j = 0; j < MAX_TAMANHO; j++) {
            //printf("\nElemento[%d][%d] = \n", i, j);
            //scanf("%d", &matrizB[i][j]);
            matrizB[i][j] = rand() % (200 + 1 - 0) + 0;
        }
    }

    //Mostrando a matriz B
    printf("\n--------------MATRIZ b--------------\n");
     for (i = 0; i < MAX_TAMANHO; i++) {
        for (j = 0; j < MAX_TAMANHO; j++) {
            printf("| %d", matrizB[i][j]);
        }
        printf("| \n");
        printf("_");
    }


    // Cria as threads
    	//pthread_create(&thrdID, NULL, (void*)printMsg, argv[1]);
    	//printf("\n---------------THREADS CRIADAS-------------\n");
    for (int i = 0; i < MAX_THREAD; i++) {
       // int* p;
        pthread_create(&threads[i], NULL, (void*)multiplicacao, argv[1]);
       // printf("Thread numero %d, ID: %ld\n", i, threads[i]);
        pthread_join(threads[i], (void *)&pstatus);

    }

    // Espera a criação de todas as threads
    for (int i = 0; i < MAX_THREAD; i++){
        pthread_join(threads[i], NULL);
      //  printf("Thread %ld finalizou com status: %d\n",threads[i],*pstatus);
}
    // Rsultado final
    printf("\n--------RESULTADO FINAL-----------\n");
      for (i = 0; i < MAX_TAMANHO; i++) {
        for (j = 0; j < MAX_TAMANHO; j++) {
            printf("%d |", matrizC[i][j]);
        }
        printf("\n");
    }

    return 0;
}
