#pragma once
#include "Header1.hpp"

template<typename T>
NGrid<T, 1>::NGrid(int newSeize): mSize(newSeize)
{
	try
	{
		mElements = new T[mSize];
	}
	catch (...) //dowolony wyj¹tek, jaki powstanie - tutaj z³a alokacja pamiêci
	{
		delete[] mElements; //wyczyszczenie pamiêci zajmowaniej przed pojawieniem siê z³ej alokacji
		//mElements = nullptr;
		//mSize = 0;
		//tutaj obiekt jest dopiero tworzony, zatem nie trzeba zerowaæ pocz¹tkowych wartoœci

		//throw std::bad_alloc;//dopiero tutaj wyrzucenie wyj¹tku bad_alloc po wczeœniejszym zwolnieniu pamiêci
		//gdybyœmy najpierw wyrzucili wyj¹tek, wtedy mog³oby dojœæ do wyceiku pamiêci
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
	ta funkcja s³u¿y tylko do kopiowania, ewentualne czyszczenie pamiêci znajduje siê na zewn¹trz funkcji
	*/

	mSize = t.mSize;//nowy rozmiar
	mElements = new T[mSize]; //tyle samo wierszy co "t", 
	int i;
	try
	{
		for (i = 0; i < mSize; i++)
			mElements[i] = t.mElements[i];
	}
	catch (...) //³apanie jakichkolwiek wyj¹tków
	{
		for (int j = 0; j < i; j++)
		{
			delete mElements[j]; //usuwanie poszczególnych elementów
		}
		delete[] mElements; //usuniêcie ca³ej tablicy
		//zerowanie pocz¹tkowych wartoœci, aby ³atwiej by³o destruktorowi:
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
	CopyFrom(t); //tutaj obs³uga wyj¹tku odbywa siê wewn¹trz funkcji CopyFrom, zatem nie potrzeba jej na zewn¹trz
	return *this;
}

template<typename T>
void NGrid<T, 1>::resize(int newSize)
{
	T* tElemetns = new T[newSize];
	for (int i = 0; i < mSize && i < newSize; i++)
	{
		tElemetns[i] = mElements[i];
		//tutaje nie ma potrzeby rekurencyjnego powtarzania do ni¿szych poziomów, bo ta klasa jest bazowa
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


