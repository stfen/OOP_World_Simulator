#pragma once
#include "Trawa.h"

Trawa::Trawa(int x, int y, Swiat* swiat, int inicjatywa, int sila, char symbol) : Roslina(x, y, swiat, inicjatywa, sila, symbol) {}

string Trawa::WypiszImie() {
	return "TRAWA";
}