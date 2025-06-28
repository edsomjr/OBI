/* par.c   */
/* OBI2004 */
/* Ulisses */
#include <stdio.h>

int main(void) {
  int n, i, np, ns, teste = 1;
  char prim[11], seg[11];

  while (scanf("%d", &n)==1 && n) {
    scanf(" %s %s", prim, seg);

    printf("Teste %d\n", teste++);
    for (i=0; i<n; i++) {
      scanf("%d %d", &np, &ns);
      printf("%s\n", ((np+ns)%2 == 0 ? prim : seg));
    }
    printf("\n");
  }

  return 0;
}
