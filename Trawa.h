#pragma once
#include "Roslina.h"

class Roslina;

class Trawa : public Roslina {
public:
	string WypiszImie() override;
	Trawa(int x, int y, Swiat* swiat, int inicjatywa, int sila, char symbol);
};
