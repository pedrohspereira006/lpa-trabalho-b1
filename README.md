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
gcc main.c PROGRAMA.c -o programa
 

## Execução 
Após a compilação, execute o programa no arquivo exe que será gerado.
 
## Uso de Inteligência Artificial 
Houve o uso do ChatGPT com a finalidade de auxiliar na definição de maior e menor valor, auxiliar na declaração das variáveis dentro das funções e solucionar conflitos na compilação.

Prompts relevantes:
1- "(Foi inserido como contexto antes do prompt: o PROGRAMA.c do primeiro commit)
Cenário: mesmo após definir parâmetros para subtotalInicial, a fim de que ele use os valores de distancia e valorBase nas funções anteriores, informa a "falta de argumentos" para subtotalInicial e informa a necessidade de uma expressão antes de "float". Considerando os códigos acima e o cenário apresentado, qual erro pode ter ocorrido que impede a compilação?"

2- "(Foi inserido como contexto antes do prompt: o PROGRAMA.C, PROGRAMA.h e main.c do terceiro commit)
Cenário: na função "int modalidade (subtotalpeso) a compilação reconhece o percentual, porém não consegue identificar/puxar o valor de "subtotalpeso" da função "float adicionalpeso". Por isso, ele também não consegue calcular o valor de taxamodalidade. O que pode ter ocorrido para a função primeiramente mencionada não ter conseguido puxar o valor "subtotalpeso"."

3- "(foi inserido como contexto antes do prompt:  o PROGRAMA.c, PROGRAMA.h e main.c, estes não registrados em commit devido ao erro de compilação)
cenário, tentativas e adicional tentativas estão impedindo a compilação, com a informação de que não são funções ou ponteiros."

4-"Como representar em um código em C um valor maior e menor após a finalização de um ciclo."

##Resultados Fornecidos:

## 1- "O erro está nesta linha do main.c:

subtotal = subtotalInicial(float distancia, float valorBase);

Ao chamar uma função em C, você não deve declarar os tipos dos argumentos. Os tipos são informados apenas na definição ou no protótipo da função.
A chamada correta seria:
subtotal = subtotalInicial(distancia, valorBase);

Porém, há outro problema importante no seu código: valorBase é declarado dentro de escolhaOpcao():

