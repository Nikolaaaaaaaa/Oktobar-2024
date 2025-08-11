#include "Lekcija.h"

Lekcija::Lekcija(int _id, double _tezina, double _duzina)
	:IspitniMaterijal(_id,_tezina)
{
	this->duzina = _duzina;
}

Lekcija::Lekcija(const Lekcija& drugi)
{
	this->id = drugi.id;
	this->tezina = drugi.tezina;
	this->status = drugi.status;
	this->duzina = drugi.duzina;
}

Lekcija::~Lekcija()
{
	id = tezina = status = duzina = 0;
}

void Lekcija::print(ostream& os)
{
	os << id << " " << tezina << " " << duzina << " ";
	if (status)
	{
		os << "Savladan";
	}
	else
	{
		os << "Nije";
	}
}

float Lekcija::Vreme(float vrednost)
{
	return duzina * tezina * vrednost;
}

Lekcija& Lekcija::operator=(Lekcija& obj)
{
	this->id = obj.id;
	this->tezina = obj.tezina;
	this->status = obj.status;
	this->duzina = obj.duzina;
	return *this;
}
