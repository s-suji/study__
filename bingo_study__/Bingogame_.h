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
	void checkInput(T* board, int boardsize, int boardfullsize); // �Է��� �˻��ؼ� �ߺ��� �Է��ϰų� �������Ǽ��� �Է��ϸ� �ٽ� �Է��ϰ� �����.
	void compareInputwithBoard(T* board, int boardfullsize); // ����迭�� input�� ���ؼ� ������ 100����, �ٸ��� �ߺ� Ȥ�� ����ó��
	bool checkBingoComplete(T* board, int boardsize); // ���ΰ��δ밢 üũ�ؼ� ����ϼ����� Ȯ��
	
	void printBoard(T* board, int boardsize); // 
	//void checkBingoError(int* board, int boardsize, int boardfullsize);
	void printErrormessage_exception();
	//void printErrormessage_duplication();
	void printEndmessage();

*/
	//==========================================
	void getInput()
	{
		std::cout << "�Է��ϼ��� : ";
		std::cin >> input;
		system("cls");
	}

	void checkInput(T* board, int boardsize, int boardfullsize)
	{
		int checkException = 1;	// ����üũ
		for (int i = 0; i < boardfullsize; ++i)
		{
			if (board[i] == input)
				checkException = 0;	// ���ܰ� �ƴ� ��� ���ܴ°���
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
		int bingoCount_ = 0; //������������ ����ī��Ʈ
		int h_count = 0; // ����üũ
		int v_count = 0; // ����üũ
		int d1_count = 0; // �밢üũ \ //
		int d2_count = 0;  // ���밢üũ / //

		//üũ�ϼ��Ǹ� ++bingocount
		for (int i = 0; i < boardsize; ++i)
		{
			for (int j = 0; j < boardsize; ++j)
			{
				if (board[i + j * (boardsize)] == "#") // ����üũ
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

		// �밢üũ \ //
		for (int i = 0; i < boardsize; ++i)
		{
			if (board[i * (boardsize + 1)] == "#")
				++d1_count;
			if (d1_count == boardsize)
				++bingoCount_;
		}
		d1_count = 0;

		// ���밢üũ / //
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
		for (int i = 0; i < boardsize; i++) // ���� ���
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
		std::cout << "���� ���� �� �� : " << bingocount << std::endl;
		std::cout << "===================================" << "\n" << "*0�� �Է��ϸ� ����˴ϴ�.*" << "\n" << "===================================" << std::endl;
	}

	void printErrormessage_exception()
	{
		std::cout << "�̹� �Է��߰ų�, �����ǿ� ���� �� �Դϴ�. �ٽ� �Է����ֽʽÿ�" << std::endl;
		system("PAUSE");
		system("cls");
	}

	void printEndmessage()
	{
		std::cout << "0�� �Է��Ͽ��ų�, 5�� �̻��� ���� �Ǿ����ϴ�. ��� �� ������ ���� �˴ϴ�.";
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
