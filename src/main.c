#include "PROGRAMA.C"

int main (void) {
	int opcao;
	float distancia, subtotal;
	
	do {
		menuExibir ();
		
		opcao = escolhaOpcao();
		distancia = distanciaExata();
		subtotal = subtotalInicial();
		
		
		
	}
	while (opcao != 0);
	
	return 0;
}
