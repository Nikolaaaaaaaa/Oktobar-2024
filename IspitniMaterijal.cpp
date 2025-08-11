#include "IspitniMaterijal.h"

IspitniMaterijal::IspitniMaterijal(int _id, double _tezina)
{
	this->id = _id;
	this->tezina = _tezina;
	status = false;
}

IspitniMaterijal::IspitniMaterijal(const IspitniMaterijal& drugi)
{
	this->id = drugi.id;
	this->tezina = drugi.tezina;
	this->status = drugi.status;
}

void IspitniMaterijal::SavladajMaterijal()
{
	if (status == true)
	{
		cout << "Vec je savladan !!!" << endl;
		return;
	}
	status = true;
}

IspitniMaterijal& IspitniMaterijal::operator=(IspitniMaterijal& obj)
{
	this->id = obj.id;
	this->tezina = obj.tezina;
	this->status = obj.status;
	return *this;
}

ostream& operator<<(ostream& os, IspitniMaterijal& obj)
{
	obj.print(os);
	return os;
}
