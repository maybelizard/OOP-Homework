#include "Volvo.h"

int Volvo::avgSpeed(Weather w) {
	if (w == Rainy)
		return 95;
	if (w == Sunny)
		return 100;
	if (w == Snowy)
		return 80;
}

double Volvo::time(int distance, Weather w) {
	if (fuelCons * distance / 100.0 > double(maxFuel))
		return -1;
	return double(distance) / double(avgSpeed(w));
}

Volvo::Volvo() {
	maxFuel = 60;
	fuelCons = 7;
	hours = 0;
}

const char* Volvo::getBrandName() {
	return "Volvo";
}