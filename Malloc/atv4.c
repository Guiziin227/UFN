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
      *(m+d) = rand() % 100;
    }
  }
}

void mostrarMatriz(int *m, int l, int c){

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

void multiplicaMatriz(int *m, int l, int c, int n){

  int d;

  for (int i = 0; i < l; i++)
  {
    for (int j = 0; j < c; j++)
    {
      d = i*c+j;
      *(m+d) *= n;
    }
  }
}



int main(){

  int col,lin,n,*m1;
  srand(time(0));

  printf("Diga um numero qualquer\n");
  scanf("%d",&n);

  printf("Diga o numero de linhas da sua matriz\n");
  scanf("%d",&lin);
  printf("Diga o numero de colunas da sua matriz\n");
  scanf("%d",&col);

  m1 = (int *)malloc(col*lin*4);

  if (!m1)
  {
    printf("error");
    exit(-1);
  }
  

  preencherMatriz(m1,lin,col);
  mostrarMatriz(m1,lin,col);

  printf("Matriz depois de multiplicada por %d\n",n);
  multiplicaMatriz(m1,lin,col,n);
  mostrarMatriz(m1,lin,col);

  free(m1);


  return 0;
}