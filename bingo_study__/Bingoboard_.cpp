#include "BingoboardValue.h"
#include "Bingoboard_.h"
#include <iostream>
#include <time.h>
//���ø����� �ѱ�鼭 ���� ���
// 
//Bingoboard_::Bingoboard_()
//	: size(0)
//	, fullsize(0)
//{
//}
//
//Bingoboard_::~Bingoboard_()
//{
//}
//
//int Bingoboard_::inputBingoSize()
//{
//	int bingosize = 0;
//	std::cout << "������ ����� �Է��Ͻÿ� : ";
//	std::cin >> bingosize;
//	system("cls");
//
//	return bingosize;
//}
//
//void Bingoboard_::create(int bingosize) // 1���� �Է¹����������������� ä�� �迭 ����
//{
//	size = bingosize;
//	fullsize = bingosize * bingosize;
//	board.create(fullsize); // BingoBoardValueŬ�������� ���� �������
//	board.shuffleboard();
//	//board.getboard();
//
//	/*for (int i = 0; i < fullsize; i++) //int�θ� �迭 ������ �� �������
//	{
//		board.getboard()[i] = i + 1;
//	}*/
//	
//}
//
////void Bingoboard_::shuffle()
////{
////	srand((unsigned int)time(0));
////
////	for (int i = 0; i < 100; i++) // 1~�Էµ��� fullsize��ŭ�� ���� shuffle
////	{
////		idx1 = rand() % fullsize;
////		idx2 = rand() % fullsize;
////
////		iTemp = board.getboard()[idx1];
////		board.getboard()[idx1] = board.getboard()[idx2];
////		board.getboard()[idx2] = iTemp;
////	}
////}
//
////int Bingoboard_::getSize()
////{
////	return size;
////}
////
////int Bingoboard_::getFullSize()
////{
////	return fullsize;
////}
////
////int* Bingoboard_::getBoard()
////{
////	return board_;
////}
//
