#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void criaVetor(int *v, int tam){
  for (int i = 0; i < tam; i++)
  {
    *(v+i) = rand() % 10;
  }
}

void mostraVetor(int *v, int tam){
  for (int i = 0; i < tam; i++)
  {
    printf("%d\t",*(v+i));
  }
  
}

void produtoEscalar(int *v1, int *v2, int *n,int tam) {
    *n = 0;

    for (int i = 0; i < tam; i++) {
        *n += *(v1 + i) * *(v2 + i);
    }
}

void multiplica(int *v1, int*v2, int *n, int tam){
  for (int i = 0; i < tam; i++)
  {
    *(v1+i) = *(v2+i) * *(n);
  }
  
}

int main(){

  int tamanho, alpha;
  srand(time(0));

  printf("Qual tamanho dos vetores A e B?\n");
  scanf("%d",&tamanho);
  printf("Digite o valor de alpha:\n");
  scanf("%d",&alpha);

  int *A = (int *)malloc(tamanho*4);
  int *B = (int *)malloc(tamanho*4);

  if (!A || !B)
  {
    printf("error");
    exit(-1);
  }
  
  criaVetor(A,tamanho);
  criaVetor(B,tamanho);

  printf("Vetor A\n");
  mostraVetor(A,tamanho);
  printf("\nVetor B\n");
  mostraVetor(B,tamanho);

  printf("\nNovo valor para alpha apos produto escalar entre A e B");
  produtoEscalar(A,B,&alpha,tamanho);
  printf("\n%d",alpha);

  printf("\nNovo valor de A apos multiplicar alpha com B\n");
  multiplica(A,B,&alpha,tamanho);
  mostraVetor(A,tamanho);

  printf("\nNovo valor para alpha apos produto escalar entre A e A");
  produtoEscalar(A,A,&alpha,tamanho);
  printf("\n%d",alpha);

  printf("\nNovo valor de B apos multiplicar alpha com A\n");
  multiplica(B,A,&alpha,tamanho);
  mostraVetor(B,tamanho);

  return 0;
}