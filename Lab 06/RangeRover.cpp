#include "RangeRover.h"

int RangeRover::avgSpeed(Weather w) {
	if (w == Rainy)
		return 60;
	if (w == Sunny)
		return 50;
	if (w == Snowy)
		return 54;
}

double RangeRover::time(int distance, Weather w) {
	if (fuelCons * distance / 100.0 > double(maxFuel))
		return -1;
	return double(distance) / double(avgSpeed(w));
}

RangeRover::RangeRover() {
	maxFuel = 61;
	fuelCons = 6;
	hours = 0;
}

const char* RangeRover::getBrandName() {
	return "RangeRover";
}