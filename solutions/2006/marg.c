/* Margaridas
 * OBI 2006 - Primeira Fase
 * Modalidade Programacao 1
 * Autor: Fernando Aires */

#include<stdio.h>

#define MAX 1000 /* Tamanho maximo da plantacao */

int main()
{
	int plantacao[MAX][MAX]; /* Numero de margaridas em cada vaso da plantacao */
	int lin, col; /* Dimensoes da plantacao */
	int m, n; /* Dimensoes de cada celula da grade */
	int max; /* Numero maximo de margaridas num lote */
	int cur; /* Numero de margaridas no lote atual */
	int i, j, k, l; /* aux */

	scanf(" %d %d %d %d", &lin, &col, &m, &n);
	max=0;
	for(i=0; i<lin; i++)
		for(j=0; j<col; j++)
			scanf(" %d", &(plantacao[i][j]));

	for(i=0; i<lin; i+=m)
	{
		for(j=0; j<col; j+=n)
		{
			cur=0;
			for(k=i; k<(i+m); k++)
				for(l=j; l<(j+n); l++)
					cur+=plantacao[k][l];
			if(cur>max) max=cur;
		}
	}

	printf("%d", max);

	return 0;
}


