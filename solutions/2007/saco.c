#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX_C 32
#define MAX_P 128

#define SINAL(x) ((x) - 'A')

int n, t;
int grafo[MAX_C][MAX_C];

int presente[MAX_C];
int sinal[MAX_C];
int matrix[MAX_C][MAX_P][MAX_P];

void dfs(int c, int a, int b) {
  int i;

  if (!matrix[c][a][b]) {
    matrix[c][a][b] = 1;

    if (a + b + presente[c] <= t)
      if (!sinal[c])
	dfs(c,a + presente[c],b);
      else
	dfs(c,a,b + presente[c]);

    for (i = 0; i < n; i++)
      if (grafo[c][i])
    	dfs(i,a,b);
  }
}

int main (void){

  int i, j, k, idc, nv, v, r;
  char type;

  memset(matrix,0,sizeof(matrix));
  memset(grafo,0,sizeof(grafo));
  
  scanf (" %d", &n);
  scanf (" %d", &t);
  
  for (i = 0; i < n; i++) {
    scanf (" %d %d %c %d", &idc, &presente[i], &type, &nv);
    sinal[i] = SINAL(type);
    printf ("-- %d %d\n", i, sinal[i]);
    for (j = 0; j < nv; j++) { 
      scanf (" %d", &v);
      grafo[i][v] = 1;
    }
  }
  
  dfs(0,0,0);

  r = MAX_P;

  for (i = 0; i < n; i ++) 
    for (j = 0; j < MAX_P; j++)
      for (k = 0; k < MAX_P; k++)
	if (j + k > 0 && matrix [i][j][k] && r > abs (j - k)) {
	  printf ("%d %d %d\n", i, j, k);
	  r = abs(j - k);
	}
  
  printf ("%d\n", r);

}
