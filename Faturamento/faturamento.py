#Desenvolvido por Gustavo Almeida

import json #Importando a biblioteca "json" para manipular os dados do arquivo

with open('dados.json', 'r') as faturamentos: #Nomeando a forma com que os dados serão carregados
    dados = json.load(faturamentos) #Pegando o que foi carregado e jogando na variável "dadps"

dia = dados 

menorValor = dia[0]['valor'] #Inicializando a variável 'menorValor' com o primeiro valor disponível na lista de dados
maiorValor = dia[0]['valor'] #Inicializando a variável 'maiorValor' com o primeiro valor disponível na lista de dados
diaMaiorValor = dia[0]['dia']
diaMenorValor = dia[0]['dia']
diasUteis= 0 #Variável para contar os "diasUteis" 
incremento = 0 #Variável destinada a ser incrementada nos loops 'for'
somaTotal = 0 #A soma total dos valores, excluindo os valores zerados (os fins de semana e feriados)
contagemDiasValorSuperior = [] #Vetor responsável por realizar a junção dos valores superiores à média

for i in dia:
    if dia[incremento]['valor'] != 0.0: #Comparação para verificar se o valor de um determinado dia é diferente de 0
        diasUteis = diasUteis + 1 #Caso seja, o número de dias úteis aumenta, para posterior cálculo da média mensal.
        if dia[incremento]['valor'] > maiorValor: #Comparação para verificar se o valor do dia X é maior que o valor armazenado atualmente na variável 'maiorValor'
            maiorValor = dia[incremento]['valor']
            diaMaiorValor = dia[incremento]['dia']
        elif dia[incremento]['valor'] < menorValor: #Comparação para verificar se o valor do dia X é menor que o valor armazenado atualmente na variável 'menorValor'
            menorValor = dia[incremento]['valor']
            diaMenorValor = dia[incremento]['dia']
        somaTotal = somaTotal + dia[incremento]['valor'] #Variável responsável por incrementar a variável soma com o valor do dia útil estudado no momento.
    incremento = incremento + 1

mediaVendas = (somaTotal/diasUteis) #Realizando o cálculo da média 
incremento = 0 #Zerando novamente a variável de incremento
diasSuperiores = 0 #Contagem dos dias com valores superiores a da média

for x in dia:
    if mediaVendas < dia[incremento]['valor']: #Verificando se o valor do dia é maior do que a média
        contagemDiasValorSuperior.append(x) #Inserindo o dia no vetor de contagem de dias cujas vendas superaram a média
        diasSuperiores = diasSuperiores + 1 #Incrementando o contador de dias que foram superiores à média
    incremento = incremento + 1 #Incrementando o contador responsável por iterar o .json com os dados

print('---------------------- DIAS COM VALORES DE VENDAS SUPERIORES A DA MEDIA -----------------------')
for x in range(diasSuperiores):
    print(f'Dia: {contagemDiasValorSuperior[x]['dia']} | Valor: R${contagemDiasValorSuperior[x]['valor']:.2f}')
print('-------------------------------------------------------------------------------------------')

print('\n-------------------------- MAIOR VALOR DE FATURAMENTO -------------------------------')
print(f'Dia do maior valor: {diaMaiorValor} | Valor: R${maiorValor:.2f}')
print('------------------------------------------------------------------------------------------')

print('\n-------------------------- MENOR VALOR DE FATURAMENTO -------------------------------')
print(f'Dia do maior valor: {diaMenorValor} | Valor: R${menorValor:.2f}')
print('------------------------------------------------------------------------------------------')