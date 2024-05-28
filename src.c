//#define _CRT_SECURE_NO_WARNINGS
//#include<stdio.h>
//#include<stdlib.h>
//
//
//typedef struct Restaurant Restaurant;
//struct Restaurant {
//	int id;
//	char* nume;
//	float profit;
//};
//struct Restaurant initRestaurant(int id, const char* nume, float profit) {
//	struct Restaurant r;
//	r.id = id;
//	r.profit = profit;
//	r.nume = malloc(strlen(nume) + 1); strcpy(r.nume, nume);
//	return r;
//}
//void afiseazaRestaurant(Restaurant r) {
//	printf("Restaurantul se numeste %s si are id-ul %d si face un profit de %.2f\n", r.nume, r.id, r.profit);
//}
//void afiseazaListaRestaurante(Restaurant*restaurante,int dim) {
//	for (int i = 0; i < dim; i++) {
//		afiseazaRestaurant(restaurante[i]);
//	}
//}
//struct Restaurant* gasesteRestauranteProfitabile(Restaurant* restaurante, int dim, int* newDim,float profitul) {
//	*newDim = 0;
//	for (int i = 0; i < dim; i++) {
//		if (restaurante[i].profit > profitul) {
//			(*newDim)++;
//		}
//	}
//	struct Restaurant* restauranteProfitabile;
//	
//
//	if ((*newDim) != 0) {
//		//struct Restaurant* restauranteProfitabile = (Restaurant*)malloc(sizeof(Restaurant) * (*newDim));
//		restauranteProfitabile = (Restaurant*)malloc(sizeof(Restaurant) * (*newDim));
//		int j = 0;
//		for (int i = 0; i < dim; i++) {
//			if (restaurante[i].profit > profitul) {
//				restauranteProfitabile[j++] = initRestaurant(restaurante[i].id, restaurante[i].nume, restaurante[i].profit);
//			}
//			
//		}
//	}
//	else {
//		restauranteProfitabile = (Restaurant*)malloc(sizeof(Restaurant));
//		*newDim = 1;
//		restauranteProfitabile[0] = initRestaurant(0, "-", 0);
//	}
//	return restauranteProfitabile;
//}
//void dezalocaMemorieRestaurant(Restaurant r) {
//	free(r.nume);
//	r.nume = NULL;
//}
//void dezalocaMemorieRestaurante(Restaurant* r, int dim) {
//	for (int i = 0; i < dim; i++) {
//		dezalocaMemorieRestaurant(r[i]);
//	}
//}
//void stergeRestauranteleNeprofitabile(Restaurant** restaurante, int* dim, float profitul) {
//	int contor = 0;
//	if ((*restaurante) != NULL) {
//		for (int i = 0; i < *dim; i++) {
//			if ((*restaurante)[i].profit < profitul) {
//				contor++;
//			}
//		}
//		if (contor != 0) { // Verifică dacă există restaurante de șters
//			Restaurant* temp = (Restaurant*)malloc(sizeof(Restaurant) * (*dim - contor)); // Alocă memorie pentru noul vector de restaurante profitabile
//			int j = 0;
//			for (int i = 0; i < *dim; i++) {
//				if ((*restaurante)[i].profit >= profitul) { // Copiază doar restaurantele profitabile în noul vector
//					temp[j++] = initRestaurant((*restaurante)[i].id,(*restaurante)[i].nume,(*restaurante)[i].profit);
//				}
//			}
//			// Dezalocă memoria pentru vectorul vechi de restaurante și actualizează dimensiunea
//			free(*restaurante);
//			*restaurante = temp;
//			*dim -= contor;
//		}
//	}
//	
//}
//
//struct Restaurant copiere(const struct Restaurant r) {
//	struct Restaurant aux;
//	aux.id = r.id;
//	aux.nume = malloc(strlen(r.nume) + 1);
//	strcpy(aux.nume, r.nume);
//	aux.profit = r.profit;
//	return aux;
//	///for(int i=0;i<r.)
//}
//
////sa imi dea numele restaurantului care face cel mai mare profit
//char* numeleRestaurantuluiProfitabil(Restaurant* restaurante, int dim) {
//	if ((restaurante) != NULL) {
//		float maxim = restaurante[0].profit;
//		int poz = 0;
//		for (int i = 1; i < dim; i++) {
//			if (maxim < restaurante[i].profit) { maxim = restaurante[i].profit; poz = i; }
//		}
//		return restaurante[poz].nume;
//	}
//	else return "nu exista";
//}
//struct Restaurant* adaugaRestaurantInVector(struct Restaurant* restaurante, struct Restaurant r, int* nr) {
//	*nr = *nr + 1;
//	struct Restaurant* aux = malloc(sizeof(Restaurant) * (*nr));
//	for (int i = 0; i < *nr - 1; i++) {
//		aux[i] = initRestaurant(restaurante[i].id, restaurante[i].nume, restaurante[i].profit);
//
//	}
//	aux[*nr - 1] = copiere(r);
//	return aux;
//}
//void adaugaRestaurantInVectorV(struct Restaurant** restaurante, struct Restaurant r, int* nr) {
//	*nr = *nr + 1;
//	struct Restaurant* aux = malloc(sizeof(Restaurant) * (*nr));
//	for (int i = 0; i < *nr - 1; i++) {
//		aux[i] = initRestaurant((*restaurante)[i].id, (*restaurante)[i].nume, (*restaurante)[i].profit);
//
//	}
//	aux[*nr - 1] = initRestaurant(r.id, r.nume, r.profit);
//	free(*restaurante); *restaurante = NULL;
//	*restaurante = aux;
//	//return aux;
//}
//struct Restaurant citireFisier(FILE* f) {
//	 Restaurant restaurant;
//	char buffer[30];
//	fscanf(f, "%d", &restaurant.id);
//
//	fscanf(f, "%s", buffer);
//    restaurant.nume = malloc(strlen(buffer) + 1);
//	strcpy(restaurant.nume, buffer);
//
//	fscanf(f, "%f", &restaurant.profit);
//	return restaurant;
//}
//struct Restaurant* citireVectorFisier(const char* numeFisier,int *nrRestaurante) {
//	FILE* f = fopen(numeFisier, "r");
//	struct Restaurant* restaurante;
//	fscanf(f, "%d", nrRestaurante);
//	restaurante = malloc(sizeof(Restaurant) * (*nrRestaurante));
//	for (int i = 0; i < (*nrRestaurante); i++) {
//		restaurante[i] = citireFisier(f);
//	}
//	return restaurante;
//
//}
//Restaurant** creeazaMatrice(Restaurant* restaurant, int** dimensiuni,int numarStructuri, int* nrCategorie) {
//	Restaurant** restaurante;
//	//aici ar fi trebuit sa stabilim nr de categorii
//	//a fost gasit nr 3
//	*nrCategorie = 2;
//	restaurante = malloc(sizeof(Restaurant*) * (*nrCategorie));
//	*dimensiuni = malloc(sizeof(int) * (*nrCategorie));
//	for (int i = 0; i < *nrCategorie; i++) {
//		(*dimensiuni)[i] = 0;
//		restaurante[i] = NULL;
//	}
//	for (int i = 0; i < numarStructuri; i++) {
//		int index=
//	}
//}
//void main() {
//	//Restaurant r1 = initRestaurant(1, "Ave Forchetta", 10000);
//	//Restaurant r2 = initRestaurant(2, "The Lobby", 20000);
//    Restaurant r4 = initRestaurant(3, "Van Gogh", 40000);
//	int dim = 3;
//	Restaurant *restaurante= (Restaurant*)malloc(sizeof(Restaurant) * dim);
//	restaurante[0] = initRestaurant(1, "Ave Forchetta", 10000);
//	restaurante[1] = initRestaurant(2, "The Lobby", 20000);
//	restaurante[2] = initRestaurant(3, "Resto Aperto", 30000);
//
//	int newDim;
//
//	//Restaurant* restauranteProfitabileVector = gasesteRestauranteProfitabile(restaurante, dim, &newDim, 10000);
//	//afiseazaListaRestaurante(restauranteProfitabileVector, newDim);
//	//stergeRestauranteleNeprofitabile(&restaurante, &dim, 12000);
//	//afiseazaListaRestaurante(restaurante, dim);
//	adaugaRestaurantInVectorV(&restaurante, r4, &dim);
//	//afiseazaListaRestaurante(restaurante, dim);
//	//FILE* f = fopen("restaurant.txt","r");
//	//Restaurant r5 = citireFisier(f);
//	//afiseazaRestaurant(r5);
//	//printf("%s", numeleRestaurantuluiProfitabil(restaurante, dim));
//	Restaurant* rr = citireVectorFisier("restaurant.txt", &newDim);
//	//printf("%d", newDim);
//	afiseazaListaRestaurante(rr, newDim);
//}


