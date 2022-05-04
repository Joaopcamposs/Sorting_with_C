#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
const int TAM = 10000;


void printa (int vet[], int TAM){
    int i;

    for (i = 0; i < TAM; i++){
        printf ("%d ",vet[i]);
    }
    printf ("\n");
}

void trocar(int *a, int *b){
   int aux;
   aux=*a;
   *a=*b;
   *b=aux;
}

void heapear(int vet[], int n){
    int fim;
    fim = 1;

    while (fim < n){
        siftUp(vet, 0, fim);
        fim++;
    }
}

void heapSort(int vet[], int n){
    int fim=0;
    heapear(vet, n);
    fim = n-1;

    while (fim > 0){
        trocar(&vet[fim], &vet[0]);
        fim--;
        siftDown(vet, 0, fim);
    }
}

void siftDown(int vet[], int inicio, int fim){
    int raiz, filho, troca;
    raiz=inicio;
    
    while(raiz*2+1 <= fim){
        filho = raiz*2+1;
        troca = raiz;
        if(vet[troca] < vet[filho])
            troca = filho;
        if(filho+1 <= fim && vet[troca] < vet[filho+1])
            troca = filho+1;
        if(troca == raiz)
            return;
        else{
            trocar(&vet[raiz], &vet[troca]);
            raiz = troca;
        }
    }
}

void siftUp(int vet[], int inicio, int fim){
    int filho=0, pai=0;
    filho = fim;
    while (filho >= inicio){
    pai = floor((filho - 1) / 2);
    if (vet[pai] < vet[filho]){
        trocar(&vet[pai], &vet[filho]);
        filho = pai;
    }
    else
        return;
    }
}

int main(){
    int vet[TAM];
    //preenchendo vetor
    for(int i=0;i<TAM;i++){
        vet[i] = rand();
    }

    clock_t Ti, Tf;
    Ti = clock();

    //O codigo a ter seu tempo de execucao medido ficaria neste ponto.
    heapSort(vet, TAM);

    Tf = clock();
    double Tempo=(Tf - Ti)*1000/CLOCKS_PER_SEC;

    //printa(vet, TAM);
    printf("\n\nTempo gasto: %g ms.", Tempo);

    return 0;
}
