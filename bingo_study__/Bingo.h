#pragma once
class Bingo
{
private:
	int* board;
	int fullsize;
	int size;
	int input;
	int bingocount;


public:
	Bingo();
	~Bingo();
	void changeNum();
	void check();
	void printBoard();
};