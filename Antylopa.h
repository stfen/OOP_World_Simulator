#pragma once
#include "Zwierze.h"

class Zwierze;

class Antylopa : public Zwierze {
public:
	//void Akcja() override;
	string WypiszImie() override;
	Antylopa(int x, int y, Swiat* swiat, int inicjatywa, int sila, char symbol);
	//bool GetDobryWech() override;
};

