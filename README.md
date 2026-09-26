# lpa-trabalho-b1
# Trabalho B1 - Lógica de Programação e Algoritmos 
 
## Descrição 
A empresa solicitou um programa capaz de calcular
o valor total de solicitações de entrega. O programa não precisa manter cadastro, apenas realizar o cálculo com os dados fornecidos pelo cliente.
São pertinentes apenas dados numéricos, como a distância da entrega, peso e valor base decorrente dessas informações, além de incluir os acréscimos referentes a modalidade e faixas de peso/distancia, além de serviços adicionais quando solicitado em booleano (ou seja, 0=não 1=sim).
Ao final de cada processamento, o programa deve receber a quantidade de tentativas adicionais e perguntar se uma nova entrega será realizada ou se o ciclo pode ser finalizado, exibindo o resumo final caso seja encerrado.

 
## Funcionalidades
SOBRE O PROCEDIMENTO:
Entrada de dados da entrega: permite informar distância, peso, modalidade de entrega, contratação de serviço adicional e quantidade de tentativas adicionais.

Validação: caso um número fora dos parâmetros definidos - em caso de medidas, números negativos, em caso de decisão booleana, números fora 0 ou 1 - o erro e acusado e solicitado a reinserção do valor digitado.

Processamento do total: leva em consideração os dados fornecidos em cada entrada, além disso, os adicionais ou taxas percentuais são calculadas separadamente utilizando dos dados informados e compõem o total ao final.

CONTROLE
Permite o processamento de múltiplas entregas, contudo ainda permite que o usuário escolha quando parar.

RESUMO FINAL
Apresenta o total acumulado de todas as entregas realizadas após um ciclo finalizado, ou seja, o faturamento.

Apresenta a contagem de entregas realizadas dentro do ciclo e a modalidade. 

 
## Organização da solução 
A estrutura modular da solução se baseia da separação de responsabilidade do programa em três arquivos "main.c" e "PROGRAMA.c" e o cabeçalho/ponte para ambos, que define o cardápio das funções que serão executadas.
main.c contém o fluxo central, e controla o ciclo (se continua ou encerra)
PROGRAMA.h, contém as declarações das funções utilizadas;

PROGRAMA.c contém os cálculos e exibição explícitos, que destrincha o que cada função definida no "cardápio" (PROGRAMA.h) deve coletar e apresentar para ser chamada na ordem definida em main.c.

O processamento ocorre no fluxo: os dados são coletados e os valores correspondente aos adicionais são definidos e o total da entrega atual é exibida ao final. O resumo com faturamento apenas é exibido após o encerramento.

 

## Compilação 
O programa foi desenvolvido em C e pode ser compilado utilizando o compilador GCC.

no terminal:
gcc main.c -o programa
 

## Execução 
Após a compilação, execute o programa no arquivo main.exe que será gerado.
 
## Uso de Inteligência Artificial 
Houve o uso do ChatGPT com a finalidade de auxiliar na definição de maior e menor valor, auxiliar na declaração das variáveis dentro das funções e solucionar conflitos na compilação.

Prompts relevantes:
1- "(Foi inserido como contexto antes do prompt: o PROGRAMA.c do primeiro commit)
Cenário: mesmo após definir parâmetros para subtotalInicial, a fim de que ele use os valores de distancia e valorBase nas funções anteriores, informa a "falta de argumentos" para subtotalInicial e informa a necessidade de uma expressão antes de "float". Considerando os códigos acima e o cenário apresentado, qual erro pode ter ocorrido que impede a compilação?"

2- "(Foi inserido como contexto antes do prompt: o PROGRAMA.c, PROGRAMA.h e main.c do segundo commit)
Cenário: na função "int modalidade (subtotalpeso) a compilação reconhece o percentual, porém não consegue identificar/puxar o valor de "subtotalpeso" da função "float adicionalpeso". Por isso, ele também não consegue calcular o valor de taxamodalidade. O que pode ter ocorrido para a função primeiramente mencionada não ter conseguido puxar o valor "subtotalpeso"."

3- "(foi inserido como contexto antes do prompt:  o PROGRAMA.c, PROGRAMA.h e main.c, estes não registrados em commit devido ao erro de compilação)
cenário, tentativas e adicional tentativas estão impedindo a compilação, com a informação de que não são funções ou ponteiros."

4-"Como representar em um código em C um valor maior e menor após a finalização de um ciclo."

 
## Fontes consultadas 
Foram consultados os conteúdos da aula-04, bem como os códigos "main.c", "estacionamento.c" e "estacionamento.h" para compreensão da estrutura modular, bem como sobre como definir as funções entre os arquivos e representar a ordem de execução no main.c.
 
