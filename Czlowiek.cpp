#pragma once
#include "Czlowiek.h"

Czlowiek::Czlowiek(int x, int y, Swiat* swiat, int inicjatywa, int sila, char symbol) : Zwierze(x, y, swiat, inicjatywa, sila, symbol) {}

string Czlowiek::WypiszImie() {
	return "CZLOWIEK";
}

void Czlowiek::Akcja() {
	if (swiat->GetLiczbaTurNaUlt() == 5) {
		string komunikat = "Oslabienie: " + WypiszImie() + " (" + to_string(GetX()) + ", " + to_string(GetY()) + ") jest ponownie mozliwy do zabicia";
		swiat->komunikaty.WypiszKomunikat(komunikat);
		UmiejetnoscSpecjalna = false;
	}
	if (UmiejetnoscSpecjalna == true)swiat->SetLiczbaTurNaUlt(swiat->GetLiczbaTurNaUlt() + 1);
	char a = swiat->GetKlawisz();
	if (a == 'W' && pozycja.GetY() < swiat->GetHeight() - 1)pozycja.SetY(pozycja.GetY() - 1);
	if (a == 'S' && pozycja.GetY() > 0)pozycja.SetY(pozycja.GetY() + 1);
	if (a == 'A' && pozycja.GetX() > 0)pozycja.SetX(pozycja.GetX() - 1);
	if (a == 'D' && pozycja.GetX() < swiat->GetWidth() - 1)pozycja.SetX(pozycja.GetX() + 1);
	if (a == 'r' && swiat->GetDelayUlt() >= 5) {
		UmiejetnoscSpecjalna = true;
		swiat->SetDelayUlt(0);
		swiat->SetLiczbaTurNaUlt(0);
		string komunikat = "Bonus: " + WypiszImie() + " (" + to_string(GetX()) + ", " + to_string(GetY()) + ") jest teraz niesmiertelny";
		swiat->komunikaty.WypiszKomunikat(komunikat);
	}
}

void Czlowiek::Kolizja() {
	if (UmiejetnoscSpecjalna == false) {
		swiat->SetDelayUlt(swiat->GetDelayUlt() + 1);
		bool kolizja = 0;
		Organizm* organizmAtakujacy = nullptr;
		for (auto* organizm : swiat->organizmy) {
			if (organizm->GetX() == pozycja.GetX() && organizm->GetY() == pozycja.GetY() && organizm != this && organizm->GetZycie() == true) {
				kolizja = 1;
				organizmAtakujacy = organizm;
			}
		}
		if (kolizja == 1) {
			if (this->sila > organizmAtakujacy->GetSila()) {
				swiat->SmiercOrganizmu(organizmAtakujacy);
				string komunikat = "Walka: " + WypiszImie() + " pokonal " + organizmAtakujacy->WypiszImie() + " (" + to_string(organizmAtakujacy->GetX()) + ", " + to_string(organizmAtakujacy->GetY()) + ")";
				swiat->komunikaty.WypiszKomunikat(komunikat);

			}
			if (this->sila < organizmAtakujacy->GetSila()) {
				swiat->SmiercOrganizmu(this);
				string komunikat = "Walka: " + organizmAtakujacy->WypiszImie() + " pokonal " + WypiszImie() + " (" + to_string(organizmAtakujacy->GetX()) + ", " + to_string(organizmAtakujacy->GetY()) + ")";
				swiat->komunikaty.WypiszKomunikat(komunikat);
			}
		}
	}
	else if (UmiejetnoscSpecjalna == true) {
		bool kolizja = 0;
		Organizm* organizmAtakujacy = nullptr;
		for (auto* organizm : swiat->organizmy) {
			if (organizm->GetX() == pozycja.GetX() && organizm->GetY() == pozycja.GetY() && organizm != this && organizm->GetZycie() == true) {
				kolizja = 1;
				organizmAtakujacy = organizm;
			}
		}
		if (kolizja == 1) {
			if (this->sila < organizmAtakujacy->GetSila()) {
				Zwierze::Akcja();
			}
		}
	}
}