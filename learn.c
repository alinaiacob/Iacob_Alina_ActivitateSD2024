#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>


typedef struct Magazin Magazin;
//typedef struct Nod Nod;
//typedef struct NodLista NodLista;
//typedef struct ListaDubla ListaDubla;
//typedef struct HashTable HashTable;
//
struct Magazin {
	int nrMagazine;
	char* nume;
};
//struct NodLista {
//	Magazin info;
//	NodLista* prev;
//	NodLista* next;
//};
//
//struct ListaDubla {
//	NodLista* primul;
//	NodLista* ultimul;
//};
//struct Nod {
//	Magazin info;
//	Nod* next;
//};


//void adaugareNodSfarsit(Nod** noduri, Magazin magazin) {
//	Nod* final = (Nod*)malloc(sizeof(Nod));
//	final->info = initMagazin(magazin.nrMagazine, magazin.nume);
//	final->next = NULL;
//	Nod* aux = *noduri;
//	if (*noduri!=NULL) {
//		while (aux->next) {
//			aux = aux->next;
//		}
//		aux->next = final;
//	}
//	else {
//		*noduri = final;
//	}
//	
//}
//void afisareLista(Nod * lista) {
//	while (lista) {
//		if(lista){
//			afisareMagazin(lista->info);
//			lista = lista->next;
//		}
//
//	}
//}
//
//void dezalocaLista(Nod **lista) {
//
//	while (*lista) {
//		Nod* aux = *lista;
//		*lista = (*lista)->next;
//		free(aux->info.nume);
//		free(aux);
//		
//		 
//	}
//	free(*lista);
//}

//char* numeleMagazinuluiCuMulteMagazine(Nod* lista) {
//	int maxim = 0;
//	char* nume = (char*)malloc(sizeof(char)*2);
//	strcpy(nume, "-");
//	while (lista) {
//		if (lista->info.nrMagazine > maxim) { 
//			maxim = lista->info.nrMagazine;
//		if (nume != NULL);
//				free(nume);
//			nume = (char*)malloc(strlen(lista->info.nume) + 1);
//			strcpy(nume, lista->info.nume);
//		}
//		lista = lista->next;
//	}
//	return nume;
//}
//int egalitateMagazine(Magazin m1, Magazin m2) {
//	if (m1.nrMagazine != m2.nrMagazine || strcmp(m1.nume, m2.nume) != 0)return 0;
//	else return 1;
//}

//void stergereNod(Nod** noduri, Magazin m) {
//	while (*noduri != NULL) {
//		if (egalitateMagazine((*noduri)->info, m)) {
//			//Nod* curent = *noduri;]
//			if ((*noduri)->next == NULL) {
//				free((*noduri)->info.nume);
//				free((*noduri));
//			}
//			else {
//				Nod* curent = *noduri;
//                //curent->next
//			}
//
//		}
//	}
//}
//Nod* adaugaNodInceput(Nod** noduri, Magazin m) {
//	Nod* inceput = (Nod*)malloc(sizeof(Nod));
//	inceput->info = initMagazin(m.nrMagazine, m.nume);
//	inceput->next = *noduri;
//	return inceput;
//}
//
//void adaugareInListaLaInceput(ListaDubla* lista, Magazin magazin) {
//	NodLista* nod = (NodLista*)malloc(sizeof(NodLista));
//	nod->info = initMagazin(magazin.nrMagazine, magazin.nume);
//	nod->next = lista->primul;
//	nod->prev = NULL;
//
//	if (lista->primul == NULL) {
//		lista->ultimul = nod;
//	}
//	else {
//		lista->primul->prev = nod;
//	}
//	lista->primul = nod;
//
//
//}
//void adaugareListaFinal(ListaDubla* lista, Magazin m) {
//	NodLista* nod = (NodLista*)malloc(sizeof(NodLista));
//	nod->info = initMagazin(m.nrMagazine, m.nume);
//	nod->next = NULL;
//	nod->prev = lista->ultimul;
//
//	if (lista->ultimul == NULL) {
//		lista->primul = nod;
//	}
//	else {
//		lista->ultimul->next = nod;
//	}
//	lista->ultimul = nod;
//}
//void stergereNod(ListaDubla* lista, Magazin m) {
//	while (lista->primul) {
//		if (egalitateMagazine(lista->primul->info, m)) {
//			NodLista* nod = lista->primul;
//			if (nod->prev == NULL) {
//				nod->next->prev = NULL;
//				nod->next = nod;
//			}
//		}
//		lista->primul = lista->primul->next;
//		
//	}
//}

