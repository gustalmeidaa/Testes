#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <locale.h>

//Desenvolvido por Gustavo Almeida

int main() {
    setlocale(LC_ALL, "portuguese");
    char *palavra = malloc(11 * sizeof(char)); //Alocando um vetor din�mico que pode armazenar at� 10 letras + o terminador '\0'
    printf("Digite uma palavra (at� 10 letras): ");
    scanf("%10s", palavra); //Obtendo a palavra e escaneando at� 10 letras
    int tam = strlen(palavra); //Obtendo o tamanho da palavra
    int aux = tam - 1; //Indo at� o �ltimo caractere do vetor
    char *palavraInvertida = malloc((tam + 1) * sizeof(char)); //Alocando dinamicamente o vetor "palavraInvertida" com base no tamanho da palavra inserida.
    for(int i = 0; i < tam; i++){
        palavraInvertida[i] = palavra[aux];
        aux--;
    }
    palavraInvertida[tam] = '\0'; //Colocando o terminador '\0' na �ltima posi��o do vetor
    puts(palavraInvertida); //Printando a palavra invertida na tela
    free(palavraInvertida); //Liberando o espa�o de mem�ria ocupado pelo vetor din�mico "palavraInvertida"
    free(palavra); //Liberando o espa�o de mem�ria ocupado pelo vetor din�mico "palavra"
    return 0;
}
