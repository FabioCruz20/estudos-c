#include <stdio.h>

// sobre a leitura de linha com fscanf:
// https://www.delftstack.com/pt/howto/c/fscanf-line-by-line-in-c/

int main(int argc, char *argv[]) {

	// argv[1] é o nome do arquivo passado pela linha de comando.
	// abre arquivo de texto no modo leitura "r"
	FILE *arquivo = fopen(argv[1], "r");

	// verifica se o arquivo foi aberto com sucesso
	if (arquivo == NULL) {
		printf("ERRO AO ABRIR ARQUIVO\n");
		return -1;
	}

	// percorre arquivo enquanto tiver conteúdo
	char linha[40];
	// feof verifica se o cursor de leitura chegou ao fim do arquivo.
	while ( ! feof(arquivo) ) {
		// lê uma linha do arquivo como string
		fscanf(arquivo, "%[^\n] ", linha);
		printf("LINHA: %s\n", linha);
	}
	// fecha arquivo previamente aberto
	fclose(arquivo);

	return 0;
}