int escolhaOpcao(void) {
    int opcao;
    float valorBase;
Portanto, essa variável só existe dentro de escolhaOpcao(). No main(), você não tem acesso a ela.

Além disso, escolhaOpcao() retorna apenas opcao, e não valorBase. Se o objetivo da atividade é evitar ponteiros e permitir que distancia e valorBase sejam compartilhadas entre as funções, você pode declará-las como variáveis globais."

## 2- "O problema não está na função modalidade() em si. O problema está em como subtotalpeso está sendo criado e passado no main.c.
1. Onde está o problema

Na sua função adicionalPeso() você calcula corretamente:
subtotalpeso = subtotalinicial + taxaPeso;

Porém, essa variável:
float subtotalpeso = 0;

é uma variável local de adicionalPeso().

Isso significa que ela só existe dentro dessa função. Quando você faz:
return taxaPeso;

a função não retorna subtotalpeso, retorna apenas taxaPeso.

No main.c, você declarou:
float subtotalinicial, subtotalpeso, subtotalmoda;

mas essa declaração cria outra variável, independente da subtotalpeso que existe dentro de adicionalPeso().
E, principalmente, você nunca atribui um valor a ela.

Você faz:
taxaPeso = adicionalPeso(peso, subtotalinicial);

mas não faz:
subtotalpeso = ...;

Consequentemente, quando chega aqui:
opcao = modalidade(subtotalpeso);

o subtotalpeso do main está sem valor inicial definido."

## 3- "O problema não está relacionado a ponteiros. Você pode corrigir tudo isso usando apenas variáveis comuns e funções com return.

O principal problema é que, no main.c, você está dando o mesmo nome para uma variável e para uma função.
1. O conflito com tentativas

Você declarou:
int tentativas;

e depois faz:
tentativas = tentativas();

Aqui tentativas está sendo usado simultaneamente como:

variável int tentativas
função int tentativas(void)

Em C, isso gera conflito porque ambos pertencem ao mesmo espaço de nomes.

Por isso, quando o compilador chega em:
tentativas();

ele pode interpretar tentativas como a variável int, e não como uma função.

2. O mesmo acontece com adicionalTentativa
Você declarou:
float adicionalTentativa;

e depois:
addTentativas = adicionalTentativa(tentativas);

Novamente, adicionalTentativa já foi declarado como uma variável no main, mas você também possui uma função com esse nome:
float adicionalTentativa(int tentativas)
Então há outro conflito."

## 4- "Se você quer encontrar o maior e o menor valor obtido durante um ciclo for ou while e exibi-los somente depois que o ciclo terminar, a ideia é:
Criar duas variáveis para armazenar o maior e o menor.
A cada repetição, comparar o valor atual com elas.
Depois do ciclo, imprimir os valores.

   #include <stdio.h>

int main(void) {
    float valor;
    float maior, menor;
    
 -   for (int i = 0; i < 5; i++) {
        printf("Digite um valor: ");
        scanf("%f", &valor);

        if (i == 0) {
            // O primeiro valor inicia maior e menor
            maior = valor;
            menor = valor;
        } else {
            if (valor > maior) {
                maior = valor;
            }

--            if (valor < menor) {
                menor = valor;
            }
        }
    }

-    // Executado somente após o ciclo
    printf("\nMaior valor: %.2f", maior);
    printf("\nMenor valor: %.2f\n", menor);

  -  return 0;
}"

## Sugestões Aproveitadas/Aplicadas:
## 1 - Até o terceiro commit (fora o inicial):
a solução aproveitada foi declarar a distância e valorBase como variáveis globais. Em suas primeiras versões, o código continha o menu de seleção de faixa de distância com os valores, solicitava a escolha e uma opção e, apenas depois, para o cálculo de subtotal, solicitava a distância exata.
Contudo, a sugestão foi descartada a partir do quarto commit, pois contava com um fluxo desnecessariamente massivo. Então foi reescrita a solução removendo o menu (que não deveria estar lá), solicitando a distância separadamente (reaproveitando apenas a validação), e definir as regras do valorBase para cada faixa de distância, juntamente com o cálculo do subtotal, tornou a solução mais consistente do que apenas declarar tudo como global, além de aprimorar o encadeamento das funções a partir do quarto commit e as versões posteriores.

## 2 Definição do calculo que compoe o valor de "subtotalPeso" que foi renomeado posteriormente (subtotal_atualA):
"subtotal_atualA = subtotal + taxaPeso;"

## 3 -Alteração da declaração da função e das variáveis.
função: tentativas. variável: float qteTentativas
função adicionalTentativa. variável: float addTentativas.


## 4- trecho acrescentado ao main:
"int main (void) {
	...
	...
	float maior;
	float menor;

-	if (entregas == 1) {
    		maior = total;
    		menor = total;
		} else {
    		if (total > maior) {
       			 maior = total;
    	}

   - 	if (total < menor) {
        	menor = total;
    	}
	...
	} while (prosseguir !=0);
	...
	printf("\nMaior valor de entrega: R$%.2f", maior);
	printf("\nMenor valor de entrega: R$%.2f", menor);
	...
	return 0;
}"

Visto que o while já servia como controlador -prosseguir atualizando o maior e menor enquanto o usuário selecionasse 1 para nova entrega - o FOR foi desconsiderado.

 
## Fontes consultadas 
Foram consultados os conteúdos da aula-04, bem como os códigos "main.c", "estacionamento.c" e "estacionamento.h" para compreensão da estrutura modular, para compreender sobre a definição de funções entre os arquivos e representar a ordem de execução no main.c.
Função reaproveitada: estrutura de do ... while do main.c.
 
