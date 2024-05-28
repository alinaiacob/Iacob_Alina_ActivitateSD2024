#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>



typedef struct Librarie Librarie;
typedef struct Nod Nod;
typedef struct NodLi NodLi;
typedef struct ListaDubla ListaDubla;

struct Librarie {
	int id;
	char* numeLibrarie;
	int nrStrazii;
};

Librarie initLibrarie(int id, const char* numeLibrarie, int nrStrazii) {
	Librarie librarie;
	librarie.id = id;
	librarie.numeLibrarie = (char*)malloc(strlen(numeLibrarie) + 1);
	strcpy(librarie.numeLibrarie, numeLibrarie);
	librarie.nrStrazii = nrStrazii;
	return librarie;
}

struct Nod {
	Librarie info;
	Nod* prev;
	Nod* next;
};
struct ListaDubla {
	Nod* cap;
	Nod* coada;
};



void dezalocaNod(Nod** nod) {
	while (*nod != NULL) {
		free((*nod)->info.numeLibrarie);
		*nod = (*nod)->next;
	}
	free(*nod);
	*nod = NULL;
}

void insereazaNodLaInceput(Nod** nodul, Librarie l) {
	Nod* primul = (Nod*)malloc(sizeof(Nod));
	primul->info = initLibrarie(l.id, l.numeLibrarie, l.nrStrazii);//deep copy
	
	if (*nodul == NULL) {
		primul->next = NULL;
		*nodul = primul;
	}
	else {
		primul->next = *nodul;
		*nodul = primul;
	}
}

void insereazaNodLaFinal(Nod** nodul,Librarie l) {
	Nod* ultimul = (Nod*)malloc(sizeof(Nod));
	ultimul->info = initLibrarie(l.id, l.numeLibrarie, l.nrStrazii);
	ultimul->next = NULL;
	if (*nodul != NULL) {
			while ((*nodul)->next != NULL) {
				*nodul = (*nodul)->next;

			}
	}
	else {
		(*nodul)= ultimul;
	}

	
}

void afiseazaLibrarie(Librarie librarie) {
	printf("Libraria %s are id-ul %d si este pe strada cu nr %d\n", librarie.numeLibrarie, librarie.id, librarie.nrStrazii);

}
void afiseazaNodul(Nod* nodul) {
	while (nodul != NULL) {
		if (nodul != NULL) {
			afiseazaLibrarie((nodul)->info);
			nodul = (nodul)->next;
		}
		
	}
}


int librariiEgale(Librarie l1, Librarie l2) {
	int ok = 1;
	if (l1.id != l2.id || strcmp(l1.numeLibrarie, l2.numeLibrarie) != 0 || l1.nrStrazii != l2.nrStrazii)ok = 0;
	return ok;
}
void stergeLibrarie(Nod** nodul,Librarie l) {
	Nod* aux = *nodul;
	while ((*nodul) != NULL) {
		if (librariiEgale((*nodul)->info,l)==1){
			free((aux)->info.numeLibrarie);
			//free(aux);
			if ((*nodul)->next == NULL) {
				free(*nodul);
				printf("\nhi");
			}
			else {
				*nodul = (*nodul)->next;
				printf("\nhi else");
			}
			printf("\nhi ---");
		}
		else {
			*nodul = (*nodul)->next;
		}
		
	}

}

Nod* adaugaLibrarieDupaUnaData(Nod* nodul, Librarie l1, Librarie l2) {
	Nod* aux = nodul;
	while (aux != NULL) {
		if (librariiEgale(aux->info, l1)) {
			Nod* nodNou = (Nod*)malloc(sizeof(Nod));
			nodNou->info = initLibrarie(l2.id, l2.numeLibrarie, l2.nrStrazii);
			nodNou->next = aux->next;
			aux->next = nodNou;
			return nodul; // Returnează lista nemodificată
		}
		aux = aux->next;
	}
	return nodul; // Returnează lista nemodificată dacă nu s-a găsit l1
}






