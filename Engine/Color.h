#pragma once
#ifndef __COLOR_H__
#define __COLOR_H__
class Color
{
public:
	Color();
	Color(int _r, int _g, int _b, int _a);
	Color(int _a);
	Color(int _r, int _g, int _b);
	~Color();

	Color operator+ (const Color& right) const;
	Color operator- (const Color& right) const;
	Color operator+ (const int right) const;
	Color operator- (const int right) const;
	Color operator* (const float right) const;
	Color operator>> (const Color& right) const;
	int r;
	int g;
	int b;
	int a;
};

#endif