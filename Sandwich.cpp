//Muhammad Kashif
//I21-0851
//Section Y
//Assignment#2

#include "pch.h"
#include "Sandwich.h"

Sandwich::Sandwich() {
	name = NULL;
	filling = NULL;
	size = NULL;
	is_ready = false;
	price = 0.0;
};
Sandwich::Sandwich(char* fillingVal, double priceVal) {
	filling = fillingVal;
	price = priceVal;
};
Sandwich::Sandwich(char* fillingVal, double priceVal, char* nameVal, char* sizeVal, bool ready_status) {
	filling = fillingVal;
	price = priceVal;
	name = nameVal;

	if ((*(sizeVal) == 's' && *(sizeVal + 1) == 'm' && *(sizeVal + 2) == 'a' && *(sizeVal + 3) == 'l' && *(sizeVal + 4) == 'l') || (*(sizeVal) == 'l' && *(sizeVal + 1) == 'a' && *(sizeVal + 2) == 'r' && *(sizeVal + 3) == 'g' && *(sizeVal + 4) == 'e') || (*(sizeVal) == 'm' && *(sizeVal + 1) == 'e' && *(sizeVal + 2) == 'd' && *(sizeVal + 3) == 'i' && *(sizeVal + 4) == 'u' && *(sizeVal + 5) == 'm')) {
		size = sizeVal;
	}
	else
	{
		size = NULL;
	}

	is_ready = ready_status;
};
Sandwich::Sandwich(const Sandwich& obj) {
	name = obj.name;
	price = obj.price;
	filling = obj.filling;
	size = obj.size;
	is_ready = obj.is_ready;
};
void Sandwich::setFilling(char* fillingVal) {
	filling = fillingVal;
};
void Sandwich::setPrice(double priceVal) {
	price = priceVal;
};
void Sandwich::setName(char* nameVal) {
	name = nameVal;
};
void Sandwich::setSize(char* sizeVal) {
	if ((*(sizeVal) == 's' && *(sizeVal + 1) == 'm' && *(sizeVal + 2) == 'a' && *(sizeVal + 3) == 'l' && *(sizeVal + 4) == 'l') || (*(sizeVal) == 'l' && *(sizeVal + 1) == 'a' && *(sizeVal + 2) == 'r' && *(sizeVal + 3) == 'g' && *(sizeVal + 4) == 'e') || (*(sizeVal) == 'm' && *(sizeVal + 1) == 'e' && *(sizeVal + 2) == 'd' && *(sizeVal + 3) == 'i' && *(sizeVal + 4) == 'u' && *(sizeVal + 5) == 'm')) {
		size = sizeVal;
	}
};
char* Sandwich::getFilling() {
	return filling;
};
double Sandwich::getPrice() {
	return price;
};
char* Sandwich::getName() {
	return name;
};
char* Sandwich::getSize() {
	return size;
};
void Sandwich::makeSandwich() {
	if (filling != NULL)
	{
		is_ready = true;
	}
};
bool Sandwich::check_status() {
	if (is_ready == true)
	{
		return true;
	}
	return false;
};