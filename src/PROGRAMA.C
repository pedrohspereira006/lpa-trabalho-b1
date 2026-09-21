#include <stdio.h>
#include "PROGRAMA.h"

void menuExibir(void) {
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
	float valorBase;
	scanf("%d", &opcao);
	
	while (opcao < 0 || opcao > 4) {
		printf("Opcao invalida\n");
		printf("Digite novamente: ");
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
	
	printf("Valor Base: %.2f\n", valorBase);

	return opcao;
}

float distanciaExata(void) {
	float distancia;
	printf("Digite a distancia: \n");
	scanf(" %.2f\n", &distancia);
	
}

float subtotalInicial(void) {
	float subtotal, distancia, valorBase;
	subtotal = valorBase + (distancia * 1.20f);
	
	printf("Subtotal Inicial: %.2f\n", subtotal);
	
	return subtotal;
}

