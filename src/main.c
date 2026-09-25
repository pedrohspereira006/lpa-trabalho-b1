#include "teste.c"

int main (void) {
	
	float distancia, peso;
	float subtotal, subtotal_atualA;
	float subtotal_atualB, subtotal_atualC;
	float total;
	float adicionalTentativa;
	
	int opcao, opcaop, prosseguir;
	
	int atendimentos = 0;
	int economica = 0;
	int expressa = 0;
	int prioritaria = 0;
	float faturamento = 0;
	
	do {
		atendimentos++;
		
		
		adicionalTentativa = (atendimentos -1) * 4.00f;
        
		distancia = distanciaExata();
		
		subtotal = subtotalinicial(distancia);
		
		peso = pesagemExata();
	
		subtotal_atualA = adicionalPeso(peso, subtotal);
		
		
		opcao = exibirmodalidade();
		
			if (opcao !=0){
			subtotal_atualB = modalidade(opcao, subtotal, subtotal_atualA);
			if (opcao == 1) {
    		economica++;
			}
			else if (opcao == 2) {
    		expressa++;
			}
			else if (opcao == 3) {
   			 prioritaria++;		
			}
}

		opcaop = opcaoProtecao();
		
		if (opcao !=0) {
			subtotal_atualC = protecao(opcaop, subtotal_atualB);
		}
			prosseguir = novaentrega();
		
			total = subtotal_atualC + adicionalTentativa;
			
			printf("Adicional de tentativa: R$%.2f\n", adicionalTentativa);
			printf("\nTotal da entrega: R$%.2f\n", total);
			
			
	}	while (prosseguir != 0);
				
	faturamento += total;
	printf("RESUMO DOS ATENDIMENTOS\n");
    printf("Atendimentos: %d\n", atendimentos);
    printf("Faturamento: R$ %.2f\n", faturamento);
    
    printf("MODALIDADES ESCOLHIDAS\n");
    printf("ECONOMICA: %d\n", economica);
    printf("EXPRESSA: %d\n", expressa);
    printf("PRIORITARIA: %d\n", prioritaria);
	return 0;
}
