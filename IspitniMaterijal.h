#pragma once
#include "iostream"
using namespace std;

class IspitniMaterijal
{
protected:
	int id;
	double tezina;
	bool status; //true<=>savladan false<=>nije savladan
public:
	IspitniMaterijal() = default;
	IspitniMaterijal(int _id, double _tezina);
	~IspitniMaterijal()=default;
	IspitniMaterijal(const IspitniMaterijal& drugi);

	virtual void print(ostream& os) = 0;

	virtual bool isSavladan() const { return status; };
	virtual void SavladajMaterijal();
	virtual float Vreme(float vrednost) = 0;

	friend ostream& operator<<(ostream& os, IspitniMaterijal& obj);
	IspitniMaterijal& operator=(IspitniMaterijal& obj);
};