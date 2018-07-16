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

	getchar();
	return 0;
}