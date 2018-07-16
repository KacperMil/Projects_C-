#pragma once
#include "Header1.hpp"


template<typename T, int N>
NGrid<T, N>::NGrid(int newSize) : mSize(newSize)
{
	mElements = new NGrid<T, N - 1>[mSize]; //utowrzenie nowej tabliicyy, w ka¿dej wymiar o 1 mniejszy

	//zosta³y utowrzone nowe p³aszczyzny, jednak ka¿da z nich ma domyœlny rozmiar kDefaultSize = 5
	//aby go zmieniæ na newSize, musimy zadaæ go rêcznie ka¿demu wymiarowi
	//st¹d u¿ycie funkcji resize, na ka¿dym elementcie mElements NGrid<T,N>
	//czyli zmiana wymiaru ka¿dego wymiaru na mSize
	for (int i = 0; i < mSize; i++)
		mElements[i].resize(newSize);
}

template<typename T, int N>
NGrid<T, N>::NGrid() : mSize(cDefaultSize)
{
	//tutaj nie zmieniamy wymiaru p³aszczyzn, zatem nie trzeba u¿ywaæ funkcji resize, stosujemy domyœlnie cDefaultSize
	mElements = new NGrid<T, N - 1>[mSize];
}

template<typename T, int N>
NGrid<T, N>::NGrid(const NGrid<T, N> & t)
{
	CopyFrom(t);
}

template<typename T, int N>
NGrid<T, N>::~NGrid()
{
	delete[] mElements;
}

template<typename T, int N>
void NGrid<T, N>::CopyFrom(const NGrid<T, N> & t)
{
	mSize = t.mSize;
	mElements = new NGrid<T, N - 1>[mSize];
	for (int i = 0; i < mSize; i++)
	{
		mElements[i] = t.mElements[i];
	}
}


template<typename T, int N>
NGrid<T, N> & NGrid<T, N>::operator=(const NGrid<T, N> & t)
{
	if (this == &t)
		return *this;

	// free old memory
	delete[] mElements;
	CopyFrom(t);

	return *this;
}

template<typename T, int N>
void NGrid<T, N>::resize(int newSize)
{
	//alokowanie nowej pamieci:
	NGrid<T, N - 1>* tElements = new NGrid<T, N - 1>[newSize];
	//kopiowanie do nowej tablicy:
	for (int i = 0; i < mSize && i < newSize;i++)
	{
		tElements[i] = mElements[i];
		tElements[i].resize(newSize); //za ka¿dym razem zmieniamy rekurencyjnie wymiar a¿ do NGrid<T,1>
	}
	mSize = newSize;
	delete[] mElements;
	mElements = tElements;
}

template<typename T, int N>
NGrid<T, N - 1> & NGrid<T, N>::operator[](int x)
{
	return mElements[x];
}

template<typename T, int N>
const NGrid<T, N - 1>& NGrid<T, N>::operator[](int x) const
{
	return mElements[x];
}

