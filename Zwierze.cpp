#pragma once
#include "Zwierze.h"
#include <string>

Zwierze::Zwierze(int x, int y, Swiat* swiat, int inicjatywa, int sila, char symbol) :
    Organizm(x, y, swiat, inicjatywa, sila, symbol) {
}

void Zwierze::Akcja() {
    poprzednia_pozycja = pozycja;
    Organizm* other = nullptr;
    int kierunek;
    bool move = 0;
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dis(1, 4);

    while (move != 1) {
        kierunek = dis(gen);
        switch (kierunek) {
        case 1:
            if (this->GetDobryWech()) {
                other = swiat->ZnajdzOrganizm(GetX(), GetY() + RozmiarRuchu);
                if (other != nullptr && other->GetSila() > this->sila)break;
            }
            if (pozycja.GetY() < swiat->GetHeight() - RozmiarRuchu) {
                pozycja.SetY(pozycja.GetY() + RozmiarRuchu);
                move = 1;
            }
            break;
        case 2:
            if (this->GetDobryWech()) {
                other = swiat->ZnajdzOrganizm(GetX() + RozmiarRuchu, GetY());
                if (other != nullptr && other->GetSila() > this->sila)break;
            }
            if (pozycja.GetX() < swiat->GetWidth() - RozmiarRuchu) {
                pozycja.SetX(pozycja.GetX() + RozmiarRuchu);
                move = 1;
            }
            break;
        case 3:
            if (this->GetDobryWech()) {
                other = swiat->ZnajdzOrganizm(GetX(), GetY() - RozmiarRuchu);
                if (other != nullptr && other->GetSila() > this->sila)break;
            }
            if (pozycja.GetY() > 0) {
                pozycja.SetY(pozycja.GetY() - RozmiarRuchu);
                move = 1;
            }
            break;
        case 4:
            if (this->GetDobryWech()) {
                other = swiat->ZnajdzOrganizm(GetX() - RozmiarRuchu, GetY());
                if (other != nullptr && other->GetSila() > this->sila)break;
            }
            if (pozycja.GetX() > 0) {
                pozycja.SetX(pozycja.GetX() - RozmiarRuchu);
                move = 1;
            }
            break;
        }
    }
}

