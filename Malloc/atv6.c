#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void preencheMatriz(int *m, int l, int c){
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

void preencheVetor( int *v, int c){
  for (int i = 0; i < c; i++)
  {
    *(v+i) = rand() % 10;
  }
}

void mostrarVetor(int *v, int c){
  for (int i = 0; i < c; i++)
  {
    printf("%d\t",*(v+i));
  }
}

void multiplicaCoisas(int *v1, int *v2, int *m, int l, int c){
  int d;

  for (int i = 0; i < l; i++)
  {
    v2[i] = 0;
    for (int j = 0; j < c; j++)
    {
      d = i*c+j;
      *(v2+i) = *(v1+i) * *(m+d);
    }
    
  }
  
}

int main(){

  int col, lin, *v1, *m1,*v2;
  srand(time(0));

  printf("Digite as colunas\n");
  scanf("%d",&col);
  printf("Digite a quantidade linhas da matriz\n");
  scanf("%d",&lin);

  v1 = (int *)malloc(lin*4);
  m1 = (int *)malloc(col*lin*4);
  v2 = (int *)malloc(lin*4);

  if (!v1 || !m1)
  {
    printf("error");
    exit(-1);
  }

  preencheMatriz(m1,lin,col);
  preencheVetor(v1,lin);

  printf("Matriz\n");
  mostrarMatriz(m1,lin,col);
  printf("Vetor\n");
  mostrarVetor(v1,lin);
  
  multiplicaCoisas(v1,v2,m1,lin,col);

  printf("\nVetor c\n");
  mostrarVetor(v2,lin);

  free(m1);
  free(v1);
  
  return 0;
}