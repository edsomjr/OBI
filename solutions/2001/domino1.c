/***********
domino.c
OBI2001
r. anido
***********/

#include <stdio.h>

int pecas[7][7];
int num[7];


int main(void)
{
	int i, j, k, tmp;
	int num_pecas, num_impar, num_componentes;
	int ci, cj;
	int componente[7];
	int n = 1;
	
	while (1) {
again:
		scanf("%d\n", &num_pecas);
		if (num_pecas == 0) break;
		printf("Teste %d\n", n++);
		for (i=0; i<7; i++) { // inicializa variaveis
			num[i]=0;
			for (j=0; j<i; j++) 
				pecas[i][j]=0;
		}
		for (k=0; k<num_pecas; k++) { // Le as pecas
			scanf("%d %d\n", &i, &j);
			if (i < j) {
				tmp = i; i = j; j = tmp;
			}
			if (i != j) pecas[i][j] = 1;
			num[i]++; num[j]++;
		}
		num_impar = 0;
		for (i=0; i<7; i++) // verifica impares
			if (num[i] % 2 != 0)
				num_impar++;
		if (num_impar > 0 && num_impar !=2) {
			printf("nao\n\n");
			continue;
		}
		// verifica conectividade
		num_componentes = 0;
		for (i=0; i<7; i++) 
			if (num[i] != 0) {
				componente[i] = i+1;
				num_componentes++;
			} else componente[i] = 0;
		if (num_componentes == 1) {
			printf("sim\n\n");
			continue;
		}
		for (i=0; i<7; i++) 
			for (j=0; j<i; j++) 
				if (pecas[i][j]) { // junta componentes i e j
					ci = componente[i]; cj = componente[j];
					if (ci != cj) {
						if (--num_componentes == 1) {
							printf("sim\n\n");
							goto again;	
						}
						for (k=0; k<7;  k++)
							if (componente[k] == cj)
								componente[k] = ci;
					}
				}
		printf("nao\n\n");
	} // while
	return(0);
}
