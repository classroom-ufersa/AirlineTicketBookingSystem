#include<stdio.h>
#include<stdlib.h>
#define TOTAL_VAGAS 50   

typedef struct aviao{
    int codigo;
    int vagas;
    char origem[100];
    char destino[100];
}Aviao;

void consultar_vagas(Aviao *novo) {

    novo = (Aviao*) malloc(sizeof(Aviao));
    int disponiveis = 0, i;
    for (i = 0; i < 50; i++) {
        disponiveis += novo->vagas;
    }
    novo->vagas = 50 - disponiveis;
    printf("\n\nVagas disponiveis: %d\n\n", novo->vagas);
}



