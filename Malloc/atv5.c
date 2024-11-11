#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void preencherVetor(int *v, int n){
  for (int i = 0; i < n; i++)
  {
    *(v+i) = rand() % 100;
  }
}

void mostrarVetor(int *v, int n){
  for (int i = 0; i < n; i++)
  {
    printf("%d\t",*(v+i));
  }
}

int primo(int num) {
    if (num <= 1) return 0; 
    for (int i = 2; i * i <= num; i++) {
        if (num % i == 0) return 0; 
    }
    return 1; 
}

void acharNumPrimo(int *v, int n){

  int contador =0;

  printf("\nA quantidade de numeros primos e de ");
  
  for (int i = 0; i < n; i++)
  {
    if (primo(*(v+i)))
    {
      contador++;
    }
  }
  printf("%d",contador);
}

int main(){

  int n, *v1;
  srand(time(0));

  printf("Digite o tamanho do seu vetor\n");
  scanf("%d",&n);

  v1 = (int *)malloc(n*4);

  if (!v1)
  {
    printf("error");
    exit(-1);
  }

  preencherVetor(v1,n);
  mostrarVetor(v1,n);
  
  acharNumPrimo(v1,n);


  return 0;
}