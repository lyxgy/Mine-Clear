#include "main.h"

//全局变量声明
int n = 0;
IMAGE img_0;
IMAGE img_mine;
IMAGE img_1;
IMAGE img_2;
IMAGE img_3;
IMAGE img_4;
IMAGE img_5;
IMAGE img_6;
IMAGE img_7;
IMAGE img_8;

int** Map = NULL;
int main() {
	srand((unsigned)time(NULL));
	Load_Picture();
	Init_Game();
	Generate_Mine();
	Generate_Number();
	system("pause");
	close();
	return 0;
}