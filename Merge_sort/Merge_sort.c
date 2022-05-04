#include <stdio.h>
#include <stdlib.h>
#include <time.h>
const int TAM = 10000;


void intercalar (int v[],int aux[],int ini1, int ini2,int fim2){
  int in1=ini1,in2=ini2,fim1=in2-1,au=0,i;
  
  while(in1<=fim1 && in2<=fim2){
    if (v[in1]<v[in2]){
      aux[au++] = v[in1++];
    } else{
      aux[au++] = v[in2++];
    }
  }
  
  while(in1<=fim1){
    aux[au++] = v[in1++];
  }
  
  while(in2<=fim2){
    aux[au++] = v[in2++];
  }

  for(i=0;i<au;i++){
    v[i+ini1]=aux[i];
  }
}

void mergeSort (int v[], int aux[],int esq, int dir){
  int meio;

  if(esq<dir){
    meio=(esq+dir)/2;
    mergeSort(v,aux,esq,meio);
    mergeSort(v,aux,meio+1,dir);
    intercalar(v,aux,esq,meio+1,dir);
  }
}

void printa (int vet[], int TAM){
  int i;

  for (i = 0; i < TAM; i++){
    printf ("%d ",vet[i]);
  }
  printf ("\n");
}

int main(){
  int vet[TAM],aux[TAM];
  //preenchendo vetor
  for(int i=0;i<TAM;i++){
    vet[i] = rand();
  }

  clock_t Ti, Tf;
  Ti = clock();

  //O codigo a ter seu tempo de execucao medido ficaria neste ponto.
  mergeSort(vet,aux,0,TAM-1);

  Tf = clock();
  double Tempo=(Tf - Ti)*1000/CLOCKS_PER_SEC;

  //printa(vet, TAM);
  printf("\n\nTempo gasto: %g ms.", Tempo);

  return 0;
}
