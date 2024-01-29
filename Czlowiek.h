#pragma once
#include "Zwierze.h"

class Zwierze;

class Czlowiek : public Zwierze {
public:
	string WypiszImie() override;
	void Akcja() override;
	void Kolizja() override;
	Czlowiek(int x, int y, Swiat* swiat, int inicjatywa, int sila, char symbol);
};
