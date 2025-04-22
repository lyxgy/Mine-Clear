#pragma once
#include <stdio.h>
#include <graphics.h>
#include <stdlib.h>
#include <time.h>
#include <Windows.h>

// #define WIND_WIDTH 600
// #define WIND_HEIGHT 600

extern IMAGE img_blank1;
extern IMAGE img_mine;
extern IMAGE img_0;
extern IMAGE img_1;
extern IMAGE img_2;
extern IMAGE img_3;
extern IMAGE img_4;
extern IMAGE img_5;
extern IMAGE img_6;
extern IMAGE img_7;
extern IMAGE img_8;
extern int n;
extern int **Map;

void Load_Picture()
{
	loadimage(&img_blank1, L"res/blank1.gif");
	loadimage(&img_mine, L"res/mine.gif");
	loadimage(&img_0, L"res/0.gif");
	loadimage(&img_1, L"res/1.gif");
	loadimage(&img_2, L"res/2.gif");
	loadimage(&img_3, L"res/3.gif");
	loadimage(&img_4, L"res/4.gif");
	loadimage(&img_5, L"res/5.gif");
	loadimage(&img_6, L"res/6.gif");
	loadimage(&img_7, L"res/7.gif");
	loadimage(&img_8, L"res/8.gif");
}
void Init_Game()
{

	scanf_s("%d", &n);

	Map = new int *[n];
	for (int i = 0; i < n; i++)
	{
		Map[i] = new int[n](); // 初始化为 0
	}

	initgraph(n * 18, n * 18, 1);
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			Map[i][j] = rand() % 3;
			putimage(j * 18, i * 18, &img_blank1);
		}
		printf("\n");
	}

	// 加载图标
	//  设置窗口图标（需替换为你的 .ico 文件路径）
	HWND hWnd = GetHWnd(); // 获取 EasyX 窗口句柄
	HICON hIcon = (HICON)LoadImage(
		NULL,				  // 当前模块
		L"res/Mineclear.ico", // 图标文件路径（需放在项目目录下）
		IMAGE_ICON,			  // 类型为图标
		0, 0,				  // 自动读取原始尺寸
		LR_LOADFROMFILE		  // 从文件加载
	);
	SendMessage(hWnd, WM_SETICON, ICON_BIG, (LPARAM)hIcon); // 设置大图标
}

void Generate_Mine()
{
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			// 随机数为零的值为地雷
			if (Map[i][j] == 0)
			{
				// putimage(j * 18, i * 18, &img_mine);
			}
		}
		printf("\n");
	}
}

void Generate_Number()
{
	int cnt = 0;
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			// 计算不是零的周围九格的地雷的个数
			if (Map[i][j] != 0)
			{
				for (int m = i - 1; m <= i + 1; ++m)
				{
					for (int k = j - 1; k <= j + 1; ++k)
					{
						// 防止越界操作内存
						if (m >= 0 && m < n && k >= 0 && k < n)
						{
							if (Map[m][k] == 0)
							{
								cnt++;
							}
						}
					}
				}
				switch (cnt)
				{
				case 0:
				{
					Map[i][j] = -1;
					int temp = rand() % n / 3;
					for (int a = i - temp; a < i + temp; ++a)
					{
						for (int b = j - temp; b < j + temp; ++b)
						{
							putimage(b * 18, a * 18, &img_0);
						}
					}
					break;
				}
				case 1:
				{
					Map[i][j] = 1;
					// putimage(j * 18, i * 18, &img_1);
					break;
				}
				case 2:
				{
					Map[i][j] = 2;
					// putimage(j * 18, i * 18, &img_2);
					break;
				}
				case 3:
				{
					Map[i][j] = 3;
					// putimage(j * 18, i * 18, &img_3);
					break;
				}
				case 4:
				{
					Map[i][j] = 4;
					// putimage(j * 18, i * 18, &img_4);
					break;
				}
				case 5:
				{
					Map[i][j] = 5;
					// putimage(j * 18, i * 18, &img_5);
					break;
				}
				case 6:
				{
					Map[i][j] = 6;
					// putimage(j * 18, i * 18, &img_6);
					break;
				}
				case 7:
				{
					Map[i][j] = 7;
					// putimage(j * 18, i * 18, &img_7);
					break;
				}
				case 8:
				{
					Map[i][j] = 8;
					// putimage(j * 18, i * 18, &img_8);
					break;
				}
				}
				cnt = 0;
			}
		}
		printf("\n");
	}
}

