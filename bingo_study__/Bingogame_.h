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
		void checkInput(int* board, int boardsize, int boardfullsize); // �Է��� �˻��ؼ� �ߺ��� �Է��ϰų� �������Ǽ��� �Է��ϸ� �ٽ� �Է��ϰ� �����.
		void compareInputwithBoard(int* board, int boardfullsize); // ����迭�� input�� ���ؼ� ������ 100����, �ٸ��� �ߺ� Ȥ�� ����ó��
		bool checkBingoComplete(int* board, int boardsize); // ���ΰ��δ밢 üũ�ؼ� ����ϼ����� Ȯ��
		
		void printBoard(int* board, int boardsize); // 
		//void checkBingoError(int* board, int boardsize, int boardfullsize);
		void printErrormessage_exception();
		//void printErrormessage_duplication();
		void printEndmessage();
};

