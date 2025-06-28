/***********
meteoro.c
OBI2001
r. anido
***********/

#include <stdio.h>


int main(void)
{
	int num, x, y;
	int x1, y1, x2, y2;
	int i, total;
	int n=1;

	while (1) {
		// le retangulo
		scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
		if (x1 == 0 && y1 == 0) break;
		scanf("%d", &num);
		total = 0;
		for (i=0; i<num; i++) { // le pontos
			scanf("%d %d", &x, &y);
			if (x >= x1 && x <=x2 && y <= y1 && y >= y2)
				total++;
		}
		printf("Teste %d\n%d\n\n", n++, total);
	} // while
	return(0);
}
