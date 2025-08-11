#pragma once
#include "iostream"
#include "string.h"
using namespace std;



class LekcijaNormalna
{
private:
	char naziv[8];
	float tezina;
	float duzina;
public:
	LekcijaNormalna() = default;
	LekcijaNormalna(char* _naziv, float _tezina, float _duzina);

	inline float Tezina() const { return tezina * duzina; };

	float operator+(float vrednost);
	bool operator>(float vrednost);
	bool operator>(const LekcijaNormalna& obj);
	bool operator<(const LekcijaNormalna& obj);

	friend ostream& operator<<(ostream& os, const LekcijaNormalna& obj);
	friend istream& operator>>(istream& is, LekcijaNormalna& obj);

};