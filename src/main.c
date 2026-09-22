#include "PROGRAMA.C"

int main (void) {
	int opcao;
	float subtotal;
	
	do {
		exibirMenu ();
		
		opcao = escolhaOpcao();
		
		if (opcao != 0) {
		distancia = distanciaExata();
		subtotal = subtotalInicial();
	}
		
	}
	while (opcao != 0);
	
	return 0;
}
