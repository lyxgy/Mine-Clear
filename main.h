#pragma once
#include <stdio.h>
#include <graphics.h>
#include <stdlib.h>
#include <time.h>

//#define WIND_WIDTH 600
//#define WIND_HEIGHT 600

extern IMAGE img_0;
extern IMAGE img_mine;
extern IMAGE img_1;
extern IMAGE img_2;
extern IMAGE img_3;
extern IMAGE img_4;
extern IMAGE img_5;
extern IMAGE img_6;
extern IMAGE img_7;
extern IMAGE img_8;
extern int n;
extern int** Map;

void Load_Picture() {
	loadimage(&img_0, L"res/blank1.gif");
	loadimage(&img_mine, L"res/mine.gif");
	loadimage(&img_1, L"res/1.gif");
	loadimage(&img_2, L"res/2.gif");
	loadimage(&img_3, L"res/3.gif");
	loadimage(&img_4, L"res/4.gif");
	loadimage(&img_5, L"res/5.gif");
	loadimage(&img_6, L"res/6.gif");
	loadimage(&img_7, L"res/7.gif");
	loadimage(&img_8, L"res/8.gif");

}
void Init_Game() {
	//初始界面，根据用户输入数生成对应大小地图
	//输入为7以下像素太小，系统默认最小126*126
	
	scanf_s("%d",&n);

	Map = new int* [n];
	for (int i = 0; i < n; i++) {
		Map[i] = new int[n]();  // 初始化为 0
	}

	initgraph(n*18, n*18, 1);
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			Map[i][j] = rand() % 3;
			putimage(j * 18, i * 18, &img_0);
		}
		printf("\n");
	}
}

void Generate_Mine() {
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			//随机数为零的值为地雷
			if (Map[i][j] == 0) {
				putimage(j * 18, i * 18, &img_mine);
			}
		}
		printf("\n");
	}
}

void Generate_Number() {
	int cnt=0;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			//计算不是零的周围九格的地雷的个数
			if (Map[i][j] != 0) {
				for (int m = i-1; m <= i+1; ++m) {
					for (int k = j-1; k <= j+1; ++k) {
						//防止越界操作内存
						if (m >= 0 && m < n && k >= 0 && k < n) {
							if (Map[m][k] == 0) cnt++;
						}
					}
				}
				switch (cnt)
				{
				case 0: {
					putimage(j * 18, i * 18, &img_0);
					break;
				}
				case 1: {
					putimage(j * 18, i * 18, &img_1);
					break;
				}
				case 2: {
					putimage(j * 18, i * 18, &img_2);
					break;
				}
				case 3: {
					putimage(j * 18, i * 18, &img_3);
					break;
				}
				case 4: {
					putimage(j * 18, i * 18, &img_4);
					break;
				}
				case 5: {
					putimage(j * 18, i * 18, &img_5);
					break;
				}
				case 6: {
					putimage(j * 18, i * 18, &img_6);
					break;
				}
				case 7: {
					putimage(j * 18, i * 18, &img_7);
					break;
				}
				case 8: {
					putimage(j * 18, i * 18, &img_8);
					break;
				}

				}
				cnt = 0;
			}
		}
		printf("\n");
	}
}


void close() {
	//释放栈资源
	for (int i = 0; i < n; i++) {
		delete[] Map[i];
	}
	delete[] Map;
}
