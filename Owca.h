#pragma once
#include "Zwierze.h"

class Zwierze;

class Owca : public Zwierze {
public:
	string WypiszImie() override;
	Owca(int x, int y, Swiat* swiat, int inicjatywa, int sila, char symbol);
};