void Zwierze::Kolizja() {
    bool kolizja = 0;
    int CzyUcieknie = 0;
    Organizm* organizmAtakujacy = nullptr;
    for (Organizm* organizm : swiat->organizmy) {
        if (organizm->GetX() == pozycja.GetX() && organizm->GetY() == pozycja.GetY() && organizm != this && organizm->GetZycie() == true) {
            kolizja = 1;
            organizmAtakujacy = organizm;
        }
    }
    if (kolizja == 1) {
        if (this->GetSzansaNaUcieczke() || organizmAtakujacy->GetSzansaNaUcieczke()) {
            random_device rd;
            mt19937 gen(rd());
            uniform_int_distribution<> dis(1, 2);
            CzyUcieknie = dis(gen);
        }
        if (organizmAtakujacy->GetSymbol() == this->symbol) {
            SetPozycja(this->GetLastPozycja());
            organizmAtakujacy->SetPozycja(organizmAtakujacy->GetLastPozycja());
            RozmnozSie(organizmAtakujacy);
        }
        else if (this->GetUmiejetnoscOdbicia() && organizmAtakujacy->GetSila() < 5 && dynamic_cast<Zwierze*>(organizmAtakujacy) != nullptr) {
            organizmAtakujacy->SetPozycja(organizmAtakujacy->GetLastPozycja());
            string komunikat = "Unik: " + WypiszImie() + " odbil atak " + organizmAtakujacy->WypiszImie() + " (" + to_string(pozycja.GetX()) + ", " + to_string(pozycja.GetY()) + ") ";
            swiat->komunikaty.WypiszKomunikat(komunikat);
        }
        else if (organizmAtakujacy->GetUmiejetnoscOdbicia() && this->GetSila() < 5 && dynamic_cast<Zwierze*>(organizmAtakujacy) != nullptr) {
            this->SetPozycja(this->GetLastPozycja());
            string komunikat = "Unik: " + organizmAtakujacy->WypiszImie() + " odbil atak " + this->WypiszImie() + " (" + to_string(pozycja.GetX()) + ", " + to_string(pozycja.GetY()) + ") ";
            swiat->komunikaty.WypiszKomunikat(komunikat);
        }
        else if (this->sila > organizmAtakujacy->GetSila() && organizmAtakujacy->GetSymbol() != this->symbol && organizmAtakujacy->GetUmiejetnoscSpecjalna()==false && dynamic_cast<Zwierze*>(organizmAtakujacy) != nullptr) {
            if (CzyUcieknie == 1) {
                organizmAtakujacy->SetPozycja(organizmAtakujacy->GetLastPozycja());
                string komunikat = "Unik: " + organizmAtakujacy->WypiszImie() + " uciekl od walki z " + WypiszImie() + " (" + to_string(organizmAtakujacy->GetX()) + ", " + to_string(organizmAtakujacy->GetY()) + ")";
                swiat->komunikaty.WypiszKomunikat(komunikat);
            }
            else {
                swiat->SmiercOrganizmu(organizmAtakujacy);
                string komunikat = "Walka: " + WypiszImie() + " pokonal " + organizmAtakujacy->WypiszImie() + " (" + to_string(organizmAtakujacy->GetX()) + ", " + to_string(organizmAtakujacy->GetY()) + ")";
                swiat->komunikaty.WypiszKomunikat(komunikat);
            }
        }
        else if (this->sila <= organizmAtakujacy->GetSila() && organizmAtakujacy->GetSymbol() != this->symbol && dynamic_cast<Zwierze*>(organizmAtakujacy) != nullptr) {
            if (CzyUcieknie == 1) {
                this->SetPozycja(this->GetLastPozycja());
                string komunikat = "Unik: " + WypiszImie() + " uciekl od walki z " + organizmAtakujacy->WypiszImie() + " (" + to_string(organizmAtakujacy->GetX()) + ", " + to_string(organizmAtakujacy->GetY()) + ")";
                swiat->komunikaty.WypiszKomunikat(komunikat);
            }
            else {
                swiat->SmiercOrganizmu(this);
                string komunikat = "Walka: " + organizmAtakujacy->WypiszImie() + " pokonal " + WypiszImie() + " (" + to_string(organizmAtakujacy->GetX()) + ", " + to_string(organizmAtakujacy->GetY()) + ")";
                swiat->komunikaty.WypiszKomunikat(komunikat);
            }
        }
    }
}

void Zwierze::Rysowanie() {
    cout << symbol;
}

void Zwierze::RozmnozSie(Organizm* organizm) {
    if (this->GetStatusRozmnozenia() == true)return;
    if (organizm->GetStatusRozmnozenia() == true)return;
    if (this->GetZycie() == false)return;
    if (organizm->GetZycie() == false)return;
    if (wiek < 15)return;
    int x;
    int y;
    bool rozmnazanie = false;

    if (swiat->czyPoleWolne(pozycja.GetX() + 1, pozycja.GetY()) == true && pozycja.GetX() + 1 < swiat->GetWidth()) {
        x = pozycja.GetX() + 1;
        y = pozycja.GetY();
        rozmnazanie = true;
    }
    else if (swiat->czyPoleWolne(pozycja.GetX() - 1, pozycja.GetY()) == true && pozycja.GetX() - 1 >= 0) {
        x = pozycja.GetX() - 1;
        y = pozycja.GetY();
        rozmnazanie = true;
    }
    else if (swiat->czyPoleWolne(pozycja.GetX(), pozycja.GetY() + 1) == true && pozycja.GetY() < swiat->GetHeight()) {
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
        if (x == false && y == true)return;
        if(x == true && y== false)return;
        swiat->DodajOrganizm(GetSymbol(),x,y);
        this->SetStatusRozmnozenia(true);
        organizm->SetStatusRozmnozenia(true);
        string komunikat = "Urodziny: nowy " + WypiszImie() + " (" + to_string(x) + ", " + to_string(y) + ") ";
        swiat->komunikaty.WypiszKomunikat(komunikat);
    }
}