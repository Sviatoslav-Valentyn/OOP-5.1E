#include "Point.h"

Point::Point()
{
	x = 0;
	y = 0;
}

Point::Point(double valueX = 0, double valueY = 0) throw (invalid_argument)
{
	if (abs(valueX) > 100 || abs(valueY) > 100)
		throw invalid_argument("value > 100 || value < 100");
	x = valueX;
	y = valueY;
}

Point::Point(const Point& a)
{
	x = a.x;
	y = a.y;
}

Point::~Point()
{}

void Point::SetX(double value) throw(invalid_argument)
{
	if (abs(value) > 100)
		throw invalid_argument("value > 100 || value < 100");
	x = value;
}

void Point::SetY(double value) throw(invalid_argument)
{
	if (abs(value) > 100)
		throw MyException("value > 100 || value < 100");
	y = value;
}

double Point::Angle()
{
	double Pi = 4. * atan(1);
	if ((x == 0) && (y == 0))
		return -1;
	if (x == 0)
		return ((y > 0) ? 90 : 270);
	double theta = atan(y / x);
	theta *= 360 / (2 * Pi);
	if (x > 0)
	{
		return ((y >= 0) ? theta : 360 + theta);
	}
	else
	{
		return (180 + theta);
	}
}

double Point::Origin()
{
	double z;
	z = sqrt((x * x) + (y * y));
	return z;
}

bool operator==(const Point& s1, const Point& s2)
{
	return s1.x == s2.x && s1.y == s2.y;
}

bool operator!=(const Point& s1, const Point& s2)
{
	return !(s1 == s2);
}

Point& Point::operator=(const Point& a)
{
	x = a.x;
	y = a.y;

	return *this;
}

ostream& operator << (ostream& out, const Point& a)
{
	out << string(a);
	return out;
}

istream& operator >> (istream& input, Point& m) throw (MyDeliveredException)
{
	cout << " x = "; input >> m.x;
	cout << " y = "; input >> m.y;
	cout << endl;

	if (abs(m.x) > 100 || abs(m.y) > 100)
		throw new MyDeliveredException();


	return input;
}

Point::operator string () const
{
	stringstream ss;
	ss << " x = " << x << endl;
	ss << " y = " << y << endl;
	return ss.str();
}

Point& Point::operator ++()
{
	x++;
	return *this;
}

Point Point::operator ++(int)
{
	Point t(*this);
	y++;
	return t;
}

Point& Point::operator --() throw(MyDeliveredException)
{
	x--;
	if (x == 0)
		throw new MyDeliveredException();
	return *this;
}

Point Point::operator --(int) throw(MyDeliveredException)
{
	Point a(*this);
	y--;
	if (y == 0)
		throw MyDeliveredException();
	return a;
}