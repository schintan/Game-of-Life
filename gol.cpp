#include "gol.h"
#include <iostream>
#include <cstdlib>

using namespace std; 

/*Initializes the grid to the size specified and randomly fills the cells with either '*' or ' ' */

GameOfLife::GameOfLife(int rows, int columns): numRows(rows), numCols(columns)
{
	srand(time(NULL));

	grid  = new char[numRows*numCols];

	for(int i = 0 ; i < numRows ; i++)
	{
		for(int j = 0 ; j < numCols; j++)
		{

			grid[i*numCols + j] = (rand()%2 ==1) ?'*':' ';
		}
	}	
}

/* Deletes the allocated memory */

GameOfLife::~GameOfLife()
{
	delete[] grid;

}

/* Prints the current state of the grid */

void GameOfLife::printGrid() const
{
	system("clear"); //system command is used to clear the screen as a short cut 
	int i,j;
	string rPat = "-----";
	
	for(i = 0 ; i < numRows ; i++)
	{
		for(j=0; j<numCols;j++)
		{
			cout<<rPat;
		}
		
		cout<<"-"<<endl;

		for(j = 0; j < numCols; j++)
		{
			cout<<"|    ";
		}
	
		cout<<"|"<<endl;	
		
		for(j = 0 ; j < numCols; j++)
		{
			cout<<"| "<<grid[i*numCols + j]<<"  ";
		}
		
		cout<<"|"<<endl;

		for(j = 0; j < numCols; j++)
		{
			cout<<"|    ";
		}
		
		cout<<"|"<<endl;
			
	}

	for(j=0; j<numCols;j++)
	{
		cout<<rPat;
	}
	
	cout<<"-"<<endl;

}

/*Calculates the number of live neighbors , considering that the edges wrap*/

unsigned GameOfLife::getNumOfNeighbors(int row , int col) const
{
	unsigned numNeighbors  =0;
	
	int previousRow = row -1 ;
	if(previousRow < 0)
	{
		previousRow = numRows -1;
	}

	int previousCol = col -1;
	if(previousCol < 0)
	{	
		previousCol = numCols -1;
	}
	
	int currentRow = row;
	int currentCol = col;

	int nextRow = row +1 ;
	if(nextRow == numRows)
	{
		nextRow = 0;
	}
	
	int nextCol = col +1;
	if(nextCol == numCols)
	{
		nextCol = 0;
	}

	if(grid[previousRow*numCols + previousCol] == '*') 
	{
		numNeighbors++;
	}
	
	if(grid[previousRow*numCols + currentCol] == '*')
	{	
		numNeighbors++;
	}
	
	if(grid[previousRow*numCols + nextCol] == '*')
	{	
		numNeighbors++;
	}
	if(grid[currentRow*numCols + nextCol] == '*')
	{
		numNeighbors++;
	}
	
	if(grid[nextRow*numCols + nextCol] == '*')
	{
		numNeighbors++;
	}
	
	if(grid[nextRow*numCols + currentCol] == '*')
	{
		numNeighbors++;
	}	

	if(grid[nextRow*numCols + previousCol] == '*')
	{
		numNeighbors++;
	}
	
	if(grid[currentRow*numCols + previousCol] == '*')
	{
		numNeighbors++;
	}
	
	return numNeighbors;

}

/* Calculates next cell state based on the game of life rules */

char GameOfLife::getNextCellState(int row, int col) const
{
	unsigned numNeighbors = getNumOfNeighbors(row,col);
	
	if( numNeighbors == 2)
	{
		return grid[row*numCols + col];
	}
	else if( numNeighbors == 3)
	{
		return '*';
	}
	else
	{
		return ' ';
	}	

}

/* Starts the game. User enters 's' or 'S' to continue to next step and any other value to terminate */

void GameOfLife::start()
{
	char step;	
	do
	{
		printGrid();
	  	grid = getNextGridState();
		cout<<endl<<"Enter s for next step or another value to exit"<<endl;
		cin>>step;
	
	}while(step =='s' || step == 'S');

}

/* Populates the next grid state  */

char* GameOfLife::getNextGridState()
{
	char *nextGrid = new char[numRows*numCols];

	for(int i = 0 ; i < numRows ; i++)
	{
		for(int j = 0 ; j < numCols; j++)
		{

			nextGrid[i*numCols + j] = getNextCellState(i,j);
		}
	}
	
	delete[] grid;
	return nextGrid;
}

