#pragma once
#include "Guarana.h"

Guarana::Guarana(int x, int y, Swiat* swiat, int inicjatywa, int sila, char symbol) : Roslina(x, y, swiat, inicjatywa, sila, symbol) {}

string Guarana::WypiszImie() {
    return "GUARANA";
}

void Guarana::Kolizja() {
    bool kolizja = 0;
    Organizm* organizmAtakujacy = nullptr;
    for (auto* organizm : swiat->organizmy) {
        if (organizm->GetX() == pozycja.GetX() && organizm->GetY() == pozycja.GetY() && organizm != this && organizm->GetZycie() == true) {
            kolizja = 1;
            organizmAtakujacy = organizm;
        }
    }
    if (kolizja == 1) {
        organizmAtakujacy->SetSila(organizmAtakujacy->GetSila() + 3);
        string komunikat = "Bonus: " + organizmAtakujacy->WypiszImie() + " zjadl " + this->WypiszImie() + " (" + to_string(pozycja.GetX()) + ", " + to_string(pozycja.GetY()) + ") i stal sie silniejszy";
        swiat->komunikaty.WypiszKomunikat(komunikat);
    }
}
