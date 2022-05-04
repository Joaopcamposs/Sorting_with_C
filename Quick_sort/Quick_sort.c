#include <stdio.h>
#include <stdlib.h>
#include <time.h>
const int TAM = 10000;


void printa (int vet[], int TAM){
    int i;

    for (i = 0; i < TAM; i++){
        printf ("%d ",vet[i]);
    }
    printf ("\n\n");
}

void troca(int *a, int *b){
   int aux;
   aux=*a;
   *a=*b;
   *b=aux;
}

int particiona(int vet[], int ini, int fim){
    int i, j;
    int p = vet[fim];
    i = ini;
    for(j=ini;j<=(fim-1);j++){
        if(vet[j] <= p){
            troca(&vet[i], &vet[j]);
            i++;
        }
    }
    troca(&vet[i], &vet[j]);
    return i;
}

void quicksort(int vet[], int ini, int fim){
    if(ini < fim){
        int p = particiona(vet, ini, fim);
        quicksort(vet, ini, p-1);
        quicksort(vet, p+1, fim);
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
    quicksort(vet, 0, TAM-1);

    Tf = clock();
    double Tempo=(Tf - Ti)*1000/CLOCKS_PER_SEC;

    //printa(vet, TAM);
    printf("\n\nTempo gasto: %g ms.", Tempo);

    return 0;
}
