#include<iostream>
#include<Windows.h>

#include"color.h"

using namespace std;

void HitKey(BYTE key)
{
	INPUT input = {};

	input.type = INPUT_KEYBOARD;
	input.ki.wVk = key;
	input.ki.dwFlags = 0;

	SendInput(1, &input, sizeof(INPUT));

	Sleep(50);

	input.type = INPUT_KEYBOARD;
	input.ki.wVk = key;
	input.ki.dwFlags = KEYEVENTF_KEYUP;

	SendInput(1, &input, sizeof(INPUT));

	Sleep(50);
}

void PressKey(BYTE key)
{
	INPUT input = {};

	input.type = INPUT_KEYBOARD;
	input.ki.wVk = key;
	input.ki.dwFlags = 0;

	SendInput(1, &input, sizeof(INPUT));

	Sleep(50);
}

void ReleaseKey(BYTE key)
{
	INPUT input = {};

	input.type = INPUT_KEYBOARD;
	input.ki.wVk = key;
	input.ki.dwFlags = KEYEVENTF_KEYUP;

	SendInput(1, &input, sizeof(INPUT));

	Sleep(50);
}

void Click()
{
	INPUT input = {};

	input.type = INPUT_MOUSE;
	input.mi.dx = 0;
	input.mi.dy = 0;
	input.mi.mouseData = 0;
	input.mi.dwFlags = MOUSEEVENTF_LEFTDOWN;
	input.mi.time = 0;
	input.mi.dwExtraInfo = 0;

	SendInput(1, &input, sizeof(INPUT));

	Sleep(50);

	input.type = INPUT_MOUSE;
	input.mi.dx = 0;
	input.mi.dy = 0;
	input.mi.mouseData = 0;
	input.mi.dwFlags = MOUSEEVENTF_LEFTUP;
	input.mi.time = 0;
	input.mi.dwExtraInfo = 0;

	SendInput(1, &input, sizeof(INPUT));

	Sleep(50);
}

int main()
{
	Color::hdc = GetDC(nullptr);

	Sleep(5000);

	while (true)
	{
		//转到菜单
		HitKey(VK_ESCAPE);

		Sleep(1200);

		//创意中心 1727 239
		SetCursorPos(1727, 239);

		Sleep(800);

		Click();

		//事件实验室 1075 707
		SetCursorPos(1075, 707);

		Sleep(800);

		Click();

		//我的赛事 1682 730
		SetCursorPos(1682, 730);

		Sleep(800);

		Click();

		//我的历史记录 1423 244
		SetCursorPos(1423, 244);

		Sleep(800);

		Click();

		//赛事 单人
		SetCursorPos(1280, 750);

		Sleep(800);

		while (true)
		{
			if ((Color::getPixel(131, 1232) == Color(244, 49, 86)) && (Color::getPixel(285, 1110) == Color(52, 23, 53)))
			{
				Sleep(100);
				break;
			}
			else
			{
				Click();
				Sleep(100);
			}
		}

		//选车 743 519
		SetCursorPos(743, 519);

		Sleep(800);

		Click();

		Click();

		Click();

		Sleep(2000);

		//开启赛事 453 528
		SetCursorPos(453, 528);

		while (true)
		{
			if ((Color::getPixel(521, 561) == Color(247, 247, 247)) && (Color::getPixel(259, 248) == Color(246, 214, 55)))
			{
				Sleep(100);
				break;
			}
			Sleep(100);
		}

		Sleep(800);

		Click();

		Click();

		Click();

		Sleep(200);

		while ((Color::getPixel(20, 1439) == Color(0, 0, 0)))
		{
			Sleep(50);
		}

		Sleep(100);

		//空格
		PressKey(VK_SPACE);

		//等待35s
		Sleep(35000);

		//松空格
		ReleaseKey(VK_SPACE);

		SetCursorPos(194, 1334);

		Sleep(2000);

		while (true)
		{
			if (!(Color::getPixel(127, 1368) == Color(64, 64, 64)))
			{
				Click();

				Sleep(100);
			}
			else
			{
				break;
			}

		}

		Sleep(2000);
	}

	ReleaseDC(nullptr, Color::hdc);

	return 0;
}