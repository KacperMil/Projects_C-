#pragma once
#ifndef HEADER1_HPP
#define HEADER1_HPP
#include <stdexcept>

template<typename T>
class OneDGrid
{
public:
//constructors:
	OneDGrid(int inSize = cDefaultSize);
	OneDGrid(const OneDGrid<T> & t);
	~OneDGrid();
//operators:
	OneDGrid<T> & operator=(const OneDGrid<T> & t);
	T & operator[] (int x);
//methods
	int getSize()const { return mSize; }
	void resize(int newSieze);
//static variables
	static const int cDefaultSize = 2;
protected:
	T * mElements;
	int mSize;
	void CopyFrom(const OneDGrid<T> & t);
};

#include "OneDGrid_methods.hpp"


//druga klasa do zagnie¿d¿ania szablonów, tutaj rekurencjê wykonuje sama klasa, nie potrzebujemy pisaæ ile razy szablonów bêdziemy mieli
// do tej metody potrzebna jest klasa podstawowa, z N = 1
template<typename T, int N>
class NGrid
{
public:
//constructors:
	NGrid();
	NGrid(int newSize);
	NGrid(const NGrid<T, N> & t);
	~NGrid();
//operators:
	NGrid<T, N> & operator=(const NGrid<T, N> & t);
	const NGrid<T, N-1>& operator[](int x) const;
	NGrid<T, N-1>& operator[](int x);
//methods:
	void resize(int newSize);
	int getSize()const { return mSize; }
//static variables
	static const int cDefaultSize = 5;
protected:
	void CopyFrom(const NGrid<T, N> & t);
	int mSize;
	NGrid<T, N - 1>* mElements; //wskaznik na obiekt NGrid z N-1
};
#include "NGrid_methods.h"


//klasa bazowa do referencji:
template<typename T>
class NGrid<T,1> //specjalizacja szablonu do jednego typu!
{
public:
//constructors:
	NGrid(int newSize = cDefautSize);
	NGrid(const NGrid<T, 1> & t);
	~NGrid()throw();
//operators:
	NGrid<T, 1> &operator=(const NGrid<T, 1> & t);
	T & operator[](int x);
	const T& operator[](int x)const;
//methods:
	int getSize()const { return mSize; } //nie ma wyjatkow
	void resize(int newSize);

//static variables:
	static const int cDefautSize = 5;
protected:
	int mSize;
	T* mElements;
	void CopyFrom(const NGrid<T, 1> & t);
};
#include "NGrid_base_methods.hpp"



template<typename T>
void Swap(T &x, T &y)
{
	auto temp = y;
	y = x;
	x = temp;
}



//seperation of odds and events:
template<typename T>
void SeperationOfOddsAndEvents(const T myArray[], int  size, T*& OddArray, T*& EvenArray)
{
	int OddNumb = 0, EvenNum = 0;
	for (int i = 0; i < size; i++)
	{
		if (myArray[i] % 2 == 0)
			EvenNum++;
		else
			OddNumb++;
	}
	EvenArray = new T[EvenNum]; //creating array for even numbers
	OddArray = new T[OddNumb]; //creating array for odd numbers

	for (int i = 0; i < size; i++)
	{
		if (myArray[i] % 2 == 0)
		{
			EvenArray[EvenNum] = myArray[i];
			EvenNum++;
		}
		else
		{
			OddArray[OddNumb] = myArray[i];
			OddNumb++;
		}
	}
}

#endif // !HEADER1_HPP