//ListaDubla stergeCafeneaDupaNume(ListaDubla listaDubla, const char* nume) {
//	if (nume == NULL) {
//		return listaDubla;
//	}
//	NodLista* nod = listaDubla.primul;
//	while (nod && strcmp(nod->info.nume, nume) != 0) {
//		nod = nod->next;
//	}
//	if (nod != NULL) {
//		if (nod->next == NULL && nod->prev == NULL) {
//			listaDubla.primul = NULL;
//			listaDubla.ultimul = NULL;
//		}
//	}
//	else if(nod->next==NULL) {
//		listaDubla.ultimul = nod->prev;
//		listaDubla.ultimul->next = NULL;
//	}
//	else {
//		nod->prev->next = nod->next;
//		nod->next->prev = nod->prev;
//	}
//}
//void afisareListaDubla(ListaDubla lista) {
//	while (lista.primul) {
//		afisareMagazin(lista.primul->info);
//		lista.primul = lista.primul->next;
//	}
//}
//struct HashTable {
//	int dimensiune;
//	Nod** vectori;
//};
//
//void dezalocaListaDubla(ListaDubla* lista) {
//	while (lista->primul) {
//		Nod* aux = lista->primul;
//		lista->primul = lista->primul->next;
//		free(aux->info.nume);
//		free(aux);
//
//	}
//	///free(*lista);
//}
//
//
Magazin initMagazin(int nrMagazine, const char* nume) {
	Magazin m;
	m.nrMagazine = nrMagazine;
	m.nume = (char*)malloc(strlen(nume) + 1); strcpy(m.nume, nume);
	return m;
}
void afisareMagazin(Magazin magazin) {
	printf("Magazinul se numeste %s si are %d magazine\n", magazin.nume, magazin.nrMagazine);
}
//
//
//
//void initHash(HashTable* h, int dimensiune) {
//	h->dimensiune = dimensiune;
//	h->vectori = (Nod**)malloc(sizeof(Nod*) * dimensiune);
//	for (int i = 0; i < dimensiune; i++)h->vectori[i] = NULL;
//}
//
//int calculHash(int dim,int nrMagazine, const char* numeMagazin) {
//	return (nrMagazine + strlen(numeMagazin)) % dim;
//}
//void insereazaMagazinNodFinal(Nod** noduri, Magazin m) {
//	Nod* final = (Nod*)malloc(sizeof(Nod));
//	final->info = initMagazin(m.nrMagazine, m.nume);
//	final->next = NULL;
//	if (*noduri == NULL)*noduri = final;
//	else {
//		Nod* aux = *noduri;
//		while (aux->next) {
//			if(aux)
//			aux = aux->next;
//		}
//		aux->next = final;
//	}
//}
//void adaugaMagazinHash(HashTable h, Magazin m) {
//	int dim = h.dimensiune;
//	int hashul = calculHash(dim, m.nrMagazine, m.nume);
//	insereazaMagazinNodFinal(&h.vectori[hashul], m);
//
//}
//void afiseazaHashTable(HashTable h) {
//	for (int i = 0; i < h.dimensiune; i++) {
//		printf("\nClusterul cu id-ul %d este : \n",i);
//		while (h.vectori[i]) {
//			afisareMagazin(h.vectori[i]->info);
//			h.vectori[i] = h.vectori[i]->next;
//		}
//	}
//}

