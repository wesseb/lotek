#include <stdio.h>
#include <time.h>
#include <stdlib.h>

/**************************************************************
*	ZBIOR W C ZE STRONY rosettacode.org/wiki/Set#C        *
**************************************************************/

typedef unsigned int set_t;

void show_set(set_t x, const char *name) {
	int i;
	printf("%s jest:", name);
	for (i = 0; (1U << i) <= x; i++)
		if (x & (1U << i))
			printf(" %d", i);
	putchar('\n');
}


int main() {
	srand(time(NULL));

	int ileliczb, maksliczba;
	int *l = NULL;
	set_t t;

	l = malloc(sizeof(int)*ileliczb);

	printf("Podaj ilosc typowanych liczb: ");
	scanf("%d", &ileliczb);

	printf("Podaj maksymalna losowana liczbe: ");
	scanf("%d", &maksliczba);

	int i = 0;
	while (i < ileliczb) {
		//TODO: Losowe liczby nie moga sie powtarzac
		int liczba = rand() % maksliczba + 1;
		//printf("DEBUG: %d\n", liczba);
		if (l[i] == 0) {
			l[i] = liczba;
			//printf("DEBUG: Zadeklarowalem liczbe %d\n", l[i]);
			i = i + 1;
		}
	}

	printf("Wylosowane liczby to: ");
	for (i = 0; i < ileliczb; i++) {
		printf("%d ", l[i]);
	}
	putchar('\n');

	//TODO: Stworzyc funkcje ktora bedzie sprawdzac czy nie zostaly podane 2x te same typy (Cos na zasadzie zbioru).
	printf("Wytypuj %d z %d liczb: ", ileliczb, maksliczba);
	putchar('\n');

	i = 0;
	t = 0; //pusty zbior
	while (i < ileliczb) {
		int typ;
		printf("Podaj liczbe %d: ", i+1);
		scanf("%d", &typ);

		if (t & (1U << typ)) {
			printf("DEBUG: Blad, dodales ta sama liczbe!");
			break;
		} else {
			t |= (1U << typ);
			show_set(t, "zbior wytypowanych liczb");
			i = i + 1;
		}
	}
	free(l);

	return 0;
}
