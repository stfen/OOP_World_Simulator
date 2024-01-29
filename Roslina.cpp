#pragma once
#include "Roslina.h"
#include <string>
Roslina::Roslina(int x, int y, Swiat* swiat, int inicjatywa, int sila, char symbol) :
    Organizm(x, y, swiat, inicjatywa, sila, symbol) {
}

void Roslina::Akcja() {
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dis(1, 50);
    int los = dis(gen);
    if (los < 2) {
        bool rozmnazanie = false;
        int x;
        int y;
        if (swiat->czyPoleWolne(pozycja.GetX() + 1, pozycja.GetY()) == true && pozycja.GetX() + 1 <= swiat->GetWidth() - 1) {
            x = pozycja.GetX() + 1;
            y = pozycja.GetY();
            rozmnazanie = true;
        }
        else if (swiat->czyPoleWolne(pozycja.GetX() - 1, pozycja.GetY()) == true && pozycja.GetX() - 1 >= 0) {
            x = pozycja.GetX() - 1;
            y = pozycja.GetY();
            rozmnazanie = true;
        }
        else if (swiat->czyPoleWolne(pozycja.GetX(), pozycja.GetY() + 1) == true && pozycja.GetY() + 1 <= swiat->GetHeight() - 1) {
            x = pozycja.GetX();
            y = pozycja.GetY() + 1;
            rozmnazanie = true;
        }
        else if (swiat->czyPoleWolne(pozycja.GetX(), pozycja.GetY() - 1) == true && pozycja.GetY() - 1 >= 0) {
            x = pozycja.GetX();
            y = pozycja.GetY() - 1;
            rozmnazanie = true;
        }
        if (rozmnazanie == true) {
            swiat->DodajOrganizm(symbol, x, y);
        }
    }
}

void Roslina::Kolizja() {

}

void Roslina::Rysowanie() {
    cout << symbol;
}