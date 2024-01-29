#pragma once
#include "Organizm.h"

Organizm::Organizm(int x, int y, Swiat* swiat, int inicjatywa, int sila, char symbol) {
	wiek = 0;
	pozycja.SetX(x);
	pozycja.SetY(y);
	this->swiat = swiat;
	this->inicjatywa = inicjatywa;
	this->sila = sila;
	this->symbol = symbol;
	this->dobrywech = false;
	this->umiejetnoscOdbiciaAtaku = false;
	this->CzyMaSzanseNaUcieczke = false;
	this->CzyNastapiloRozmnozenie = false;
	this->UmiejetnoscSpecjalna = false;
	this->RozmiarRuchu = 1;
}

void Organizm::Urodziny() {
	wiek++;
}

int Organizm::GetX() {
	return pozycja.GetX();
}

int Organizm::GetY() {
	return pozycja.GetY();
}

int Organizm::GetInicjatywa() {
	return inicjatywa;
}

bool Organizm::GetStatusRozmnozenia() {
	return CzyNastapiloRozmnozenie;
}
void Organizm::SetStatusRozmnozenia(bool a) {
	CzyNastapiloRozmnozenie = a;
}

int Organizm::GetSila() {
	return sila;
}

void Organizm::SetSila(int sila) {
	this->sila = sila;
}

char Organizm::GetSymbol() {
	return symbol;
}

Punkt Organizm::GetPozycja() {
	return pozycja;
}

void Organizm::SetPozycja(Punkt pozycja) {
	this->pozycja = pozycja;
}

Punkt Organizm::GetLastPozycja() {
	return poprzednia_pozycja;
}

bool Organizm::GetZycie() {
	return zywy;
}

void Organizm::SetZycie(bool a) {
	this->zywy = a;
}

int Organizm::GetWiek() {
	return wiek;
}

void Organizm::SetWiek(int a) {
	wiek = a;
}

bool Organizm::GetDobryWech() {
	return dobrywech;
}

bool Organizm::GetUmiejetnoscOdbicia() {
	return umiejetnoscOdbiciaAtaku;
}

bool Organizm::GetSzansaNaUcieczke() {
	return CzyMaSzanseNaUcieczke;
}

bool Organizm::GetUmiejetnoscSpecjalna() {
	return UmiejetnoscSpecjalna;
}

void Organizm::SetUmiejetnoscSpecjalna(bool a) {
	UmiejetnoscSpecjalna = a;
}

string Organizm::WypiszImie() {
	return "ORGANIZM";
}