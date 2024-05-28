////#define _CRT_SECURE_NO_WARNINGS
////#include<stdio.h>
////#include<stdlib.h>
////#include<string.h>
////
////struct Librarie {
////	char* nume;
////	int nr_carti;
////	float suprafata;
////
////};
////
////typedef struct Nod Nod;
////struct Nod {
////	Librarie info;
////	Nod* next;
////};
////
////
////
////Librarie initializeazaLibrarie(const char* nume, int nr_carti, float suprafata) {
////	Librarie l;
////	l.nr_carti = nr_carti;
////	l.suprafata = suprafata;
////	l.nume = (char*)malloc((strlen(nume) + 1) * sizeof(char));
////	strcpy(l.nume, nume);
////	return l;
////}
////void afisareLibrarie(Librarie l) {
////	printf("Libraria %s are %d carti si suprafata de %f mp\n", l.nume, l.nr_carti, l.suprafata);
////
////}
////void afisareLista(Nod* cap) {
////	while (cap != NULL) {
////		afisareLibrarie((*cap).info);
////		cap = (*cap).next;
////	}
////}
////void inserareFinal(Nod** primNod, Librarie l) {
////	if (*primNod != NULL) {
////		Nod* aux = *primNod;
////		while ((*aux).next != NULL) {
////			aux = (*aux).next;
////		}
////		Nod* nou = (Nod*)malloc(sizeof(Nod));
////		(*nou).info = l;
////		(*nou).next = NULL;
////		(*aux).next = nou;
////	}
////	else {
////		*primNod = (Nod*)malloc(sizeof(Nod));
////		(*primNod)->info = l;
////		(*primNod)->next = NULL;
////
////	}
////}
////void inserareFinal2(Nod** primNod, Librarie l) {
////	if (*primNod != NULL) {
////		Nod* aux = *primNod;
////		while ((*aux).next != NULL) {
////			aux = aux->next;
////		}
////		Nod* nou = (Nod*)malloc(sizeof(Nod));
////		nou->info = l;
////		nou->next = NULL;
////		aux->next = nou;
////	}
////	else {
////		*primNod = (Nod*)malloc(sizeof(Nod));
////		(*primNod)->info = l;
////		(*primNod)->next = NULL;
////	}
////}
////
////void inserareFinal3(Nod** primNod, Librarie l) {
////	if (*primNod != NULL) {
////		Nod* aux = *primNod;
////		while (aux->next != NULL) {
////			aux = aux->next;
////		}
////		Nod* nou = (Nod*)malloc(sizeof(Nod));
////		nou->info = l;
////		nou->next = NULL;
////		aux->next = nou;
////	}
////	else {
////		*primNod = (Nod*)malloc(sizeof(Nod));
////		(*primNod)->info = l;
////		(*primNod) -> next = NULL;
////	}
////}
////struct Nod* insereazaInceput(Nod* cap, Librarie l) {
////	Nod *nod = (struct Nod*)malloc(sizeof(Nod));
////	nod->info = l;
////	nod->next = cap;
////	return nod;
////}
////Nod* inserareInceput(Nod* cap, Librarie l) {
////	Nod* nou = (Nod*)malloc(sizeof(Nod));
////	nou->info = l;
////	//	(*nou).info = l;
////	(*nou).next = cap;
////	return nou;
////}
////void main() {
////	Librarie l, l2,l3;
////	l = initializeazaLibrarie("Carturesti", 500, 200);
////	l2 = initializeazaLibrarie("Humanitas", 820, 350);
////	l3 = initializeazaLibrarie("Mihai Eminescu", 200, 50);
////	Nod* cap = NULL;
////	cap=inserareInceput(cap, l);
////	cap = insereazaInceput(cap, l2);
////	inserareFinal2(&cap, l3);
////	afisareLista(cap);
////}
//
////struct Nod* inseInceput(Nod* cap, Librarie l) {
////	Nod* nou = (Nod*)malloc(sizeof(Nod));
////	nou->info = l;
////	nou->next = cap;
////	return nou;
////}
////
////
////struct Nod* ins(Nod* cap, Librarie l) {
////	Nod* nou = (Nod*)malloc(sizeof(Nod));
////	nou->info = l;
////	nou->next = cap;
////	return nou;
////}
////
////void afisareLista(Nod* cap) {
////	while (cap != NULL) {
////		afisareLibrarie(cap->info);
////		cap = cap->next;
////	}
////}
//
//#define _CRT_SECURE_NO_WARNINGS
//#include<stdio.h>
//#include<string.h>
//#include<stdlib.h>
//
//
//struct Carte {
//	int id;
//	char* titlul;
//	int nrPagini;
//};
//typedef struct Nod;
//struct Nod {
//	struct Carte info;
//	struct Nod* next;
//};
//struct Carte initializeazaCarte(int id, const char* titlul, int nrPagini) {
//	struct Carte cartea;
//	cartea.id = id;
//	cartea.nrPagini = nrPagini;
//	cartea.titlul = (char*)malloc(strlen(titlul) + 1);
//	strcpy(cartea.titlul, titlul);
//	return cartea;
//}
//void afiseazaCartea(struct Carte carte) {
//	printf("Cartea %s are id-ul %d si are %d pagini\n", carte.titlul, carte.id, carte.nrPagini);
//}
//void afiseazaLista(struct Nod* cap) {
//	while (cap != NULL) {
//		afiseazaCartea(cap->info);
//		cap = cap->next;
//	}
//}
//struct Nod* insereazaInceput(struct Nod* cap,struct Carte carte) {
//	struct Nod* nou = (struct Nod*)malloc(sizeof(struct Nod));
//	nou->info = carte;
//	nou->next = cap;
//	return nou;
//}
//void insereazaFinal(struct Nod** cap, struct Carte carte) {
//	if (*cap != NULL) {
//		struct Nod* aux = *cap;
//		while (aux->next != NULL) {
//			aux = aux->next;
//		}
//		struct Nod* nou = (struct Nod*)malloc(sizeof(struct Nod));
//		nou->info = carte;
//		nou->next = NULL;
//		aux->next = nou;
//	}
//	else {
//		* cap= (struct Nod*)malloc(sizeof(struct Nod));
//		(*cap)->info = carte;
//		(*cap)->next = NULL;
//		
//	}
//	
//
//}
////void inserareFinal3(Nod** primNod, Librarie l) {
////	if (*primNod != NULL) {
////		Nod* aux = *primNod;
////		while (aux->next != NULL) {
////			aux = aux->next;
////		}
////		Nod* nou = (Nod*)malloc(sizeof(Nod));
////		nou->info = l;
////		nou->next = NULL;
////		aux->next = nou;
////	}
////	else {
////		*primNod = (Nod*)malloc(sizeof(Nod));
////		(*primNod)->info = l;
////		(*primNod) -> next = NULL;
////	}
////}
//
//void main() {
//	struct Nod* cap=NULL;
//	struct Carte c1=initializeazaCarte(1, "Mandrie si prejudecata", 400);
//	struct Carte c2 = initializeazaCarte(2, "La rascruce de vanturi", 700);
//	cap = insereazaInceput(cap,c1);
//	insereazaFinal(&cap, c2);
//	afiseazaLista(cap);
//
//}

