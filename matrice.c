#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<malloc.h>


struct Locuinta {
	int id;
	char* strada;
	int nr;
};
void inserareLocuinta(struct Locuinta** locuinte, int* dim, struct Locuinta locuinta) {
	struct Locuinta* copie;
	copie =(struct Locuinta*) malloc(sizeof(struct Locuinta) * (++(*dim)));
	for (int i = 0;i < (*dim) - 1;i++) {
		copie[i] = (*locuinte)[i];
	}

	copie[(*dim - 1)] = locuinta;
	if (locuinte != NULL) {
		free(*locuinte);
}
	(*locuinte) = copie;
}
void citesteFisier(const char*nume_fisier,struct Locuinta**locuinte,int *dim) {
	if (nume_fisier != NULL && strlen(nume_fisier)>0) {
		FILE* f = fopen(nume_fisier,"r");
		if (f != NULL) {
			*dim = 0;
			char buffer[100];
			char delimiter[] = ",\n";
			while (fgets(buffer,100,f)!=NULL) {//returneaza un pointer

				char* token;
				token=strtok(buffer, delimiter);
				struct Locuinta locuinta;
				locuinta.id = atoi(token);

				token=strtok(NULL, delimiter);
                locuinta.strada = (char*)malloc(strlen(token) + 1);
				strcpy(locuinta.strada, token);

				token = strtok(NULL, delimiter);
				locuinta.nr = atoi(token);
				inserareLocuinta(locuinte, dim, locuinta);
				
			}
			
		}
		fclose(f);
	}
}
void afisareLocuinta(struct Locuinta l) {

	printf("\nId-ul locuintei: %d", l.id);
	if (l.strada != NULL) {
		printf("\nStrada: %s", l.strada);
	}
	else printf("\n strada- ");
	printf("\nNr strazii %d", l.nr);
	printf("\n");
}
void citestMatriceFisier(const char* nume_fisier, struct Locuinta** matrice, int nrLinii,int *nrColoane) {
	if (nume_fisier != NULL && strlen(nume_fisier) > 0) {
		FILE* f = fopen(nume_fisier, "r");
		if (f != NULL) {
			
			char buffer[100];
			char delimiter[] = ",\n";
			while (fgets(buffer, 100, f) != NULL) {//returneaza un pointer

				char* token;
				token = strtok(buffer, delimiter);
				struct Locuinta locuinta;
				locuinta.id = atoi(token);

				token = strtok(NULL, delimiter);
				locuinta.strada = (char*)malloc(strlen(token) + 1);
				strcpy(locuinta.strada, token);

				token = strtok(NULL, delimiter);
				locuinta.nr = atoi(token);
				
				int pozitie=(locuinta.nr)%2;
				afisareLocuinta(locuinta);
				
				inserareLocuinta((&matrice)[pozitie], (&nrColoane)[pozitie], locuinta);
			}
			fclose(f);
			}
			
		}
	
	}



void afisareVectorLocuinte(struct Locuinta* locuinta, int dim) {
	for (int i = 0;i < dim;i++) {
		afisareLocuinta(locuinta[i]);
	}
}
void stergeLocuinta(struct Locuinta** locuinte, int* dim, int id) {
	char flag = 0;
	for (int i = 0;i < (*dim);i++) {
		if ((*locuinte)[i].id == id) {
			flag = 1;
			break;
		}
		
	}
	if (flag == 1) {
		struct Locuinta* copie = (struct Locuinta*)malloc(sizeof(struct Locuinta*) * (*dim - 1));
		int j = 0;
		for (int i = 0;i < (*dim);i++) {
			if ((*locuinte)[i].id != id) {
				copie[j++] = (*locuinte)[i];
			}
		}
		(*dim)--;
		if ((*locuinte) != NULL) {
			free((*locuinte));
		}
		(*locuinte) = copie;
	}
}
void afisareMatrice(struct Locuinta** matrice, int nrLinii, int* nrColoane) {
	for (int i = 0;i < nrLinii;i++) {
		for (int j = 0;j < nrColoane[i];j++) {
			afisareLocuinta(matrice[i][j]);
		}
	}
}
void afisareIDDePeOParte(int paritate,struct Locuinta**matrice,int nrLinii,int *nrColoane) {
	paritate = paritate % 2;

		for (int j = 0;j < nrColoane[paritate];j++) {
			//if (matrice[paritate][j].nr == paritate) {
				printf("%d", matrice[paritate][j].id);
			//}
		
	}
}
struct Locuinta cautareLocuintaDupaId(int idCautat, struct Locuinta** matrice, int nrLinii, int* nrColoane) {
	int ok = 0;
	for (int i = 0;i < nrLinii;i++) {
		for (int j = 0;j < nrColoane[i];j++) {
			if (matrice[i][j].id == idCautat) {
				return matrice[i][j];ok = 1;
			}
		}
	}
	struct Locuinta copie;
	copie.id = -1;
	copie.nr = -1;
	copie.strada = NULL;
	return copie;
 }
void dezalocareMatrice(struct Locuinta*** matrice, int *nrLinii, int** nrColoane) {
	for (int i = 0;i < (*nrLinii);i++) {
		for (int j = 0;j < (*nrColoane)[i];j++) {
			free((*matrice[i][j]).strada);
			(*matrice[i][j]).strada = NULL;
		}
			
		free(*matrice[i]);
	}
	free(*matrice);
	*matrice = NULL;	

	(*nrLinii) = 0;
	free(*nrColoane);
	*nrColoane = NULL;
}
void schimbareNrLocuinta(struct Locuinta** matrice, int nrLinii, int* nrColoane, int nrLocuinta) {
	int pozitie = nrLocuinta % 2;
	int idLocuinta = -1;
	int indexInVector = -1;
	for (int i = 0;i < nrColoane;i++) {
		if (matrice[pozitie][i].nr== nrLocuinta) {
			matrice[pozitie][i].nr++;
			idLocuinta = matrice[pozitie][i].id;
			indexInVector = i;
		}
	}
	if (idLocuinta != -1) {
		int index = (nrLocuinta + 1) % 2;
		inserareLocuinta(&(matrice[index]), (&nrColoane[index]), matrice[pozitie][indexInVector]);
		stergeLocuinta(&(matrice[pozitie]), &(nrColoane[pozitie]), idLocuinta);
	}
}
void main() {
	int nrLinii = 2;
	int* nrColoane;
	struct Locuinta** matrice;
	nrColoane = (int*)malloc(sizeof(int) * nrLinii);
	matrice = (struct Locuinta**)malloc(sizeof(struct Locuinta*) * nrLinii);

	for (int i = 0;i < nrLinii;i++) {
		matrice[i] = NULL;
		nrColoane[i] = 0;
	}
	citestMatriceFisier("locuinte.txt", matrice, nrLinii, &nrColoane);
	////printf("%d", nrColoane);
	//afisareMatrice(matrice, nrLinii, &nrColoane);
	//struct Locuinta locuinta1 = cautareLocuintaDupaId(22, matrice, nrLinii, &nrColoane);
	//dezalocareMatrice(&matrice, &nrLinii, &nrColoane);
}