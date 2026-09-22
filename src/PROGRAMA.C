#include <stdio.h>
#include "PROGRAMA.h"

float distancia;
float valorBase;
float taxaPeso;

void exibirMenu(void) {
	printf("SISTEMA DE ENTREGAS");
	printf("\nSelecione a faixa de distancia: ");
	printf("\n1- Maior que 0 ate 5 Km........R$8,00");
	printf("\n2- Acima de 5 Km ate 15 Km.....R$12,00");
	printf("\n3- Acima de 15 Km ate 30 Km....R$18,00");
	printf("\n4- Acima de 30 Km..............R$25,00");
	printf("\n0- Encerrar");
}

int escolhaOpcao(void) {
	int opcao;
	scanf("%d", &opcao);
	
	while (opcao < 0 || opcao > 4) {
		printf("Opcao invalida\n");
		printf("Digite novamente: ");
		scanf("%d", &opcao);
	}
	if (opcao==1) {
	valorBase = 8;
	} 
	else if (opcao==2) {
	valorBase = 12;
	}
	else if (opcao==3) {
	valorBase = 18;
	}
	else if (opcao==4) {
	valorBase = 25;
	}
	
	if (opcao != 0) {
	printf("Valor Base: %.2f\n", valorBase);
}

	return opcao;
}

//função responsável por coletar a distancia.

float distanciaExata(void) {
	float distancia;
	printf("Digite a distancia: \n");
	scanf(" %f", &distancia);
	return distancia;	
}

//função subtotal inicial
float subtotalInicial(void) {
	float subtotal;
	subtotal = valorBase + (distancia * 1.20f);
	
	printf("\nSubtotal Inicial: %.2f\n", subtotal);
	
	return subtotal;
}

//exibir menu de adicional de pesagem
void menuPeso (void) {
	printf("PESAGEM");
	printf("\nSelecione o peso medio: ");
	printf("\n1- Ate 2 Kg...................0%");
	printf("\n2- Acima de 2 Kg ate 5 Kg.....5%");
	printf("\n3- Acima de 5 Kg ate 10 Kg....10%");
	printf("\n4- Acima de 10 Kg.............20%");
}

//opcoes de pesagem.
int opcaoPeso(float subtotal) {
	int opcao2;
	scanf("%d", &opcao2);
	
	while (opcao2 < 1 || opcao2 > 4) {
		printf("Opcao invalida\n");
		printf("Digite novamente: ");
		scanf("%d", &opcao2);
	}
	if (opcao2==1) {
	taxaPeso = 0*subtotal;
	} 
	else if (opcao2==2) {
	taxaPeso = 0.05*subtotal;
	}
	else if (opcao2==3) {
	taxaPeso = 0.1*subtotal;
	}
	else if (opcao2==4) {
	taxaPeso = 0.2*subtotal;
	}
	
	if (opcao2 != 0) {
	printf("Adicional por faixa de peso: %.2f\n", taxaPeso);
}

	return opcao2;
}
