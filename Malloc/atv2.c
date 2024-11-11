#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void escreverString(char *p,int tam){
  printf("Escreva a palavra letra por letra\n");
  for (int i = 0; i < tam; i++)
  {
    fflush(stdin);
    scanf("%c",p+i);
  }

  for (int i = 0; i < tam; i++)
  {
    printf("%c", *(p+i));
  }
}



int main(){

  int tam;
  printf("Diga o tamanho da palavra que quer digitar\n");
  scanf("%d",&tam);

  char *c;

  c = (char *)malloc(tam*sizeof(char));

  if (!c || tam == 0)
  {
    printf("error");
    exit(-1);
  }
  
  escreverString(c,tam);

  free(c);

  return 0;
}