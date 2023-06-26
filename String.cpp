//Muhammad Kashif
//I21-0851
//Section Y
//Assignment#2

#include "pch.h"
#include "String.h"
#include <iostream>
using namespace std;

String::String() {
	length = 0;
	data = NULL;
};
String::String(int size) {
	length = size;
	data = new char[length + 1];

	for (int i = 0; i < length + 1; i++)
	{
		*(data + i) = NULL;
	}
};
String::String(char* str) {
	int i = 0;
	while (*(str + i) != '\0')
	{
		i++;
	}

	length = i;

	data = new char[length + 1];

	for (int j = 0; j < length; j++)
	{
		*(data + j) = *(str + j);
	}

	*(data + length) = '\0';
};
String::String(const String& str) {
	length = str.length;
	data = new char[length + 1];

	for (int i = 0; i < length; i++)
	{
		*(data + i) = str.data[i];
	}

	*(data + length) = '\0';

};
String::~String() {
	delete[]data;
	data = NULL;
};
int String::strLength() {
	return length;
};
void String::clear() {
	delete[]data;
	data = NULL;
	length = NULL;
};
bool String::empty() {
	if (length == NULL || length == 0) {
		return true;
	}

	return false;
};
char* String::getdata() {
	return data;
};
int String::charAt(char c) {
	for (int i = 0; i < length; i++)
	{
		if (*(data + i) == c)
		{
			return i;
		}
	}
	return -1;
};
bool String::equals(char* str) {
	bool tempflag = false;
	for (int i = 0; i < length; i++)
	{
		if (str[i] != data[i]) {
			return false;
		}
		else {
			tempflag = true;
		}
	}
	if (tempflag == true && (str[length] == '\0') && (data[length] == '\0'))
	{
		return true;
	}
};
bool String::equalsIgnoreCase(char* str) {
	bool tempflag = false;
	for (int i = 0; i < length; i++)
	{
		if (str[i] != data[i]) {
			if (str[i] != (data[i] + 32)) {
				if (str[i] != (data[i] - 32))
				{
					return false;
				}
			}
		}
		else {
			tempflag = true;
		}
	}
	if (tempflag == true && (str[length] == '\0') && (data[length] == '\0'))
	{
		return true;
	}
};
//char* String::substring(char* substr, int startIndex) {
//	int substr_size = 0;
//	bool checkflag = 0;
//	int match = 0;
//	int returnsize = 0;
//
//	for (int i = 0; substr[i] != '\0'; i++)
//	{
//		substr_size++;
//	}
//
//	for (int i = startIndex; i < length; i++)
//	{
//			if (substr[0] != data[i])
//			{
//				checkflag = false;
//			}
//			else {
//				checkflag = true;
//				match = i;
//				break;
//		}
//	}
//
//	for (int i = match; i < length; i++)
//	{
//		for (int j = 0; j < substr_size; j++)
//		{
//			if (substr[j] == data[i]) {
//				checkflag = true;
//			}
//			else {
//				checkflag = false;
//			}
//		}
//		if (checkflag == false)
//		{
//			break;
//		}
//	}
//
//	for (int i = match; i < length; i++)
//	{
//		cout << data[i];
//	}
//	cout << endl;
//
//	for (int i = match; i < length; i++)
//	{
//		returnsize++;
//	}
//
//	char* returnptr = new char[returnsize];
//
//	for (int i = 0; i < returnsize; i++)
//	{
//		returnptr[i] = data[match + i];
//	}
//
//	for (int i = 0; i < returnsize; i++)
//	{
//		cout << returnptr[i];
//	}
//	cout << endl;
//
//	if (checkflag == true) {
//		return returnptr;
//	}
//
//	return 0;
//};
//char* String::substring(char* substr, int startIndex, int endIndex) {
//
//};
//void String::print() {
//
//};