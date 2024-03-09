#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

#include <stdlib.h>

#include <string.h>


#define MAX_LINE_LENGTH 100

struct Preparat {

    char* numePreparat;

    int nrProduseNecesare;

    char** numeleProduselorNecesare;

    int timpPregatire;

};



struct Preparat citestePreparatDinFisier(const char* numeFisier) {
    FILE* f = fopen(numeFisier, "r");
    struct Preparat p;
    char line[MAX_LINE_LENGTH];
    if (f != NULL) {
        while (fgets(line, MAX_LINE_LENGTH, f)) {
            char* token = strtok(line, ",\n");
            // Alocare memorie pentru numele preparatului și copierea acestuia
            p.numePreparat = (char*)malloc(strlen(token) + 1);
            strcpy(p.numePreparat, token);

            token = strtok(NULL, ",\n");
            p.nrProduseNecesare = atoi(token);

            // Alocare memorie pentru array-ul de pointeri către numele produselor
            p.numeleProduselorNecesare =(char**) malloc(p.nrProduseNecesare * sizeof(char*));

            int contor = 0;
            while (contor < p.nrProduseNecesare) {
                token = strtok(NULL, ",\n");
                // Alocare memorie pentru fiecare nume de produs și copierea acestuia
                p.numeleProduselorNecesare[contor] = (char*)malloc(strlen(token) + 1);
                strcpy(p.numeleProduselorNecesare[contor], token);
                contor++;
            }

            token = strtok(NULL, ",\n");
            p.timpPregatire = atoi(token);
        }
        fclose(f);
    }
    return p;
}
struct Preparat* citestePreparateDinFisier(const char* numeFisier, int* nrPreparate) {
    FILE* f = fopen(numeFisier, "r");
    if (f != NULL) {
        char line[MAX_LINE_LENGTH];
        int nrLinii = 0;
        while (fgets(line, MAX_LINE_LENGTH, f))nrLinii++;
        fseek(f, 0, SEEK_SET);
        struct Preparat* preparate =(struct Preparat*)malloc(nrLinii * sizeof(struct Preparat));
        *nrPreparate = 0;
        while (fgets(line, MAX_LINE_LENGTH, f)) {
            char *token = strtok(line, ",\n");
            preparate[*nrPreparate].numePreparat = (char*)malloc(strlen(token) + 1);
            strcpy(preparate[*nrPreparate].numePreparat, token);

            token = strtok(NULL, ",\n");
            preparate[*nrPreparate].nrProduseNecesare = atoi(token);
            preparate[*nrPreparate].numeleProduselorNecesare = (char**)malloc(preparate[*nrPreparate].nrProduseNecesare * sizeof(char*));
            int contor = 0;
            while (contor < preparate[*nrPreparate].nrProduseNecesare) {
                token = strtok(NULL, ",\n");
                preparate[*nrPreparate].numeleProduselorNecesare[contor] = (char*)malloc(strlen(token) + 1);
                strcpy(preparate[*nrPreparate].numeleProduselorNecesare[contor], token);
                contor++;
            }
            token = strtok(NULL, ",\n");
            preparate[*nrPreparate].timpPregatire = atoi(token);
            (*nrPreparate)++;
        }
        fclose(f);
        return preparate;
    }
    return NULL;
}


void citestePreparat(struct Preparat* p) {

    printf("Numele preparatului: ");

    char buffer[100]; // Buffer pentru citirea numelor preparatului

    scanf("%s", buffer);

    p->numePreparat = (char*)malloc((strlen(buffer) + 1) * sizeof(char)); // Alocare dinamică a memoriei pentru numePreparat

    strcpy(p->numePreparat, buffer);



    printf("Nr de produse necesare pentru a realiza preparatul: ");

    scanf("%d", &p->nrProduseNecesare);



    p->numeleProduselorNecesare = (char**)malloc(p->nrProduseNecesare * sizeof(char*));



    for (int i = 0; i < p->nrProduseNecesare; i++) {

        printf("Produsul cu indexul %i: ", i);

        scanf("%s", buffer);

        p->numeleProduselorNecesare[i] = (char*)malloc((strlen(buffer) + 1) * sizeof(char)); // Alocare dinamică a memoriei pentru fiecare nume de produs

        strcpy(p->numeleProduselorNecesare[i], buffer);

    }



    printf("Timpul de pregatire: ");

    scanf("%d", &p->timpPregatire);

}



