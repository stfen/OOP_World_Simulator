#pragma once
#include "Punkt.h"
#include "Swiat.h"
#include "Informator.h"
#include "Properties.h"
#include <String>

class Swiat;

class Organizm {
protected:
	bool wyrysowany = 0;
	bool zywy = 1;
	bool dobrywech;
	bool umiejetnoscOdbiciaAtaku;
	bool CzyNastapiloRozmnozenie;
	bool CzyMaSzanseNaUcieczke;
	bool UmiejetnoscSpecjalna;
	char symbol;
	int sila;
	int inicjatywa;
	int wiek;
	int RozmiarRuchu;
	Swiat* swiat;
	Punkt pozycja;
	Punkt poprzednia_pozycja;
public:
	virtual void Akcja() = 0;
	virtual void Kolizja() = 0;
	virtual void Rysowanie() = 0;

	int GetX();
	int GetY();
	int GetInicjatywa();
	int GetSila();
	void SetSila(int sila);
	int GetWiek();
	void SetWiek(int a);
	char GetSymbol();
	Punkt GetPozycja();
	void SetPozycja(Punkt pozycja);
	Punkt GetLastPozycja();
	bool GetZycie();
	void SetZycie(bool a);
	bool GetStatusRozmnozenia();
	void SetStatusRozmnozenia(bool a);
	bool GetUmiejetnoscSpecjalna();
	void SetUmiejetnoscSpecjalna(bool a);
	Organizm* ZnajdzOrganizm2(int x, int y);
	virtual string WypiszImie();
	virtual bool GetDobryWech();
	bool GetUmiejetnoscOdbicia();
	bool GetSzansaNaUcieczke();
	//bool CzyWyrysowany();

	void Urodziny();
	Organizm(int x, int y, Swiat* swiat, int inicjatywa, int sila, char symbol);
};
