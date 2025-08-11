#include "Zadatak.h"

Zadatak::Zadatak(int _id, double _tezina, double _brLinija)
	:IspitniMaterijal(_id, _tezina)
{
	this->brLinija = _brLinija;
}

Zadatak::Zadatak(const Zadatak& drugi)
{
	this->id = drugi.id;
	this->tezina = drugi.tezina;
	this->status = drugi.status;
	this->brLinija = drugi.brLinija;
}

Zadatak::~Zadatak()
{
	id = tezina = status = brLinija = 0;
}

void Zadatak::print(ostream& os)
{
	os << id << " " << tezina << " " << brLinija << " ";
	if (status)
	{
		os << "Savladan";
	}
	else
	{
		os << "Nije";
	}
}

float Zadatak::Vreme(float vrednost)
{
	return tezina * brLinija * vrednost * 0.05;
}

Zadatak& Zadatak::operator=(Zadatak& obj)
{
	this->id = obj.id;
	this->tezina = obj.tezina;
	this->status = obj.status;
	this->brLinija = obj.brLinija;
	return *this;
}
