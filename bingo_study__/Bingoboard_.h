#pragma once
class Bingoboard_
{
private:
	int* board_;
	int fullsize;
	int size;

	int idx1, idx2, iTemp;

public:
	Bingoboard_();
	~Bingoboard_();
	int inputBingoSize();
	void create(int bingosize);
	void shuffle();
	inline int getSize()
	{
		return size;
	}
	//int getsize() const;
	//const int getsize();
	//const int getsize() const;
	
	// 1. inline
	// 2. const ÇÔ¼ö
	
	inline int getFullSize()
	{
		return fullsize;
	}

	inline int* getBoard() 
	{
		return board_;
	}
};

