#pragma once
#include "Wilk.h"

Wilk::Wilk(int x, int y, Swiat* swiat, int inicjatywa, int sila, char symbol) : Zwierze(x, y, swiat, inicjatywa, sila, symbol) {}

string Wilk::WypiszImie() {
	return "WILK";
}