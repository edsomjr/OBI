/* tv.c    */
/* OBI2004 */
/* Ulisses */
#include <stdio.h>

#define NMAX 1001

int m, n, img[NMAX][NMAX];

int main(void) {
  int i, j, ic, jc, dh, dv, a, b, teste = 1;

  while (scanf("%d %d", &m, &n)==2 && m) {
    for (i=0; i<m; i++)
      for (j=0; j<n; j++)
	scanf("%d", &img[i][j]);

    dh = dv = 0;
    while (scanf("%d %d", &a, &b)==2 && (a || b)) {
      dh += a;
      dv += b;
    }
    dv = -dv;

    printf("Teste %d\n", teste++);
    for (i=0; i<m; i++) {
      for (j=0; j<n; j++) {
	if (j != 0)
	  printf(" ");
	ic = (m + (i-dv)%m) % m;
	jc = (n + (j-dh)%n) % n;
	printf("%d", img[ic][jc]);
      }
      printf("\n");
    }
    printf("\n");
  }

  return 0;
}
