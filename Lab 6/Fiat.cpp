#include "Fiat.h"

int Fiat::avgSpeed(Weather w) {
	if (w == Rainy)
		return 40;
	if (w == Sunny)
		return 35;
	if (w == Snowy)
		return 24;
}

double Fiat::time(int distance, Weather w) {
	if (fuelCons * distance / 100.0 > double(maxFuel))
		return -1;
	return double(distance) / double(avgSpeed(w));
}

Fiat::Fiat() {
	maxFuel = 100;
	fuelCons = 6;
	hours = 0;
}

const char* Fiat::getBrandName() {
	return "Fiat";
}