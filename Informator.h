#pragma once
#include <iostream>
#include <string>
#include <windows.h>
#include "Punkt.h"

class Informator {
    COORD position;
public:
    Informator();
    void SetY(int a);
    void SetX(int a);
    int GetX();
    void WypiszKomunikat(string komunikat);
    void WypiszKomunikat(char komunikat);
};