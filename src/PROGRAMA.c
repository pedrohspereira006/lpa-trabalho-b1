#include <stdio.h>
#include "PROGRAMA.h"


float distanciaExata(void) {
	float distancia;
	
	printf("_______________________________________________________________________");
	printf("\nSISTEMA DE ENTREGAS");
	printf("\n_______________________________________________________________________");
	printf("\nRealize seu pedido de entrega de encomenda ");
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
//CALCULA SUBTOTALINICIAL.

float subtotalinicial(float distancia) {
	float valorBase;
	float subtotal = 0;
	
	if (distancia >0 && distancia <=5) {
		valorBase = 8;
	} else if (distancia >5 && distancia <=15) {
		valorBase = 12;
	} else if (distancia >15 && distancia <=30) {
		valorBase = 18;
	} else {
		valorBase = 25;
	}
	
	if (distancia != 0) {
		subtotal = valorBase + (distancia * 1.20f);
		
		printf("\nValor-Base: R$%.2f", valorBase);
		printf("\nSubtotal Inicial: R$%.2f\n", subtotal);
	}
	return subtotal;
}



float pesagemValida(void) {
	float peso;
	
	printf("_______________________________________________________________________");
	printf("\nPESAGEM E MODALIDADE DE ENTREGA");
	printf("\n_______________________________________________________________________");
	printf("\nDigite o peso: ");
	
	scanf("%f", &peso);
	
	while (peso <= 0) {
		printf("Peso invalido\n");
		printf("Digite novamente: ");
		scanf("%f", &peso);
	}
	return peso;	
}



//TAMBEM CALCULA O SUBTOTAL + ADICIONAL DE PESO
float adicionalPeso(float peso, float subtotal) {
	float percentual;
	float taxaPeso= 0;
	float subtotal_atualA = 0;
	
	if (peso >0 && peso <=2) {
		percentual = 0;
	} else if (peso >2 && peso <=5) {
		percentual = 0.05;
	} else if (peso >5 && peso <=10) {
		percentual = 0.1;
	} else {
		percentual = 0.2;
	}
	
	if (peso != 0){
		taxaPeso = percentual * subtotal;
	
		subtotal_atualA = subtotal + taxaPeso;
}
	return taxaPeso;
	
}





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




float modalidade(int opcao, float subtotal, float subtotal_atualA) {
	float percentualModa;
	float taxamodalidade = 0;
	float subtotal_atualB = 0;
	
	if (opcao==1) {
		percentualModa = 0;
	} else if (opcao==2) {
		percentualModa = 0.15;
	} else {
		percentualModa = 0.30;
	}
	
	if (opcao != 0){
		taxamodalidade = percentualModa * subtotal;
	
		subtotal_atualB = subtotal_atualA + taxamodalidade;
	} 
	return taxamodalidade;
	
}




int opcaoProtecao (void) {
	int opcaop;
	
	printf("\nDeseja contratar servico de protecao? (adicional de R$7.50)");
	printf("\n0 - NAO\n");
	printf("1 - SIM");
	printf("\nEscolha: ");
	
	scanf("%d", &opcaop);
	
	while (opcaop < 0 || opcaop > 1) {
		printf("Opcao nao listada\n");
		printf("Digite novamente: ");
		scanf("%d", &opcaop);
	}
	return opcaop;
	
}




float taxaprotecao (int opcaop, float subtotal_atualB) {
	float protecao;
	
	if (opcaop==1) {
	protecao = 7.50;
	}  else {
	protecao = 0;
	} 
	
	
	printf("\n_______________________________________________________________________");
	
	return protecao;
	
}



int tentativas (void) {
	int qtdTentativas;
	printf("\nQuantas vezes deseja repetir esta mesma entrega?: ");
	
	scanf("%d", &qtdTentativas);
	
	while (qtdTentativas < 0) {
		printf("Valor invalido para repeticoes\n");
		printf("Digite novamente: ");
		
		scanf("%d", &qtdTentativas);
	}	
	return qtdTentativas;
	
}




float adicionalTentativa(int qtdTentativas) {
	float addTentativas;
	
	addTentativas = qtdTentativas*4.00f;
	
	return addTentativas;
}




int novaentrega(void) {
	int prosseguir;
	
	printf("\n0- Encerrar");
	printf("\n1- Nova entrega");
	printf("\nDeseja solicitar nova entrega?: ");
	
	scanf("%d", &prosseguir);
	
	while (prosseguir < 0 || prosseguir > 1) {
		printf("Opcao nao listada\n");
		printf("Digite novamente: ");
		
		scanf("%d", &prosseguir);
}
	return prosseguir;
	
}	
