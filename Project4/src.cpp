#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

#include <stdlib.h>

#include <string.h>



struct Preparat {

    char* numePreparat;

    int nrProduseNecesare;

    char** numeleProduselorNecesare;

    int timpPregatire;

};




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

int main() {

    struct Preparat preparate[5];

    for (int i = 0; i < 5; i++) {

        citestePreparat(&preparate[i]);

    }



    for (int i = 0; i < 5; i++) {

        free(preparate[i].numePreparat);

        for (int j = 0; j < preparate[i].nrProduseNecesare; j++) {

            free(preparate[i].numeleProduselorNecesare[j]);

        }

        free(preparate[i].numeleProduselorNecesare);

    }



    return 0;

}