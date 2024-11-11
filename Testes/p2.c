#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void criarManual(int tam, int *m){

  int d;

  printf("Pode comecar a digitar\n");

  for (int i = 0; i < tam; i++)
  {
    for (int j = 0; j < tam; j++)
    {
      d = i*tam+j;
      printf("[%d][%d]=",i,j);
      scanf("%d",(m+d));
    }
    
  }
}

void criarAutomatico(int tam, int *m){

  int d;

  for (int i = 0; i < tam; i++)
  {
    for (int j = 0; j < tam; j++)
    {
      d = i*tam+j;

      *(m+d) = rand() % 100;
    }
    
  }
  

}

void mostraMatriz(int tam, int *m){
   int d;

  for (int i = 0; i < tam; i++)
  {
    for (int j = 0; j < tam; j++)
    {
      d = i*tam+j;
      printf("%d\t",*(m+d));
    }
    printf("\n");
  }
}

void mostraClasse(int tam, int *m) {
    int d, transposta;
    int simetrica = 1, diagonal = 1, triangularSuperior = 1, triangularInferior = 1;

    for (int i = 0; i < tam; i++) {
        for (int j = 0; j < tam; j++) {
            d = i * tam + j;
            transposta = j * tam + i;

          
            if (*(m + d) != *(m + transposta)) {     
                simetrica = 0;
            }
        
            if (i != j && *(m + d) != 0) {
                diagonal = 0;
            }
           
            if (i < j && *(m + d) != 0) {
                triangularSuperior = 0;
            }
          
            if (i > j && *(m + d) != 0) {
                triangularInferior = 0;
            }
        }
    }

    if (diagonal) {
        printf("A matriz e diagonal\n");
    }
    if (simetrica) {
        printf("A matriz e simetrica\n");
    }
    if (triangularSuperior) {
        printf("A matriz e triangular superior\n");
    }
    if (triangularInferior) {
        printf("A matriz e triangular inferior\n");
    }
    if (!simetrica && !diagonal && !triangularSuperior && !triangularInferior) {
        printf("A matriz nao possui classe definida\n");
    }
}


void calculaMatriz(int tam, int *m){

  int d, somatorioPrimeiraColuna =0, n;
  int somaDiagonal =0;


  printf("Diga um numero qualquer\n");
  scanf("%d",&n);

  for (int i = 0; i < tam; i++)
  {
    for (int j = 0; j < tam; j++)
    {
      d = i*tam+j;

      if (j == 0)
      {
        somatorioPrimeiraColuna += *(m+d);
      }
    }
  }

  printf("O somatorio da primeira coluna e: %d\n",somatorioPrimeiraColuna);

  printf("Multiplicacao da primeira linha por %d:\n", n);


  for (int i = 0; i < tam; i++)
  {
    for (int j = 0; j < tam; j++)
    {
      d = i * tam + j;

      if (i == 0)
      {
        printf("%d\t",*(m+d) * n);
      }
      
    }
    
  }


  printf("\n");

  for (int i = 0; i < tam; i++) { //Aqui eu utilizei a lógica de que para diagonal i e j precisam ser iguais portanto uso so i
        d = i * tam + i;
        somaDiagonal += *(m + d);
    }

  printf("A soma dos valores da diagonal principal e de %d\n",somaDiagonal);
  
  int maiorValor = *m;


  for (int i = 0; i < tam; i++)
  {
    for (int j = 0; j < tam; j++)
    {
      d = i * tam + j;
      if (*(m+d) > maiorValor)
      {
        maiorValor = *(m+d);
      }
    }
  }

    printf("Maior valor da matriz e %d\n", maiorValor);

  
  for (int i = 0; i < tam; i++)
  {
    for (int j = 0; j < tam; j++)
    {
      d = i * tam + j;
      if (*(m+d) == maiorValor)
      {
        printf("O valor %d e encontrado na linha %d e na coluna %d ",maiorValor,i,j);
      }
    }
  }
  
}

int main(){

  int escolha, tam, *m1;
  char opcao;
  srand(time(0));

  printf("Qual sera o tamanho de sua matriz? (NxN)");
  scanf("%d",&tam);

  printf("Se quiser criar sua propria matriz digite 1, caso queira que o programa crie digite 2:\n");
  scanf("%d",&escolha);
 

  m1 = (int *)malloc(tam*tam*sizeof(int));

  if (!m1)
  {
    printf("error");
    exit(-1);
  }
  
  
  if (escolha == 1)
  {
    criarManual(tam,m1);
    mostraMatriz(tam,m1);
  } else if (escolha == 2)
  {
    criarAutomatico(tam,m1);
    mostraMatriz(tam,m1);
  } else {
    printf("Opcao invalida");
    free(m1);
    return 1;
  }
  
 
    printf("Escolha uma opcao\nA-Classe da matriz\nB-Calculo sobre a matriz\nC-Encerrar\n");
  fflush(stdin);
  scanf("%c",&opcao);

  switch (opcao)
  {
  case 'A':
    mostraClasse(tam,m1);
    break;
  case 'a':
    mostraClasse(tam,m1);
    break;
  case 'B':
    calculaMatriz(tam,m1);
    break;
  case 'b':
    calculaMatriz(tam,m1);
    break;
  case 'c':
    printf("Encerrando...");
    break;
  case 'C':
    printf("Encerrando...");
    break;
  default:
    printf("Opcao invalida");
    break;
  }
    

  return 0;
}