void afiseazaPreparatul(struct Preparat p) {

    printf("\n---METODA AFISARE PREPARAT-------");

    printf("\nNumele preparatului: %s", p.numePreparat);

    printf("\nNr de produse necesare: %d", p.nrProduseNecesare);

    printf("\n");



    for (int i = 0; i < p.nrProduseNecesare; i++) {

        printf("Numele produsului cu indexul %i: %s\n", i, p.numeleProduselorNecesare[i]);

    }



    printf("Timpul de pregatire: %d", p.timpPregatire);

}

void modificaArticol(struct Preparat* p, int timp) {



    printf("\nSchimba timpul de pregatire: ");





    if (timp > 0) {

        p->timpPregatire = timp;

    }

    else {

        printf("\nTimpul de pregatire nu poate fi mai mic decat 0");

    }

}



void afiseazaAnumitePreparate(struct Preparat preparate[], struct Preparat* anumitePreparate[], int nrPreparate) {

    int contor = 0;

    struct Preparat* preparateleCorespunzatoare;

    for (int i = 0; i < nrPreparate; i++) {

        if (preparate[i].nrProduseNecesare > 5) {

            contor++;

            // anumitePreparate[]

        }

    }

}
static void scriePreparatInFisier(struct Preparat preparat,const char *numeFisier) {
    FILE* f = fopen(numeFisier, "w");
    if (f != NULL) {
        if (preparat.numePreparat != NULL) {
            fprintf(f, "%s,", preparat.numePreparat);
        }
        else {
            fprintf(f, " ,");
        }
        fprintf(f, "%d,", preparat.nrProduseNecesare);
        for (int i = 0; i < preparat.nrProduseNecesare; i++) {
            fprintf(f, "%s,", preparat.numeleProduselorNecesare[i]);
        }
        fprintf(f, "%d", preparat.timpPregatire);
        fclose(f);
    }
    else printf("\Nu s-a putut deschide fisierul :((");
}
static void scriePreparateInFisier(struct Preparat* preparate,int nrPreparate, const char* numeFisier) {
    FILE* f = fopen(numeFisier, "w");
    if (f != NULL) {
        if (preparate != NULL && nrPreparate>0) {
            for (int i = 0; i < nrPreparate; i++) {
                if (preparate[i].numePreparat != NULL) {
                    fprintf(f, "%s,", preparate[i].numePreparat);
                }
                else {
                    fprintf(f, " ,");
                }
                fprintf(f, "%d,", preparate[i].nrProduseNecesare);
                for (int i = 0; i < preparate[i].nrProduseNecesare; i++) {
                    fprintf(f, "%s,", preparate[i].numeleProduselorNecesare[i]);
                }
                fprintf(f, "%d\n", preparate[i].timpPregatire);
            }
            fclose(f);
        }
        else printf("\nNu avem ce sa scriem in fisier:((");
    }
}
//static void scriePrepa

int main() {

    struct Preparat preparate[5];

    //for (int i = 0; i < 5; i++) {

    //    citestePreparat(&preparate[i]);

    //}



    //for (int i = 0; i < 5; i++) {

    //    free(preparate[i].numePreparat);

    //    for (int j = 0; j < preparate[i].nrProduseNecesare; j++) {

    //        free(preparate[i].numeleProduselorNecesare[j]);

    //    }

    //    free(preparate[i].numeleProduselorNecesare);

    //}
   // struct Preparat p=citestePreparatDinFisier("Preparate.txt");
    int nrPreparate = 0;
    struct Preparat* p = citestePreparateDinFisier("Preparate.txt", &nrPreparate);
    printf("%d", nrPreparate);
    afiseazaPreparatul(p[1]);
   // FILE *f=fopen("Test.txt")
    FILE* f; f = fopen("Test.txt", "w");
   // scriePreparatInFisier2(p[0], f);
    scriePreparatInFisier(p[1], "Test.txt");
    scriePreparateInFisier(p, 2, "Teste.txt");
    return 0;

}
