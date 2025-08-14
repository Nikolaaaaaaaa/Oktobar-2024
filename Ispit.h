#pragma once
#include "iostream"
#include "fstream"
using namespace std;

template <typename T>
class Ispit
{
private:
	T* niz;
	int uk;
	int tr;
public:
	Ispit() = default;
	Ispit(int _uk);
	//~Ispit();

	void Dodaj(T obj);
	void Izbaci(int prvi, int drugi);
	float Ukupno();
	int UkupniBrojVrednost(float vrednost, float& ukupnaVrednost);
	void minMax(int a, int b, T& min, T& max);

	void Sacuvaj(const char* fajl);
	void Ucitaj(const char* fajl);

	friend ostream& operator<<(ostream& os, const Ispit<T>& obj)
	{
		os << obj.uk << endl;
		os << obj.tr << endl;
		for (int i = 0; i < obj.tr; i++)
		{
			os << obj.niz[i] << endl; //operator<<
		}
		return os;
	}

};

template<typename T>
inline Ispit<T>::Ispit(int _uk)
{
	uk = _uk;
	niz = new T[uk];
	tr = 0;
}

template<typename T>
inline void Ispit<T>::Dodaj(T obj)
{
	if (tr >= uk)
	{
		throw "KOLEKCIJA JE PUNA !!!";
	}
	niz[tr++] = obj; //operator=
}

template<typename T>
inline void Ispit<T>::Izbaci(int prvi, int drugi)
{
	for (int j = 1; j <= drugi; j++)
	{
		for (int i = prvi; i < tr; i++)
		{
			niz[i] = niz[i + 1];
		}
		tr--;
	}
	
}

template<typename T>
inline float Ispit<T>::Ukupno()
{
	float sum = 0;
	for (int i = 0; i < tr; i++)
	{
		sum = niz[i] + sum; //operator+(float)
	}
	return sum;
}

template<typename T>
inline int Ispit<T>::UkupniBrojVrednost(float vrednost, float& ukupnaVrednost)
{
	int sum = 0;

	for (int i = 0; i < tr; i++)
	{
		if (niz[i] > vrednost) //operator>(float)
		{
			sum++;
			ukupnaVrednost = niz[i] + ukupnaVrednost;
		}
	}

	return sum;
}

template<typename T>
inline void Ispit<T>::minMax(int a, int b, T& min, T& max)
{
	if (a<0 || b<0 || a>tr || b>tr || b < a)
	{
		throw "GRANICNI USLOVI LOSI !!!";
	}
	int imin = a;
	int imax = a;

	for (int i = a; i <= b; i++)
	{
		if (niz[i] < niz[imin]) //operator<(T)
			imin = i;
		if (niz[i] > niz[imax]) //operator>(T)
			imax = i;
	}
	min = niz[imin];
	max = niz[imax];
}

template<typename T>
inline void Ispit<T>::Sacuvaj(const char* fajl)
{
	fstream izlaz;
	izlaz.open(fajl, ios::out);

	if (izlaz.good())
	{
		izlaz << *this;
		izlaz.close();
		cout << "Upisano u fajl" << endl;
	}
	else
	{
		throw "GRESKA PRI UPISIVANJU U FAJL !!!";
	}
}

template<typename T>
inline void Ispit<T>::Ucitaj(const char* fajl)
{
	fstream ulaz;
	ulaz.open(fajl, ios::in);

	if (ulaz.good())
	{
		tr = 0;
		ulaz >> uk;
		ulaz >> tr;
		delete[] niz;
		niz = new T[uk];
		for (int i = 0; i < tr; i++)
		{
			ulaz >> niz[i]; //operator>>
		}
		ulaz.close();
		cout << "Ucitano iz fajla" << endl;
	}
	else
	{
		throw"GRESKA PRI UCITAVANJU IZ FAJLA !!!";
	}
}
