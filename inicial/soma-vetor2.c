#include <stdio.h>
#include <stdlib.h>

// declaração de cabeçalhos das funções auxiliares
float mediaVetor(int *numeros, int N);

// programa principal
int main(int argc, char *argv[]) {

	int i, N = atoi(argv[1]);

	// aloca espaço para N inteiros na HEAP
	int *numeros = (int *) malloc(sizeof(int) * N);

	for (i = 0; i < N; i++) {
		printf("%dº valor: ", i + 1);
		scanf("%d", &numeros[i]);
	}

	float media = mediaVetor(numeros, N);
	// imprime a média com 2 casas decimais e pula uma linha.
	printf("MÉDIA: %.2f\n", media);

	// libera o espaço alocado
	free(numeros);
	return 0;
}

// funções auxiliares

/**
 * Obtém a média do vetor de N números inteiros.
 * @param numeros - vetor de números inteiros.
 * @param N - quantidade de elementos do vetor.
 * @returns média dos valores do vetor. 
 */
float mediaVetor(int *numeros, int N) {
	int i, soma = 0;
	for (i = 0; i < N; i++) {
		// soma = soma + numeros[i];
		soma += numeros[i];
	}
	return soma / N;
}
