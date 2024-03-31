#pragma once
class Number {
	char value[100];
	int base;
public:
	Number(const char* value, int base); // where base is between 2 and 16
	Number(int value);
	Number(const Number& n);
	~Number() {};

	friend Number operator+(Number n1, Number n2);
	friend Number operator-(Number n1, Number n2);

	char operator[](int index);
	bool operator==(Number n);
	bool operator!=(Number n);
	bool operator<(Number n);
	bool operator>(Number n);
	bool operator>=(Number n);
	bool operator<=(Number n);
	Number& operator=(Number n);
	Number& operator=(int n);
	Number& operator=(const char* n);
	void operator--();
	void operator--(int);

	void SwitchBase(int newBase);
	void Print();
	int  GetDigitsCount(); // returns the number of digits for the current number
	int  GetBase(); // returns the current base
};
