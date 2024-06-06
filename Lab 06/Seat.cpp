#include "Seat.h"

int Seat::avgSpeed(Weather w) {
	if (w == Rainy)
		return 70;
	if (w == Sunny)
		return 85;
	if (w == Snowy)
		return 64;
}

double Seat::time(int distance, Weather w) {
	if (fuelCons * distance / 100.0 > double(maxFuel))
		return -1;
	return double(distance) / double(avgSpeed(w));
}

Seat::Seat() {
	maxFuel = 35;
	fuelCons = 8;
	hours = 0;
}

const char* Seat::getBrandName() {
	return "Seat";
}