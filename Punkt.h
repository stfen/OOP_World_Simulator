#pragma once
#include <iostream>
using namespace std;

class Punkt {
	int x;
	int y;
public:
	void SetX(const int& x);
	void SetY(const int& y);
	int GetX();
	int GetY();
	Punkt();
	bool operator==(const Punkt& other) const;
};