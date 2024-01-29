#include "Informator.h"
using namespace std;

Informator::Informator() {
    position.X = 50;
    position.Y = 0;
}

void Informator::WypiszKomunikat(string komunikat) {
    HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleCursorPosition(hOut, position);
    cout << komunikat << endl;
    position.Y++;
}

void Informator::WypiszKomunikat(char komunikat) {
    HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleCursorPosition(hOut, position);
    cout << komunikat << endl;
    position.X++;
}

void Informator::SetY(int a) {
    position.Y = a;
}

void Informator::SetX(int a) {
    position.X = a;
}

int Informator::GetX() {
    return position.X;
}