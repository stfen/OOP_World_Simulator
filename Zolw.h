#pragma once
#include "Zwierze.h"

class Zwierze;

class Zolw : public Zwierze {
public:
	void Akcja() override;
	string WypiszImie() override;
	Zolw(int x, int y, Swiat* swiat, int inicjatywa, int sila, char symbol);
	//bool GetDobryWech() override;
};
