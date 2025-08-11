#pragma once
#include "Lekcija.h"
#include "Zadatak.h"

class IspitPriprema
{
private:
	IspitniMaterijal** niz;
	int uk;
	int tr;
public:
	IspitPriprema(int _uk);
	~IspitPriprema();

	//resize
	void Dodaj(IspitniMaterijal* obj);
	void Obrisi(int br);
	void Savladaj(int br);
	int UkupnoSavladanih();
	float UkupnoVreme(float vrednost);

	void VratiNaj(float vrednost, IspitniMaterijal** min, IspitniMaterijal** max);


	friend ostream& operator<<(ostream& os, IspitPriprema& obj);
};
