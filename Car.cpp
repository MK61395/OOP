//Muhammad Kashif
//I21-0851
//Section Y
//Assignment#2

#include "pch.h"
#include "Car.h"


Car::Car() {
	petrolLevel = 0;
}
Car::Car(int x) {
	petrolLevel = x;
}
void Car::setPetrolLevel(int x) {
	if (x <= 45 && x > 0) {
		petrolLevel = x;
	}
}
int Car::getPetrolLevel() {
	return petrolLevel;
}
bool Car::MoveCar(int x) {
	if (petrolLevel >= x) {
		petrolLevel = petrolLevel - x;
		return true;
	}

	return false;
}
void Car::Refill() {
	petrolLevel = 45;
}
bool Car::isEmpty() {
	if (petrolLevel == 0)
	{
		return true;
	}
	return false;
}