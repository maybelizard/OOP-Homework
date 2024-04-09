#include "BMW.h"

int BMW::avgSpeed(Weather w) {
	if (w == Rainy)
		return 90;
	if (w == Sunny)
		return 75;
	if (w == Snowy)
		return 59;
}

double BMW::time(int distance, Weather w) {
	if (fuelCons * distance / 100.0 > double(maxFuel))
		return -1;
	return double(distance) / double(avgSpeed(w));
}

BMW::BMW() {
	maxFuel = 57;
	fuelCons = 5;
	hours = 0;
}

const char* BMW::getBrandName() {
	return "BMW";
}