/*
  Nome: Guilherme Weber Henriques, Guilherme da Silva Scher

  Programa para "verificar os bits de entrada" o qual retorna F caso receba o bit 9 e S caso a entrada seja somente 0 ou 1.
*/

#include <stdio.h>

int main() {
    int bits[8];
    int i;
    
    for (i = 0; i < 8; i++) {
        scanf("%d", &bits[i]); //Adicionando os bits
        
       
        if (bits[i] != 0 && bits[i] != 1 && bits[i] != 9) {
            printf("Entrada inválida\n");
            return 1;  //Aqui eu filtro os bits que podem dar entrada
        }
    }

    for (i = 0; i < 8; i++) {
        if (bits[i] == 9) {
            printf("F\n");
            return 0; 
        } // "Se tiver 9 = F"
    }
    

    printf("S\n");
    
    return 0;
}
