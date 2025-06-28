
/*

Problema penalidade mínima
Por Raphael Marcos Menderico

*/

#include <stdio.h>

#define MAX_N 1000
#define INFINITO 1000000

int minimo(int a,int b)
{
  if (a < b)
    return a;
  else 
    return b;
}

int conta_divisoes(int a,int b)
{
  int contador;

  contador = 0;
  while (a % b == 0) {
    a /= b;
    contador++;
  }
  return contador;
}

int main(void)
{
  int i,j,k;
  int n;
  int matriz_anterior[2][MAX_N + 1],matriz_atual[2][MAX_N + 1];
  int digito;

  //

  scanf("%d",&n);

  for (i = 0;i < 2;++i)
  {
    matriz_anterior[i][1] = 0;
    for (j = 2;j <= n;++j)
      matriz_anterior[i][j] = INFINITO;
    matriz_atual[i][0] = INFINITO;
  }

  for (i = 1;i <= n;++i) {
    for (j = 1;j <= n;++j) {
      scanf(" %d",&digito);
      
      for (k = 0;k < 2;++k)
        if (!digito)
          matriz_atual[k][j] = INFINITO;
        else
          matriz_atual[k][j] = conta_divisoes(digito,!k ? 2 : 5) +
                                 minimo(matriz_atual[k][j - 1],
                                       matriz_anterior[k][j]);
    }

    for (j = 0;j < 2;++j)
      for (k = 1;k <= n;++k)
        matriz_anterior[j][k] = matriz_atual[j][k];
  }

  printf("%d\n",minimo(matriz_atual[0][n],matriz_atual[1][n]));

  return 0;
}
