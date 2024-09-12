#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

/*
Desenvolvido por: Gustavo Almeida
*/

int main()
{
    setlocale(LC_ALL, "portuguese");
    int *fibonacci = (int) malloc(30 * sizeof(int)); //Alocando um vetor dinamicamente pensando em at� 30 n�meros poss�veis dentro da sequ�ncia
    int numEscolhido = 0, achou = 0, posicao = 0, continuar = 1;
    while(continuar == 1){
            printf("Digite um n�mero: ");
            scanf("%d", &numEscolhido);
            for(int i = 0; i < 30; i++){
                if(i == 0){
                    fibonacci[i] = 0; //Colocando o 0 na posi��o 0 do vetor din�mico
                } else if (i == 1){
                    fibonacci[i] = 1; //Colocando o 1 na posi��o 1 do vetor din�mico
                } else {
                    fibonacci[i] = fibonacci[i-1] + fibonacci[i-2]; //Caso n�o sejam as duas primeiras posi��es do vetor, seguir normalmente.
                }
                if(numEscolhido == fibonacci[i]){
                    achou = 1;
                    posicao = i;
                    break; //Parando o la�o de repeti��o para evitar gastos com processamento, caso o n�mero tenha sido encontrado na sequ�ncia
                }
            }
            if(achou == 1){
                printf("O n�mero %d foi encontrado na posi��o %d da sequ�ncia de Fibonacci! :D\n", numEscolhido, posicao + 1);
            } else {
                printf("O n�mero %d nao pode ser encontrado na sequ�ncia :(\n", numEscolhido);
            }
            printf("\nDeseja testar outro n�mero (1 - Sim | 2 - N�o)? ");
            scanf("%d", &continuar);
    }

    printf("Obrigado pela aten��o!");

    free(fibonacci); //Liberando a mem�ria alocada dinamicamente do vetor "fibonacci"

}
