#pragma once
#include "Roslina.h"

class Roslina;

class WilczeJagody : public Roslina {
public:
	string WypiszImie() override;
	void Kolizja() override;
	WilczeJagody(int x, int y, Swiat* swiat, int inicjatywa, int sila, char symbol);
};



