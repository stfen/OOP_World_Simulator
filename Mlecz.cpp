#pragma once
#include "Mlecz.h"

Mlecz::Mlecz(int x, int y, Swiat* swiat, int inicjatywa, int sila, char symbol) : Roslina(x, y, swiat, inicjatywa, sila, symbol) {}

string Mlecz::WypiszImie() {
	return "MLECZ";
}

void Mlecz::Akcja() {
	for (int i = 0; i < 3; i++) {
		Roslina::Akcja();
	}
}