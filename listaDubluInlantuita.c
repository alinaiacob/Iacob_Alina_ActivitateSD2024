//#define _CRT_SECURE_NO_WARNINGS
//#include<stdio.h>
//#include<stdlib.h>
//
//typedef struct Librarie Librarie;
//struct Librarie {
//	char* nume;
//	int nrCarti;
//	float suprafata;
//};
//
//typedef struct Nod Nod;
//
//struct Nod {
//	Librarie info;
//	Nod* next;
//};
//typedef struct NodLdi NodLdi;
//
//struct NodLdi {
//	Librarie info;
//	NodLdi* prev;
//	NodLdi* next;
//};
//
//struct ListaDubla {
//	NodLdi* prim;
//	NodLdi* ultim;
//};
//
//struct ListaDubla inserareInceputLdi(struct ListaDubla lista, Librarie librarie) {
//	NodLdi* nou = malloc(sizeof(NodLdi));
//	nou->info = librarie;
//	nou->next = lista.prim;
//	nou->prev = NULL;
//	if (lista.prim) {
//	//	*((lista.prim)).prev = nou;
//		lista.prim->prev = nou;
//	}
//	else {
//		lista.ultim = nou;
//	}
//	lista.prim = nou;
//	return lista;
//}
//Nod* inserareInceput(Nod* cap, Librarie l) {
//	Nod* nou = (Nod*)malloc(sizeof(Nod));
//	nou->info = l;
//	nou->next = cap;
//	return nou;
//}
//
//Librarie initializeazaLibrarie(const char* nume, int nrCarti, float suprafata) {
//	Librarie l;
//	l.nrCarti = nrCarti;
//	l.suprafata = suprafata;
//	l.nume = (char*)malloc((strlen(nume) + 1) * sizeof(char);
//	strcpy(l.nume, nume);
//	return l;
//}
//
//void afisareLibrarie(Librarie l) {
//	printf("Libraria %s are %d carti si suprafata de %f mp\n", l.nume, l.nrCarti, l.suprafata);
//
//}
//
//void afisareLdi(struct ListaDubla lista) {
//	while (lista.prim) {
//		afisareLibrarie(lista.prim->info);
//		lista.prim = lista.prim->next;
//	}
//}
//
//void afisareLista(Nod* cap) {
//	while (cap != NULL) {
//		afisareLibrarie(cap->info);
//		cap = cap->next;
//	}
//}
//
//void inserareFinal(Nod** primNod, Librarie l) {
//	if (*primNod != NULL) {
//		Nod* aux = *primNod;
//		while (aux->next != NULL) {
//			aux = aux->next;
//		}
//		Nod* nou = (Nod*)malloc(sizeof(Nod));
//		nou->info = l;
//		nou->next = NULL;
//		aux->next = nou;
//	}
//	else {
//		*primNod = malloc(sizeof(Nod));
//		(*primNod)->info = l;
//		(*primNod)->next = NULL;
//	}
//}
//
//struct ListaDubla inserareSfarsitLdi(struct ListaDubla lista, Librarie librarie) {
//	NodLdi* nou = malloc(sizeof(NodLdi));
//	nou->next = NULL;
//	nou->prev = lista.ultim;
//	nou->info = librarie;
//	if (lista.ultim != NULL) {
//		lista.ultim->next = nou;
//
//	}
//	else {
//		lista.prim = nou;
//
//	}
//	lista.ultim = nou;
//	return lista;
//}
//
//int contorizareLDi(struct ListaDubla lista) {
//	int contor = 0;
//	while (lista.prim) {
//		contor += 1;
//		lista.prim = lista.prim->next;
//	}
//	return contor;
//}

#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

typedef struct Restaurant Restaurant;
struct Restaurant {
	int id;
	char* numeleRestaurantului;
	int nrStrazii;

};
struct Restaurant initRestaurant(int id,const char* nume, int nrStrazii) {
	struct Restaurant restaurant;
	restaurant.id = id;
	restaurant.numeleRestaurantului = (char*)malloc(strlen(nume) + 1); strcpy(restaurant.numeleRestaurantului, nume);
	restaurant.nrStrazii = nrStrazii;
	return restaurant;

}
void afiseazaRestaurant(struct Restaurant restaurant) {
	printf("Numele restaurantului: %s ,care are id-ul %d si care este pe strada %d\n", restaurant.numeleRestaurantului, restaurant.id, restaurant.nrStrazii);
}
typedef struct Node Node;
struct Node {
	Restaurant info;
	//Node* prev;
	Node* next;

};
typedef struct NodLdi NodLdi;
struct NodLdi {
	Restaurant info;
	NodLdi* next;
	NodLdi* prev;


};
typedef struct ListaDubla ListaDubla;
struct ListaDubla {
	NodLdi* prim;
	NodLdi* ultim;
};

