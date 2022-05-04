#include <stdio.h>
#include <stdlib.h>
#include <time.h>
const int TAM = 10000;

void BubbleSort(int vet[], int TAM){
    int i, j, aux;
    for(i=0;i<TAM;i++)
    {
        for(j=0;j<TAM;j++)
        {
            if(vet[i]<vet[j])
            {
                aux=vet[i];
                vet[i]=vet[j];
                vet[j]=aux;
            }
        }
    }
}

void printa(int vet[], int TAM){
    int i;
    for(i=0;i<TAM;i++)
    {
        printf("%d\t",vet[i]);
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
    BubbleSort(vet, TAM);

    Tf = clock();
    double Tempo=(Tf - Ti)*1000/CLOCKS_PER_SEC;

    //printa(vet, TAM);
    printf("\n\nTempo gasto: %g ms.", Tempo);

    return 0;
}
