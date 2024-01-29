#pragma once
#include "Roslina.h"

class Roslina;

class BarszczSosnowskiego : public Roslina {
public:
	string WypiszImie() override;
	void Kolizja() override;
	void Akcja() override;
	BarszczSosnowskiego(int x, int y, Swiat* swiat, int inicjatywa, int sila, char symbol);
};



