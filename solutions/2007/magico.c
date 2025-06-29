#include<stdio.h>
#define MAX 10

int q [MAX][MAX];
int main () {
  int i, j, n;
  int s, p;
  scanf (" %d", &n);
  for (i = 0; i < n; i++) 
    for (j = 0; j < n; j++) 
      scanf (" %d", &q[i][j]);

  s = 0;
  for (i = 0; i < n; i++)
    s += q[0][i];

  for (i = 1; i < n && s != -1; i++) {
    p = 0;
    for (j = 0; j < n; j++)
      p += q[i][j];
    if (p != s) s = -1;
  }

  for (j = 0; j < n && s != -1; j++) {
    p = 0;
    for (i = 0; i < n; i++)
      p += q[i][j];
    if (p != s) s = -1;
  }

  p = 0;
  for (i = 0; i < n && s != -1; i++)
    p += q[i][i];
  if (p != s) s = -1;

  p = 0;
  for (i = 0; i < n && s != -1; i++)
    p += q[i][n - i - 1];
  if (p != s) s = -1;

  printf ("%d\n", s);

  return (0);
}
