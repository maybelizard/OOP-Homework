#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "student.h"

void Student::setName(const char* name) {
	strcpy(this->name, name);
}
void Student::setMathGrade(float grade) {
	if (grade >= 1 && grade <= 10)
		math = grade;
}
void Student::setEnglishGrade(float grade) {
	if (grade >= 1 && grade <= 10)
		english = grade;
}
void Student::setHistoryGrade(float grade) {
	if (grade >= 1 && grade <= 10)
		history = grade;
}

char* Student::getName() {
	return name;
}
float Student::getMathGrade() {
	return math;
}
float Student::getEnglishGrade() {
	return english;
}
float Student::getHistoryGrade() {
	return history;
}

float Student::averageGrade() {
	return (math + english + history) / 3.0;
}

