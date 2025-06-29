#include <stdio.h>
int main (void) {
  int total = 0;
  int i, cortes, c;
  scanf ("%d", &cortes);
  for (i = 0; i < cortes; i++) { 
    scanf ("%d", &c);
    total += c - 1;
  }
  printf ("%d\n", total);
  return (0);
}
