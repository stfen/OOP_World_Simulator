#pragma once
#include "WilczeJagody.h"

WilczeJagody::WilczeJagody(int x, int y, Swiat* swiat, int inicjatywa, int sila, char symbol) : Roslina(x, y, swiat, inicjatywa, sila, symbol) {}

string WilczeJagody::WypiszImie() {
    return "WILCZE JAGODY";
}

void WilczeJagody::Kolizja() {
    bool kolizja = 0;
    Organizm* organizmAtakujacy = nullptr;
    for (auto* organizm : swiat->organizmy) {
        if (organizm->GetX() == pozycja.GetX() && organizm->GetY() == pozycja.GetY() && organizm != this && organizm->GetZycie() == true) {
            kolizja = 1;
            organizmAtakujacy = organizm;
        }
    }
    if (kolizja == 1) {
        string komunikat = "Zatrucie: " + organizmAtakujacy->WypiszImie() + " zjadl " + this->WypiszImie() + " (" + to_string(pozycja.GetX()) + ", " + to_string(pozycja.GetY()) + ") i zmarl";
        swiat->komunikaty.WypiszKomunikat(komunikat);
        swiat->SmiercOrganizmu(organizmAtakujacy);
    }
}