// 递归揭示空格周围的数字
void RevealEmpty(int row, int col)
{
	if (row < 0 || row >= n || col < 0 || col >= n || Map[row][col] == -2)
	{
		return; // 越界或已经处理过
	}

	if (Map[row][col] == -1)
	{ // 空格
		putimage(col * 18, row * 18, &img_0);
		Map[row][col] = -2; // 标记为已处理

		// 递归揭示周围的格子
		for (int i = row - 1; i <= row + 1; ++i)
		{
			for (int j = col - 1; j <= col + 1; ++j)
			{
				RevealEmpty(i, j);
			}
		}
	}
	else if (Map[row][col] > 0)
	{ // 数字
		// 显示数字
		switch (Map[row][col])
		{
		case 1:
			putimage(col * 18, row * 18, &img_1);
			break;
		case 2:
			putimage(col * 18, row * 18, &img_2);
			break;
		case 3:
			putimage(col * 18, row * 18, &img_3);
			break;
		case 4:
			putimage(col * 18, row * 18, &img_4);
			break;
		case 5:
			putimage(col * 18, row * 18, &img_5);
			break;
		case 6:
			putimage(col * 18, row * 18, &img_6);
			break;
		case 7:
			putimage(col * 18, row * 18, &img_7);
			break;
		case 8:
			putimage(col * 18, row * 18, &img_8);
			break;
		}
		Map[row][col] = -2; // 标记为已处理
	}
}

void Mouse_take()
{
	MOUSEMSG msg;
	while (1)
	{
		msg = GetMouseMsg();
		switch (msg.uMsg)
		{
		case WM_LBUTTONDOWN:
		{						  // 左键点击事件
			int row = msg.y / 18; // 计算点击的行
			int col = msg.x / 18; // 计算点击的列

			// 防止越界
			if (row >= 0 && row < n && col >= 0 && col < n)
			{
				if (Map[row][col] == 0)
				{ 
					// 点击到地雷
					MessageBox(NULL, L"💣💣炸弹来了！！！", L"提示", MB_OK);

					for(int i = 0;i< n;++i){
						for (int j = 0; j < n; ++j)
						{
							if (Map[i][j] == 0)
							{
								putimage(j * 18, i * 18, &img_mine);
							}
						}
					}
					return; // 游戏结束
				}
				else if (Map[row][col] > 0)
				{ // 点击到数字
					// 显示数字
					switch (Map[row][col])
					{
					case 1:
						putimage(col * 18, row * 18, &img_1);
						break;
					case 2:
						putimage(col * 18, row * 18, &img_2);
						break;
					case 3:
						putimage(col * 18, row * 18, &img_3);
						break;
					case 4:
						putimage(col * 18, row * 18, &img_4);
						break;
					case 5:
						putimage(col * 18, row * 18, &img_5);
						break;
					case 6:
						putimage(col * 18, row * 18, &img_6);
						break;
					case 7:
						putimage(col * 18, row * 18, &img_7);
						break;
					case 8:
						putimage(col * 18, row * 18, &img_8);
						break;
					}
				}
				else if (Map[row][col] == -1)
				{						   // 点击到空格
					RevealEmpty(row, col); // 递归揭示空格周围的数字
				}
			}
			break;
		}
		}
	}
}

void close()
{
	// 释放栈资源
	for (int i = 0; i < n; i++)
	{
		delete[] Map[i];
	}
	delete[] Map;
}
