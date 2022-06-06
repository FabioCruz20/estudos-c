#include <stdio.h>

// Lê números, um por linha, de um arquivo de texto, e escreve o dobro desses
// valores em outro arquivo de texto.
int main(int argc, char *argv[]) {

  FILE *entrada = fopen(argv[1], "r");
  FILE *saida = fopen(argv[2], "w");

  // verifica se os arquivos foram abertos corretamente
  if (entrada == NULL) {
    printf("ERRO AO ABRIR ARQUIVO DE ENTRADA\n");
    return -1;
  }

  if (saida == NULL) {
    printf("ERRO AO ABRIR ARQUIVO DE SAÍDA\n");
    return -1;
  }

  int valorLinha;
  while ( ! feof(entrada) ) {
    // lendo número do arquivo de entrada
    fscanf(entrada, "%d\n", &valorLinha);
    // escrevendo o dobro do número no arquivo de saída
    fprintf(saida, "%d\n", valorLinha * 2);
  }

  // fechar arquivos de entrada e saída
  fclose(entrada);
  fclose(saida);

  return 0;
}