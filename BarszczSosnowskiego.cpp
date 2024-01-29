#pragma once
#include "BarszczSosnowskiego.h"

BarszczSosnowskiego::BarszczSosnowskiego(int x, int y, Swiat* swiat, int inicjatywa, int sila, char symbol) : Roslina(x, y, swiat, inicjatywa, sila, symbol) {}

string BarszczSosnowskiego::WypiszImie() {
    return "BARSZCZ SOSNOWSKIEGO";
}

void BarszczSosnowskiego::Akcja() {
    Organizm* temp = nullptr;
    temp = swiat->ZnajdzOrganizm(pozycja.GetX() + 1, pozycja.GetY());
    if (dynamic_cast<Zwierze*>(temp)!=nullptr)swiat->SmiercOrganizmu(temp);
    temp = nullptr;
    temp = swiat->ZnajdzOrganizm(pozycja.GetX(), pozycja.GetY() + 1);
    if (dynamic_cast<Zwierze*>(temp) != nullptr)swiat->SmiercOrganizmu(temp);
    temp = nullptr;
    temp = swiat->ZnajdzOrganizm(pozycja.GetX() - 1, pozycja.GetY());
    if (dynamic_cast<Zwierze*>(temp) != nullptr)swiat->SmiercOrganizmu(temp);
    temp = nullptr;
    temp = swiat->ZnajdzOrganizm(pozycja.GetX(), pozycja.GetY() - 1);
    if (dynamic_cast<Zwierze*>(temp) != nullptr)swiat->SmiercOrganizmu(temp);
    temp = nullptr;
    Roslina::Akcja();
}

void BarszczSosnowskiego::Kolizja() {
    bool kolizja = false;
    Organizm* organizmAtakujacy = nullptr;
    for (auto* organizm : swiat->organizmy) {
        if (organizm->GetX() == pozycja.GetX() && organizm->GetY() == pozycja.GetY() && organizm != this && organizm->GetZycie() == true) {
            kolizja = true;
            organizmAtakujacy = organizm;
        }
    }
    if (kolizja == true) {
        string komunikat = "Zatrucie: " + organizmAtakujacy->WypiszImie() + " zjadl " + this->WypiszImie() + " (" + to_string(pozycja.GetX()) + ", " + to_string(pozycja.GetY()) + ") i zmarl";
        swiat->komunikaty.WypiszKomunikat(komunikat);
        swiat->SmiercOrganizmu(organizmAtakujacy);
    }
}
