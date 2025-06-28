#include <stdio.h>

/*
  Programa "Escada perfeita"
  Solução por Raphael Marcos Menderico
  Complexidade O(n).

*/

int main () {
  int vetor [10000];
  int i, n;
  int soma;
  int altura;
  int movimentos;

  scanf (" %d", &n);

  soma = 0;

  for (i = 0; i < n; i++) {
    scanf (" %d", &vetor[i]);
    soma += vetor[i];
  }

  soma -= (n * n + n) / 2; /*Atenção --- o resultado dessa soma é sempre 
			    inteiro*/

  if (soma >= 0 && soma % n == 0) {

    movimentos = 0;
    altura = (soma / n) + 1;

    for (i = 0; i < n; i++) {
      if (vetor[i] > altura)
	movimentos += (vetor[i] - altura);
      altura++;
    }

    printf ("%d\n", movimentos);

  } else {
    printf ("-1\n");
  }

}
