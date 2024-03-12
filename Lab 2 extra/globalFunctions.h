#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <ctime>
#include "movie.h"
#include "movieSeries.h"

int compareName(Movie m1, Movie m2);

int compareReleasedYears(Movie m1, Movie m2);

int compareImdbScore(Movie m1, Movie m2);

int compareLength(Movie m1, Movie m2);

int comparePassedYears(Movie m1, Movie m2);