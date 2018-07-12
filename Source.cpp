#include <iostream>
#include "Header1.hpp"


extern int x = 5;
int main()
{
	
	/*OneDGrid<int> SingleGrid;
	OneDGrid<OneDGrid<int> > twoDGrid;
	OneDGrid<OneDGrid<OneDGrid<int> > > thirdDGrid;

	SingleGrid[0] = 5;
	twoDGrid[0][0] = 5;
	*/

	//drugi sposób na wielowymiarow¹ przestrzeñ:
	NGrid<int, 3> myGird(2);
	myGird[0][0][0] = 10;
	std::cout << myGird[0][0][0] << std::endl;


	
	int * myOddArray = nullptr;
	int * myEvenArray = nullptr;

	const int  myArray[10] = { 1,2,3,4,5,6,7,8,9,10 };
	SeperationOfOddsAndEvents(myArray, 10, myOddArray, myEvenArray);

	for (int i = 0; i < 5; i++)
	{
		std::cout << i << ": " << myOddArray[i] << std::endl;
	}
	std::cout << "\nEven Numbers: \n";
	for (int i = 0; i < 5; i++)
	{
		std::cout << i << ": " << myEvenArray[i] << std::endl;
	}

	delete[] myOddArray;
	delete[] myEvenArray;
	

	getchar();
	return 0;
}