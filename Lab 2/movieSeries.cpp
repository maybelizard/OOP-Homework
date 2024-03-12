#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <ctime>
#include "movie.h"
#include "movieSeries.h"

void MovieSeries::initialization() {
	for (int i = 0; i < 16; i++)
		this->movies[i] = NULL;
	this->number = 0;
}

void MovieSeries::addMovie(Movie* movie) {
	if (number < 16) {
		movies[number] = movie;
		number++;
	}
}

void MovieSeries::printInfo() {
	for (int i = 0; i < number; i++) {
		std::cout << movies[i]->getName() << " : Released in " << movies[i]->getReleaseYear();
		std::cout << ", " << movies[i]->getImdbScore() << " IMDB score, " << movies[i]->getLength() << " minutes\n";
	}
}

void MovieSeries::sortMovies() {
	for (int i = 0; i < number - 1; i++)
		for (int j = i + 1; j < number; j++)
			if (movies[i]->yearsPassed() < movies[j]->yearsPassed())
				std::swap(movies[i], movies[j]);
}