/***********
dengue.c
OBI2001
r. anido
***********/

#include <stdio.h>

#define MAX 100

int fila[MAX];
int poe, tira;

void coloca_na_fila(int n)
{
	fila[poe] = n;
	poe = (poe+1) % MAX;
}

int retira_da_fila(void)
{
	int n;
	
	n = fila[tira];
	tira = (tira+1) % MAX;
	return(n);
}


int main(void)
{
	int mapa[MAX][MAX];
	int num_ligacoes[MAX];
	int i, j, k, num, restam;
	int n=1;

	while (1) {
		scanf("%d", &num);
		if (num == 0) break;
		printf("Teste %d\n", n++);
		if (num == 1) {
			printf("1\n\n");
			continue;
		}
		for (i=0; i<num; i++) { // inicializa variaveis
			num_ligacoes[i]=0;
			for (j=0; j<num; j++) 
				mapa[i][j]=mapa[j][i]=0;
		}
		poe=tira=0;
		for (k=1; k<num; k++) { // Le as ligacoes
			scanf("%d %d", &i, &j);
			i--; j--;
			mapa[i][j]=mapa[j][i]=1;
			num_ligacoes[i]++; num_ligacoes[j]++;
		}
		for (i=0; i<num; i++) // verifica quais vilas sao "folhas"
			if (num_ligacoes[i] == 1) {
				coloca_na_fila(i);
			}
		restam = num;
		while (restam > 1) {
			k = retira_da_fila();
			restam--;
			for (i=0; i<num; i++) 
				if (mapa[i][k]) {
					mapa[i][k] = mapa[k][i] = 0;
					if (--num_ligacoes[i] == 1) {
						coloca_na_fila(i);
					}
				}
			
		} // while
		printf("%d\n\n", 1+retira_da_fila());
	} // while
	return(0);
}
