/* furos.c */
/* OBI2004 */
/* Ulisses */
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <values.h>

#define NMAX 1001

int n, centro[NMAX][2];
int mdist2[NMAX];

int main(void) {
  int i, j, dx, dy, dist2, menor, teste = 1;

  while (scanf("%d", &n)==1 && n) {
    for (i=0; i<n; i++)
      scanf("%d %d", &centro[i][0], &centro[i][1]);
    memset(mdist2, 0, sizeof(mdist2));

    for (i=0; i<n; i++)
      for (j=i+1; j<n; j++)
	if (i!=j) {
	  dx = centro[i][0]-centro[j][0];
	  dy = centro[i][1]-centro[j][1];
	  dist2 = dx*dx + dy*dy;

	  if (dist2 > mdist2[i])
	    mdist2[i] = dist2;
	  if (dist2 > mdist2[j])
	    mdist2[j] = dist2;
	}

    menor = MAXINT;
    for (i=0; i<n; i++)
      if (mdist2[i] < menor)
	menor = mdist2[i];

    printf("Teste %d\n", teste++);
    printf("%.0f\n\n", 2*sqrt(menor)+5);
  }

  return 0;
}
