#include "LekcijaNormalna.h"

LekcijaNormalna::LekcijaNormalna(char* _naziv, float _tezina, float _duzina)
{
	strcpy(naziv, _naziv); 
	tezina = _tezina;
	duzina = _duzina;
}

float LekcijaNormalna::operator+(float vrednost)
{
	return this->Tezina()+vrednost;
}

bool LekcijaNormalna::operator>(float vrednost)
{
	if (this->Tezina() > vrednost)
		return true;
	else
		return false;
}

bool LekcijaNormalna::operator>(const LekcijaNormalna& obj)
{
	if (this->Tezina() > obj.Tezina())
		return true;
	else
		return false;
}

bool LekcijaNormalna::operator<(const LekcijaNormalna& obj)
{
	if (this->Tezina() < obj.Tezina())
		return true;
	else
		return false;
}

ostream& operator<<(ostream& os, const LekcijaNormalna& obj)
{
	os << obj.naziv << " " << obj.tezina << " " << obj.duzina;
	return os;
}

istream& operator>>(istream& is, LekcijaNormalna& obj)
{
	return is >> obj.naziv >> obj.tezina >> obj.duzina;
}
