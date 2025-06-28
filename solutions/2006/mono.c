/* Monopolio
 * OBI 2006 - Primeira Fase
 * Modalidade Programacao 1
 * Autor: Fernando Aires */

#include<stdio.h>

int main()
{
	int inicial; /* Quantidade inicial de dinheiro */
	int ntrans; /* Numero de transacoes */
	char jog1, jog2; /* Iniciais dos jogadores 1 e 2 */
	int valor; /* Valor da transacao */
	char tipo; /* Tipo de transacao */
	int caixa[3]; /* Quantidade de valor de cada um dos jogadores */
	int i; /* aux */

	scanf(" %d %d", &inicial, &ntrans);
	caixa[0]=inicial; /* Dalia */
	caixa[1]=inicial; /* Eloi */
	caixa[2]=inicial; /* Felix */
	for(i=0; i<ntrans; i++)
	{
		scanf(" %c", &tipo);
		switch(tipo)
		{
			case 'C':
				scanf(" %c %d", &jog1, &valor);
				caixa[jog1-'D']-=valor;
				break;
			case 'V':
				scanf(" %c %d", &jog1, &valor);
				caixa[jog1-'D']+=valor;
				break;
			case 'A':
				scanf(" %c %c %d", &jog1, &jog2, &valor);
				caixa[jog1-'D']+=valor;
				caixa[jog2-'D']-=valor;
				break;
		}
	}

	for(i=0;i<3;i++) printf("%d ", caixa[i]);
	printf ("\n");

	return 0;
}