#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct Locuinta Locuinta;
struct Locuinta {
	int id;
	char* strada;
	int numar;
};

Locuinta initLocuinta(int id, const char* strada, int numar) {
	struct Locuinta locuinta;
	locuinta.id = id;
	locuinta.numar = numar;
	locuinta.strada = malloc(strlen(strada) + 1);
	return locuinta;
}
void afisareLocuinta(Locuinta l) {
	printf("Locuinta este pe strada: %s,are id-ul %d,si nr %d", l.strada, l.id, l.numar);
}
void afisareVectorLocuinte(struct Locuinta* vector, int dim) {
	for (int i = 0; i < dim; i++) {
		afisareLocuinta(vector[i]);
	}
}

void stergeLocuinta(struct Locuinta** vector, int* dim, int id) {
	char flag = 0;
	for (int i = 0; i < (*dim); i++) {
		if ((*vector)[i].id == id) {
			flag = 1;
			break;
		}
	}
	if (flag == 1) {
		struct Locuinta* copie = (struct Locuinta*)malloc(sizeof(Locuinta) * ((*dim) - 1));
		int j = 0;
		for (int i = 0; i < (*dim); i++) {
			if ((*vector)[i].id != id) {
				copie[j++] = (*vector)[i];
			}
		}
		(*dim)--;
		if ((*vector) != NULL) {
			free((*vector));
		}
		*vector = copie;
	}
}
void inserareLocuinta(struct Locuinta** vector, int* dim, Locuinta l) {
	Locuinta* copie;
	copie = malloc(sizeof(struct Locuinta) * (++(*dim)));
	for (int i = 0; i < (*dim); i++) {
		copie[i] = (*vector)[i];
	}
	copie[(*dim) - 1] = l;
	if ((*vector) != NULL) {
		free((*vector));
	}
	*vector = copie;
}
void citesteMatriceFisier(const char* numeFisier, struct Locuinta** matrice, int nrLinii, int* nrColoane) {
	if (numeFisier != NULL && strlen(numeFisier) > 0) {
		FILE* f = fopen(numeFisier, "r");
		if (f != NULL) {
			char buffer[100];
			char delimitator[] = ",\n";
			//*dim = 0;
			while (fgets(buffer, 100, f) != NULL){
				char* token;
				token = strtok(buffer, delimitator);

				struct Locuinta locuinta;
				locuinta.id = atoi(token);

				token = strtok(NULL, delimitator);
				locuinta.strada = (char*)malloc(strlen(token) + 1);
				strcpy(locuinta.strada, token);

				token = strtok(NULL, delimitator);
				locuinta.numar = atoi(token);
				int pozitie = locuinta.numar % 2;

				inserareLocuinta(&matrice[pozitie], &(nrColoane[pozitie]), locuinta);

			}
			fclose(f);
		}
	}
}

void afisareMatrice(Locuinta** matrice, int nrLinii, int* nrColoane) {
	for (int i = 0; i < nrLinii; i++) {
		for (int j = 0; j < nrColoane; j++)
			afisareLocuinta(matrice[i][j]);
		printf("\n");
	}
}




void main() {
	int nrLinii;
	int* nrColoane;
	struct Locuinta** locuinte;
	nrLinii = 2;
	nrColoane = (int*)malloc(sizeof(int) * nrLinii);
	locuinte = (struct Locuinta**)malloc(sizeof(Locuinta*) * nrLinii);
	for (int i = 0; i < nrLinii; i++) {
		locuinte[i] = NULL;
		nrColoane = 0;
	}
	citesteMatriceFisier("locuinte.txt", locuinte, nrLinii, nrColoane);
	afisareMatrice(locuinte, nrLinii, nrColoane);
	//int paritate
}