#pragma once
#include "Roslina.h"

class Roslina;

class Guarana : public Roslina {
public:
	string WypiszImie() override;
	void Kolizja() override;
	Guarana(int x, int y, Swiat* swiat, int inicjatywa, int sila, char symbol);
};


