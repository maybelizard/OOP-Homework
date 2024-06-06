#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

class Student {
	char name[256];
	float math, english, history;

public:

	void setName(const char* name);
	void setMathGrade(float mathGrade);
	void setEnglishGrade(float englishGrade);
	void setHistoryGrade(float historyGrade);

	char* getName();
	float getMathGrade();
	float getEnglishGrade();
	float getHistoryGrade();

	float averageGrade();
};