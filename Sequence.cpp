//Muhammad Kashif
//I21-0851
//Section Y
//Assignment#2

#include "pch.h"
#include "Sequence.h"


Sequence::Sequence() {
	length = 10;
	pseq = new int[length];

	for (int i = 0; i < length; i++)
	{
		*(pseq + i) = 0;
	}
};
Sequence::Sequence(int lengthVal, int n1, int n2, int n3, int n4, int n5, int n6, int n7, int n8, int n9, int n10) {
	length = lengthVal;
	int i = 0;
	pseq = new int[length];

	if (i < lengthVal) {
		*(pseq + i) = n1;
		i++;
		if (i >= lengthVal)
		{
			return;
		}
	}
	if (i < lengthVal) {
		*(pseq + i) = n2;
		i++;
		if (i >= lengthVal)
		{
			return;
		}
	}
	if (i < lengthVal) {
		*(pseq + i) = n3;
		i++;
		if (i >= lengthVal)
		{
			return;
		}
	}
	if (i < lengthVal) {
		*(pseq + i) = n4;
		i++;
		if (i >= lengthVal)
		{
			return;
		}
	}
	if (i < lengthVal) {
		*(pseq + i) = n5;
		i++;
		if (i >= lengthVal)
		{
			return;
		}
	}
	if (i < lengthVal) {
		*(pseq + i) = n6;
		i++;
		if (i >= lengthVal)
		{
			return;
		}
	}
	if (i < lengthVal) {
		*(pseq + i) = n7;
		i++;
		if (i >= lengthVal)
		{
			return;
		}
	}
	if (i < lengthVal) {
		*(pseq + i) = n8;
		i++;
		if (i >= lengthVal)
		{
			return;
		}
	}
	if (i < lengthVal) {
		*(pseq + i) = n9;
		i++;
		if (i >= lengthVal)
		{
			return;
		}
	}
	if (i < lengthVal) {
		*(pseq + i) = n10;
		i++;
		if (i >= lengthVal)
		{
			return;
		}
	}
};
Sequence::Sequence(const Sequence& obj) {
	length = obj.length;
	pseq = new int[length];

	for (int i = 0; i < length; i++)
	{
		*(pseq + i) = *(obj.pseq + i);
	}
};
int Sequence::getLength() {
	return length;
};
int* Sequence::getSeq() {
	return pseq;
};
void Sequence::Sort(int n) {
	int temp, counter;
	for (int i = 1; i < n; i++)
	{
		temp = *(pseq + i);
		counter = i;
		while ((counter > 0) && (*(pseq + (counter - 1)) > temp))
		{
			*(pseq + counter) = *(pseq + (counter - 1));
			counter--;
		}
		*(pseq + counter) = temp;
	}
};
int Sequence::RemoveDuplicates() {
	int temp, n = 1;
	int counter;
	for (int i = 0; i < length; i++)
	{
		temp = *(pseq + i);
		for (int j = i + 1; j < length; j++)
		{
			if (*(pseq + j) == temp)
			{
				*(pseq + j) = 2147483647;
			}
		}
	}

	temp = 0;
	for (int i = 1; i < length; i++)
	{
		temp = *(pseq + i);
		counter = i;
		while ((counter > 0) && (*(pseq + (counter - 1)) > temp))
		{
			*(pseq + counter) = *(pseq + (counter - 1));
			counter--;
		}
		*(pseq + counter) = temp;
	}

	for (int i = 1; i < length; i++) {
		int j = 0;
		for (j = 0; j < i; j++) {
			if (*(pseq + i) == *(pseq + j)) {
				break;
			}
			if (i - 1 == j) {
				n++;
			}
		}
	}

	return n - 1;
};
void Sequence::Rotate(int steps) {
	int* tempptr = new int[length];
	int helper;
	for (int i = 0; i < length; i++)
	{
		helper = i + steps;
		if (helper > length - 1)
		{
			helper = helper % length;
		}
		*(tempptr + helper) = *(pseq + i);
	}
	for (int i = 0; i < length; i++)
	{
		*(pseq + i) = *(tempptr + i);
	}

	delete[]tempptr;
	tempptr = nullptr;
};
Sequence::~Sequence() {
	delete[]pseq;
	pseq = nullptr;
};