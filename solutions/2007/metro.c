#include <stdio.h>
#define MAX 10000

int paes[MAX];
int n;
int k;

int verifica(int t) {
  int i;
  int total = 0;
  for (i = 0; i < k; i++) { 
    total += paes[i] / t;
  }
  return (total >= n);
}

main () {
    int i;
    int sol;
    int esq, dir, meio;
    scanf ("%d %d", &n, &k);
    for (i = 0; i < k; i++) {
      scanf ("%d", &paes[i]);
    }
    sol = 0;
    esq = 0;
    dir = MAX + 1;
    while (esq <= dir) {
      meio = (esq + dir) / 2; 
      if (verifica(meio)) {
	esq = meio + 1;
	sol = meio;
      } else 
	dir = meio - 1;

    }
    printf ("%d\n", sol);

}
