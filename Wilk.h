#pragma once
#include "Zwierze.h"

class Zwierze;

class Wilk : public Zwierze {
public:
	string WypiszImie() override;
	Wilk(int x, int y, Swiat* swiat, int inicjatywa, int sila, char symbol);
};