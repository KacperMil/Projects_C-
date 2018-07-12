#pragma once
#include "Header1.hpp"

template<typename T>
NGrid<T, 1>::NGrid(int newSeize): mSize(newSeize)
{
	try
	{
		mElements = new T[mSize];
	}
	catch (...) //dowolony wyj�tek, jaki powstanie - tutaj z�a alokacja pami�ci
	{
		delete[] mElements; //wyczyszczenie pami�ci zajmowaniej przed pojawieniem si� z�ej alokacji
		//mElements = nullptr;
		//mSize = 0;
		//tutaj obiekt jest dopiero tworzony, zatem nie trzeba zerowa� pocz�tkowych warto�ci

		//throw std::bad_alloc;//dopiero tutaj wyrzucenie wyj�tku bad_alloc po wcze�niejszym zwolnieniu pami�ci
		//gdyby�my najpierw wyrzucili wyj�tek, wtedy mog�oby doj�� do wyceiku pami�ci
	}
	
}

template<typename T>
NGrid<T, 1>::NGrid(const NGrid<T, 1> & t)
{
	CopyFrom(t);
}

template<typename T>
NGrid<T, 1>::~NGrid()
{
	delete[] mElements;
}

template<typename T>
void NGrid<T, 1>::CopyFrom(const NGrid<T, 1> & t)
{
	/*
	ta funkcja s�u�y tylko do kopiowania, ewentualne czyszczenie pami�ci znajduje si� na zewn�trz funkcji
	*/

	mSize = t.mSize;//nowy rozmiar
	mElements = new T[mSize]; //tyle samo wierszy co "t", 
	int i;
	try
	{
		for (i = 0; i < mSize; i++)
			mElements[i] = t.mElements[i];
	}
	catch (...) //�apanie jakichkolwiek wyj�tk�w
	{
		for (int j = 0; j < i; j++)
		{
			delete mElements[j]; //usuwanie poszczeg�lnych element�w
		}
		delete[] mElements; //usuni�cie ca�ej tablicy
		//zerowanie pocz�tkowych warto�ci, aby �atwiej by�o destruktorowi:
		mElements = nullptr;
		mSize = 0;
		//throw std::bad_alloc;
	}

}

template<typename T>
NGrid<T, 1> & NGrid<T, 1>::operator=(const NGrid<T, 1> & t)
{
	if (this == &t)
		return *this;
	//free old memory:
	delete[] mElements;
	CopyFrom(t); //tutaj obs�uga wyj�tku odbywa si� wewn�trz funkcji CopyFrom, zatem nie potrzeba jej na zewn�trz
	return *this;
}

template<typename T>
void NGrid<T, 1>::resize(int newSize)
{
	T* tElemetns = new T[newSize];
	for (int i = 0; i < mSize && i < newSize; i++)
	{
		tElemetns[i] = mElements[i];
		//tutaje nie ma potrzeby rekurencyjnego powtarzania do ni�szych poziom�w, bo ta klasa jest bazowa
	}
	delete[]mElements;
	mElements = tElemetns;
	mSize = newSize;

}

template<typename T>
T& NGrid<T, 1>::operator[](int x)
{
	if (x < 0 || x >= mSize)
	{
		throw std::out_of_range("Invalid size");
	}
	return mElements[x];
}

template<typename T>
const T& NGrid<T, 1>::operator[](int x) const
{
	if (x < 0 || x >= mSize)
	{
		throw std::out_of_range("Invalid size");
	}
	return mElements[x]
}


