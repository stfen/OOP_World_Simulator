#pragma once
#include "Roslina.h"

class Roslina;

class Mlecz : public Roslina {
public:
	string WypiszImie() override;
	void Akcja() override;
	Mlecz(int x, int y, Swiat* swiat, int inicjatywa, int sila, char symbol);
};

