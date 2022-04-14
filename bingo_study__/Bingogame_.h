#pragma once
#include "Bingoboard_.h"
#include <string>
#include <iostream>

template <typename T>
class Bingogame_
{
private:
	int bingocount;
	T input;


public:
	Bingogame_()
		: bingocount(0)
		, input("")
	{
	}
	~Bingogame_()
	{
	}

public:
/*
	void Start();

	void getInput();
	void checkInput(T* board, int boardsize, int boardfullsize); // 입력을 검사해서 중복을 입력하거나 범위외의수를 입력하면 다시 입력하게 만든다.
	void compareInputwithBoard(T* board, int boardfullsize); // 보드배열과 input을 비교해서 같으면 100대입, 다르면 중복 혹은 예외처리
	bool checkBingoComplete(T* board, int boardsize); // 세로가로대각 체크해서 빙고완성여부 확인
	
	void printBoard(T* board, int boardsize); // 
	//void checkBingoError(int* board, int boardsize, int boardfullsize);
	void printErrormessage_exception();
	//void printErrormessage_duplication();
	void printEndmessage();

*/
	//==========================================
	void getInput()
	{
		std::cout << "입력하세요 : ";
		std::cin >> input;
		system("cls");
	}

	void checkInput(T* board, int boardsize, int boardfullsize)
	{
		int checkException = 1;	// 예외체크
		for (int i = 0; i < boardfullsize; ++i)
		{
			if (board[i] == input)
				checkException = 0;	// 예외가 아닌 경우 예외는거짓
		}

		if (checkException == -1)
			printErrormessage_exception();
	}

	void compareInputwithBoard(T* board, int boardfullsize)
	{

		for (int i = 0; i < boardfullsize; i++)
		{
			if (board[i] == input)
			{
				board[i] = 35;
			}
		}

	}

	bool checkBingoComplete(T* board, int boardsize)
	{
		int bingoCount_ = 0; //지역변수로의 빙고카운트
		int h_count = 0; // 가로체크
		int v_count = 0; // 세로체크
		int d1_count = 0; // 대각체크 \ //
		int d2_count = 0;  // 역대각체크 / //

		//체크완성되면 ++bingocount
		for (int i = 0; i < boardsize; ++i)
		{
			for (int j = 0; j < boardsize; ++j)
			{
				if (board[i + j * (boardsize)] == "#") // 가로체크
				{
					++h_count;
				}
			}
			if (h_count == boardsize)
				++bingoCount_;
			h_count = 0;
		}

		for (int i = 0; i < boardsize; ++i)
		{
			for (int j = 0; j < boardsize; ++j)
			{
				if (board[i * boardsize + j] == "#") // 
				{
					++v_count;
				}
			}
			if (v_count == boardsize)
				++bingoCount_;
			v_count = 0;
		}

		// 대각체크 \ //
		for (int i = 0; i < boardsize; ++i)
		{
			if (board[i * (boardsize + 1)] == "#")
				++d1_count;
			if (d1_count == boardsize)
				++bingoCount_;
		}
		d1_count = 0;

		// 역대각체크 / //
		for (int i = 1; i < (boardsize + 1); ++i)
		{
			if (board[i * (boardsize - 1)] == "#")
				++d2_count;
			if (d2_count == boardsize)
				++bingoCount_;
		}
		d2_count = 0;

		bingocount = bingoCount_;

		if (bingocount >= 5)
		{
			return true;
		}
		return false;
	}

	void printBoard(T* board, int boardsize)
	{
		for (int i = 0; i < boardsize; i++) // 숫자 출력
		{
			for (int j = 0; j < boardsize; j++)
			{
				if (board[i * boardsize + j] == "#")
					std::cout << "#\t";
				else
					std::cout << board[i * boardsize + j] << "\t";
			}
			std::cout << std::endl;
		}
		std::cout << "현재 빙고 줄 수 : " << bingocount << std::endl;
		std::cout << "===================================" << "\n" << "*0을 입력하면 종료됩니다.*" << "\n" << "===================================" << std::endl;
	}

	void printErrormessage_exception()
	{
		std::cout << "이미 입력했거나, 빙고판에 없는 수 입니다. 다시 입력해주십시오" << std::endl;
		system("PAUSE");
		system("cls");
	}

	void printEndmessage()
	{
		std::cout << "0을 입력하였거나, 5개 이상의 빙고가 되었습니다. 잠시 후 게임이 종료 됩니다.";
	}


	//========================================
	void Start()
	{
		Bingoboard_<T> Bingoboard;
		Bingoboard.create(Bingoboard.inputBingoSize());
		Bingoboard.shuffle();
		printBoard(Bingoboard.getCompleteBoard(), Bingoboard.getSize());
		while (true)
		{
			getInput();

			/*if (input == 0)
				break;*/

			checkInput(Bingoboard.getCompleteBoard(), Bingoboard.getSize(), Bingoboard.getFullSize());
			compareInputwithBoard(Bingoboard.getCompleteBoard(), Bingoboard.getFullSize());
			checkBingoComplete(Bingoboard.getCompleteBoard(), Bingoboard.getSize());
			bool fiveBingo = checkBingoComplete(Bingoboard.getCompleteBoard(), Bingoboard.getSize());
			if (fiveBingo == true)
				break;
			printBoard(Bingoboard.getCompleteBoard(), Bingoboard.getSize());

			//checkBingoError(Bingoboard.getboard(), Bingoboard.getsize(), Bingoboard.getfullsize());

		}
		printEndmessage();
	}
};
