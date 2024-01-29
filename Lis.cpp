#pragma once
#include "Lis.h"

Lis::Lis(int x, int y, Swiat* swiat, int inicjatywa, int sila, char symbol) : Zwierze(x, y, swiat, inicjatywa, sila, symbol) {
    this->dobrywech = true;
}

string Lis::WypiszImie() {
    return "LIS";
}

