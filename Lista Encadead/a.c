#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
  int valor;
  struct node *next;
  
} node_t;

//Mostrar a lista

void printList(node_t *head){
  node_t *atual = head;

  while (atual != NULL)
  {
    printf("%d\n",atual->valor);
    atual = atual->next;
  }
  
}



void push(node_t **head, int v){
  node_t *novo;
  
  novo = (node_t *) malloc(sizeof(node_t));
  novo->valor = v;
  novo->next = *head;
  *head = novo;
}

int pop(node_t **head){
  int v = -1;

  node_t *proximo = NULL;

  if (*head == NULL)
  {
    return -1;
  }

  proximo = (*head)->next;
  v = (*head)->valor;
  free(*head);
  *head = proximo;

  return v;
}

int removeLast(node_t *head){

  int v = 0;

  if (head->next == NULL)
  {
    v = head->valor;
    free(head);
    return v;
  }

  node_t *atual = head;
  while (atual->next->next !=NULL)
  {
    atual = atual->next;
  }
  
  v = atual->next->valor;
  free(atual->next);
  
  atual->next = NULL;
  return v;
}



int main(){

  node_t *head = NULL;

  head = (node_t *) malloc(sizeof(node_t));
  if (head ==NULL)
  {
    return 1;
  }

  head->valor = 1;
  head->next = (node_t *) malloc(sizeof(node_t));
  head->next->valor = 2;
  head->next->next = (node_t *)malloc(sizeof(node_t));
  head->next->next->valor = 3;
  head->next->next->next = NULL;

  printList(head);
  push(&head,5);
  printf("\n");
  printList(head);
  int remov = pop(&head);
  printf("Valor removido %d\n",remov);
  printList(head);

  int removLast = removeLast(head);
  printf("Valor final removido %d\n",removLast);
  printList(head);

  return 0;

}