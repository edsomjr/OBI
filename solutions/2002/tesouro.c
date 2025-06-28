/* Problema Tesouro - OBI2002
   tesouro.c -- por Guilherme Ottoni */

#include <stdio.h>
#include <string.h>

char possivel[10500];
int x, y, n, valores[100];

int main()
{
  int max, objetivo, soma, teste=1, i, j;
  while (scanf("%d %d %d", &x, &y, &n) == 3 && x > 0)
    {
      soma = 0;
      for (i = 0; i < n; i++)
	{
	  scanf("%d", &valores[i]);
	  soma += valores[i];
	}
      printf("Teste %d\n", teste++);
      if ((soma + x + y) % 2 != 0)
	printf("N\n\n");
      else
	{
	  objetivo = (soma + x + y) / 2 - x;
	  memset(possivel, 0, sizeof(possivel));
	  possivel[0] = 1;
	  max = 0;
	  for (i = 0; i < n && !possivel[objetivo]; i++)
	    {
	      for (j = max; j >= 0; j--)
		if (possivel[j])
		  possivel[j+valores[i]] = 1;
	      max += valores[i];
	    }
	  printf("%c\n\n", possivel[objetivo]? 'S' : 'N');
	}      
    }
  return 0;
}

