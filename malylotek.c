#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int main() {
	srand(time(NULL));
	int liczba = rand() % 10 + 1;

	int l;

	//printf("DEBUG: Wylosowana liczba to %d\n", liczba);

	for (int i = 0; i <= 2; i++) {
		printf("Proba nr: %d\n", i + 1);
		printf("Jaka liczbe mam na mysli? ");
		scanf("%d", &l);


		if (liczba == l) {
			printf("Zgadles! Dobra robota!\n");
		} else if (i == 2) {
			printf("Mialem na mysli liczbe: %d\n", liczba);

		} else {
			printf("Dupa.\n");
		}
	}
}
