#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "Swiat.h"
#include "Properties.h"
#include "Organizm.h"
#include "Zwierze.h"
#include "Wilk.h"
#include "Owca.h"
#include <random>
#include <conio.h>
using namespace std;

int main() {
	Swiat swiat(BOARD_HEIGHT, BOARD_WIDTH);
	char a;
	cout << "Press 'P' to start the game";
	do {
		a = _getch();
		if (a == ARROWLEFT || a==ARROWRIGHT || a==ARROWDOWN || a==ARROWUP || a=='r' || a=='p' || a=='s' || a=='l') {
			if (a == ARROWLEFT)a = 'A';
			if (a == ARROWRIGHT)a = 'D';
			if (a == ARROWUP)a = 'W';
			if (a == ARROWDOWN)a = 'S';
			if (a == 's')swiat.SaveTheGame();
			if (a == 'l')swiat.LoadTheGame();
			swiat.SetKlawisz(a);
			system("cls");
			swiat.wykonajTure();
			swiat.rysujSwiat();
		}
	} while (a != 'q');
	return 0;
}