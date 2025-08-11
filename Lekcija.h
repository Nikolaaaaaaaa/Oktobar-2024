#pragma once
#include "IspitniMaterijal.h"

class Lekcija : public IspitniMaterijal
{
protected:
	double duzina;
public:
	Lekcija(int _id, double _tezina, double _duzina);
	Lekcija(const Lekcija& drugi);
	~Lekcija();

	void print(ostream& os)override;

	float Vreme(float vrednost) override;

	Lekcija& operator=(Lekcija& obj);
};