//#define _CRT_SECURE_NO_WARNINGS
//#include<stdio.h>
//#include<stdlib.h>
//
//struct Preparat {
//	int id;
//	char* numele;
//	int nrCalorii;
//};
//typedef struct Nod Nod;
//
//struct Nod {
//	struct Preparat info;
//	Nod* next;
//};
//struct Nod* adaugaInFata(Nod* cap, struct Preparat preparat) {
//	Nod* nou = (struct Nod*)malloc(sizeof(struct Nod*));
//	(*nou).info = preparat;
//	(*nou).next = cap;
//	return nou;
//}
//void adaugaLaFinal(struct Nod** final, struct Preparat preparat) {
//	if (*final != NULL) {
//		Nod* aux = *final;
//		while (aux->next != NULL) {
//			aux = aux->next;
//		}
//		Nod* nou = (struct Nod*)malloc(sizeof(struct Nod*));
//		nou->info = preparat;
//		nou->next =NULL;
//		aux->next = nou;
//	}
//	else {
//		*final = (struct Nod*)malloc(sizeof(struct Nod*));
//		(*final)->info = preparat;
//		(*final)->next = NULL;
//	}
//}
//
//struct Preparat initPreparat(int id, const char* nume, int nrCalorii) {
//	struct Preparat preparat;
//	preparat.id = id;
//	preparat.numele = (char*)malloc(strlen(nume) + 1);
//	strcpy(preparat.numele, nume);
//	preparat.nrCalorii = nrCalorii;
//	return preparat;
//}
//void afiseazaPreparat(struct Preparat p) {
//	printf("Numele preparatului %s are id-ul %d si are %d calorii\n", p.numele, p.id, p.nrCalorii);
//}
//void afiseazaLista(Nod* nod) {
//	while (nod!=NULL) {
//		afiseazaPreparat(nod->info);
//		nod = nod->next;
//	}
//}
//
//void main() {
//	struct Preparat preparat = initPreparat(1, "Tiramisu", 100);
//	struct Preparat preparat2 = initPreparat(2, "Tagliatele", 100);
//	struct Preparat preparat3 = initPreparat(3, "Steak", 1000);
//	//afiseazaPreparat(preparat);
////	afiseazaPreparat(preparat);
//	Nod* nod = NULL;
//	nod=adaugaInFata(nod, preparat);
//	//afiseazaPreparat(nod->info);
//	nod=adaugaInFata(nod, preparat2);
//	adaugaLaFinal(&nod, preparat3);
//	afiseazaLista(nod);
//}

#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>


struct Strada {
	int id;
	char* numeleStrazii;
	int nr;
};

typedef struct Node Node;
struct Node {
	struct Strada strada;
	struct Node* next;
};
struct Strada initStrada(int id, const char* numeleStrazii, int nr) {
	struct Strada strada;
	strada.id = id;
	strada.numeleStrazii = (char*)malloc(strlen(numeleStrazii) + 1);
	strcpy(strada.numeleStrazii, numeleStrazii);
	strada.nr = nr;
	return strada;
}
void afiseazaStrada(struct Strada strada) {
	printf("Id-ul strazii: %d ,numele strazii: %s,nr strazii: %d\n", strada.id, strada.numeleStrazii, strada.nr);
}
struct Node* adaugaInceput(struct Node* inceputul, struct Strada strada) {
	struct Node* nou = (struct Node*)malloc(sizeof(struct Node*));
	nou->next = inceputul;
	nou->strada = strada;

	return nou;
}

void afiseazaLista(struct Node* node) {
	while (node != NULL) {
		afiseazaStrada(node->strada);
		node = node->next;
	}
}
void main() {
	struct Strada s1 = initStrada(1, "Calea Victoriei", 100);
	struct Strada s2 = initStrada(2, "Piata Romana", 20);
	struct Strada s3 = initStrada(3, "Piata Unirii", 10);
	struct Node* node = NULL;
	node = adaugaInceput(node, s1);


	node = adaugaInceput(node, s2);
  
	afiseazaLista(node);

}