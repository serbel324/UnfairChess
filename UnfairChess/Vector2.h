#ifndef __VECTOR2_H__
#define __VECTOR2_H__

#include <iostream>

template <typename T>
struct Vector2
{
	T x, y;

	Vector2();
	Vector2(T _x);
	Vector2(T _x, T _y);

	void set(T _x, T _y);
	void set(Vector2 p);

	Vector2 operator*(double r) const;
	Vector2 operator/(double r) const;

	template <typename T2>
	Vector2 operator+(const Vector2<T2> r) const;
	template <typename T2>
	Vector2 operator-(const Vector2<T2> r) const;
	template <typename T2>
	Vector2 operator*(Vector2<T2> r) const;

	Vector2<int> operator%(Vector2<int> r) const;
	Vector2<float> operator%(Vector2<float> r) const;
	
	void operator+=(const Vector2 r);
	void operator-=(const Vector2 r);

	operator Vector2<int>() { return Vector2<int>(x, y); };
	operator Vector2<float>() { return Vector2<float>(x, y); };
	operator Vector2<double>() { return Vector2<int>(x, y); };

	static Vector2 norm(Vector2 v);
	static Vector2 rotate(Vector2, double a);
	static double get_angle(Vector2 v);
	static double abs(Vector2 v);

	static T dot_prod(Vector2 v1, Vector2 v2);
	static T cross_prod(Vector2 v1, Vector2 v2);
};

#include "Vector2.cpp"
#endif // __VECTOR_2_H__