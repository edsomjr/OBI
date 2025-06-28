#include <stdio.h>
int main () {
  
  int m, n, x, y, k;
  int dir;
  int i;
  int x_atual, y_atual;
  int minutos;

  scanf (" %d %d", &m, &n);
  
  scanf (" %d %d", &x, &y);

  scanf (" %d", &k);
  
  minutos = 0;
  x_atual = 0;
  y_atual = 0;

  for (i = 0; i < k; i++) {
    scanf (" %d", &dir);

    switch(dir) {
    case 1: 
      y_atual++;
      break;
    case 2:
      y_atual--;
      break;
    case 3:
      x_atual++;
      break;
    case 4:
      x_atual--;
      break;
    }
    
    if (x_atual >= x - 1 && 
	x_atual <= x + 1 &&
	y_atual >= y - 1 && 
	y_atual <= y + 1) 
      minutos++;
  }

  printf ("%d\n", minutos);

  return (0);
}
