/* senha.c */
/* OBI2004 */
/* Ulisses */
#include <stdio.h>

#define NMAX 11

int n, num[NMAX][5][2];
char sen[NMAX][6];

int main(void) {
  int i, j, k, nch, noh, all, teste = 1;

  while (scanf("%d", &n)==1 && n) {
    for (i=0; i<n; i++) {
      for (j=0; j<5; j++)
	scanf("%d %d", &num[i][j][0], &num[i][j][1]);
      for (k=0; k<6; k++)
	scanf(" %c", &sen[i][k]);
    }

    printf("Teste %d\n", teste++);
    for (k=0; k<6; k++) {
      nch = num[0][sen[0][k]-'A'][0];
      noh = num[0][sen[0][k]-'A'][1];

      all = 1;
      for (i=1; i<n; i++)
	if (nch != num[i][sen[i][k]-'A'][0] &&
	    nch != num[i][sen[i][k]-'A'][1])
	  all = 0;

      if (k != 0)
	printf(" ");
      printf("%d", (all ? nch : noh));
    }
    printf("\n\n");
  }

  return 0;
}
