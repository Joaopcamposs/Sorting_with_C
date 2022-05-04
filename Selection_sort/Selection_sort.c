#include <stdio.h>
#include <stdlib.h>
#include <time.h>
const int TAM = 10000;

void selection_sort (int vet[],int TAM){
  int i, j, min, aux;

  for (i = 0; i < (TAM - 1); i++){
    /* O minimo � o primeiro n�mero n�o ordenado ainda */
    min = i;

    for (j = i+1; j < TAM; j++){
      /* Caso tenha algum numero menor ele faz a troca do minimo*/
      if (vet[j] < vet[min]){
       	min = j;
      }
    }

    /* Se o minimo for diferente do primeiro numero n�o ordenado ele faz a troca para ordena-los*/
    if (i != min){
      aux = vet[i];
      vet[i] = vet[min];
      vet[min] = aux;
    }
  }
}

void printa (int vet[], int TAM){
    int i;
    for (i = 0; i < TAM; i++)
    {
      printf ("%d ",vet[i]);
    }
    printf ("\n");
}


int main (){
    int  vet[TAM];

    //preenchendo vetor
    for(int i=0;i<TAM;i++){
      vet[i] = rand();
    }

    clock_t Ti, Tf;
    Ti = clock();

    //O codigo a ter seu tempo de execucao medido ficaria neste ponto.
    selection_sort (vet, TAM);

    Tf = clock();
    double Tempo=(Tf - Ti)*1000/CLOCKS_PER_SEC;

    //printa(vet, TAM);
    printf("\n\nTempo gasto: %g ms.", Tempo);
}
