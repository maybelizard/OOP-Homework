#pragma once
#include "Car.h"

class Circuit {
	int length;
	Weather w;
	Car* cars;
	int carsNumber;
	double* times;
public:
	void SetLength(int length);
	void SetWeather(Weather w);
	void AddCar(Car* c);
	void Race();
	void ShowFinalRanks();
	void ShowWhoDidNotFinish();
	Circuit();
	~Circuit() {};
};