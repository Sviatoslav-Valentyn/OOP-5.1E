#pragma once
#include<iostream>
#include <string>
#include <sstream>
#include <exception>
#include "Object.h"
#include "MyException.h"
#include "MyDeliveredException.h"
using namespace std;

class Point : public Object
{
private:
	double x, y;
public:
	Point(); // конструктор за умовчанням
	Point(double, double) throw (invalid_argument); // конструктор ініціалізації
	Point(const Point&); //копіювання
	~Point();

	double GetX() const { return x; };
	double GetY() const { return y; };
	void SetX(double value) throw (invalid_argument);
	void SetY(double value) throw (invalid_argument);


	double Angle();
	double Origin();

	friend bool operator== (const Point& s1, const Point& s2);
	friend bool operator!= (const Point& s1, const Point& s2);

	Point& operator = (const Point&);
	friend ostream& operator << (ostream&, const Point&);
	friend istream& operator >> (istream&, Point&) throw (MyDeliveredException);
	operator string() const;

	Point& operator ++()throw(MyException); // префіксний інкремент
	Point operator ++(int)throw(MyException); // постфіксний інкремент
	Point& operator --()throw(MyException); // префіксний декремент
	Point operator --(int)throw(MyException); // постфіксний декремент
};