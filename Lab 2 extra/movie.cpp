#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <ctime>
#include "movie.h"

void Movie::setName(const char* name) {
	strcpy(this->name, name);
}
void Movie::setReleaseYear(int releaseYear) {
	this->releaseYear = releaseYear;
}
void Movie::setImdbScore(double imdbScore) {
	if (imdbScore >= 1 && imdbScore <= 10)
		this->imdbScore = imdbScore;
}
void Movie::setLength(int length) {
	this->length = length;
}

char* Movie::getName() {
	return name;
}
int Movie::getReleaseYear() {
	return releaseYear;
}
double Movie::getImdbScore() {
	return imdbScore;
}
int Movie::getLength() {
	return length;
}

int Movie::yearsPassed() {
	std::time_t t = std::time(nullptr);
	std::tm* now = std::localtime(&t);
	int currentYear = now->tm_year + 1900;
	return currentYear - releaseYear;
}