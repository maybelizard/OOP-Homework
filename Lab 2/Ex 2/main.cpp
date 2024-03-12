#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "student.h"
#include "globalFunctions.h"

int main() {
	Student vasile;
	vasile.setName("Vasile Popescu");
	vasile.setEnglishGrade(3.5);
	vasile.setMathGrade(9.8);
	vasile.setHistoryGrade(6.77);

	Student ana;
	ana.setName("Ana Ionescu");
	ana.setMathGrade(3.46);
	ana.setEnglishGrade(8.78);
	ana.setHistoryGrade(9.99);

	std::cout << vasile.averageGrade() << '\n' << ana.averageGrade() << '\n';
	std::cout << compareName(vasile, ana) << " " << compareMathGrade(vasile, ana) << " " << compareEnglishGrade(vasile, ana);
	std::cout << " " << compareHistoryGrade(vasile, ana) << " " << compareAverageGrade(vasile, ana) << '\n';
	return 0;
}