#include <iostream>
#include "Canvas.h"

using namespace std;

int main() {
	Canvas c(30, 20);
	c.DrawRect(1, 4, 8, 10, 'd');
	c.Print();
	c.FillRect(9, 0, 18, 3, 'f');
	c.Print();
	c.SetPoint(4, 4, 'x');
	c.Print();
	c.DrawLine(4, 7, 20, 13, '9');
	c.Print();
	c.DrawCircle(5, 14, 4, '!');
	c.Print();
	c.FillCircle(10, 15, 10, '0');
	c.Print();
	c.Clear();
	c.Print();
}