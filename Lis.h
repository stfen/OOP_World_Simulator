#pragma once
#include "Zwierze.h"

class Zwierze;

class Lis : public Zwierze {
public:
	string WypiszImie() override;
	Lis(int x, int y, Swiat* swiat, int inicjatywa, int sila, char symbol);
	//bool GetDobryWech() override;
};