Node* adaugareInceput(Node* cap, Restaurant r) {
	Node* n = (Node*)malloc(sizeof(Node));
	n->info = r;
	n->next = cap;
	return n;
}
void adaugareFinal(Node** cap, Restaurant r) {
	Node* n = malloc(sizeof(Node));
	n->info = initRestaurant(r.id, r.numeleRestaurantului, r.nrStrazii);
	n->next = NULL;

	if (*cap != NULL) {
		Node* aux = *cap;
		while (aux->next) {
			aux = aux->next;
		}
		aux->next = n;
	}
	else {
		*cap = n;
	}
}
void inserareListaDublaSfarsit(ListaDubla* listaDubla, Restaurant r) {
	NodLdi* nod = malloc(sizeof(NodLdi));
	nod->prev = listaDubla->ultim;
	nod->next = NULL;
	nod->info = initRestaurant(r.id, r.numeleRestaurantului, r.nrStrazii);
	if (listaDubla->ultim != NULL) {
		listaDubla->ultim->next = nod;
	}
	else {
		listaDubla->prim = nod;
	}
	listaDubla->ultim = nod;
}

void inserareListaDublaInceput(ListaDubla* listaDubla, Restaurant r) {
	NodLdi* nod = malloc(sizeof(NodLdi));
	nod->info = initRestaurant(r.id, r.numeleRestaurantului, r.nrStrazii);
	nod->prev = NULL;
	nod->next = listaDubla->prim;
    
	if (listaDubla->prim) {
		listaDubla->prim->prev = nod;
		listaDubla->prim = nod;
	}
	else {
		listaDubla->prim = listaDubla->ultim = nod;
	}

}

void afisareLista(Node* cap) {
	while (cap) {
		afiseazaRestaurant(cap->info);
		cap = cap->next;
	}
}

void stergereLista(Node** cap) {
	while (*cap) {
		free((*cap)->info.numeleRestaurantului);
		Node* aux;
		aux = (*cap)->next;
		free((*cap));
		(*cap) = aux;
	}
}

void afisareListaDublaDeLaSfarsit(ListaDubla listaRestaurante) {
	NodLdi* p = listaRestaurante.ultim;
	while (p) {
		afisareRestaurant(p->info);
		p = p->prev;
	}
}
void stergereListaDubla(ListaDubla* listaRestaurante) {
	NodLdi* p = listaRestaurante->prim;
	while (p) {
		free(p->info.numeleRestaurantului);
		NodLdi* temp = p->next;
		free(p);
		p = temp;
	}
	listaRestaurante->prim = NULL;
	listaRestaurante->ultim = NULL;
}

//struct Node* addToEmpty(struct Node* head, struct Restaurant r) {
//	struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
//	temp->prev = NULL;
//	temp->info = initRestaurant(r.id, r.numeleRestaurantului, r.nrStrazii);
//	temp->next = NULL;
//	head = temp;
//	return head;
//}
//struct Node* addAtBeg(struct Node* head, struct Restaurant r) {
//	struct Node* temp = malloc(sizeof(Node));
//	temp->prev = NULL;
//	temp->info = initRestaurant(r.id, r.numeleRestaurantului, r.nrStrazii);
//	temp->next = NULL;
//	head->prev = temp;
//	head = temp;
//	return head;
//}
//
//void parcurgeLista(struct Node* lista) {
//	while (lista) {
//		afiseazaRestaurant(lista->info);
//		lista = lista->next;
//	}
//}
void main() {
	//struct Restaurant r1 = initRestaurant(1, "Ave Forchetta", 20);
	//struct Restaurant r2 = initRestaurant(2, "Van Gogh", 50);
	////afiseazaRestaurant(r1);
	//struct Node* head = NULL;
	////head = addToEmpty(head, r1);
	//head = addAtBeg(head, r2);
	//head = addAtBeg(head, r1);
	//parcurgeLista(head);
	//afiseazaRestaurant(head->info);
}