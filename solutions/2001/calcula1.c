/***********
calcula.c
OBI2001
r. anido
***********/

#include <stdio.h>


int main(void)
{
	int num, x, soma;
	int i;
	int n=1;

	while (1) {
		scanf("%d", &num);
		if (num == 0) break;
		soma = 0;
		for (i=0; i<num; i++) { // le valores
			scanf("%d", &x);
			soma += x;
		}
		printf("Teste %d\n%d\n\n", n++, soma);
	} // while
	return(0);
}
