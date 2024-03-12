#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <ctime>
#include "movie.h"

class MovieSeries {

	Movie* movies[16];
	int number;

public:
	void initialization();

	void addMovie(Movie* movie);

	void printInfo();

	void sortMovies();

};