#include "IspitPriprema.h"

ostream& operator<<(ostream& os, IspitPriprema& obj)
{
    for (int i = 0; i < obj.tr; i++)
    {
        obj.niz[i]->print(os);
        os << endl;
    }
    return os;
}

IspitPriprema::IspitPriprema(int _uk)
{
    this->uk = _uk;
    this->tr = 0;
    niz = new IspitniMaterijal * [uk];
}

IspitPriprema::~IspitPriprema()
{
    for (int i = 0; i < uk; i++)
    {
        delete niz[i];
    }
    uk = tr = 0;
    delete[] niz;
}

void IspitPriprema::Dodaj(IspitniMaterijal* obj)
{
    if (tr >= uk)
    {
        cout << "PUN!!!" << endl;
        return;
    }
    niz[tr++] = obj;
}

void IspitPriprema::Obrisi(int br)
{
    if (br >= tr)
    {
        cout << "NEMA TAJ BROJ!!!" << endl;
        return;
    }
    if (niz[br - 1]->isSavladan())
    {
        cout << "NE mozes da obrises vec savladan materijal!!!" << endl;
        return;
    }
    for (int i = br-1; i < tr; i++)
    {
        niz[i] = niz[i + 1];
    }
    /*delete niz[tr];*/
    tr--;
}

void IspitPriprema::Savladaj(int br)
{
    if (br >= tr)
    {
        cout << "NEMA TAJ BROJ!!!" << endl;
        return;
    }
    niz[br - 1]->SavladajMaterijal();
    cout <<"materijal "<<*niz[br-1] << " je savladan" << endl;
}

int IspitPriprema::UkupnoSavladanih()
{
    int sum = 0;
    for (int i = 0; i < tr; i++)
    {
        if (niz[i]->isSavladan())
            sum++;
    }
    return sum;
}

float IspitPriprema::UkupnoVreme(float vrednost)
{
    float sum = 0;
    for (int i = 0; i < tr; i++)
    {
        sum += niz[i]->Vreme(vrednost);
    }
    return sum;
}

void IspitPriprema::VratiNaj(float vrednost, IspitniMaterijal** min, IspitniMaterijal** max)
{
    int imin = 0;
    int imax = 0;
    for (int i = 1; i < tr; i++)
    {
        if (niz[i]->Vreme(vrednost) < niz[imin]->Vreme(vrednost))
        {
            imin = i;
            continue;
        }
        if (niz[i]->Vreme(vrednost) > niz[imax]->Vreme(vrednost))
        {
            imax = i;
            continue;
        }
    }
    *min = niz[imin];
    *max = niz[imax];
}

//t=6
//br=3
//        t-1 t
//0 1 2 3  4  5

