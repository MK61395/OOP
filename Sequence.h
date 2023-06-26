#pragma once
class Sequence {
private:
	int length;
	int* pseq;

public:
	Sequence();
	Sequence(int, int = 0, int = 0, int = 0, int = 0, int = 0, int = 0, int = 0, int = 0, int = 0, int = 0);
	Sequence(const Sequence&);
	int getLength();
	int* getSeq();
	void Sort(int);
	int RemoveDuplicates();
	void Rotate(int);
	~Sequence();
};