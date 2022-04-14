#pragma once
#include <iostream>
#include <string>

// ����
// ������ Ŭ����(�ϰ� ����) ������ ������ ȣ��Ǵ��� �ȵǴ��� Ȯ�� ����.
// ������ �տ��� a������ ȣ��. �׷��� �����ͷ� ������ ptr�ʿ����� �׳� ����. �����ϵǱ�����. �ٵ� ����

class TestClass
{
public:
	int member;

public:
	TestClass()
		:member(18)
	{
		std ::cout << "������ ȣ��Ǿ����ϴ�";
	};
};
/*
main()
{
	TestClass a;
	std::cout << a.member;

	TestClass* ptr;
	std::cout << ptr->member;

	

	// �����ڰ� ȣ���� �ȴٴ°� = ��ǻ�� �޸𸮿� �� ��ü�� ���� �޸𸮰� �����ٴ°�
	// �����͸� �����ϴ°� �޸𸮿� �����ٴ� �Ҹ���? ��ü�� ���� �޸𸮰� ����������. 
	
	ptr = new TestClass();
	// �޸𸮰� �Ҵ��̉�� = �� ��ü�� ���� �޸� ������ ��Ҵ�
	// �����ڰ� ȣ���̵ȴ�. 

	std::cout << ptr->member;
	// ok
}
*/

template <typename T>
class BingoboardValue
{
private:
	T* board_;
	T input;


public:
	BingoboardValue()
		: board_(nullptr)
		
	{
		
	}

	~BingoboardValue()
	{
		delete[] board_;
	}

	T* create(int fullsize)
	{
		board_ = new T[fullsize]; // T�� �����ڰ� ȣ���� �Ǵ� �κ�

		std::cout << " ���� ������ ������ �Է��Ͻÿ� :" << std::endl;
		for (int i = 0; i < fullsize; ++i)
		{
			input = {};
			std::cin >> input;
			unsigned int size = sizeof input;
			T* arr = new T[size];
			*arr = input;
			board_[i] = *arr;
			delete[] arr;
		}
		system("cls");

		return board_;
	}


	inline T* getboard()
	{
		return board_;
	}

};