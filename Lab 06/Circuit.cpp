#include "Circuit.h"
#include <algorithm>
#include <iostream>

bool sorting(Car a, Car b) {
	if (a.hours > b.hours)
		return 0;
	return 1;
}

void Circuit::SetLength(int length) {
	this->length = length;
}

void Circuit::SetWeather(Weather w) {
	this->w = w;
}

void Circuit::AddCar(Car* c) {
	Car* newCars = new Car[carsNumber + 1];
	for (int i = 0; i < carsNumber; i++)
		newCars[i] = cars[i];
	newCars[carsNumber] = c;
	carsNumber++;
	delete[] cars;
	cars = newCars;
}

void Circuit::Race() {
	for (int i = 0; i < carsNumber; i++)
		cars[i].hours = cars[i].time(length, w);
}

void Circuit::ShowFinalRanks() {
	std::sort(cars, cars + carsNumber, sorting);
	for (int i = 0; i < carsNumber; i++)
		if (cars[i].hours != -1)
			std::cout << cars[i].getBrandName() << ": " << cars[i].hours << "hours\n";
}

void Circuit::ShowWhoDidNotFinish() {
	for (int i = 0; i < carsNumber; i++)
		if (cars[i].hours == -1)
			std::cout << cars[i].getBrandName() << "did not finish the circuit\n";
}

Circuit::Circuit() {
	carsNumber = 0;
}