#pragma once
#include "IspitniMaterijal.h"

class Zadatak : public IspitniMaterijal
{
protected:
	double brLinija;
public:
	Zadatak(int _id, double _tezina, double _brLinija);
	Zadatak(const Zadatak& drugi);
	~Zadatak();

	void print(ostream& os)override;

	float Vreme(float vrednost) override;

	Zadatak& operator=(Zadatak& obj);
};

