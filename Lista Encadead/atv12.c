#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Carro {
    char placa[8];
    char nome[30];
    char telefone[11];
    float valor;
    int situacao;
    struct Carro *proximo; //Ponteiro para o proximo elemento
} Carro;


Carro* criarCarro() {
    Carro* novoCarro = (Carro*)malloc(sizeof(Carro));
    novoCarro->proximo = NULL;
    return novoCarro;
}


void registrarCarro(Carro* carro) {
    printf("Qual a placa do carro? ");
    scanf("%s",carro->placa);
    fflush(stdin);
    printf("Qual seu nome? ");
    fgets(carro->nome, sizeof(carro->nome), stdin);
    printf("Qual seu telefone? ");
    scanf("%s",carro->telefone);
    printf("Qual o valor a pagar? ");
    scanf("%f", &carro->valor);
    carro->situacao = 0;
}



void registrarPagamento(Carro* first, char* placa) {
    Carro* atual = first;
    while (atual != NULL) {
        if (strcmp(atual->placa, placa) == 0) {
            atual->situacao = 1;
            printf("Pagamento registrado pelo carro de placa: %s\n", atual->placa);
            return;
        }
        atual = atual->proximo;
    }
    printf("Carro com placa %s nao encontrado.\n", placa);
}


void mostrarDados(Carro* first) {
    Carro* atual = first;
    while (atual != NULL) {
        printf("\nPlaca: %s, Dono: %s, Telefone: %s, Valor: %.1f, Situacao: %s", atual->placa, atual->nome, atual->telefone, atual->valor, atual->situacao ? "pago" : "nao pago");
        printf("\n----------------------------------");
        atual = atual->proximo;
    }
}


float total(Carro* first) {
    float valor = 0;
    Carro* atual = first;
    while (atual != NULL) {
        if (atual->situacao == 1) {
            valor += atual->valor;
        }
        atual = atual->proximo;
    }
    return valor;
}

void destruirLista(Carro* first){
    Carro* atual = first;
    while (atual != NULL) {
        Carro* temp = atual;
        atual = atual->proximo;
        free(temp);
    }

}


int main() {
    Carro* first = NULL;  //Aqui eu criei os ponteiros do tipo "carro" inicializado em nulo de acordo com os slides
    Carro* ultimo = NULL; 
    int escolha;
    char placa[8]; 

    do {
        printf("\n1) Registrar um carro\n");
        printf("2) Registrar um pagamento\n");
        printf("3) Mostrar dados dos carros\n");
        printf("4) Mostrar valor total ganho\n");
        printf("5) Sair\n");
        scanf("%d", &escolha);
        fflush(stdin);

        switch (escolha) {
            case 1: {
                Carro* novoCarro = criarCarro();
                registrarCarro(novoCarro);
                if (first == NULL) {
                    first = novoCarro;
                } else {
                    ultimo->proximo = novoCarro;
                }
                ultimo = novoCarro;
                break;
            }
            case 2: {
                fflush(stdin);
                printf("Qual a placa do carro?\n");
                scanf("%s",placa);
                registrarPagamento(first, placa);
                break;
            }
            case 3:
                mostrarDados(first);
                break;
            case 4:
                printf("Valor total recebido: R$ %.2f\n", total(first));
                break;
            case 5:
                printf("Saindo...\n");
                destruirLista(first);
                break;
            default:
                printf("Opção inválida!\n");
                break;
        }
    } while (escolha != 5);

  
    return 0;
}
