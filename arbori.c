#define _CRT_SECURE_NO_WARNINGS	
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct Cinema Cinema;
typedef struct Nod Nod;
struct Cinema {
	int id;
	int nrFilme;
	char** numeFilme;
};
struct Nod {
	Cinema info;
	Nod* st;
	Nod* dr;
};

Cinema initCinema() {

}
void inserareInArbore(Nod** radacina, Cinema c) {
	if (*radacina != NULL) {
		if ((*radacina)->info.id > c.id) {
			inserareInArbore(&((*radacina)->st), c);
		}
		else {
			inserareInArbore(&((*radacina)->dr), c);
		}
	}
	else {
		Nod* nod = (Nod*)malloc(sizeof(Nod));
		nod->info = c;
		nod->st = NULL;
		nod->dr = NULL;
		*radacina = nod;
	}
}

Cinema citireCinema(FILE *f) {
	Cinema cinema;
	fscanf(f, "%d", cinema.id);
	fscanf(f, "%d", cinema.nrFilme);
	if (cinema.nrFilme > 0) {
		cinema.numeFilme = (char**)malloc(sizeof(char*) * cinema.nrFilme);

		for (int i = 0; i < cinema.nrFilme; i++) {
			char buffer[100];
			fscanf(f, "%s", &buffer);
			cinema.numeFilme[i] = (char*)malloc((strlen(buffer) + 1) * sizeof(char));
			strcpy(cinema.numeFilme[i], buffer);

		}
		
	}
	else {
		cinema.id = -1;
		cinema.nrFilme = 0;
		cinema.numeFilme = NULL;
	}
	return cinema;
}

Nod* citireFisier(const char* numeFisier) {
	Nod* radacina = NULL;
	if (numeFisier && strlen(numeFisier)>0) {
		FILE* f = fopen(numeFisier, "r");
		if (f) {
			int dim;
			fscanf(f, "%d",&dim);
		
			for (int i = 0; i < dim; i++) {
				Cinema cinema=citireCinema(f);
				inserareInArbore(&radacina, cinema);
			}
          //  printf("%d", dim);
			fclose(f);
		}
		else {

		}
    }
	return radacina;
}
void afisareCinema(Cinema c) {
	printf("Cinematograful cu id-ul %d are in derulare %d filme", c.id, c.nrFilme);
	for (int i = 0; i < c.nrFilme; i++) {
		printf("%s, ", c.numeFilme[i]);
	}
}
void afisareArborePreOrdine(Nod* rad) {
	if (rad) {
		afisareCinema(rad->info);
		afisareArborePreOrdine(rad->st);
		afisareArborePreOrdine(rad->dr);
	}
}
void afisareArboreInOrdine(Nod* rad) {
	if (rad) {
		afisareArboreInOrdine(rad->st);
		afisareCinema(rad->info);
		afisareArboreInOrdine(rad->dr);
	}
}
int calculNrFilmeRedate(Nod* radacina) {
	if (radacina) {
		int suma = radacina->info.nrFilme;
		suma += calculNrFilmeRedate(radacina->st);
		suma += calculNrFilmeRedate(radacina->dr);
		return suma;
	}
	else {
		return 0;
	}
}
void main() {
	Nod* arbore = NULL;
	arbore=citireFisier("cinema.txt");
	afisareArborePreOrdine(arbore);
	
}