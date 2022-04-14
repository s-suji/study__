#include "BingoboardValue.h"
#include "Bingoboard_.h"
#include <iostream>
#include <time.h>
//템플릿으로 넘기면서 전부 취소
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
//	std::cout << "빙고의 사이즈를 입력하시오 : ";
//	std::cin >> bingosize;
//	system("cls");
//
//	return bingosize;
//}
//
//void Bingoboard_::create(int bingosize) // 1부터 입력받은사이즈제곱으로 채운 배열 생성
//{
//	size = bingosize;
//	fullsize = bingosize * bingosize;
//	board.create(fullsize); // BingoBoardValue클래스에서 보드 만들어줌
//	board.shuffleboard();
//	//board.getboard();
//
//	/*for (int i = 0; i < fullsize; i++) //int로만 배열 관리할 때 사용했음
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
////	for (int i = 0; i < 100; i++) // 1~입력들어온 fullsize만큼의 숫자 shuffle
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
