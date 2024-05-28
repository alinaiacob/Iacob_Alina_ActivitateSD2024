#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<malloc.h>
#include<string.h>

struct Test {
    int id;
    char* disciplina;
    int nota;
};

struct Test initTest(int id, const char* disciplina, int nota) {
    struct Test test;
    test.id = id;
    test.disciplina = (char*)malloc(strlen(disciplina) + 1);
    strcpy(test.disciplina, disciplina);
    test.nota = nota;
    return test;
}

 void afiseazaTest(struct Test test) {
    printf("\nId: %d, Disciplina: %s, Nota: %d", test.id, test.disciplina, test.nota);
}

 void afiseazaTeste(struct Test* teste, int dim) {
    for (int i = 0; i < dim; i++) {
        afiseazaTest(teste[i]);
    }
}

void adaugaInVector(struct Test** teste, int* dim, struct Test test) {
    struct Test* copie;
    copie = (struct Test*)malloc(sizeof(struct Test) * (++(*dim)));
    printf("%d", *dim);
    for (int i = 0;i < *dim-1;i++) {
        copie[i] = (*teste)[i];
    }
    copie[*dim - 1] = test;
    if (*teste != NULL)
        free((*teste));
    *teste = copie;
}
void adaugaDinFisier(const char* numeFisier, struct Test** teste, int* dim) {
    FILE* f;
    if (numeFisier != NULL && strlen(numeFisier) > 0) {
        FILE* f = fopen(numeFisier, "r");
        if (f != NULL) {
            (*dim) = 0;
            char buffer[100];
            char delimitator[] = ",\n";
            while (fgets(buffer, 100, f) != NULL) {
                char* token;
                token = strtok(buffer, delimitator);
                struct Test test;
                test.id = atoi(token);

                token = strtok(NULL, delimitator);
                test.disciplina = (char*)malloc(strlen(token) + 1);
                strcpy(test.disciplina, token);

                token = strtok(NULL, delimitator);
                test.nota = atoi(token);
                
                adaugaInVector(teste, dim, test);
            }
            fclose(f);
        }
   }
}


void adaugaDinFisier2(const char* numeFisier, struct Test** teste, int* dim) {
    if (numeFisier != NULL && strlen(numeFisier) > 0) {
        FILE* f = fopen(numeFisier, "r");
        if (f != NULL) {
            *dim = 0;
            char delimiter[] = ",\n";
            char buffer[100];
            while (fgets(buffer, 100, delimiter)!=NULL) {
                struct Test test;
                char* token;
                token = strtok(buffer, delimiter);
                test.id = atoi(token);
               // printf("%s ", token);

                token = strtok(buffer, delimiter);
                test.disciplina = (char*)malloc(strlen(token) + 1);strcpy(test.disciplina, token);
                token = strtok(buffer, delimiter);

                test.nota = atoi(buffer);
                adaugaInVector(teste, dim, test);
            }
            fclose(f);
        }

    }
}
void creazaMatrice(const char* numeFisier, struct Test** teste, int nrLinii,int *nrColoane) {
    if (numeFisier != NULL && strlen(numeFisier) > 0) {
        FILE* f = fopen(numeFisier, "r");
        if (f != NULL) {
           // *dim = 0;
            char delimiter[] = ",\n";
            char buffer[1000];
            while ((fgets(buffer, 100,f)) != NULL) {
                struct Test test;
                char* token;
                token = strtok(buffer, delimiter);
                test.id = atoi(token);
              //  printf("%s ", token);

                token = strtok(NULL, delimiter);
                test.disciplina = (char*)malloc(strlen(token) + 1);
                strcpy(test.disciplina, token);

                token = strtok(NULL, delimiter);

                test.nota = atoi(token);
                printf("\n %d", test.nota);
                int pozitie;
                if (test.nota > 5)pozitie = 1;
                else pozitie = 0;
                adaugaInVector(&teste[pozitie], &nrColoane[pozitie], test);
            }
            fclose(f);
        }

    }
}
void afiseazaTesteMatrice(struct Test** teste, int nrLinii, int* nrColoane) {
    for (int i = 0;i < nrLinii;i++) {
        if (i == 0) {
            printf("\nMateriile la care studentul a picat");
        }
        else {
            printf("\nMateriile la care studentul a trecut");
        }
        for (int j = 0;j < nrColoane[i];j++) {
            afiseazaTest(teste[i][j]);
         
        }
    }
}
int main() {
    //int dim = 0; // Inițializăm dimensiunea la 0
    //struct Test t1 = initTest(1, "Algebra liniara", 7);
    //struct Test t2 = initTest(1, "Analiza matematica", 7);
    //struct Test t3 = initTest(1, "Structuri de date", 10);
    //struct Test t4 = initTest(1, "Java", 10);
    //struct Test* teste = NULL; // Inițializăm vectorul de teste cu NULL

    //adaugaInVector(&teste, &dim, t1);
    //adaugaInVector(&teste, &dim, t2);
    //adaugaInVector(&teste, &dim, t3);
    //adaugaInVector(&teste, &dim, t4);

    //afiseazaTeste(teste, dim); // Afișăm toate testele din vector

    //// Dezalocăm memoria alocată dinamic pentru fiecare test
    //for (int i = 0; i < dim; i++) {
    //    free(teste[i].disciplina);
    //}

    //// Dezalocăm memoria alocată pentru vector
    //free(teste);


    //struct Test* testele=NULL;
    //int dim2;
    //adaugaDinFisier2("materii.txt", &testele, &dim2);
    //printf("%d", dim2);

    struct Test** matrix;
    int* nrCol;int nrLinii=2;
    nrCol = (char*)malloc(sizeof(int) * nrLinii);
    matrix = (struct Test**)malloc(sizeof(struct Test*) * nrLinii);
    for (int i = 0;i < nrLinii;i++) {

        matrix[i] = NULL;
        nrCol[i] = 0;
    }

    creazaMatrice("materii2.txt",matrix, nrLinii, nrCol);
    afiseazaTesteMatrice(matrix, nrLinii, nrCol);
    return 0;
}
