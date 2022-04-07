#pragma once
class Bingoboard
{
private:
	int* board;
	int fullsize;
	int size;

	int idx1, idx2, iTemp;

public:
	Bingoboard();
	~Bingoboard();
	int setBingosize();
	void boardArr(int bingosize_);
	void shuffle();
	void createboard(int bingosize_); //
};

