#define _CRT_SECURE_NO_WARNINGS
#include "Number.h"
#include <cstring>
#include <iostream>
#include <cmath>
#include <string>

Number::Number(const char* value, int base) {
	if (base >= 2 && base <= 16) {
		strcpy(this->value, value);
		this->base = base;
	}
}

Number::Number(int value) {
	base = 10;
	int i = (int)(log10((double)value)) + 1;
	this->value[i] = NULL;
	i--;
	do {
		this->value[i] = value % 10 + '0';
		value /= 10;
		i--;
	} while (value);
}

Number::Number(const Number& n) {
	strcpy(value, n.value);
	base = n.base;
}

char Number::operator[](int index) {
	return value[index];
}

Number operator+(Number n1, Number n2) {
	int maxBase = std::max(n1.base, n2.base);
	n1.SwitchBase(10);
	n2.SwitchBase(10);
	int sum = std::atoi(n1.value) + std::atoi(n2.value);
	int index = (int)(log10((double)sum)) + 1;
	char s[100];
	s[index--] = '\0';
	do {
		s[index--] = sum % 10 + '0';
		sum /= 10;
	} while (sum);
	strcpy(n1.value, s);
	n1.SwitchBase(maxBase);
	return n1;
}

Number operator-(Number n1, Number n2) {
	int maxBase = std::max(n1.base, n2.base);
	n1.SwitchBase(10);
	n2.SwitchBase(10);
	int dif = std::atoi(n1.value) - std::atoi(n2.value);
	int index = (int)(log10((double)dif)) + 1;
	char s[100];
	s[index--] = '\0';
	do {
		s[index--] = dif % 10 + '0';
		dif /= 10;
	} while (dif);
	strcpy(n1.value, s);
	n1.SwitchBase(maxBase);
	return n1;
}

bool Number::operator==(Number n) {
	n.SwitchBase(base);
	if (strcmp(value, n.value) == 0)
		return true;
	else
		return false;
}

bool Number::operator!=(Number n) {
	n.SwitchBase(base);
	if (strcmp(value, n.value) != 0)
		return true;
	else
		return false;
}

bool Number::operator<(Number n) {
	n.SwitchBase(base);
	if (strcmp(value, n.value) < 0)
		return true;
	else
		return false;
}

bool Number::operator>(Number n) {
	n.SwitchBase(base);
	if (strcmp(value, n.value) > 0)
		return true;
	else
		return false;
}

bool Number::operator>=(Number n) {
	n.SwitchBase(base);
	if (strcmp(value, n.value) >= 0)
		return true;
	else
		return false;
}

bool Number::operator<=(Number n) {
	n.SwitchBase(base);
	if (strcmp(value, n.value) <= 0)
		return true;
	else
		return false;
}

Number& Number::operator=(Number n) {
	strcpy(value, n.value);
	base = n.base;
	return *this;
}

Number& Number::operator=(int n) {
	int i = (int)(log((double)n) / log((double)base)) + 1;
	value[i] = NULL;
	i--;
	while (n > 0) {
		int remainder = n % base;
		if (remainder < 10)
			value[i] = remainder + '0';
		else
			value[i] = remainder + 'A' - 10;
		i--;
		n /= base;
	}
	return *this;
}

Number& Number::operator=(const char* n) {
	strcpy(value, n);
	return *this;
}

void Number::operator--() {
	strcpy(value, value + 1);
}

void Number::operator--(int) {
	value[strlen(value) - 1] = NULL;
}

void Number::SwitchBase(int newBase) {
	if (newBase >= 2 && newBase <= 16) {
		int base10 = 0, power = 0;
		for (int i = strlen(value) - 1; i >= 0; i--) {
			int digit = 0;
			if (value[i] >= '0' && value[i] <= '9')
				digit = value[i] - '0';
			else if (value[i] >= 'A' && value[i] <= 'F')
				digit = value[i] - 'A' + 10;
			base10 += digit * std::pow(base, power);
			power++;
		}
		base = newBase;

		int i = (int)(floor(log((double)base10) / log((double)base)) + 1);
		value[i] = '\0';
		i--;
		while (base10 > 0) {
			int remainder = base10 % base;
			if (remainder < 10)
				value[i] = remainder + '0';
			else
				value[i] = remainder + 'A' - 10;
			i--;
			base10 /= base;
		}
	}
}

void Number::Print() {
	std::cout << value << '\n';
}

int  Number::GetDigitsCount() {
	return strlen(value);
}

int  Number::GetBase() {
	return base;
}