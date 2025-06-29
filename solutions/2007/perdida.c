#include <stdio.h>
#define MAX 1000

int encontrado[MAX];

int main (void) {
  int n, l, i;
  scanf (" %d", &n);
  for (i = 0; i < n; i++) 
    encontrado[i] = 0;

  for (i = 0; i < n - 1; i++) {
    scanf (" %d", &l);
    encontrado[l - 1] = 1;
  }

  for (i = 0; i < n; i++) 
    if (!encontrado[i]) {
      printf ("%d\n", i + 1);
      return (0);
    }

  return (0);

}
