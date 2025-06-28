#include <stdio.h>
#define MAX 10000

/*
  Solução para o problema terreno
  criada por Raphael Marcos Menderico
  em 02/04/2006
  Usa programação dinâmica, complexidade O(n^2)
*/

int matriz [MAX+1][MAX+1];
int acumulado [MAX+1][MAX+1];

int main() {
  int l, c, l_m, c_m;
  int i, j;
  int ponto, max_ponto = 0;

  scanf ("%d %d %d %d", &l, &c, &l_m, &c_m);
  max_ponto = 0;
  
  for (i = 1; i <= l; i++) {
    for (j = 1; j <= c; j++) {
      scanf ("%d", &matriz[i][j]);
    }
  }
  
  for (i = 0; i <= l; i++) {
    acumulado [i][0] = 0;
    acumulado [0][i] = 0;
  }
  
  for (i = 1; i <= l; i++) {
    for (j = 1; j <= c; j++) {
      acumulado[i][j] = acumulado [i-1][j] + acumulado[i][j-1]
	- acumulado [i-1][j-1] + matriz[i][j];
    }
  }
  
  for (i = l_m; i <= l; i++) {
    for (j = c_m; j <= c; j++) {
      ponto = acumulado [i][j] - acumulado[i - l_m][j] - acumulado [i][j - c_m]
	+ acumulado[i - l_m][j - c_m];
      if (ponto > max_ponto) {
	max_ponto = ponto;
      }
    }
  }
  printf ("%d\n", max_ponto);
}
