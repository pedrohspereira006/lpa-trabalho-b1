#include <stdio.h>
#include "PROGRAMA.h"

float distanciaExata(void) {
	printf("\nSISTEMA DE ENTREGAS");
	printf("\nRealize seu pedido de entrega de encomenda ");
	float distancia;
	printf("\nDigite a distancia: ");
	scanf("%f", &distancia);
	
	while (distancia <= 0) {
	printf("Distancia invalida\n");
	printf("Digite novamente: ");
	scanf("%f", &distancia);
}
	return distancia;	
}

//DEFINE VALOR-BASE COM BASE NA DISTANCIA E
//CALCULA SUBTOTAL.

float subtotalinicial(float distancia) {
	float valorBase;
	float subtotal = 0;
	
	if (distancia >0 && distancia <=5) {
	valorBase = 8;
	} 
	else if (distancia >5 && distancia <=15) {
	valorBase = 12;
	}
	else if (distancia >15 && distancia <=30) {
	valorBase = 18;
	} else {
	valorBase = 25;
	}
	
	if (distancia != 0) {
	printf("Valor Base: %.2f\n", valorBase);
	
	subtotal = valorBase + (distancia * 1.20f);
	
	printf("\nSubtotal Inicial: %.2f\n", subtotal);
}
	return subtotal;
}


//COLETA UMA PESAGEM VALIDA.
float pesagemExata(void) {
	float peso;
	printf("\nDigite a pesagem: ");
	scanf("%f", &peso);
	
	while (peso <= 0) {
	printf("Peso invalido\n");
	printf("Digite novamente: ");
	scanf("%f", &peso);
}
	return peso;	
}

//CALCULA O ADICIONAL DE PESO, SUA PERCENTAGEM
//E CALCULA O SUBTOTAL COM ADICIONAL DE PESO
float adicionalPeso(float peso, float subtotal) {
	float percentual;
	float taxaPeso= 0;
	float subtotalpeso = 0;
	
	if (peso >0 && peso <=2) {
	percentual = 0;
	} 
	else if (peso >2 && peso <=5) {
	percentual = 0.05;
	}
	else if (peso >5 && peso <=10) {
	percentual = 0.1;
	} else {
	percentual = 0.2;
	}
	printf("Percentual da taxa de peso: %.f%%\n", percentual*100);
	
	if (peso != 0){
	taxaPeso = percentual * subtotal;
	printf("Adicional de peso: %.2f\n", taxaPeso);
	
	subtotalpeso = subtotal + taxaPeso;
	printf("Subtotal atual com adicional de peso: %.2f\n", subtotalpeso);
}
	return subtotalpeso;
}

//EXIBICAO E SELECAO DE MODALIDADE
int exibirmodalidade(void) {
	int opcao;
	printf("\nMODALIDADE DE ENTREGA");
	printf("\n1- ECONOMICA......0%%");
	printf("\n2- EXPRESSA.......15%%");
	printf("\n3- PRIORITARIA....30%%");
	printf("\nSelecione a modalidade de entrega: ");
	
		
	scanf("%d", &opcao);
	while (opcao < 1 || opcao > 3) {
	printf("Opcao invalida\n");
	printf("Digite novamente: ");
	scanf("%d", &opcao);
}
	return opcao;
}


//CALCULO DO ADICIONAL DE MODALIDADE.
float modalidade(int opcao, float subtotal, float subtotalpeso) {
	float percentualModa;
	float taxamodalidade = 0;
	float subtotalmoda = 0;
	
	if (opcao==1) {
	percentualModa = 0;
	} 
	else if (opcao==2) {
	percentualModa = 0.15;
	}
	else {
	percentualModa = 0.30;
	}
	
	printf("\nPercentual da modalidade de entrega: %.f%%\n", percentualModa*100);
	
	if (opcao != 1){
	taxamodalidade = percentualModa * subtotal;
	printf("Adicional de modalidade: %.2f\n", taxamodalidade);
	
	subtotalmoda = subtotalpeso + taxamodalidade;
	printf("Subtotal atual com adicional de modalidade: %.2f\n", subtotalmoda);
}
	return subtotalmoda;
}

//OPCAO DE PROTECAO

int opcaoProtecao (void) {
	int opcaop;
	
	printf("\nSERVICO DE PROTECAO (Adicional de 7.50)");
	printf("\n0 - NAO\n");
	printf("1 - SIM");
	printf("\nDeseja contratar servico de protecao?: ");
	
	scanf("%d", &opcaop);
	while (opcaop < 0 || opcaop > 1) {
	printf("Opcao invalida\n");
	printf("Digite novamente: ");
	scanf("%d", &opcaop);
}
	return opcaop;
}

//CALCULO SUBTOTAL COM SERVICO DE PROTECAO
//SE HOUVER.

float protecao (int opcaop, float subtotalmoda) {
	float taxaprotecao;
	float subtotalpro = 0;
	
	if (opcaop==0) {
	taxaprotecao = 0;
	}  else {
	taxaprotecao = 7.50;
	} 
	
	if (opcaop=! 0) {
		subtotalpro = subtotalmoda + taxaprotecao;
		printf("Subtotal atual com servico de protecao: %.2f\n", subtotalpro);
	}
	return subtotalpro;
}

