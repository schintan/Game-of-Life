#include "gol.h"
#include <iostream>

using namespace std;

int main()
{
	unsigned int numRows,numCols;
	cout<<"Enter number of rows"<<endl;
	cin>>numRows;
	cout<<"Enter number of columns"<<endl;
	cin>>numCols;

	//Initialize Game of Life
	GameOfLife gol(numRows,numCols);	

	//Start
	gol.start();

}
