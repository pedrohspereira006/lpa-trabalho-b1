#include "PROGRAMA.c"

int main (void) {
	float distancia, peso;
	float subtotal, subtotalpeso;
	float subtotalmoda, subtotalpro;
	int opcao, opcaop;
	
	do {
		distancia = distanciaExata();
		
		if (distancia != 0) {
			subtotal = subtotalinicial(distancia);
			peso = pesagemExata();
			subtotalpeso = adicionalPeso(peso, subtotal);
		}
		
		opcao = exibirmodalidade();
		
			if (opcao !=0){
			subtotalmoda = modalidade(opcao, subtotal, subtotalpeso);
}

		opcaop = opcaoProtecao();
		
		if (opcao !=0) {
			subtotalpro = protecao(opcaop, subtotalmoda);
		}
		
	} while (distancia != 0); 

	return 0;
}
