#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "student.h"
#include "globalFunctions.h"

int compareName(Student s1, Student s2) {
	char s1Name[256], s2Name[256];
	strcpy(s1Name, s1.getName());
	strcpy(s2Name, s2.getName());
	int comparation = strcmp(s1Name, s2Name);
	if (comparation < 0) return -1;
	if (comparation == 0) return 0;
	if (comparation > 0) return 1;
}

int compareMathGrade(Student s1, Student s2) {
	double s1Grade = s1.getMathGrade();
	double s2Grade = s2.getMathGrade();
	if (s1Grade < s2Grade) return -1;
	if (s1Grade == s2Grade) return 0;
	if (s1Grade > s2Grade) return 1;
}

int compareEnglishGrade(Student s1, Student s2) {
	double s1Grade = s1.getEnglishGrade();
	double s2Grade = s2.getEnglishGrade();
	if (s1Grade < s2Grade) return -1;
	if (s1Grade == s2Grade) return 0;
	if (s1Grade > s2Grade) return 1;
}

int compareHistoryGrade(Student s1, Student s2) {
	double s1Grade = s1.getHistoryGrade();
	double s2Grade = s2.getHistoryGrade();
	if (s1Grade < s2Grade) return -1;
	if (s1Grade == s2Grade) return 0;
	if (s1Grade > s2Grade) return 1;
}

int compareAverageGrade(Student s1, Student s2) {
	double s1Grade = s1.averageGrade();
	double s2Grade = s2.averageGrade();
	if (s1Grade < s2Grade) return -1;
	if (s1Grade == s2Grade) return 0;
	if (s1Grade > s2Grade) return 1;
}