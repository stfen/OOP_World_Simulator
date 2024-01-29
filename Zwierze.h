#pragma once
#include "Organizm.h"
#include "Swiat.h"
#include "Informator.h"


class Zwierze : public Organizm {
public:
	void Akcja() override;
	void Kolizja() override;
	void Rysowanie() override;
	void RozmnozSie(Organizm* organizm);
	Organizm* ZnajdzDrugiegoRodzica(Organizm* rodzic1, int x, int y);
	Zwierze(int x, int y, Swiat* swiat, int inicjatywa, int sila, char symbol);
};