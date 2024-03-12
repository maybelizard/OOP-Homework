#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <ctime>
#include "movie.h"
#include "movieSeries.h"
#include "globalFunctions.h"

int main() {
	Movie shrek;
	shrek.setName("Shrek");
	shrek.setReleaseYear(2001);
	shrek.setImdbScore(7.9);
	shrek.setLength(90);

	Movie mulan;
	mulan.setName("Mulan");
	mulan.setReleaseYear(1998);
	mulan.setImdbScore(7.7);
	mulan.setLength(88);

	std::cout << shrek.yearsPassed() << '\n';
	std::cout << comparePassedYears(shrek, mulan) << '\n';
	std::cout << compareName(shrek, mulan) << '\n';
	std::cout << mulan.getImdbScore() << '\n';

	Movie ep5;
	ep5.setName("Star Wars: Episode V - The Empire Strikes Back");
	ep5.setImdbScore(8.7);
	ep5.setReleaseYear(1980);
	ep5.setLength(124);

	Movie ep4;
	ep4.setName("Star Wars: Episode IV - A New Hope");
	ep4.setImdbScore(8.6);
	ep4.setReleaseYear(1977);
	ep4.setLength(121);

	Movie ep6;
	ep6.setName("Star Wars: Episode VI - Return of the Jedi");
	ep6.setImdbScore(8.3);
	ep6.setReleaseYear(1983);
	ep6.setLength(131);

	printf(
		R"(
	ep4, ep5 comparisons:
	name        : %d
	year        : %d
	score       : %d
	length      : %d
	passed years: %d
	)",
	compareName(ep4, ep5),
	compareReleasedYears(ep4, ep5),
	compareImdbScore(ep4, ep5),
	compareLength(ep4, ep5),
	comparePassedYears(ep4, ep5));

	MovieSeries series;
	series.initialization();
	series.addMovie(&ep5);
	series.addMovie(&ep4);
	series.addMovie(&ep6);

	series.sortMovies();
	std::cout << '\n';
	series.printInfo();
	return 0;
}