#pragma once
#pragma message("Top in: " __FILE__)
#include "Owca.h"

#pragma message("Before class in: " __FILE__)


Owca::Owca(int x, int y, Swiat* swiat, int inicjatywa, int sila, char symbol) : Zwierze(x, y, swiat, inicjatywa, sila, symbol) {}

string Owca::WypiszImie() {
	return "OWCA";
}
