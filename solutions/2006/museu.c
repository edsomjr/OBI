/*
  solução para o problema museu
  busca de circuito mínimo em grafos
  complexidade O (n^3)
*/

#include <stdio.h>

#define MAX 1000

int grafo[MAX][MAX];
int tempo[MAX];

#define INF 2000000

int main () {

  int s, c;
  int o, d, t;
  int i, j, k;

  int max;
  max = INF;

  scanf("%d %d", &s, &c);

  for (i = 0; i < s; i++) {
    scanf("%d", &tempo[i]);
    for(j = 0; j < s; j++) {
      grafo[i][j] = INF;
    }
  }

  for (i = 0; i < c; i++) {
    scanf ("%d %d %d", &o, &d, &t);
    o--; d--;
    grafo[o][d] = t + tempo[d];
  }

  for (i = 0; i < s; i++) 
    for (j = 0; j < s; j++) 
      for (k = 0; k < s; k++)
	if (grafo[i][j] > grafo[i][k] + grafo[k][j])
	  grafo[i][j] = grafo[i][k] + grafo[k][j];

  for (i = 0; i < s; i++) 
    for (j = 0; j < s; j++) 
      if (max > grafo[i][j] + grafo[j][i])
	max = grafo[i][j] + grafo[j][i];
  
  printf ("%d\n", max);
    
  return (0);

}
