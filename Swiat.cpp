#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <conio.h>
#include <string.h>
#include "Swiat.h"
#include "Organizm.h"
#include "Wilk.h"
#include "Antylopa.h"
#include "Owca.h"
#include "Lis.h"
#include "Zolw.h"
#include "Trawa.h"
#include "Mlecz.h"
#include "Guarana.h"
#include "WilczeJagody.h"
#include "BarszczSosnowskiego.h"
#include "Czlowiek.h"
//using namespace std;

Swiat::Swiat(const int& HEIGHT, const int& WIDTH) {
	this->HEIGHT = HEIGHT;
	this->WIDTH = WIDTH;
    this->klawisz = 0;
    this->LiczbaTurNaUlt = 0;
    this->DelayUlt = 5;

    for (int y = 0; y < HEIGHT; y++) {
        for (int x = 0; x < WIDTH; x++) {
            if(x!=8 && y!=8)WylosujStartoweOrganizmy(x, y);
            if(x==8 && y==8)organizmy.push_back(new Czlowiek(x, y, this, INICJATYWA_CZLOWIEKA, SILA_CZLOWIEKA, SYMBOL_CZLOWIEKA));
        }
    }
}

char Swiat::GetKlawisz() {
    return klawisz;
}

void Swiat::SetKlawisz(char klawisz) {
    this->klawisz = klawisz;
}

Swiat::~Swiat() {
    for (Organizm* organizm : organizmy) {
        delete organizm;
    }
}

int Swiat::GetHeight() {
	return HEIGHT;
}

int Swiat::GetWidth() {
	return WIDTH;
}

int Swiat::GetOrganizmySize() {
    return organizmy.size();
}

void Swiat::wykonajTure() {
    sort(organizmy.begin(), organizmy.end(), [](Organizm* a, Organizm* b) {
        if (a->GetInicjatywa() != b->GetInicjatywa()) return a->GetInicjatywa() < b->GetInicjatywa();
        else return (a->GetWiek() < b->GetWiek());
        });
    for (int i = 0; i < organizmy.size(); i++) {
        Organizm* organizm = organizmy[i];
        if(organizm->GetStatusRozmnozenia()==false && organizm->GetWiek() != 0)organizm->Akcja();
        if (organizm->GetStatusRozmnozenia() == false && organizm->GetWiek() != 0)organizm->Kolizja();
    }
    for (int i = 0; i < organizmy.size(); i++) {
        Organizm* organizm = organizmy[i];
        organizm->SetStatusRozmnozenia(false);
        organizm->Urodziny();
    }
    UsunOrganizmy();
    komunikaty.SetY(0);
}

void Swiat::rysujSwiat() {
    COORD start;
    start.X = 0;
    start.Y = 0;
    HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleCursorPosition(hOut, start);
    bool PustePole = 1;
    cout << "   ";
    for (int i = 0; i < BOARD_WIDTH; i++) {
        if (i < 10)cout << i << " ";
        else cout << i-10<<" ";
    }
    cout << endl;
    cout << "   ";
    for (int i = 0; i < BOARD_WIDTH; i++) {
        cout << "_ ";
    }
    cout << endl;
    for (int y = 0; y < HEIGHT; y++) {
        cout << y;
        if (y > 9)cout << "|";
        else cout << " |";
        for (int x = 0; x < WIDTH; x++) {
            Organizm* wyrysowywany = nullptr;
            wyrysowywany = ZnajdzOrganizm(x, y);
            if (wyrysowywany != nullptr && wyrysowywany->GetZycie()==true) {
                wyrysowywany->Rysowanie();
                cout << " ";
                PustePole = 0;
            }
            else if (PustePole == 1)cout << ". ";
            PustePole = 1;
        }
        cout << endl;
    }
}

