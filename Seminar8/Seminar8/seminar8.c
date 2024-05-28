#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<malloc.h>
#include<string.h>

//heap ul ne spune val min sau max
//sortam vect cresc
//cautam min
//transalatam intr-un arbore binar
//completam fiecare nivel complet

typedef struct Quiz Quiz;
typedef struct Heap Heap;

struct Quiz {
	char* materie;
	int grileGresite;
};
struct Heap {
	Quiz* vector;
	int dim;
	int dimVizibia;
};

Heap initializare(int nrObiecte) {
	Heap heap;
	heap.vector = malloc(nrObiecte * sizeof(Quiz));
	heap.dim = nrObiecte;
	heap.dimVizibia = 0;
	return heap;
}

Heap adaugareObiectInHeap(Quiz obiect,Heap heap) {
	if (heap.dimVizibia<heap.dim)
	{
		heap.vector[heap.dim] = obiect;
		heap.dim++;
		//TO DO filtrare
	}
	return heap;

}

Quiz intializareQuiz(const char* materie,int grileGresite) {
	Quiz quiz;
	quiz.materie = (char*)malloc(strlen(materie) + 1);
	strcpy(quiz.materie, materie);
	quiz.grileGresite = grileGresite;
	return quiz;
	

}

void afisareQuiz(Quiz quiz) {
	printf("Materia: %s ", quiz.materie);
	printf("Grile gresite: %d\n", quiz.grileGresite);
}

void afisareHeap(Heap heap) {
	for (int i = 0; i < heap.dimVizibia; i++)
	{
		afisareQuiz(heap.vector[i]);
	}
}

void filtreazaHeap(Heap heap, int pozRadacina) {
	int nodSt = pozRadacina * 2 + 1;
	int nodDr = pozRadacina * 2 + 2;
	int min = pozRadacina;
	if (nodSt<heap.dimVizibia && heap.vector[nodSt].grileGresite<heap.vector[min].grileGresite)
	{
		min = nodSt;
	}
	if (nodDr < heap.dimVizibia && heap.vector[nodDr].grileGresite < heap.vector[min].grileGresite) {
		min = nodDr;
	}

	if (min != pozRadacina) {
		Quiz aux;
		aux = heap.vector[pozRadacina];
		heap.vector[pozRadacina] = heap.vector[min];
		heap.vector[min] = aux;
		if (min*2+1<heap.dimVizibia-1)
		{
			filtreazaHeap(heap, min);
		}
	}

}

Quiz extragereMin(Heap* heap) {
	if (heap->dimVizibia > 0)
	{
		Quiz aux;
		aux = heap->vector[0];
		heap->vector[0] = heap->vector[heap->dimVizibia - 1];
		heap->vector[heap->dimVizibia - 1] = aux;
		heap->dimVizibia--;
		for (int i = heap->dimVizibia / (2 - 1); i > 0; i--)
		{
			filtreazaHeap((*heap), i);
		}
		return aux;
	}
	
}
void dezalocareHeap(Heap* heap) {
	for (int i = 0; i < heap->dim; i++)
	{
		free(heap->vector[i].materie);

	}
	free(heap->vector);
	heap->vector = NULL;
	heap->dim = 0;
	heap->dimVizibia = 0;

}

void main() {
	Heap heap;
	heap = initializare(6);
	heap.vector[0] = intializareQuiz("SDD", 3);
	heap.vector[1] = intializareQuiz("Java", 7);
	heap.vector[2] = intializareQuiz("Macro", 5);
	heap.vector[3] = intializareQuiz("PAW", 2);
	heap.vector[4] = intializareQuiz("PAW", 9);
	heap.vector[5] = intializareQuiz("SDD", 4);

	heap.dimVizibia = 6;
	afisareHeap(heap);
	for (int i = heap.dimVizibia/(2-1); i > 0; i--)
	{
		filtreazaHeap(heap, i);
	}
	afisareHeap(heap);

	printf("\n\n");
	afisareQuiz(extragereMin((&heap)));
	afisareHeap(heap);
	dezalocareHeap(&heap);

}