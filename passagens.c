#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"extra.c"

typedef struct passagem{
    char nome[100];
    char origem[100];
    char destino[100];
    int aviao;
    struct passagem *prox;
    struct passagem *ant;
}Passagem;

void insere_passagem(Passagem **p) {

    // Alocação da novo passagem
    Passagem *novo = (Passagem*) malloc(sizeof(Passagem));

    /* Iserção dos dados na struct, tonando os primeiros caracteres 
    minúsculos em maiúsculus se necessário*/
    printf("\nDigite seu nome\n: ");
    scanf("%s", novo->nome);
    maiuscula(novo->nome);
    printf("Digite a origem de sua viagem\n: ");
    scanf("%s", novo->origem);
    maiuscula(novo->origem);
    printf("Digite o destino de sua viagem\n: ");
    scanf("%s", novo->destino);
    maiuscula(novo->destino);
    printf("Digite o numero do aviao\n: ");
    scanf("%d", &novo->aviao);
    printf("\n\nPassagem foi cadastrada com sucesso.\n\n");
    
    // Arquivo para colocar os dados da struct é aberto
    FILE *fp = fopen("/home/joao/Algorithms/sistema/output/Passagem.txt", "a+");
    if (fp == NULL) {
        printf("\nErro ao abrir o arquivo.\n");
        exit(1);
    }

    // ADICIONAR: Algoritmo de ordenação - abrir o aquivo, ler e ordenar

    // Função que ordena os nomes em ordem alfabética
 
    // O Arquivo agora aberto é preenchido com os dados do usuário
    fprintf(fp, "Nome: %s\tOrigem: %s\tDestino: %s\tAviao: %d\n", novo->nome, novo->origem, novo->destino, novo->aviao);
    fclose(fp);

    // A lista encadeada dupla é atualizada com os novos dados
    novo->prox = NULL;
    novo->ant = NULL;
    if (*p == NULL) {
        *p = novo;
    } else {
        Passagem *atual = *p;
        while (atual->prox != NULL) {
            atual = atual->prox;
        }
        atual->prox = novo;
        novo->ant = atual;
    }
}

Passagem **remove_passagem(Passagem **lista) {

    char nome[100];
    printf("\nDigite o nome do passagem a ser removida\n:");
    scanf("%s", &nome);
    maiuscula(nome);

    if (*lista == NULL) {
        printf("Lista vazia!\n");
        return lista;
    }

    Passagem *novo = *lista;
    while (novo != NULL && strcmp(novo->nome, nome) != 0) {
        novo = novo->prox;
    }

    if (novo == NULL) {
        printf("\nPassagem nao foi encontrada!\n");
        return lista;
    }

    if (novo->ant == NULL) { // Se o passagem é a primeira da lista
        *lista = novo->prox;
    }

    else { // Se o passagem não é a primeira da lista
        novo->ant->prox = novo->prox;
    }

    if (novo->prox != NULL) { 
        novo->prox->ant = novo->ant; // Lista é atualizada
    }

    free(novo); // Passagem é removida
    printf("\nPassagem removido com sucesso!\n");

    // ADICIONAR: Atualizar as remoções para o arquivo "passagem"

    // ADICIONAR: Atualizar a ordem do arquivo (algoritmo de ordenação)

    return lista;
}

