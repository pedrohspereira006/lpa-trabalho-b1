#include "PROGRAMA.C"

int main (void) {
	int opcao;
	float subtotal;
	int opcao2;
	
	do {
		exibirMenu ();
		
		opcao = escolhaOpcao();
		
		if (opcao != 0) {
		distancia = distanciaExata();
		subtotal = subtotalInicial();
	}
		menuPeso ();
		
		opcao2 = opcaoPeso(subtotal);
	}
	while (opcao != 0);
	
	return 0;
}
