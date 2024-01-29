#pragma once
#include "Punkt.h"
#include <iostream>

void Punkt::SetX(const int& x) {
	this->x = x;
}

void Punkt::SetY(const int& y) {
	this->y = y;
}

int Punkt::GetX() {
	return x;
}

int Punkt::GetY() {
	return y;
}

Punkt::Punkt() {
	this->x = 0;
	this->y = 0;
};

bool Punkt::operator==(const Punkt& other) const {
	return x == other.x && y == other.y;
}