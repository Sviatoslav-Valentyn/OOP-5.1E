#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include"Point.h"
#include <Windows.h>

using namespace std;

void _unexpected_to_bad()
{
	cerr << "bad_exception" << endl;
	throw;
}

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	set_unexpected(_unexpected_to_bad);
	set_terminate(_unexpected_to_bad);

	cout << "Point a:\n";

	Point a;

	try
	{
		cin >> a;
		cout << "Angle = " << a.Angle() << endl;
		cout << "Origin = " << a.Origin() << endl;
	}
	catch (MyDeliveredException* ex)
	{
		cerr << "Exception b: " << ex->What() << endl;
	}

	cout << "========================================================" << "\nPoint b:\n";

	try
	{
		Point b(2, 24);
		cout << b << endl;
		b++;
		cout << "b++" << endl;
		cout << b << endl;
		cout << "Angle = " << b.Angle() << endl;
		cout << "Origin = " << b.Origin() << endl;

		if (a == b)
		{
			cout << "Äâà îáºêòè º ð³âí³\n";
		}
		if (a != b)
		{
			cout << "Äâà îáºêòè íå º ð³âí³\n";
		}

	}
	catch (invalid_argument a)
	{
		cerr << "Exception b: " << a.what() << endl;
	}
	catch (MyException& ex)
	{
		cerr << ex.What() << endl;
	}
	
	cout << "Object count: " << a.get_count() << endl;

	return 0;
}
