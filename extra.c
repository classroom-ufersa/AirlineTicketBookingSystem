#include<stdio.h>
#include<ctype.h>
#include<string.h>


void maiuscula(char *string) {
    int i, tamanho = strlen(string);
    for (i = 0; i < tamanho; i++) {
        if ((i == 0 || string[i - 1] == ' ') && islower(string[i])) {
            string[i] = toupper(string[i]);
        }
    }
    string[i] = '\0';
    remove_char_especiais(string);
}

int apenas_numeros(){
    int valor, retorno = -1;
    char letra;
    do{
        printf("Digite um opcao\n:");
        retorno = scanf("%d", &valor);
        do{
          letra = getchar();
        }while(letra != '\n');
    }while(retorno == 0);
    return valor;
}

void remove_char_especiais(char *nome_verificar) {
  int cont_original = 0, cont_novo = 0;
  char aux[50];
  
  // loop para percorrer toda a string
  while (nome_verificar[cont_original] != '\0') {
    if (isalpha(nome_verificar[cont_original])) {
      // Salvando na string auxiliar os valores que são somente caracteres 
      aux[cont_novo] = nome_verificar[cont_original];
      cont_novo++;
    }
    cont_original++;
  }
  strcpy(nome_verificar,aux);
}
