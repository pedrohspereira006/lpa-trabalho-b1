#include "PROGRAMA.h"

int main (void) {
	
	float distancia, peso;
	float subtotal, subtotal_atualA;
	float subtotal_atualB, subtotal_atualC;
	float total;
	float adicionalTentativa;
	float percentual, taxaPeso;
	float protecao,  percentualModa, taxamodalidade;
	
	int opcao, opcaop, prosseguir;
	
	int entregas = 0;
	float totalCalculado = 0;
	int economica = 0;
	int expressa = 0;
	int prioritaria = 0;
	
	float maior;
	float menor;
	float media;
	
	do {
		entregas++;
		adicionalTentativa = (entregas -1) * 4.00f;
        
		distancia = distanciaExata();
		
		subtotal = subtotalinicial(distancia);
		
		peso = pesagemValida();
		
	
		taxaPeso = adicionalPeso(peso, subtotal);

		subtotal_atualA = subtotal + taxaPeso;
		
		
		
		opcao = exibirmodalidade();

		taxamodalidade = modalidade(opcao, subtotal, subtotal_atualA);

		subtotal_atualB = subtotal_atualA + taxamodalidade; 

			if (opcao == 1) {
    			economica++;
			} else if (opcao == 2) {
    			expressa++;
			} else if (opcao == 3) {
   				prioritaria++;		
			}



		opcaop = opcaoProtecao();

		protecao= taxaprotecao(opcaop, subtotal_atualB);
		
		subtotal_atualC = subtotal_atualB + protecao;
		
		
		prosseguir = novaentrega();
		
		total = subtotal_atualC + adicionalTentativa;
		
		if (entregas == 1) {
    		maior = total;
    		menor = total;
		} else {
    		if (total > maior) {
       			 maior = total;
    	}

    	if (total < menor) {
        	menor = total;
    	}
}
		totalCalculado = totalCalculado + total;
		media = totalCalculado / entregas;
		
		printf("\nAdicional de nova entrega: R$%.2f", adicionalTentativa);
		printf("\nTotal da entrega: R$%.2f\n", total);
	
			
}	while (prosseguir != 0);

	printf("_______________________________________________________________________");
	printf("\nENCERRADO\n");
	printf("\n_______________________________________________________________________");

    printf("\nEntregas Processadas: %d\n", entregas);
    printf("\nTotal Calculado: R$ %.2f\n", totalCalculado);
    
    printf("\nMaior valor de entrega: R$%.2f", maior);
	printf("\nMenor valor de entrega: R$%.2f", menor);
	printf("\nValor medio das entregas: R$%.2f\n", media);
	
    printf("\nMODALIDADES\n");
    printf("\nECONOMICA: %d", economica);
    printf("\nEXPRESSA: %d", expressa);
    printf("\nPRIORITARIA: %d", prioritaria);
    
    
	
		
	return 0;
}
