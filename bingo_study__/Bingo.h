#pragma once
class Bingo
{
private:
	int* board;
	int fullsize;
	int size;

	int idx1, idx2, iTemp;
	int input;
	int bingocount;


public:
	Bingo();
	~Bingo();
	void setBingo(int bingosize_);
	void shuffle();
	void changeNum();
	void check();
	void printBoard();
};