void insereazaMagazinMatrice(Magazin** magazine, int* dim,Magazin m) {
	if (*magazine == NULL) {
		*magazine = (Magazin*)malloc(sizeof(Magazin));
		*magazine[0] = initMagazin(m.nrMagazine, m.nume);
		*dim = *dim + 1;
	}
	else {
		printf("----");
		Magazin *copieMagazine=  (Magazin*)malloc(sizeof(Magazin)*(*dim+1));
		for (int i = 0; i < *dim; i++) {
			copieMagazine[i] = initMagazin((*magazine)[i].nrMagazine, (*magazine)[i].nume);
		}
		copieMagazine[*dim]= initMagazin(m.nrMagazine, m.nume);
		free(*magazine);
		*magazine = copieMagazine;
		*dim = *dim + 1;
	}
}
void initMatrice(const char* numeFisier, Magazin** magazin, int elLinii, int *coloane) {
	if (numeFisier != NULL) {
		FILE* f = fopen(numeFisier, "r");
		if (f) {
			char buffer[100];
			char delimitator[] = ",\n";
			while (fgets(buffer, 100, f)) {
				char* token;
				token = strtok(buffer, delimitator);
				Magazin m;
				m.nrMagazine = atoi(token);
				token=strtok(NULL, delimitator);
				//printf("%s ", atoi(token));
				
				//token=strtok(NULL, delimitator);
				m.nume = (char*)malloc(sizeof(char)*(strlen(token) + 1)); 
				strcpy(m.nume,token);
				token = strtok(NULL, delimitator);

				int poz = m.nrMagazine % 2;
				insereazaMagazinMatrice(&(magazin[poz]), &(coloane[poz]), m);
				

			}
			fclose(f);
		}
	}
}
void afisareMatrice(Magazin** magazine, int nrLinii, int* nrColoane) {
	for (int i = 0; i < nrLinii; i++) {
	
		for (int j = 0; j < nrColoane[i]; j++) {
			afisareMagazin(magazine[i][j]);
		}
	}
}
void initMatrice2(const char* nume, Magazin** magazine,int nrLinii, int* coloane) {
	if (nume) {
		FILE* f = fopen(nume, "r");
		if (f) {
			char buffer[100];
			char delimitator[] = ",\n";
			while (fgets(buffer, 100, f)) {
				char* token;
				token = strtok(buffer, delimitator);
				Magazin m;
				m.nrMagazine = atoi(token);
				token = strtok(NULL, delimitator);
				m.nume = (char*)malloc(strlen(token) + 1);
				strcpy(m.nume, token);
				//token = strtok(NULL, delimitator);
				int poz = m.nrMagazine % 2;
				insereazaMagazinMatrice(&(magazine[poz]), &(coloane[poz]), m);
			}
			fclose(f);
		}
	}
}
void main() {
	Magazin m1 = initMagazin(20, "Sephora");
	Magazin m2 = initMagazin(22, "Douglas");
	Magazin m3 = initMagazin(24, "CCC");
	Magazin m4 = initMagazin(25, "Marionaud");
	int nrLinii=2;
	int* nrColoane = (int*)malloc(sizeof(int) * nrLinii);
	Magazin** matrice=(Magazin**)malloc(sizeof(Magazin*)*nrLinii);
	for (int i = 0; i < nrLinii; i++) {
		nrColoane[i] = 0;
		matrice[i] = NULL;
	}
	
	initMatrice2("magazine.txt", matrice, nrLinii, nrColoane);
	afisareMatrice(matrice, nrLinii, nrColoane);
	//int dim = 5;
	//HashTable h;
	//
	//initHash(&h, dim);
	//adaugaMagazinHash(h, m1);
	//afiseazaHashTable(h);

	/*Nod* nodul = NULL;
	adaugareNodSfarsit(&nodul, m1);
	adaugareNodSfarsit(&nodul, m2);
	adaugareNodSfarsit(&nodul, m3);

	nodul = adaugaNodInceput(&nodul, m4);

	afisareLista(nodul);
	char* nume = numeleMagazinuluiCuMulteMagazine(nodul);
	printf("%s ", nume);
	dezalocaLista(&nodul);
	afisareLista(nodul);*/

	/*ListaDubla listaDubla;
	listaDubla.primul = NULL; listaDubla.ultimul = NULL;
	adaugareInListaLaInceput(&listaDubla, m1);
	adaugareInListaLaInceput(&listaDubla, m2);
	adaugareInListaLaInceput(&listaDubla, m3);
	adaugareListaFinal(&listaDubla, m4);
	afisareListaDubla(listaDubla);
	dezalocaListaDubla(&listaDubla);
	afisareListaDubla(listaDubla);*/
}


