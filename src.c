#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct Cafenea Cafenea;
typedef struct Nod Nod;
typedef struct NodLista NodLista;
typedef struct ListaDubla ListaDubla;
typedef struct HashTable HashTable;
struct Cafenea {
	int id;
	char* nume;
};

struct Nod {
	Cafenea info;
	Nod* next;
};
struct NodLista {
	Cafenea info;
	NodLista* prev;
	NodLista* next;
};
struct ListaDubla {
	NodLista* primul;
	NodLista* ultimul;
};




Cafenea initCafenea(int id, const char* nume) {
	Cafenea c;
	c.id = id;
	c.nume = (char*)malloc(strlen(nume) + 1);
	strcpy(c.nume, nume);
	return c;
}

void afisareCafenea(Cafenea c) {
	printf("Cafeneaua se numeste %s si are id-ul %d\n", c.nume, c.id);
}

void listaSimplaFinal(Nod** noduri, Cafenea c) {
	Nod* final = (Nod*)malloc(sizeof(Nod));
	final->next = NULL;
	final->info = initCafenea(c.id, c.nume);
	if (*noduri == NULL)*noduri = final;
	else {
		Nod* aux = *noduri;
		while (aux->next) {
			aux = aux->next;
		}
		aux->next = final;
	}
}

Nod* adaugaInceput(Nod* noduri, Cafenea c) {
	Nod* final = (Nod*)malloc(sizeof(Nod));
	final->next = noduri;
	final->info = initCafenea(c.id, c.nume);
	return final;
}

Nod* stergeCafeneaNume(Nod* noduri, const char* nume) {
	Nod* nodurileCerinta=NULL;
	while(noduri){
		if (strcmp(noduri->info.nume, nume) != 0) {
			listaSimplaFinal(&nodurileCerinta, noduri->info);
		}
		noduri = noduri->next;
	}
	
	return nodurileCerinta;
}

void afisareListaSimpla(Nod* noduri) {
	while (noduri) {
		afisareCafenea(noduri->info);
		noduri = noduri->next;
	}
}

void dezalocaLista(Nod** noduri) {
	while (*noduri) {
		Nod* aux = *noduri;
		*noduri = (*noduri)->next;
		free(aux->info.nume);
		free(aux);
	}
	free(*noduri);
}

void citesteFisier(const char* numeFisier, Nod** noduri) {
	if (numeFisier) {
		FILE* f = fopen(numeFisier, "r");
		if (f) {
			char buffer[100];
			char delimitator[] = ",\n";
			while (fgets(buffer, 100, f)) {
				char* token;
				token = strtok(buffer, delimitator);
				Cafenea c;
				c.id = atoi(token);
				token = strtok(NULL, delimitator);
				c.nume = (char*)malloc(strlen(token) + 1);
				strcpy(c.nume, token);
				listaSimplaFinal(noduri, c);
			}
		}
	}
}

void adaugareNodLDF(ListaDubla* l, Cafenea c) {
	NodLista* final = (NodLista*)malloc(sizeof(NodLista));
	final->info = initCafenea(c.id, c.nume);
	
	final->prev = l->ultimul;
	final->next = NULL;
	if (l->ultimul == NULL)l->primul = final;
	else {
		l->ultimul->next = final;
	}
	l->ultimul = final;
}

void afisareListaDubla(ListaDubla l) {
	while (l.primul) {
		if (l.primul) {
			afisareCafenea(l.primul->info);
			l.primul = l.primul->next;
			
		}
	
	}
}
struct HashTable {
	int dimensiune;
	Nod** vectori;
};

HashTable initHashTable(int dim) {
	HashTable  h;
	h.dimensiune = dim;
	h.vectori = (Nod**)malloc(sizeof(Nod*) * dim);
	for (int i = 0; i < dim; i++) 
		h.vectori[i] = NULL;
	
		return h;
}
int calculHash(int dim, const char* nume) {
	return strlen(nume) % dim;
}
void adaugaNodInHash(HashTable h,Cafenea c) {
	int calculHashu = calculHash(h.dimensiune, c.nume);
	listaSimplaFinal(&(h.vectori[calculHashu]), c);
}

void main() {
	Nod* noduri = NULL;
	Cafenea c = initCafenea(20, "test");
	Cafenea c2 = initCafenea(21, "test2");
	ListaDubla l;
	l.primul = NULL; l.ultimul = NULL;
	adaugareNodLDF(&l, c);
	adaugareNodLDF(&l, c2);
	afisareListaDubla(l);
	citesteFisier("cafenele.txt", &noduri);
	//afisareListaSimpla(noduri);
	Nod* nodurileCerute = stergeCafeneaNume(noduri, "Starbucks");
	//afisareListaSimpla(nodurileCerute);
	HashTable h = initHashTable(5);
	adaugaNodInHash(h, c);

}