#include <stdio.h>

// ====================================================================================================
// ================================== CABEÇALHOS DAS FUNÇÕES ==========================================
// ==================================================================================================== 

// Declarar, antes de main, as funções criadas neste arquivo, para evitar confundir o compilador.
int somaVetor(int *numeros, int N);

// ====================================================================================================
// ======================================= FUNÇÃO PRINCIPAL ===========================================
// ==================================================================================================== 

int main () {
	int N = 3, i, numeros[3];

	for (i = 0; i < N; i++) {
		printf("%dº valor: ", i + 1);
		scanf("%d", &numeros[i]);
	}

	int soma = somaVetor(numeros, N);

	printf("Soma do vetor: %d\n", soma);
}


// ====================================================================================================
// ====================================== FUNÇÕES AUXILIARES ==========================================
// ====================================================================================================

/**
 * Soma N elementos de um vetor.
 * @param numeros - vetor de inteiros.
 * @param N - número de elementos do vetor a serem somados.
 * @returns soma dos N primeiros números do vetor.
 */
int somaVetor(int *numeros, int N) {
	int i, soma = 0;
	for (i = 0; i < N; i++) {
		soma = soma + numeros[i];
	}
	return soma;
}
