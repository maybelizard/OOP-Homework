#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <ctime>

class Movie {

	char name[256];
	int releaseYear;
	double imdbScore;
	int length;

public:

	void setName(const char* name);
	void setReleaseYear(int releaseYear);
	void setImdbScore(double imdbScore);
	void setLength(int length);

	char* getName();
	int getReleaseYear();
	double getImdbScore();
	int getLength();

	int yearsPassed();
};