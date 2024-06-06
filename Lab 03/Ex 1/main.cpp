#include <iostream>
#include "Math.h"

using namespace std;

int main() {
	cout << Math::Add(3, 5) << " " << Math::Add(4, 7, 23) << " " << Math::Add(8.32,- 9.25423) << " " << Math::Add(2.432, 546.3, 95.23) << '\n';
	cout << Math::Mul(4, -18) << " " << Math::Mul(5, -123, 453) << " " << Math::Mul(2.13, 43.32) << " " << Math::Mul(-3.42, 234.5, -85.3) << '\n';
	cout << Math::Add(5, 23, 54, 203, -43, -553) << " " << Math::Add(8, 36, 234, 5436, -2435, -223, -6, 2, 6) << '\n';
	cout << Math::Add("54313", "6983023") << " " << Math::Add("97245", "8642") << " " << Math::Add("5678", "4932");
}