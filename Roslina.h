#pragma once
#include "Organizm.h"
#include "Swiat.h"
#include "Zwierze.h"
#include "Informator.h"


class Roslina : public Organizm {
public:
	void Akcja() override;
	void Kolizja() override;
	void Rysowanie() override;
	Roslina(int x, int y, Swiat* swiat, int inicjatywa, int sila, char symbol);
};