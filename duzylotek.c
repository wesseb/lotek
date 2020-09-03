#include <stdio.h>
#include <time.h>
#include <stdlib.h>

/**************************************************************************************
*	SPRAWDZENIE ZBIORU (show_set) W C ZE STRONY rosettacode.org/wiki/Set#C        *
***************************************************************************************/

typedef unsigned int set_t;

void show_set(set_t x, const char *name) {
	int i;
	printf("%s to:", name);
	for (i = 0; (1U << i) <= x; i++)
		if (x & (1U << i))
			printf(" %d", i);
	putchar('\n');
}

/* Generowanie ciagu znakow */

void powtorz (char wejscie, int liczba) {
	for (int i = 0; i != liczba; i++) {
		printf("%c", wejscie);
	}
	putchar('\n');
}


/* Glowny kod */

int main() {
	srand(time(NULL));

	int ileliczb, maksliczba;
	int *l = NULL;
	set_t typowanie, toto;

	l = malloc(sizeof(int)*ileliczb);

	printf("Podaj ilosc typowanych liczb: ");
	scanf("%d", &ileliczb);

	printf("Podaj maksymalna losowana liczbe do 30: ");
	scanf("%d", &maksliczba);

	if (maksliczba > 30) {
		printf("Maksymalny zakres tylko do 30 liczb.\n");
		free(l);
		return 0;
	} else if (ileliczb > maksliczba) {
		printf("Bledne dane. Ilosc typowanych liczb nie moze byc wieksza od maksymalnego zakresu\n");
		free(l);
		return 0;
	}

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

	/*printf("DEBUG: Wylosowane liczby to: ");
	for (i = 0; i < ileliczb; i++) {
		printf("%d ", l[i]);
	}*/
	putchar('\n');

	printf("Wytypuj %d z %d liczb: ", ileliczb, maksliczba);
	putchar('\n');
	powtorz('x', 20);

	i = 0;
	typowanie = 0;
	while (i < ileliczb) {
		int typ;
		printf("Podaj liczbe %d: ", i+1);
		scanf("%d", &typ);

		if ((typ <= 0) || (typ > 30) || (typowanie & (1U << typ))) {
			printf("DEBUG: Blad, dodales liczbe %d ktora nie jest w zakresie liczbowym lub ktora jest duplikatem zbioru.\n",typ);
			free(l);
			return 0;
		} else {
			typowanie |= (1U << typ);
			//show_set(typowanie, "DEBUG: zbior wytypowanych liczb");
			i = i + 1;
		}
		powtorz('x', 20);
	}

	toto = 0;

	for (i = 0; i < ileliczb; i++) {
		toto |= (1U << l[i]);
	}
	show_set(toto, "Wylosowane liczby to");

	if (typowanie & toto) {
		show_set(typowanie & toto, "Trafione liczby");
	} else {
		printf("Nie trafiles! Sprobuj jeszcze raz\n");
	}

	free(l);

	return 0;
}
