#define _CRT_SECURE_NO_WARNINGS
#include<string>
#include <iostream>
using namespace std;
//Iulia Guguloi - articol Inregistrare
struct Inregistrare {
	int id;
	char* nume;
	string numarTelefon;
	string mail;
	Inregistrare() {
		this->id = 0;
		this->nume = new char[strlen("necunoscut") + 1];
		strcpy(this->nume, "necunoscut");
		this->numarTelefon = " ";
		this->mail = " ";
	}
	Inregistrare(int id, const char* nume, string numarTelefon, string mail) {
		this->id = id;
		this->nume = new char[strlen(nume) + 1];
		strcpy(this->nume, nume);
		this->numarTelefon = numarTelefon;
		this->mail = mail;
	}
	Inregistrare(const Inregistrare& i) {
		this->id = i.id;
		this->nume = new char[strlen(i.nume) + 1];
		strcpy(this->nume, i.nume);
		this->numarTelefon = i.numarTelefon;
		this->mail = i.mail;
	}
	~Inregistrare() {
		if (this->nume!=nullptr)
		{
			delete[]this->nume;
			this->nume = nullptr;
		}
	}
	void citire() {
		cout << "\nIntroduceti id-ul: ";
		cin >> this->id;
		cout << "\nIntroduceti numele: ";
		char buffer[100];
		cin >> buffer;
		cin.getline(buffer, 99);
		if (this->nume != nullptr)
		{
			delete[]this->nume;
			this->nume = nullptr;
		}
		this->nume = new char[strlen(buffer) + 1];
		strcpy(this->nume, buffer);
		cout << "\nIntroduceti numarul de telefon: ";
		cin >> ws;
		getline(cin, this->numarTelefon);
		cout << "\nIntroduceti mail-ul: ";
		cin >> ws;
		getline(cin, this->mail);
	}

	void afisare() {
		cout << "\nId: " << this->id;
		cout << "\nNume: " << this->nume;
		if (this->numarTelefon.size() == 10)
		{
			cout << "\nNumar telefon: " << this->numarTelefon;
		}
		else
			cout << "\nNumar invalid";
		cout << "\nMail: " << this->mail;
	}
	void afisareLitere() {
		int litere = strlen(this->nume);
		cout << "\n Numele are "<<litere<<" litere";
	}
	friend string schimbareMail(Inregistrare& i, string mail) {
		i.mail = mail;
		return i.mail;
	}
};
int main()
{
	Inregistrare i;
	Inregistrare i1(2, "Alexandru", "0756324891", "alex@gmail.com");
	//i.citire();
	//i.afisare();
	i1.afisareLitere();
	schimbareMail(i1, "aergfvds");
	i1.afisare();
	return 0;
}