void Swiat::WylosujStartoweOrganizmy(int x, int y) {
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dis(1, 100);
    int los = dis(gen);
    if (los > 2 && los < 6) {
       organizmy.push_back(new Wilk(x, y, this, INICJATYWA_WILKA, SILA_WILKA, SYMBOL_WILKA));
    }
    if (los > 7 && los < 11) {
       organizmy.push_back(new Owca(x, y, this, INICJATYWA_OWCY, SILA_OWCY, SYMBOL_OWCY));
    }
    if (los > 12 && los < 15) {
        organizmy.push_back(new Lis(x, y, this, INICJATYWA_LISA, SILA_LISA, SYMBOL_LISA));
    }
    if (los > 15 && los < 17) {
        organizmy.push_back(new Zolw(x, y, this, INICJATYWA_ZOLWIA, SILA_ZOLWIA, SYMBOL_ZOLWIA));
    }
    if (los > 17 && los < 21) {
        organizmy.push_back(new Antylopa(x, y, this, INICJATYWA_ANTYLOPY, SILA_ANTYLOPY, SYMBOL_ANTYLOPY));
    }
    if (los > 22 && los < 25) {
       organizmy.push_back(new Trawa(x, y, this, 100, 0, SYMBOL_TRAWY));
    }
    if (los > 25 && los < 27) {
       organizmy.push_back(new Mlecz(x, y, this, 100, 0, SYMBOL_MLECZA));
    }
    if (los > 27 && los < 30) {
        organizmy.push_back(new Guarana(x, y, this, 100, 0, SYMBOL_GUARANY));
    }
    if (los > 30 && los < 32) {
        organizmy.push_back(new WilczeJagody(x, y, this, 100, SILA_WILECZEJJAGODY, SYMBOL_WILCZEJJAGODY));
    }
    if (los > 32 && los < 34) {
        organizmy.push_back(new BarszczSosnowskiego(x, y, this, 100, SILA_BARSZCZU, SYMBOL_BARSZCZU));
    }
}

Organizm* Swiat::ZnajdzOrganizm(int x, int y) {
    Organizm* temp = nullptr;
    for (int i = 0; i < organizmy.size();i++) {
        Organizm* organizm = organizmy[i];
        if (organizm->GetX() == x && organizm->GetY() == y && organizm->GetZycie() == true) {
            if (temp == nullptr || temp->GetInicjatywa() < organizm->GetInicjatywa()) {
                temp = organizm;
            }
        }
    }
    return temp;
}

void Swiat::DodajOrganizm(char symbol, int x, int y) {
    Organizm* temp = nullptr;
    if (symbol == SYMBOL_WILKA)temp = new Wilk(x, y, this, INICJATYWA_WILKA, SILA_WILKA, SYMBOL_WILKA);
    if (symbol == SYMBOL_OWCY)temp = new Owca(x, y, this, INICJATYWA_OWCY, SILA_OWCY, SYMBOL_OWCY);
    if (symbol == SYMBOL_LISA)temp = new Lis(x, y, this, INICJATYWA_LISA, SILA_LISA, SYMBOL_LISA);
    if (symbol == SYMBOL_ZOLWIA)temp = new Zolw(x, y, this, INICJATYWA_ZOLWIA, SILA_ZOLWIA, SYMBOL_ZOLWIA);
    if (symbol == SYMBOL_ANTYLOPY)temp = new Antylopa(x, y, this, INICJATYWA_ANTYLOPY, SILA_ANTYLOPY, SYMBOL_ANTYLOPY);
    if (symbol == SYMBOL_TRAWY)temp = new Trawa(x, y, this, 0, 0, SYMBOL_TRAWY);
    if (symbol == SYMBOL_MLECZA)temp = new Mlecz(x, y, this, 0, 0, SYMBOL_MLECZA);
    if (symbol == SYMBOL_GUARANY)temp = new Guarana(x, y, this, 0, 0, SYMBOL_GUARANY);
    if (symbol == SYMBOL_WILCZEJJAGODY)temp = new WilczeJagody(x, y, this, 0, SILA_WILECZEJJAGODY, SYMBOL_WILCZEJJAGODY);
    if (symbol == SYMBOL_BARSZCZU)temp = new BarszczSosnowskiego(x, y, this, 0, SILA_BARSZCZU, SYMBOL_BARSZCZU);
    if (temp != nullptr) {
        organizmy.push_back(temp);
        temp->SetStatusRozmnozenia(true);
    }
}

