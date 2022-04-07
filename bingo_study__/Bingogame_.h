#pragma once
class Bingogame_
{
	private:
		int bingocount;
		int input;


	public:
		Bingogame_();
		~Bingogame_();

		void Start();

		void getInput();
		void checkInput(int* board, int boardsize, int boardfullsize); // 입력을 검사해서 중복을 입력하거나 범위외의수를 입력하면 다시 입력하게 만든다.
		void compareInputwithBoard(int* board, int boardfullsize); // 보드배열과 input을 비교해서 같으면 100대입, 다르면 중복 혹은 예외처리
		bool checkBingoComplete(int* board, int boardsize); // 세로가로대각 체크해서 빙고완성여부 확인
		
		void printBoard(int* board, int boardsize); // 
		//void checkBingoError(int* board, int boardsize, int boardfullsize);
		void printErrormessage_exception();
		//void printErrormessage_duplication();
		void printEndmessage();
};

