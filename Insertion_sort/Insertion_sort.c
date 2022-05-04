#include <stdio.h>
#include <stdlib.h>
#include <time.h>
const int TAM = 10000;


void insertion(int vet[], int TAM){
    int aux,menor,j,i;
    for (i=0; i<TAM;i++){
        j=i;
        while(j>0 &&vet[j-1]>vet[j]){
            aux=vet[j];
            vet[j]=vet[j-1];
            vet[j-1]=aux;
            j--;
        }
    }
}

void printa(int vet[], int TAM){
    int i;
    for (i = 0; i < TAM; i++){
        printf ("%d ",vet[i]);
    }
    printf ("\n");
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
    insertion(vet, TAM);

    Tf = clock();
    double Tempo=(Tf - Ti)*1000/CLOCKS_PER_SEC;

    //printa(vet, TAM);
    printf("\n\nTempo gasto: %g ms.", Tempo);
}
