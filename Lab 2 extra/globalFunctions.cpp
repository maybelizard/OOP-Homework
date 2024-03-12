#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <ctime>
#include "movie.h"
#include "movieSeries.h"
#include "globalFunctions.h"

int compareName(Movie m1, Movie m2) {
	char m1Name[256], m2Name[256];
	strcpy(m1Name, m1.getName());
	strcpy(m2Name, m2.getName());
	int comparation = strcmp(m1Name, m2Name);
	if (comparation < 0) return -1;
	if (comparation == 0) return 0;
	if (comparation > 0) return 1;
}

int compareReleasedYears(Movie m1, Movie m2) {
	int m1Year = m1.getReleaseYear();
	int m2Year = m2.getReleaseYear();
	if (m1Year < m2Year) return -1;
	if (m1Year == m2Year) return 0;
	if (m1Year > m2Year) return 1;
}

int compareImdbScore(Movie m1, Movie m2) {
	double m1Score = m1.getImdbScore();
	double m2Score = m2.getImdbScore();
	if (m1Score < m2Score) return -1;
	if (m1Score == m2Score) return 0;
	if (m1Score > m2Score) return 1;
}

int compareLength(Movie m1, Movie m2) {
	int m1Length = m1.getLength();
	int m2Length = m2.getLength();
	if (m1Length < m2Length) return -1;
	if (m1Length == m2Length) return 0;
	if (m1Length > m2Length) return 1;
}

int comparePassedYears(Movie m1, Movie m2) {
	int m1Years = m1.yearsPassed();
	int m2Years = m2.yearsPassed();
	if (m1Years < m2Years) return -1;
	if (m1Years == m2Years) return 0;
	if (m1Years > m2Years) return 1;
}