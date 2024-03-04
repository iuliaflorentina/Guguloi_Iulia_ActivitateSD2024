#include <stdio.h>
#include<malloc.h>

struct Avion {
	int nrPasageri;
	char* companie;
	float pretBilet;

};

struct Avion initializare(int nrPasageri, const char* companie, float pretBilet) {
	struct Avion avion;
	avion.nrPasageri = nrPasageri;
	avion.companie = (char*)malloc(sizeof(char)*(strlen(companie) + 1));
	strcpy(avion.companie, companie);
	avion.pretBilet = pretBilet;

	return avion;
}

void afisareAvion(struct Avion av) {
	printf("%s are un avion de %d locuri cu preturile %5.2f RON pe loc\n", av.companie, av.nrPasageri, av.pretBilet);
}

//vector structura de date omogena,liniara,
//cand avem alocare statica tot avelasi spatiu ocupa indiferent de cate elemente dam in vector
void afisareAvioane(struct Avion* vector, int nrAvioane) {
	if (vector!=NULL)
	{
		for (int i = 0; i < nrAvioane; i++)
		{
			afisareAvion(vector[i]);

		}
	}
	
}

void dezalocare(struct Avion** avioane, int* nrAvioane) {
	if ((*avioane)!=NULL)
	{
		for (int i = 0; i < nrAvioane; i++)
		{
			free((*avioane)[i].companie);

		}
		free(*avioane);
		*nrAvioane = 0;
		*avioane = NULL;
	}
	
}

void copiazaAvioaneCuBiletRedus(struct Avion* avioane, int nrAvioane, float pragPret, struct Avion** avioaneNou, int* dimensiune) {
	*dimensiune = 0;
	
	for (int i = 0; i < nrAvioane; i++)
	{
		if (avioane[i].pretBilet<pragPret)
		{
			(*dimensiune)++;
		}
		if (*avioaneNou != NULL)
		{
			dezalocare(avioaneNou, dimensiune);
		}
		else {
			*dimensiune = 0;
		}
		for (int i = 0; i < nrAvioane; i++)
		{
			if (avioane[i].pretBilet < pragPret)
			{
				(*dimensiune)++;
			}
		}
	}
	*avioaneNou = (struct Avion*)malloc(sizeof(struct Avion) * (*dimensiune)); 
	int k = 0;
	for (int i = 0; i < nrAvioane; i++)
	{
		if (avioane[i].pretBilet<pragPret)
		{
			(*avioaneNou)[k++] = initializare(avioane[i].nrPasageri, avioane[i].companie, avioane[i].pretBilet);
		}
	}
	
}

struct Avion* vectorCopiePrimeleNAvioane(struct Avion* avioane,int nrAvioane, int nrAvioaneCopiate ) {
	if (nrAvioaneCopiate<nrAvioane && nrAvioaneCopiate>0)
	{
		struct Avion* avioaneCopiate = (struct Avion*)malloc(sizeof(struct Avion) * nrAvioaneCopiate);
		for (int i = 0; i < nrAvioaneCopiate; i++)
		{
			avioaneCopiate[i] = initializare(avioane[i].nrPasageri,avioane[i].companie,avioane[i].pretBilet);
		}
		return avioaneCopiate;
	}
	else {
		return NULL;
	}
}

struct Avion getPrimulAvionCompanie(struct Avion* avioane, int nrAvione, const char* companie) {
	if (avioane!=NULL && companie!=NULL)
	{
		for (int i = 0; i < nrAvione; i++)
		{
			if (avioane[i].companie != NULL) {
				if (strcmp(avioane[i].companie, companie) == 0)
				{
					return initializare(avioane[i].nrPasageri,avioane[i].companie,avioane[i].pretBilet);
				}

			}
			else {
				return initializare(-1, "N\A", -1);
			}
		}
	
	{
		return initializare(-1, "N\A", -1);
	}
	}
	else {
		return initializare(-1, "N\A", -1);
	}
	
}

void main() {
	int nrAvioane = 5;
	struct Avion* avioane = (struct Avion*)malloc(sizeof(struct Avion) * nrAvioane);
	for (int i = 0; i < nrAvioane; i++)
	{
		avioane[i] = initializare(i + 50, "Tarom", 10 * i + 40);
	}
	afisareAvioane(avioane, nrAvioane);

	int nrAvioaneCopiate = 3;
	printf("\n");
	struct Avion* avioaneCopiate = vectorCopiePrimeleNAvioane(avioane, nrAvioane, nrAvioaneCopiate);
	afisareAvioane(avioaneCopiate, nrAvioaneCopiate);

	struct Avion* avioaneCuBileteReduse = NULL;
	int nrAvioaneCuBileteReduse = 0;
	avioane[4].pretBilet = 30;

	copiazaAvioaneCuBiletRedus(avioane, nrAvioane, 70, &avioaneCuBileteReduse,&nrAvioaneCuBileteReduse);
	printf("\n\n");

	afisareAvioane(avioaneCuBileteReduse, nrAvioaneCuBileteReduse);
	struct Avion avion = getPrimulAvionCompanie(avioane, nrAvioane, "Tarom");
	printf("\nPrimul avion: ");
	afisareAvion(avion);

	dezalocare(&avioane, &nrAvioane);
	dezalocare(&avioaneCopiate, &nrAvioaneCopiate);
	dezalocare(&avioaneCuBileteReduse, &nrAvioaneCuBileteReduse);
	free(avion.companie);

}