//Nod* adaugaLibrarieUnaDupaAlta(Nod* nodul, Librarie l1, Librarie l2) {
//	Nod* aux = nodul;
//}
//
//struct NodLi {
//	Nod* primul;
//	Nod* ultimul;
//};
//
//
//
//void adaugaNodFinal(NodLi **nodul, Librarie l) {
//	if ((*nodul)->primul==NULL && (*nodul)->ultimul==NULL) {
//		Nod* noul = (Nod*)malloc(sizeof(Nod));
//		noul->info = initLibrarie(l.id, l.numeLibrarie, l.nrStrazii);
//		noul->next = NULL;
//		
//		(*nodul)->primul = noul;
//		(*nodul)->primul->next = (*nodul)->ultimul;
//		(*nodul)->ultimul = noul;
//	}
//	else if ((*nodul)->primul != NULL && (*nodul)->ultimul != NULL) {
//		Nod* noul = (Nod*)malloc(sizeof(Nod));
//		noul->info = initLibrarie(l.id, l.numeLibrarie, l.nrStrazii);
//		noul->next = NULL;
//		NodLi* aux = *nodul;
//		printf("\n-----hi");
//		//(*nodul)->primul->next = noul;
//		(*nodul)->ultimul = noul;
//		(*nodul)->ultimul->next = noul;
//	}
//}
//
//void adaugaNodFinall(NodLi** nodul, Librarie l) {
//	Nod* noul = (Nod*)malloc(sizeof(Nod));
//	noul->info = initLibrarie(l.id, l.numeLibrarie, l.nrStrazii);
//	noul->next = NULL;
//
//	if ((*nodul)->primul == NULL && (*nodul)->ultimul == NULL) {
//		// Lista este goală
//		(*nodul)->primul = noul;
//		(*nodul)->ultimul = noul;
//	}
//	else {
//		// Lista nu este goală
//		(*nodul)->ultimul->next = noul;
//		(*nodul)->ultimul = noul;
//	}
//}
//
//void adaugaNodInceput(NodLi** nodul, Librarie l) {
//	Nod* noul = (Nod*)malloc(sizeof(Nod));
//	noul->info = initLibrarie(l.id, l.numeLibrarie, l.nrStrazii);
//	noul->next = NULL;
//	if ((*nodul)->primul == NULL && (*nodul)->ultimul == NULL) {
//		(*nodul)->primul = noul;
//		(*nodul)->ultimul = noul;
//	}
//	else {
//		Nod* prim = (*nodul)->primul;
//		(*nodul)->primul->next = noul;
//		(*nodul)->primul
//	}
//}

//void afiseazaListaDublu(NodLi* nodul) {
//	while (nodul->primul != NULL) {
//		afiseazaLibrarie((nodul->primul)->info);
//		nodul->primul = nodul->primul->next;
//	}
//}

void afiseazaListaDubla(ListaDubla lista) {
	while ((lista).cap) {
		afiseazaLibrarie((lista).cap->info);
		(lista).cap = (lista).cap->next;
	}
}

void afiseazaLista(ListaDubla lista) {
	while ((lista.cap)) {
		afiseazaLibrarie((lista).cap->info);
		lista.cap = (lista).cap->next;
	}
}

void adaugaNodLaInceput(ListaDubla* lista, Librarie l) {
	Nod* nod = (Nod*)malloc(sizeof(Nod));
	nod->prev = NULL;
	nod->next = (lista)->cap;
	nod->info = initLibrarie(l.id, l.numeLibrarie, l.nrStrazii);

	if ((lista)->cap == NULL) {

		(lista)->coada = nod;
	}
	else {
		(lista)->cap->prev = nod;
	}
	(lista)->cap = nod;
}


void adaugaNodLaFinal(ListaDubla* lista, Librarie l) {
	Nod* nod = (Nod*)malloc(sizeof(Nod));
	nod->prev = (lista)->coada;
	nod->next = NULL;
	nod->info = initLibrarie(l.id, l.numeLibrarie, l.nrStrazii);
	if (lista->coada == NULL) {
		lista->cap = nod;
	}
	else {
		lista->coada->next = nod;
		//lista->coada->prev=lista->coada->
	}

	lista->coada = nod;
}

char* afiseazaLibrariaCuCelMaiMareId(ListaDubla list) {
	if (list.cap == NULL) {
		return "-";
	}
	else {
		char* c = malloc(strlen("-") + 1); strcpy(c, "-");

		int max = 0;
		while (list.cap!=NULL) {
			if (max < list.cap->info.id) {
				max = list.cap->info.id;
				free(c);
				c = malloc(strlen(list.cap->info.numeLibrarie) + 1);
				strcpy(c, list.cap->info.numeLibrarie);
			}
			list.cap = list.cap->next;
		}
		return c;
	}
}

void adaugaNodLaInceput2(ListaDubla* lista, Librarie l) {
	Nod* nod = (Nod*)malloc(sizeof(Nod));
	nod->prev = NULL;
	nod->next = (lista->cap);
	nod->info = initLibrarie(l.id, l.numeLibrarie, l.nrStrazii);
	if ((lista)->cap == NULL) {
		lista->coada = nod;
	}
	else {
		lista->cap->prev = nod;
	}

	lista->cap = nod;
}
void dezalocaListaDubla(ListaDubla* lista) {
	while ((lista)->cap != NULL) {
		free(lista->cap->info.numeLibrarie);
		free(lista->cap->prev);
		lista->cap = lista->cap->next;
	}
}



void main() {
	Librarie l1 = initLibrarie(1, "Carturesti", 20);
	Librarie l2 = initLibrarie(2, "Humanitas", 21);
	Librarie l4 = initLibrarie(4, "M E", 23);
	Librarie l3 = initLibrarie(3, "Mihai Eminescu", 22);



	ListaDubla lista;
	lista.cap = NULL;
	lista.coada = NULL;
	adaugaNodLaInceput(&lista, l1);
	adaugaNodLaFinal(&lista, l2);
	adaugaNodLaFinal(&lista, l3);
	
	//adaugaNodLaInceput2(&lista, l3);
	afiseazaListaDubla(lista);
	char* nume = afiseazaLibrariaCuCelMaiMareId(lista);
	printf("%s ", nume);
	dezalocaListaDubla(&lista);
	free(nume);
	afiseazaLista(lista);
}