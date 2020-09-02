#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int main() {
	srand(time(NULL));

	int ileliczb;
	int maksliczba;
	int *l = NULL;
	int *t = NULL;

	l = malloc(sizeof(int)*ileliczb);
	t = malloc(sizeof(int)*ileliczb);

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
	printf("\n");

	//TODO: Stworzyc funkcje ktora bedzie sprawdzac czy nie zostaly podane 2x te same typy (Cos na zasadzie zbioru)
	/*i = 0;
	int znalezione = 0;
	while (i < ileliczb) {
		int typ = 0;
		printf("Podaj liczbe: ");
		scanf("%d", &typ);

		for (int j = 0; j < ileliczb; j++) {
			if (t[j] == typ) {
				znalezione = 1;
				break;
			}
			else {
				t[i] = typ;
				i = i + 1;
			}
		}
	}*/

	if (znalezione == 1) {
		printf("DEBUG: Juz podales taka liczbe!");
	}
	else {
		printf("DEBUG: Jest ok!");
	}

	free(l);
	free(t);

	return 0;
}