void Swiat::WczytajOrganizm(char symbol, int sila, int wiek, int x, int y) {
    Organizm* temp = nullptr;
    if (symbol == SYMBOL_WILKA)temp = new Wilk(x, y, this, INICJATYWA_WILKA, SILA_WILKA, SYMBOL_WILKA);
    if (symbol == SYMBOL_OWCY)temp = new Owca(x, y, this, INICJATYWA_OWCY, SILA_OWCY, SYMBOL_OWCY);
    if (symbol == SYMBOL_LISA)temp = new Lis(x, y, this, INICJATYWA_LISA, SILA_LISA, SYMBOL_LISA);
    if (symbol == SYMBOL_ZOLWIA)temp = new Zolw(x, y, this, INICJATYWA_ZOLWIA, SILA_ZOLWIA, SYMBOL_ZOLWIA);
    if (symbol == SYMBOL_ANTYLOPY)temp = new Antylopa(x, y, this, INICJATYWA_ANTYLOPY, SILA_ANTYLOPY, SYMBOL_ANTYLOPY);
    if (symbol == SYMBOL_TRAWY)temp = new Trawa(x, y, this, 0, 0, SYMBOL_TRAWY);
    if (symbol == SYMBOL_MLECZA)temp = new Mlecz(x, y, this, 0, 0, SYMBOL_MLECZA);
    if (symbol == SYMBOL_GUARANY)temp = new Guarana(x, y, this, 0, 0, SYMBOL_GUARANY);
    if (symbol == SYMBOL_WILCZEJJAGODY)temp = new WilczeJagody(x, y, this, 0, SILA_WILECZEJJAGODY, SYMBOL_WILCZEJJAGODY);
    if (symbol == SYMBOL_BARSZCZU)temp = new BarszczSosnowskiego(x, y, this, 0, SILA_BARSZCZU, SYMBOL_BARSZCZU);
    if (temp != nullptr) {
        organizmy.push_back(temp);
        temp->SetStatusRozmnozenia(true);
        temp->SetSila(sila);
        temp->SetWiek(wiek);
        if (symbol < 65 || symbol > 122) {
            temp->SetZycie(false);
        }
    }
}

bool Swiat::czyPoleWolne(int x, int y) {
    for (Organizm* organizm : organizmy) {
        if ((organizm->GetX() == x && organizm->GetY() == y) || (organizm->GetLastPozycja().GetX()==x && organizm->GetLastPozycja().GetY() == y)) {
            return false;
        }
    }
    return true;
}

void Swiat::SmiercOrganizmu(Organizm* organizm) {
    Punkt polozenie_new = organizm->GetPozycja();
    organizm->SetZycie(false);
};

void Swiat::UsunOrganizmy() {
    organizmy.erase(remove_if(organizmy.begin(), organizmy.end(), [](Organizm* organizm) {
        return !organizm->GetZycie();
        }), organizmy.end());
}

int Swiat::GetLiczbaTurNaUlt() {
    return LiczbaTurNaUlt;
}

int Swiat::GetDelayUlt() {
    return DelayUlt;
}

void Swiat::SetLiczbaTurNaUlt(int a) {
    LiczbaTurNaUlt = a;
}

void Swiat::SetDelayUlt(int a) {
    DelayUlt = a;
}

void Swiat::SaveTheGame() {
    char disc[30] = { };
    char a;
    int i = 0;
    system("cls");
    cout << "Save: ";
    komunikaty.SetX(6);
    for (;;) {
        a = _getch();
        komunikaty.WypiszKomunikat(a);
        if (a == ESCAPE)return;
        else if (a == ENTER) {
            disc[i] = '\0';
            break;
        }
        else {
            disc[i] = a;
            i++;
        }
    }
    ofstream file;
    file.open(disc);
    file << organizmy.size() << endl;
    for (Organizm* organizm : organizmy) {
        file << organizm->GetSymbol() << " " << organizm->GetSila() << " " << organizm->GetWiek() << " " << organizm->GetX() << " " << organizm->GetY() << endl;
    }
    file.close();
    komunikaty.SetX(50);
}
void Swiat::LoadTheGame() {
    char symbol='a';
    int x=100;
    int y = 100;
    int wiek = 100;
    int sila = 0;
    int ilosc = 0;
    char disc[30] = { };
    char a;
    int i = 0;
    system("cls");
    cout << "Load: ";
    komunikaty.SetX(6);
    for (;;) {
        a = _getch();
        komunikaty.WypiszKomunikat(a);
        if (a == ESCAPE)return;			//petla ktora wczytuje i wyswietla po kolei wpisane znaki do tablicy charow
        else if (a == ENTER) {
            disc[i] = '\0';
            break;
        }
        else {
            disc[i] = a;
            i++;
        }
    }
    ifstream file;
    for (Organizm* organizm : organizmy) {
        organizm->SetZycie(false);
    }
    UsunOrganizmy();
    int size = 0;
    file.open(disc);
    file >> size;
    for (int i = 0; i < size;i++) {
        file >> symbol >> sila >> wiek >> x >> y;
        WczytajOrganizm(symbol, sila, wiek, x, y);
    }
    file.close();
    komunikaty.SetX(50);
}