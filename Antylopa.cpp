#pragma once
#include "Antylopa.h"
#include <string>

Antylopa::Antylopa(int x, int y, Swiat* swiat, int inicjatywa, int sila, char symbol) : Zwierze(x, y, swiat, inicjatywa, sila, symbol) {
    this->CzyMaSzanseNaUcieczke = true;
    this->RozmiarRuchu = 2;
}

string Antylopa::WypiszImie() {
    return "ANTYLOPA";
}

