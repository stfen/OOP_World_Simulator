#pragma once
#include <iostream>
#include <conio.h>
#include <string.h>
#include <vector>
#include <fstream>
#include <random>
#include <algorithm>
#include "Properties.h"
#include "Organizm.h"
#include "Punkt.h"
#include "Informator.h"

class Organizm;

class Swiat {
protected:
	int HEIGHT;
	int WIDTH;
	int LiczbaTurNaUlt;
	int DelayUlt;
	char klawisz;
public:
	Informator komunikaty;
	vector<Organizm*>organizmy;
	void wykonajTure();
	void rysujSwiat();

	void SaveTheGame();
	void LoadTheGame();

	int GetHeight();
	int GetWidth();
	int GetOrganizmySize();
	int GetLiczbaTurNaUlt();
	int GetDelayUlt();
	void SetLiczbaTurNaUlt(int a);
	void SetDelayUlt(int a);
	char GetKlawisz();
	void SetKlawisz(char klawisz);
	bool czyPoleWolne(int x, int y);

	void WylosujStartoweOrganizmy(int x, int y);
	Organizm* ZnajdzOrganizm(int x, int y);
	void SmiercOrganizmu(Organizm* organizm);
	void DodajOrganizm(char symbol, int x, int y);
	void WczytajOrganizm(char symbol, int sila, int wiek, int x, int y);
	void UsunOrganizmy();

	Swiat(const int& HEIGHT, const int& WIDTH);
	~Swiat();

};