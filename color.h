#pragma once

#include<iostream>
#include<cstdlib>
#include<Windows.h>

class Color
{
public:

	const int r;
	const int g;
	const int b;

	Color() = delete;

	Color(const int& r, const int& g, const int& b) :
		r(r), g(g), b(b)
	{}

	//��Ļ�ϵ����ص���ɫ���ܻ���΢�仯
	//ֻҪ��Ŀ����ɫ�������ж����
	bool operator==(const Color& color)
	{
		if (r > color.r + colorRange || r < color.r - colorRange)
		{
			return false;
		}
		else if (g > color.g + colorRange || g < color.g - colorRange)
		{
			return false;
		}
		else if (b > color.b + colorRange || b < color.b - colorRange)
		{
			return false;
		}
		return true;
	}

	void print()
	{
		std::cout << r << " " << g << " " << b << "\n";
	}

	static HDC hdc;

	static constexpr int colorRange = 1;

	static Color getPixel(int x, int y)
	{
		COLORREF pixelColor = GetPixel(hdc, x, y);
		return Color(GetRValue(pixelColor), GetGValue(pixelColor), GetBValue(pixelColor));
	}
};

HDC Color::hdc;