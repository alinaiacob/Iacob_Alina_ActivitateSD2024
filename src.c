#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

typedef struct Quiz Quiz;
typedef struct Heap Heap;
struct Quiz {
	char* numeMaterie;
	int grileGresite;

};

struct Heap {
	Quiz* vector;
	int dimensiune;
	int dimensiuneTotala;
};

Quiz initializareQuiz(const char* numeMaterie, int grileGresite) {
	Quiz  quiz;
	quiz.numeMaterie = (char*)malloc(strlen(numeMaterie) + 1);
	strcpy(quiz.numeMaterie, numeMaterie);
	quiz.grileGresite = grileGresite;
	return quiz;
}
Heap initializareHeap(int dim) {
	Heap heap;
	heap.dimensiuneTotala = dim;
	heap.dimensiune = 0;
	heap.vector = (Quiz*)malloc(sizeof(Quiz) * dim);
	return heap;

}

Heap adaugareQuizInHeap(Quiz quiz,Heap heap) {
	if (heap.dimensiune < heap.dimensiuneTotala) {
		heap.vector[heap.dimensiune] = quiz;//shallow copy
		heap.dimensiune++;
		
		//TO DO FILTRARE

	}
	return heap;
}
void afisareQuiz(Quiz q) {
	printf("La quiz-ul de la materie %s sunt %d grile gresite\n", q.numeMaterie, q.grileGresite);
	
}
void afisareHeap(Heap h) {
	for (int i = 0; i < h.dimensiune; i++)afisareQuiz(h.vector[i]);
}

void afisareTotalaHeap(Heap h) {
	for (int i = 0; i < h.dimensiuneTotala; i++)afisareQuiz(h.vector[i]);
}

void filtreazaHeap(Heap heap, int pozRadacina) {
	int nodSt = pozRadacina * 2 + 1;
	int nodDr = pozRadacina * 2 + 2;
	int pozMin = pozRadacina;
	if (nodSt < heap.dimensiune && heap.vector[nodSt].grileGresite < heap.vector[pozMin].grileGresite) {
		pozMin = nodSt;
	}
	if (nodDr < heap.dimensiune && heap.vector[nodDr].grileGresite < heap.vector[pozMin].grileGresite) {
		pozMin = nodDr;
	}
	if (pozMin != pozRadacina) {
		Quiz aux;
		aux = heap.vector[pozRadacina];
		heap.vector[pozRadacina] = heap.vector[pozMin];
		heap.vector[pozMin] = aux;
		if (pozMin * 2 + 1 < heap.dimensiune - 1)//
			filtreazaHeap(heap, pozMin);
	}

}

void extragereMinim(Heap *heap) {
	if (heap->dimensiune > 0) {
		Quiz aux;
		aux = heap->vector[0];
		heap->vector[0] = heap->vector[heap->dimensiune - 1];
		heap->vector[heap->dimensiune - 1] = aux;
		heap->dimensiune--;

		for (int i = (heap->dimensiune) / 2 - 1; i >= 0; i--) {
			filtreazaHeap(*heap, i);
		}
		return aux;
	}

}
void dezalocareHeap(Heap *heap) {
	for (int i = 0; i < heap->dimensiuneTotala; i++) {
		free(heap->vector[i].numeMaterie);
	}
	free(heap->vector);
	heap->dimensiune = 0;
	heap->dimensiuneTotala = 0;
}
void main() {
	Heap heap;
	/*Quiz q1 = initializareQuiz("SDD", 3);
	Quiz q2 = initializareQuiz("PEAG", 7);
	Quiz q3 = initializareQuiz("SDD", 5);
	Quiz q4 = initializareQuiz("SDD", 2);
	Quiz q5 = initializareQuiz("SDD", 9);
	Quiz q6 = initializareQuiz("SDD", 4);*/
	heap = initializareHeap(6);

	heap.vector[0] = initializareQuiz("sdd", 3);
	heap.vector[1] = initializareQuiz("java", 7);
	heap.vector[2] = initializareQuiz("c++", 5);
	heap.vector[3] = initializareQuiz("peag", 2);
	heap.vector[4] = initializareQuiz("sgbd", 9);
	heap.vector[5] = initializareQuiz("atp", 4);

	heap.dimensiune = 6;
	afisareHeap(heap);
	//filtreazaHeap(heap, 0);
	//afisareHeap(heap);
	//for (int i = heap.dimensiune / 2 - 1; i >= 0;i--) {
	//	filtreazaHeap(heap, i);
	//}
	dezalocareHeap(&heap);
	printf("\n\n");
	afisareHeap(heap);
	//adaugareQuizInHeap()
}
