/* pal.c   */
/* OBI2004 */
/* Ulisses */
#include <stdio.h>

#define NMAX 2002
#define INF NMAX*NMAX

char str[NMAX], pal[NMAX][NMAX];
int n, partes[NMAX];

int main(void) {
  int i, j, menor, val, teste = 1;

  while (scanf("%d", &n)==1 && n) {
    scanf(" %s", str);
    memset(pal, 0, sizeof(pal));

    for (i=0; i<n; i++)
      pal[i][i] = 1;
    for (j=1; j<n; j++)
      for (i=j-1; i>=0; i--)
	pal[i][j] = ((str[i]==str[j]) && (i+1>=j-1 || pal[i+1][j-1]));

    for (j=0; j<n; j++) {
      if (pal[0][j]) {
	partes[j] = 1;
      } else {
	menor = INF;
	for (i=1; i<=j; i++) {
	  if (pal[i][j] && partes[i-1]+1<menor)
	    menor = partes[i-1]+1;
	}
	partes[j] = menor;
      }
    }

    printf("Teste %d\n", teste++);
    printf("%d\n\n", partes[n-1]);
  }

  return 0;
}
