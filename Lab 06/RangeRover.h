#pragma once
#include "Car.h"

class RangeRover : public Car {
	int maxFuel; //in liters
	int fuelCons; //in liters/km
	double hours;
public:
	int avgSpeed(Weather w); //in km/h
	double time(int distance, Weather w); //distance in km, time in h
	RangeRover();
	const char* getBrandName();
};