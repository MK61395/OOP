//Muhammad Kashif
//I21-0851
//Section Y
//Assignment#2

#include "pch.h"
#include "CustomerAccount.h"
#include <iostream>
using namespace std;

void OpenCustomerAccount(CustomerAccount* customers[], int& accountsOpen, char* NameVal, char* addVal, char* cityVal, char* stateVal, int zipcodeVal, long long phoneVal, float balanceVal) {

	if (accountsOpen < 100)
	{
		customers[accountsOpen] = new CustomerAccount;
		customers[accountsOpen]->name = NameVal;
		customers[accountsOpen]->address.address = addVal;
		customers[accountsOpen]->address.city = cityVal;
		customers[accountsOpen]->address.state = stateVal;
		customers[accountsOpen]->address.zip_code = zipcodeVal;
		customers[accountsOpen]->phoneNum = phoneVal;
		customers[accountsOpen]->balance = balanceVal;

		customers[accountsOpen]->accountNum = new char[5];
		*(customers[accountsOpen]->accountNum) = 'P';
		*(customers[accountsOpen]->accountNum + 1) = 'K';
		*(customers[accountsOpen]->accountNum + 2) = 48 + ((accountsOpen + 1) / 100);
		*(customers[accountsOpen]->accountNum + 3) = 48 + (((accountsOpen + 1) % 100) / 10);
		*(customers[accountsOpen]->accountNum + 4) = 48 + (((accountsOpen + 1) % 100) % 10);

		accountsOpen++;
	}

	return;
};
int SearchCustomer(CustomerAccount* customers[], int accountsOpen, char* accountNum) {
	for (int i = 0; i < accountsOpen; i++)
	{
		if (i < 100) {
			if ((*(customers[i]->accountNum + 2) == *(accountNum + 2)) && (*(customers[i]->accountNum + 3) == *(accountNum + 3)) && (*(customers[i]->accountNum + 4) == *(accountNum + 4))) {
				return i;
			}
		}
	}
	return -1;
};
bool UpdateCustomerAccount(CustomerAccount* customers[], int accountsOpen, char* accountNum, Address addressVal) {
	for (int i = 0; i < accountsOpen; i++)
	{
		if ((*(customers[i]->accountNum + 2) == *(accountNum + 2)) && (*(customers[i]->accountNum + 3) == *(accountNum + 3)) && (*(customers[i]->accountNum + 4) == *(accountNum + 4))) {
			customers[i]->address.address = addressVal.address;
			customers[i]->address.city = addressVal.city;
			customers[i]->address.state = addressVal.state;
			customers[i]->address.zip_code = addressVal.zip_code;
			return true;
		}
	}
	return false;
};
bool UpdateCustomerAccount(CustomerAccount* customers[], int accountsOpen, char* accountNum, long long phoneVal) {
	for (int i = 0; i < accountsOpen; i++)
	{
		if ((*(customers[i]->accountNum + 2) == *(accountNum + 2)) && (*(customers[i]->accountNum + 3) == *(accountNum + 3)) && (*(customers[i]->accountNum + 4) == *(accountNum + 4))) {
			customers[i]->phoneNum = phoneVal;
			return true;
		}
	}
	return false;
};
bool UpdateCustomerAccount(CustomerAccount* customers[], int accountsOpen, char* accountNum, float balanceVal) {
	for (int i = 0; i < accountsOpen; i++)
	{
		if ((*(customers[i]->accountNum + 2) == *(accountNum + 2)) && (*(customers[i]->accountNum + 3) == *(accountNum + 3)) && (*(customers[i]->accountNum + 4) == *(accountNum + 4))) {
			customers[i]->balance = balanceVal;
			return true;
		}
	}
	return false;
};
void DisplayAllCustomers(CustomerAccount* customers[], int accountsOpen) {
	for (int i = 0; i < accountsOpen; i++)
	{
		cout << "Account Number : ";
		for (int j = 0; j < 5; j++)
		{
			cout << customers[i]->accountNum[j];
		}
		cout << endl;
		cout << "Name : ";
		for (int j = 0; customers[i]->name[j] != '\0'; j++)
		{
			cout << customers[i]->name[j];
		}
		cout << endl;
		cout << "Address : ";
		for (int j = 0; customers[i]->address.address[j] != '\0'; j++)
		{
			cout << customers[i]->address.address[j];
		}
		cout << endl;
		cout << "City : ";
		for (int j = 0; customers[i]->address.city[j] != '\0'; j++)
		{
			cout << customers[i]->address.city[j];
		}
		cout << endl;
		cout << "Address : ";
		for (int j = 0; customers[i]->address.state[j] != '\0'; j++)
		{
			cout << customers[i]->address.state[j];
		}
		cout << endl;
		cout << "Zipcode : " << customers[i]->address.zip_code << endl;
		cout << "Phone Number : " << customers[i]->phoneNum << endl;
		cout << "Balance : " << customers[i]->balance << endl;
		cout << endl;
		cout << endl;
	}
};