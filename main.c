#include<stdio.h>
#include<stdlib.h>
#include"passagens.c"
#include"aviao.c"

int main(void){
    Aviao *aviao = NULL; // Variável struct passagem que manipula dados sobre voos
    Passagem *p = NULL; // Variável struct passagem que manipula dados dos passageiros
    FILE *fp = NULL; // Variável para manipulação de arquivos
    int opcao; // Variável para escolher uma opção no menu
    // Inicio do laço de repetição
    do {
        printf("\n|---------------------------------|\n");
        printf("|     MENU - PASSAGENS AEREAS     |\n");
        printf("|---------------------------------|\n");
        printf("| 1 - Inserir passagem            |\n");
        printf("| 2 - Remover passagem            |\n");
        printf("| 3 - Listar passagens            |\n");
        printf("| 4 - Buscar passagens            |\n");
        printf("| 5 - Consultar vagas disponiveis |\n");
        printf("| 6 - Quantitativo de passageiros |\n");
        printf("| 7 - Sair do programa            |\n");
        printf("|---------------------------------|\n\n");
        opcao = apenas_numeros();
        switch(opcao) {
            case 1:
                insere_passagem(&p);
                break;
            case 2:
                remove_passagem(&p);
                break;
            case 3:
                lista_passagens(p, fp);
                break;
            case 4:
                busca_passagem(p);
                break;
            case 5:
                // consultar_vagas(aviao);
                break;
            case 6:
                quantidade_passageiros(p);
                break;
            case 7:
                // libera_lista(p);
                printf("\nObrigado por usar o nosso programa!\n\n");
                exit(1);
                break;
            default:
                printf("Opcao invalida! Tente novomente.");
                break;
        }
    } while (opcao != 7); // Fim do laço de repetição
    return 0; // Fim do programa
}
