#include "pch.h"
#include "Color.h"
#include <algorithm>


Color::Color()
{
	int r = 0;
	int g = 0;
	int b = 0;
	int a = 255;
}

Color::Color(int _r, int _g, int _b, int _a)
{
	r = _r;
	g = _g;
	b = _b;
	a = _a;
}
Color::Color(int _a)
{
	r = _a;
	g = _a;
	b = _a;
	a = 255;
}
Color::Color(int _r, int _g, int _b)
{
	r = _r;
	g = _g;
	b = _b;
	a = 255;
}


Color::~Color()
{
}

Color Color::operator+(const Color& right) const
{
	int red = std::min(255, r + right.r);
	int green = std::min(255, g + right.g);
	int blue = std::min(255, b + right.b);
	return Color(red, green, blue, a);
}

Color Color::operator+(const int right) const
{
	int red = std::min(255, r + right);
	int green = std::min(255, g + right);
	int blue = std::min(255, b + right);
	return Color(red, green, blue, a);
}

Color Color::operator-(const Color& right) const
{
	int red = std::max(0, r - right.r);
	int green = std::max(0, g - right.g);
	int blue = std::max(0, b - right.b);
	return Color(red, green, blue, a);
}

Color Color::operator-(const int right) const
{
	int red = std::max(0, r - right);
	int green = std::max(0, g - right);
	int blue = std::max(0, b - right);
	return Color(red, green, blue, a);
}

Color Color::operator*(const float right) const
{
	return Color(r * right, g * right, b * right, a);
}

Color Color::operator>>(const Color& right) const
{
	return Color((r + right.r) / 2, (g + right.g) / 2, (b + right.b) / 2, (a + right.a) / 2);
}
