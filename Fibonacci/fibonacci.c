#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

/*
Desenvolvido por: Gustavo Almeida
*/

int main()
{
    setlocale(LC_ALL, "portuguese");
    int *fibonacci = (int) malloc(30 * sizeof(int)); //Alocando um vetor dinamicamente pensando em até 30 números possíveis dentro da sequência
    int numEscolhido = 0, achou = 0, posicao = 0, continuar = 1;
    while(continuar == 1){
            printf("Digite um número: ");
            scanf("%d", &numEscolhido);
            for(int i = 0; i < 30; i++){
                if(i == 0){
                    fibonacci[i] = 0; //Colocando o 0 na posição 0 do vetor dinãmico
                } else if (i == 1){
                    fibonacci[i] = 1; //Colocando o 1 na posição 1 do vetor dinãmico
                } else {
                    fibonacci[i] = fibonacci[i-1] + fibonacci[i-2]; //Caso não sejam as duas primeiras posições do vetor, seguir normalmente.
                }
                if(numEscolhido == fibonacci[i]){
                    achou = 1;
                    posicao = i;
                    break; //Parando o laço de repetição para evitar gastos com processamento, caso o número tenha sido encontrado na sequência
                }
            }
            if(achou == 1){
                printf("O número %d foi encontrado na posição %d da sequência de Fibonacci! :D\n", numEscolhido, posicao + 1);
            } else {
                printf("O número %d nao pode ser encontrado na sequência :(\n", numEscolhido);
            }
            printf("\nDeseja testar outro número (1 - Sim | 2 - Não)? ");
            scanf("%d", &continuar);
    }

    printf("Obrigado pela atenção!");

    free(fibonacci); //Liberando a memória alocada dinamicamente do vetor "fibonacci"

}
