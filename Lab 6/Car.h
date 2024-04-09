#pragma once
#include "Weather.h"

class Car {
	int maxFuel; //in liters
	int fuelCons; //in liters/100 km
public:
	double hours;
	virtual int avgSpeed(Weather w); //in km/h
	virtual double time(int distance, Weather w); //distance in km, time in h
	Car();
	Car(Car* c) {
		maxFuel = c->maxFuel, fuelCons = c->fuelCons, hours = c->hours;
	}
	virtual const char* getBrandName();
	~Car() {};
};