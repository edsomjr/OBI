#include <stdio.h>

#define MAX 10000


typedef struct intervalos {
	int inicio, final;
} intervalos;


intervalos sorveteiros[MAX];

int compara(const void *intervalo1, const void *intervalo2)
{
    if ( (*(intervalos *) intervalo1).inicio > (*(intervalos *) intervalo2).inicio ) 
        return 1;
    else if ( (*(intervalos *) intervalo1).inicio < (*(intervalos *) intervalo2).inicio ) 
        return -1;
    else return 0;
}

int main(void)
{
	int tam_praia, num_sorveteiros;
	int i;
	int min, max;
	int n=1;
	
	while (1) {
		scanf("%d %d\n", &tam_praia, &num_sorveteiros);
		if (tam_praia == 0) break;
		printf("Teste %d\n", n++);
		for (i=0; i<num_sorveteiros; i++) { // Le os intervalos
			scanf("%d %d\n", &sorveteiros[i].inicio, &sorveteiros[i].final);
		}
		qsort(sorveteiros, num_sorveteiros, sizeof(intervalos), compara);
		min = sorveteiros[0].inicio;
		max = sorveteiros[0].final;
		for (i=1; i<num_sorveteiros; i++) { // processa os intervalos
			if (sorveteiros[i].inicio > max) { //imprime intervalo corrente
				printf("%d %d\n", min, max);
				min = sorveteiros[i].inicio;
				max = sorveteiros[i].final;
			}
			else if (sorveteiros[i].final > max)
				max = sorveteiros[i].final;
		} // for
		printf("%d %d\n\n", min, max); // imprime ultimo intervalo
	} // while
	return(0);
}