void lista_passagens(Passagem *p, FILE *arquivo) {

    int opcao;

    Passagem * novo = NULL;

    // Verificação se alguma reserva foi feita
    if (p == NULL) {
        printf("\nNenhum passagem cadastrada.\n");
    }

    printf("\n");
    printf("|-----------------------------------------------|\n");
    printf("|                 MENU - LISTAGEM               |\n");
    printf("|-----------------------------------------------|\n");
    printf("| 1 - Listar passagens adicionadas recentemente |\n");
    printf("| 2 - Listar todas as passagens                 |\n");
    printf("|-----------------------------------------------|\n\n");
    printf("Digite a opcao desejada\n: ");
    scanf("%d", &opcao);
    switch(opcao) {
        case 1:
            if (p == NULL)
            {
                printf("\n\nLista vazia!\n\n");
            }

            else{
                while (p != NULL){
                    printf("\nNome: %s\n", p->nome);
                    printf("Origem: %s\n", p->origem);
                    printf("Destino: %s\n", p->destino);
                    printf("Aviao: %d\n\n", p->aviao);
                    p = p->prox;
                }
            }
            
            
            break;
        case 2:
            // Abindo um arquivo que já foi criado para leitura
            arquivo = fopen("/home/joao/Algorithms/sistema/output/Passagem.txt", "r");
            if (arquivo == NULL) {
                printf("\nErro ao abrir o arquivo.\n");
                exit(1);
            } 
            char linha[100];
            while(fgets(linha, 100, arquivo) != NULL){
                Passagem *aux = (Passagem*) malloc(sizeof(Passagem));
                sscanf(linha, "Nome: %[^\t]\tOrigem: %[^\t]\tDestino: %[^\t]\tAviao: %d\n", aux->nome, aux->origem, aux->destino, &aux->aviao);
                printf("Nome: %s\nOrigem: %s\nDestino: %s\nAviao: %d\n\n", aux->nome, aux->origem, aux->destino, aux->aviao);
                novo = aux;

                novo->prox = NULL;
                novo->ant = NULL;
                if (p == NULL) {
                    p = novo;
                } else {
                    Passagem *atual = p;
                    while (atual->prox != NULL) {
                    atual = atual->prox;
                }
                atual->prox = novo;
                novo->ant = atual;
                }
            }
            fclose(arquivo);
            break;
        default:
            printf("\n\nOpcao invalida! Tente novomente.\n\n");
    }
}

Passagem *busca_passagem(Passagem *lista) {

    // Verifica se a lista está vazia
    if (lista == NULL)
    {
        printf("Lista esta vazia!");
    }

    /* Usuário digita o nome do passagem, 
    se estiver minúsculo transforma em maiúsculo */ 
    char *nome[100];
    printf("\nDigite o nome do Passagem\n: ");
    scanf("%s", nome);
    maiuscula(nome);

    // ADICIONAR: Ler os dados que estão no arquivo "passagem"

    /* Se não estiver vazia o nome do Passagem será 
    procurado e imprimido na tela */
    Passagem *atual = lista;
    while (atual != NULL) {
        if (strcmp(atual->nome, nome) == 0) {
            printf("\nPassagem esta na lista.\n\n");
            printf("Nome: %s\n", atual->nome);
            printf("Origem: %s\n", atual->origem);
            printf("Destino: %s\n", atual->destino);
            printf("Aviao: %d\n\n", atual->aviao);
            return atual;
        }
        atual = atual->prox;
    }
    /*Se mesmo com a lista estando preenchida a função nao encontrar
    o nome do passagem isso será imprimido na tela*/
    printf("\nPassagem nao foi encontrada.\n");
    return NULL;
}

/*void passagem_ordem(Passagem **lista, Passagem *nova_passagem) {
    // Caso a lista esteja vazia ou a nova passagem vem antes da primeira
    if (*lista == NULL || strcmp(nova_passagem->nome, (*lista)->nome) < 0) {
        nova_passagem->prox = *lista;
        if (*lista != NULL) {
            (*lista)->ant = nova_passagem;
        }
        *lista = nova_passagem;
    }
    
    // Procurar a posição correta para inserir a nova passagem
    Passagem *atual = *lista;
    while (atual->prox != NULL && strcmp(nova_passagem->nome, atual->prox->nome) > 0) {
        atual = atual->prox;
    }
    
    // Inserir a nova passagem na posição correta
    nova_passagem->prox = atual->prox;
    if (atual->prox != NULL) {
        atual->prox->ant = nova_passagem;
    }
    atual->prox = nova_passagem;
    nova_passagem->ant = atual;
}*/
