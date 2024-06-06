#include "Math.h"
#include <cstring>
#include <stdarg.h>
#include <iostream>

int Math::Add(int a, int b) {
	return a + b;
}

int Math::Add(int a, int b, int c) {
	return a + b + c;
}

int Math::Add(double a, double b) {
	return int(a + b);
}

int Math::Add(double a, double b, double c) {
	return int(a + b + c);
}

int Math::Mul(int a, int b) {
	return a * b;
}

int Math::Mul(int a, int b, int c) {
	return a * b * c;
}

int Math::Mul(double a, double b) {
	return int(a * b);
}

int Math::Mul(double a, double b, double c) {
	return int(a * b * c);
}

int Math::Add(int count, ...) { // sums up a list of integers
	int sum = 0;
	va_list args;
	va_start(args, count);
	for (int i = 0; i < count; i++)
		sum += va_arg(args, int);
	va_end(args);
	return sum;
}

char* Math::Add(const char* a, const char* b) {
	if (a == nullptr || b == nullptr)
		return nullptr;
	char* sum = new char[std::max(strlen(a), strlen(b)) + 2];
	bool carry = 0;
	int k = 0, i = strlen(a) - 1, j = strlen(b) - 1;
	char aux;
	while (i >= 0 || j >= 0 || carry) {
		int s = carry;
		if (i >= 0)
			s += a[i] - '0', i--;
		if (j >= 0)
			s += b[j] - '0', j--;
		sum[k++] = (s % 10) + '0';
		carry = s / 10;
	}
	for (i = 0, j = k - 1; i < j; i++, j--)
		aux = sum[i], sum[i] = sum[j], sum[j] = aux;
	sum[k] = NULL;
	return sum;
}
