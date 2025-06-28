#include <stdio.h>

int v[14];

int inicializa_vetor () {
  v [4] = 1;
  v [5] = 2;
  v [6] = 3;
  v [7] = 4;
  v [12] = 5;
  v [11] = 6;
  v [13] = 7;
  v [1] = 8;
  v [2] = 9;
  v [3] = 10;
}

int main () {
  int numjogos = 0;

  int i;
  
  int p1, p2;
  int pp1, pp2;
  int c[2][3];
  
  inicializa_vetor();
  
  scanf ("%d", &numjogos);
  p1 = 0; 
  p2 = 0;
  for (i = 0; i < numjogos; i++) {
    pp1 = 0;
    pp2 = 0;
    scanf ("%d %d %d %d %d %d", 
	   &c[0][0], &c[0][1], &c[0][2],
	   &c[1][0], &c[1][1], &c[1][2]);
    if (v[c[0][0]] >= v[c[1][0]]) pp1++; else pp2++;
    if (v[c[0][1]] >= v[c[1][1]]) pp1++; else pp2++;
    if (v[c[0][2]] >= v[c[1][2]]) pp1++; else pp2++;
    if (pp1 > pp2) p1++; else p2++;
  }
  printf ("%d %d\n", p1, p2);
}
