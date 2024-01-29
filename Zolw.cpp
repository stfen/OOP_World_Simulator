#pragma once
#include "Zolw.h"

Zolw::Zolw(int x, int y, Swiat* swiat, int inicjatywa, int sila, char symbol) : Zwierze(x, y, swiat, inicjatywa, sila, symbol){
    umiejetnoscOdbiciaAtaku = true;
}

void Zolw::Akcja() {
    poprzednia_pozycja = pozycja;
    Organizm* other = nullptr;
    int szansa;
    bool move = 0;
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dis(1, 4);
    szansa = dis(gen);
    if (szansa != 1)return;
    else Zwierze::Akcja();
}

string Zolw::WypiszImie() {
    return "ZOLW";
}