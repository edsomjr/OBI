/*******************/
/* pal.c           */
/* r.anido         */
/* 2004-01-02      */
/*******************/
#include <stdio.h>
#include <string.h>

#define MAX_SIZE 5000

char input_word[MAX_SIZE + 1];
char pal[MAX_SIZE][MAX_SIZE];
int n;
int parts[MAX_SIZE];
int min;

int main (int argc, const char * argv[])
{
  int  i, j, k, teste = 1;

  // le comprimento da cadeia
  scanf("%d", &n);
  while (n) {
    // le a cadeia
    scanf("%s", input_word);
    // pre-computa palindromes
    for (i=0; i<n; i++)
      pal[i][i] = 1;
    for (i=0; i<n - 1; i++)
      pal[i][i+1] = input_word[i]==input_word[i+1];
    for (k=2; k<n+1; k++) {
      for (i=0; i<n-k; i++) {
	j = i + k;
	pal[i][j] = pal[i+1][j-1] & input_word[i]==input_word[j];
      }
    }

    // agora resolve
    for (i=0; i<n; i++) {
      if (pal[0][i]) {
	parts[i] = 1;
	continue;
      }
      min = 0;
      for (j=0; j<i; j++) {
	if (pal[j+1][i] && (!min || parts[j] < min))
	  min = parts[j];
	parts[i] = min + 1;
      }
    }

    // imprime resultado e le novo comprimento de palavra
    printf("Teste %d\n", teste++);
    printf("%d\n\n", parts[n-1]);
    scanf("%d", &n);
  }
  return 0;
}
