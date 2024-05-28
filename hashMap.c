#include<stdio.h>
#include<stdlib.h>

typedef struct Galerie Galerie;
struct Galerie {
	int cod;
	char* nume;
	float pretIntrare;

};
typedef struct nod nod;
struct nod {
	Galerie info;
	nod* next;
};
typedef struct hashTable HashTable;
struct hashTable {
	nod** vector;
	int dim;
};

HashTable initializareHashTable(int dimensiune) {
	HashTable hash;
	hash.dim = dimensiune;
	hash.vector = (nod**)malloc(sizeof(nod*) * dimensiune);
	for (int i = 0;i < dimensiune;i++) {
		hash.vector[i] = NULL;
	}
	return hash;
}
Galerie initGalerie(int cod, const char* nume, float pretIntrare) {
	Galerie g;
	g.cod = cod;
	g.nume = (char*)malloc(strlen(nume) + 1);strcpy(g.nume, nume);
	g.pretIntrare = pretIntrare;
	return g;
}
int calculHash(int cod,const char*nume,int dimensiune) {
	if (dimensiune > 0) {
		int rez = cod * strlen(nume);
		return rez % dimensiune;
	}
	return -1;
}

void inserareLaFinal(nod** cap, Galerie g) {
	nod* temp = (nod*)malloc(sizeof(nod));
	temp->info = g;
	temp->next = NULL;
	if (*cap) {
		nod* aux = *cap;
		while (aux->next) {
			aux = aux->next;
		}
		aux->next = temp;
	}
	else {
		*cap = temp;
	}
}

void inserareGalerieTabela(HashTable h,Galerie g) {
	if (h.dim > 0) {
		int pozitie = calculHash(g.cod, g.nume, h.dim);
			if (h.vector[pozitie] != NULL) {
				inserareLaFinal(&(h.vector[pozitie]), g);
			}
			else {
				inserareLaFinal(&(h.vector[pozitie]), g);
			}
		
	}
}

void afisareGalerie(Galerie g) {
	printf("%d. Intrarea la galeria %s costa %.2f\n",g.cod,g.nume,
		g.pretIntrare);
}

void afisareListaGalerii(nod* cap) {
	while (cap) {
		printf(" ");
		afisareGalerie(cap->info);
		cap = cap->next;
	}
}

void afisareTabela(HashTable tabela) {
	for (int i = 0;i < tabela.dim;i++) {
		if (tabela.vector[i] != NULL) {
			printf("Clusterul: %d\n", (i + 1));
			afisareListaGalerii(tabela.vector[i]);
		}
	}
}

Galerie cautaGalerieDupaCheie(int cod, const char* nume, HashTable tabela) {
	int pozitie = calculHash(cod, nume, tabela.dim);
	if (pozitie >= 0 && pozitie < tabela.dim) {
		nod* p = tabela.vector[pozitie];
		while (p && p->info.cod != cod && strcmp(p->info.nume,nume != 0)) {
			p = p->next;
		}
		if (p) {
			return p->info;
		}
		else {
			return initGalerie(-1, "NONAME", 0);
		}
	}
	else {
		return initGalerie(-1, "NONAME", 0);

	}
}

void main() {
	Galerie g1 = initGalerie(1, "Orizont", 10);
	Galerie g2 = initGalerie(2, "Cercul armatei", 6);
	Galerie g3 = initGalerie(3, "Louvre", 30);
	Galerie g4 = initGalerie(4, "Istorie", 3);
	Galerie g5 = initGalerie(5, "Geologie", 4);
	Galerie g6 = initGalerie(6, "Antipa", 15);
	HashTable tabela = initializareHashTable(5);
	inserareGalerieTabela(tabela, g1);
	inserareGalerieTabela(tabela, g2);
	inserareGalerieTabela(tabela, g3);
	inserareGalerieTabela(tabela, g4);
	inserareGalerieTabela(tabela, g5);
	inserareGalerieTabela(tabela, g6);
	afisareTabela(tabela);
	Galerie g = cautaGalerieDupaCheie(6, "Antipa", tabela);
	afisareGalerie(g);
}