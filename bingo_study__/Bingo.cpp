#include "bingo.h"
#include <iostream>
#include <time.h>



Bingo::Bingo()
	:board(nullptr)
	, size(0), fullsize(0)
	, idx1(0), idx2(0), iTemp(0)
	, input(0)
	, bingocount(0)
{

}


Bingo::~Bingo()
{
	delete[] board;
}


void Bingo::setBingo(int bingosize_)
{
	size = bingosize_;
	fullsize = bingosize_ * bingosize_;
	board = new int[fullsize];

	srand((unsigned int)time(0));

	for (int i = 0; i < fullsize; i++)
	{
		board[i] = i + 1;
	}
	shuffle();
	printBoard();
}


void Bingo::shuffle()
{
	for (int i = 0; i < 100; i++) // 1~�Էµ��� fullsize��ŭ�� ���� shuffle
	{
		idx1 = rand() % fullsize;
		idx2 = rand() % fullsize;

		iTemp = board[idx1];
		board[idx1] = board[idx2];
		board[idx2] = iTemp;
	}
}


void Bingo::changeNum()
{
	while (true)
	{
		int redupCheck = -1; // �ߺ�üũ
		std::cout << "���ڸ� �Է��ϼ��� : ";
		std::cin >> input;
		system("cls");

		if (input == 0)
			break;

		for (int i = 0; i < fullsize; i++)
		{
			if (board[i] == input)
			{
				board[i] = 100;
				redupCheck = input;
			}
		}
		check();
		printBoard();


		// ���� ���� ���� �Է½� "�����ǿ� ���� �� �Դϴ�. �ٽ� �Է����ֽʽÿ�"
		if (input == 0 || input > fullsize)
		{
			redupCheck = input;
			std::cout << "�����ǿ� ���� �� �Դϴ�. �ٽ� �Է����ֽʽÿ�" << std::endl;
			system("PAUSE");
			system("cls");
			printBoard();
		}

		// �̹� üũ�Ǽ� ���� ���� �Է¹����� "�̹� �Է��� ���Դϴ�. �ٽ��Է����ֽʽÿ�" ���ٰ� ����
		if (redupCheck == -1)
		{
			std::cout << "�̹� �Է��� ���Դϴ�. �ٽ� �Է����ֽʽÿ�" << std::endl;
			system("PAUSE");
			system("cls");
			printBoard();
		}

		if (bingocount >= 5)
		{
			std::cout << "5�� �̻��� ���� �Ǿ����ϴ�. ��� �� ������ ���� �˴ϴ�.";
			break;
		}
	}
}

void Bingo::check()
{
	int bingoCount_ = 0; //������������ ����ī��Ʈ
	int h_count = 0; // ����üũ
	int v_count = 0; // ����üũ
	int d1_count = 0; // �밢üũ \ //
	int d2_count = 0;  // ���밢üũ / //

	//üũ�ϼ��Ǹ� ++bingocount
	for (int i = 0; i < size; ++i)
	{
		for (int j = 0; j < size; ++j)
		{
			if (board[i + j * (size)] == 100) // ����üũ
			{
				++h_count;
			}
		}
		if (h_count == size)
			++bingoCount_;
		h_count = 0;
	}

	for (int i = 0; i < size; ++i)
	{
		for (int j = 0; j < size; ++j)
		{
			if (board[i * size + j] == 100) // 
			{
				++v_count;
			}
		}
		if (v_count == size)
			++bingoCount_;
		v_count = 0;
	}

	// �밢üũ \ //
	for (int i = 0; i < size; ++i)
	{
		if (board[i * (size + 1)] == 100)
			++d1_count;
		if (d1_count == size)
			++bingoCount_;
	}
	d1_count = 0;

	// ���밢üũ / //
	for (int i = 1; i < (size + 1); ++i)
	{
		if (board[i * (size - 1)] == 100)
			++d2_count;
		if (d2_count == size)
			++bingoCount_;
	}
	d2_count = 0;

	bingocount = bingoCount_;
}

void Bingo::printBoard()
{
	for (int i = 0; i < size; i++) // ���� ���
	{
		for (int j = 0; j < size; j++)
		{
			if (board[i * size + j] == 100)
				std::cout << "#\t";
			else
				std::cout << board[i * size + j] << "\t";
		}
		std::cout << std::endl;
	}
	std::cout << "���� ���� �� �� : " << bingocount << std::endl;
	std::cout << "===================================" << "\n" << "*0�� �Է��ϸ� ����˴ϴ�.*" << "\n" << "===================================" << std::endl;
}

