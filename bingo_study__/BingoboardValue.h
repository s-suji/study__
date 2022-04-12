#pragma once
#include <iostream>
#include <string>

// 숙제
// 포인터 클래스(니가 만들어서) 했을떄 생성자 호출되는지 안되는지 확인 직접.
// 생성자 앞에는 a에서는 호출. 그러나 포인터로 선언한 ptr쪽에서는 그냥 터짐. 컴파일되긴했음. 근데 터짐

class TestClass
{
public:
	int member;

public:
	TestClass()
		:member(18)
	{
		std ::cout << "생성자 호출되었습니다";
	};
};
/*
main()
{
	TestClass a;
	std::cout << a.member;

	TestClass* ptr;
	std::cout << ptr->member;

	

	// 생성자가 호출이 된다는건 = 컴퓨터 메모리에 이 객체에 관한 메모리가 잡힌다는거
	// 포인터를 선언하는건 메모리에 잡힌다는 소리야? 객체에 대한 메모리가 잡히지않음. 
	
	ptr = new TestClass();
	// 메모리가 할당이됬다 = 이 객체에 대한 메모리 공간을 잡았다
	// 생성자가 호출이된다. 

	std::cout << ptr->member;
	// ok
}
*/

template <typename T>
class BingoboardValue
{
private:
	T* board;
	T input;

public:
	BingoboardValue()
		: board(nullptr)
	{
		
	}

	~BingoboardValue()
	{
		delete[] board;
	}

	T* createArr(int fullsize)
	{
		board = new T[fullsize]; // T의 생성자가 호출이 되는 부분

		std::cout << " 빙고를 구성할 내용을 입력하시오 : " << std::endl;
		for (int i = 0; i < fullsize; ++i)
		{
			input = {};
			std::cin >> input;
			unsigned int size = sizeof input;
			T* arr = new T[size];
			*arr = input;
			board[i] = *arr;
			delete[] arr;
		}

		return board;
	}

	inline T* getboard()
	{
		return board;
	}

};