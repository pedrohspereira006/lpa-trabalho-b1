#include "PROGRAMA.C"

int main (void) {
	int opcao;
	float distancia, subtotal;
	
	do {
		exibirMenu ();
		
		opcao = escolhaOpcao();
		distancia = distanciaExata();
		subtotal = subtotalInicial();
		
		
		
	}
	while (opcao != 0);
	
	return 0;
}
