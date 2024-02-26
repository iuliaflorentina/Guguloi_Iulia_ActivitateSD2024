#include<stdio.h>
#include<malloc.h>

struct Haina {
	int marime;
	char* marca;
	float pret;
	char gender;
};
void afiseazaHaina(struct Haina h) {
	if (h.marca!=NULL)
	{
		printf("Marca: %s\n", h.marca);
	}
	printf("Marime: %d\n", h.marime);
	printf("Pret: %5.2f\n", h.pret);
	printf("Gender: %c\n\n", h.gender);
	
}

struct Haina InitializareHaina(int marime,char* marca, float pret, char gender) {
	struct Haina h;
	h.marime = marime;
	if (marca!=NULL && strlen(marca)>0)
	{
		h.marca = malloc(strlen(marca) + 1);
		strcpy(h.marca, marca);

	}
	else {
		h.marca = NULL;
	}
	h.pret = pret;
	h.gender = gender;
	return h;
}
void dezalocareHaina(struct Haina *h) {
	free(h->marca);
	h->marca = NULL;

}

void main() {
	struct Haina haina1;
	haina1.marime = 34;
	haina1.marca = (char*)malloc(sizeof(char) * (strlen("Nike") + 1));
	strcpy(haina1.marca, "Nike");
	haina1.pret = 100;
	haina1.gender = 'M';
	afiseazaHaina(haina1);
	dezalocareHaina(&haina1);
	struct Haina haina2= InitializareHaina(36, "Adidas", 23.6, 'F');
	afiseazaHaina(haina2);
	dezalocareHaina(&haina2);//s-a facut dereferentiere pentru ca pointa catre ceva null la afisare, s-a sters legatura;
	afiseazaHaina(haina2);

}