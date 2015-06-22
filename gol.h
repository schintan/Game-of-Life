#ifndef _GOL_H_
#define _GOL_H_

class GameOfLife
{
	public:
	
	GameOfLife(int rows = 5, int columns = 5);
	~GameOfLife();
	void printGrid() const;
	void start();

	private:

	unsigned getNumOfNeighbors(int row, int column) const;
	char getNextCellState(int row, int column) const;
	char* getNextGridState();
	GameOfLife(const GameOfLife& src);
	GameOfLife& operator=(const GameOfLife& src);
	char* grid;
	int numRows;
	int numCols;
};

#endif



