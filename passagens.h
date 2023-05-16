// Funções de passagem
#include"passagens.c"

// Cria e insere uma novo passagem na lista
void insere_passagem(Passagem **inicio, FILE *fp);

// Lista as passagens já reservadas
void lista_passagens(Passagem *inicio);

// Revove uma reserva
Passagem **remove_passagem(Passagem **lista);

/* Busca uma passagem pelo nome e retorna o ponteiro para o nó correspondente.
Caso não encontre, retornará NULL */ 
Passagem *busca_passagem(Passagem *lista);

// Qsort
int compara_nome(const void *a, const void *b);
