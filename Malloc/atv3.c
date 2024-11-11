#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void preencherMatriz(int *m, int l, int c){

  int d;

  for (int i = 0; i < l; i++)
  {
    for (int j = 0; j < c; j++)
    {
      d = i*c+j;
      *(m+d) = rand() % 10;
    }
  }
}

void mostraMatriz(int *m, int l, int c){
  int d;

  for (int i = 0; i < l; i++)
  {
    for (int j = 0; j < c; j++)
    {
      d = i*c+j;
      printf("%d\t",*(m+d));
    }
    printf("\n");
  }
}

void somaMatrizes(int *m1, int *m2, int l, int c){
  int d;

  for (int i = 0; i < l; i++)
  {
    for (int j = 0; j < c; j++)
    {
      d = i*c+j;
      *(m2+d) += *(m1+d);
    }
  }
}

int main(){

  int lin1,col1, *m1, *m2;
  srand(time(0));

  printf("Digite a quantidade de colunas na matriz 1\n");
  scanf("%d",&col1);
  printf("Digite a quantidade de linhas na matriz 1\n");
  scanf("%d",&lin1);
 

  m1 = (int *)malloc(col1*lin1*4);
  m2 = (int *)malloc(col1*lin1*4);


  preencherMatriz(m1,lin1,col1);
  preencherMatriz(m2,lin1,col1);

  printf("Matriz 1\n");
  mostraMatriz(m1,lin1,col1);
  printf("Matriz 2\n");
  mostraMatriz(m2,lin1,col1);

  printf("Matriz 2 apos soma com matriz 1\n");
  somaMatrizes(m1,m2,lin1,col1);
  mostraMatriz(m2,lin1,col1);


  return 0;
}