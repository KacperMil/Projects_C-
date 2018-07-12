#pragma once
#include "Header1.hpp"


template<typename T>
void OneDGrid<T>::CopyFrom(const OneDGrid<T> & t)
{
	mSize = t.mSize;
	mElements = new T[mSize];
	for (int i = 0; i < mSize; i++)
	{
		mElements[i] = t.mElements[i];
		std::cout << x << std::endl;
	}

}

template<typename T>
OneDGrid<T>::OneDGrid(int inSize) : mSize(inSize)
{
	std::cout << "Constructor has been called!\n";
	mElements = new T[mSize];
}

template<typename T>
OneDGrid<T>::OneDGrid(const OneDGrid<T> & t)
{
	CopyFrom(t);

}

template<typename T>
OneDGrid<T>::~OneDGrid()
{
	delete[] mElements;
}

template<typename T>
OneDGrid<T> & OneDGrid<T>::operator=(const OneDGrid<T> & t)
{
	if (this == &t)
		return *this;
	//usuwanie pierwszej tablicy
	delete[] mElements;

	CopyFrom(t);

	return *this;
}

template<typename T>
T& OneDGrid<T>::operator[](int x)
{
	return mElements[x];
}


template<typename T>
void OneDGrid<T>::resize(int newSize)
{
	T* newElem = new T[newSize];
	for (int i = 0; i < newSize && i < mSize; i++)
	{
		newElem[i] = mElements[i];
	}
	mSize = newSize;
	delete[] mElements;
	mElements = newElem;
}


