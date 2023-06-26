//Muhammad Kashif
//I21-0851
//Section Y
//Assignment#2

#include "pch.h"
#include "Matrix.h"
#include <iostream>
using namespace std;

Matrix::Matrix(int n1, int n2, int n3, int n4, int row, int col) {
	Matrix::row = row;
	Matrix::col = col;

	matrix = new int* [row];

	for (int i = 0; i < row; i++)
	{
		matrix[i] = new int[col];
	}

	matrix[0][0] = n1;
	matrix[0][1] = n2;
	matrix[1][0] = n3;
	matrix[1][1] = n4;
};
Matrix::Matrix(int n1, int n2, int n3, int n4, int n5, int n6, int n7, int n8, int n9, int row, int col) {
	Matrix::row = row;
	Matrix::col = col;

	matrix = new int* [row];

	for (int i = 0; i < row; i++)
	{
		matrix[i] = new int[col];
	}

	matrix[0][0] = n1;
	matrix[0][1] = n2;
	matrix[0][2] = n3;
	matrix[1][0] = n4;
	matrix[1][1] = n5;
	matrix[1][2] = n6;
	matrix[2][0] = n7;
	matrix[2][1] = n8;
	matrix[2][2] = n9;
};
Matrix::Matrix(int n1, int n2, int n3, int n4, int n5, int n6, int n7, int n8, int n9, int n10, int n11, int n12, int n13, int n14, int n15, int n16, int row, int col) {
	Matrix::row = row;
	Matrix::col = col;

	matrix = new int* [row];

	for (int i = 0; i < row; i++)
	{
		matrix[i] = new int[col];
	}

	matrix[0][0] = n1;
	matrix[0][1] = n2;
	matrix[0][2] = n3;
	matrix[0][3] = n4;
	matrix[1][0] = n5;
	matrix[1][1] = n6;
	matrix[1][2] = n7;
	matrix[1][3] = n8;
	matrix[2][0] = n9;
	matrix[2][1] = n10;
	matrix[2][2] = n11;
	matrix[2][3] = n12;
	matrix[3][0] = n13;
	matrix[3][1] = n14;
	matrix[3][2] = n15;
	matrix[3][3] = n16;
};
Matrix::Matrix(const Matrix& m) {
	row = m.row;
	col = m.col;

	matrix = new int* [row];

	for (int i = 0; i < row; i++)
	{
		matrix[i] = new int[col];
	}

	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			matrix[i][j] = m.matrix[i][j];
		}
	}
};
Matrix::~Matrix() {
	for (int i = 0; i < row; i++) {
		delete[]matrix[i];

	}
	delete[]matrix;
	matrix = '\0';
};
int Matrix::getRow() const {
	return row;
};
int Matrix::getCol() const {
	return col;
};
int Matrix::getValue(int row, int col) {
	return matrix[row][col];
};
void Matrix::setValue(int row, int col, int value) {
	matrix[row][col] = value;
};
int Matrix::Total() {
	int sum = 0;
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			sum += matrix[i][j];
		}
	}

	return sum;
};
double Matrix::Average() {
	double total = Total();
	return total / (row * col);
};
int Matrix::RowTotal(int row) {
	int tot = 0;
	for (int i = 0; i < col; i++)
	{
		tot += matrix[row][i];
	}

	return tot;
};
int Matrix::ColumnTotal(int col) {
	int tot = 0;
	for (int i = 0; i < row; i++)
	{
		tot += matrix[i][col];
	}

	return tot;
};
int Matrix::HighestInRow(int row) {
	int max = matrix[row][0];

	for (int i = 0; i < col; i++)
	{
		if (matrix[row][i] > max) {
			max = matrix[row][i];
		}
	}

	return max;
};
int Matrix::LowestInRow(int row) {
	int min = matrix[row][0];

	for (int i = 0; i < col; i++)
	{
		if (matrix[row][i] < min) {
			min = matrix[row][i];
		}
	}

	return min;
};
Matrix Matrix::Transpose() {
	if (row == 2) {
		Matrix tempmatrix(0, 0, 0, 0);

		for (int i = 0; i < row; i++)
		{
			for (int j = 0; j < col; j++)
			{
				tempmatrix.matrix[i][j] = matrix[j][i];
			}
		}

		return tempmatrix;
	}
	else if (row == 3)
	{
		Matrix tempmatrix(0, 0, 0, 0, 0, 0, 0, 0, 0);
		for (int i = 0; i < row; i++)
		{
			for (int j = 0; j < col; j++)
			{
				tempmatrix.matrix[i][j] = matrix[j][i];
			}
		}

		return tempmatrix;
	}
	else if (row == 4)
	{
		Matrix tempmatrix(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);
		for (int i = 0; i < row; i++)
		{
			for (int j = 0; j < col; j++)
			{
				tempmatrix.matrix[i][j] = matrix[j][i];
			}
		}

		return tempmatrix;
	}

};
int Matrix::LeftDiagonalTotal() {
	int tot = 0;

	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			if (i == j) {
				tot += matrix[i][j];
			}
		}
	}

	return tot;
};
int Matrix::RightDiagonalTotal() {
	int tot = 0;
	int helpptr = col - 1;

	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			if (j == 0) {
				tot += matrix[i][j + helpptr];
				helpptr--;
			}
		}
	}

	return tot;
};
Matrix Matrix::Add(Matrix m) {
	if (row == 2) {
		Matrix addmatrix(0, 0, 0, 0);
		if (row != m.row && col != m.col)
		{
			addmatrix.row = 0;
			addmatrix.col = 0;
			delete[]addmatrix.matrix;
			addmatrix.matrix = '\0';

			return addmatrix;
		}

		for (int i = 0; i < row; i++)
		{
			for (int j = 0; j < col; j++)
			{
				addmatrix.matrix[i][j] = m.matrix[i][j] + matrix[i][j];
			}
		}

		return addmatrix;
	}
	else if (row == 3) {
		Matrix addmatrix(0, 0, 0, 0, 0, 0, 0, 0, 0);
		if (row != m.row && col != m.col)
		{
			addmatrix.row = 0;
			addmatrix.col = 0;
			delete[]addmatrix.matrix;
			addmatrix.matrix = '\0';

			return addmatrix;
		}

		for (int i = 0; i < row; i++)
		{
			for (int j = 0; j < col; j++)
			{
				addmatrix.matrix[i][j] = m.matrix[i][j] + matrix[i][j];
			}
		}

		return addmatrix;
	}
	else if (row == 4) {
		Matrix addmatrix(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);
		if (row != m.row && col != m.col)
		{
			addmatrix.row = 0;
			addmatrix.col = 0;
			delete[]addmatrix.matrix;
			addmatrix.matrix = '\0';

			return addmatrix;
		}

		for (int i = 0; i < row; i++)
		{
			for (int j = 0; j < col; j++)
			{
				addmatrix.matrix[i][j] = m.matrix[i][j] + matrix[i][j];
			}
		}

		return addmatrix;
	}


};
Matrix Matrix::Subtract(Matrix m) {
	if (row == 2) {
		Matrix submatrix(0, 0, 0, 0);
		if (row != m.row && col != m.col)
		{
			submatrix.row = 0;
			submatrix.col = 0;
			delete[]submatrix.matrix;
			submatrix.matrix = '\0';

			return submatrix;
		}

		for (int i = 0; i < row; i++)
		{
			for (int j = 0; j < col; j++)
			{
				submatrix.matrix[i][j] = matrix[i][j] - m.matrix[i][j];
			}
		}

		return submatrix;
	}
	else if (row == 3) {
		Matrix submatrix(0, 0, 0, 0, 0, 0, 0, 0, 0);
		if (row != m.row && col != m.col)
		{
			submatrix.row = 0;
			submatrix.col = 0;
			delete[]submatrix.matrix;
			submatrix.matrix = '\0';

			return submatrix;
		}

		for (int i = 0; i < row; i++)
		{
			for (int j = 0; j < col; j++)
			{
				submatrix.matrix[i][j] = matrix[i][j] - m.matrix[i][j];
			}
		}

		return submatrix;
	}
	else if (row == 4) {
		Matrix submatrix(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);
		if (row != m.row && col != m.col)
		{
			submatrix.row = 0;
			submatrix.col = 0;
			delete[]submatrix.matrix;
			submatrix.matrix = '\0';

			return submatrix;
		}

		for (int i = 0; i < row; i++)
		{
			for (int j = 0; j < col; j++)
			{
				submatrix.matrix[i][j] = matrix[i][j] - m.matrix[i][j];
			}
		}

		return submatrix;
	}

};
Matrix Matrix::Multiply(Matrix m) {
	if (row == 2) {
		Matrix multimatrix(0, 0, 0, 0);
		if (row != m.row && col != m.col)
		{
			multimatrix.row = 0;
			multimatrix.col = 0;
			delete[]multimatrix.matrix;
			multimatrix.matrix = '\0';

			return multimatrix;
		}

		for (int i = 0; i < row; i++)
		{
			for (int j = 0; j < col; j++)
			{
				for (int k = 0; k < col; k++)
				{
					multimatrix.matrix[i][j] += matrix[i][k] * m.matrix[k][j];
				}
			}
		}

		return multimatrix;
	}
	else if (row == 3) {
		Matrix multimatrix(0, 0, 0, 0, 0, 0, 0, 0, 0);
		if (row != m.row && col != m.col)
		{
			multimatrix.row = 0;
			multimatrix.col = 0;
			delete[]multimatrix.matrix;
			multimatrix.matrix = '\0';

			return multimatrix;
		}

		for (int i = 0; i < row; i++)
		{
			for (int j = 0; j < col; j++)
			{
				for (int k = 0; k < col; k++)
				{
					multimatrix.matrix[i][j] += matrix[i][k] * m.matrix[k][j];
				}
			}
		}
		return multimatrix;
	}
	else if (row == 4) {
		Matrix multimatrix(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);
		if (row != m.row && col != m.col)
		{
			multimatrix.row = 0;
			multimatrix.col = 0;
			delete[]multimatrix.matrix;
			multimatrix.matrix = '\0';

			return multimatrix;
		}

		for (int i = 0; i < row; i++)
		{
			for (int j = 0; j < col; j++)
			{
				for (int k = 0; k < col; k++)
				{
					multimatrix.matrix[i][j] += matrix[i][k] * m.matrix[k][j];
				}
			}
		}
		return multimatrix;
	}
};
int Matrix::FindkSmallest(int k) {
	int temp, ksmall = 0, unique = 0;

	int* tempptr = new int[row * col];

	for (int i = 0; i < 9; i++)
	{
		tempptr[i] = matrix[i / 3][i % 3];
	}

	for (int i = 0; i < 9; i++)
	{
		for (int j = i + 1; j < 9; j++)
		{
			if (tempptr[i] > tempptr[j])
			{
				temp = tempptr[i];
				tempptr[i] = tempptr[j];
				tempptr[j] = temp;
			}

		}

	}

	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			if (tempptr[i] == tempptr[i + 1])
			{
				tempptr[i + 1] = 2147483647;
			}
		}

	}

	for (int j = 0; j < 8; j++)
	{
		for (int i = 0; i < 8; i++)
		{
			if (tempptr[i] == 2147483647)
			{
				tempptr[i] = tempptr[i + 1];
				tempptr[i + 1] = 2147483647;
			}

		}
	}


	for (int i = 0; tempptr[i] != 2147483647; i++)
	{
		unique++;
	}

	if (k > unique)
	{
		ksmall = tempptr[unique - 1];
	}

	else if (k < 1) {
		ksmall = 0;
	}
	else {
		ksmall = tempptr[k - 1];
	}


	delete[]tempptr;
	tempptr = '\0';

	return ksmall;
};
int Matrix::FindkLargest(int k) {
	int temp, klarge = 0, unique = 0;

	int* tempptr = new int[row * col];

	for (int i = 0; i < 9; i++)
	{
		tempptr[i] = matrix[i / 3][i % 3];
	}

	for (int i = 0; i < 9; i++)
	{
		for (int j = i + 1; j < 9; j++)
		{
			if (tempptr[i] < tempptr[j])
			{
				temp = tempptr[i];
				tempptr[i] = tempptr[j];
				tempptr[j] = temp;
			}

		}

	}

	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			if (tempptr[i] == tempptr[i + 1])
			{
				tempptr[i + 1] = -2147483647;
			}
		}

	}

	for (int j = 0; j < 8; j++)
	{
		for (int i = 0; i < 8; i++)
		{
			if (tempptr[i] == -2147483647)
			{
				tempptr[i] = tempptr[i + 1];
				tempptr[i + 1] = -2147483647;
			}

		}
	}


	for (int i = 0; tempptr[i] != -2147483647; i++)
	{
		unique++;
	}

	if (k > unique)
	{
		klarge = tempptr[unique - 1];
	}

	else if (k < 1) {
		klarge = 0;
	}
	else {
		klarge = tempptr[k - 1];
	}


	delete[]tempptr;
	tempptr = '\0';

	return klarge;
};
Matrix Matrix::merge(Matrix m) {
	int col2 = 2 * col;
	Matrix mergematrix(0, 0, 0, 0, row, col2);
	if (row != m.row || col != m.col)
	{
		mergematrix.row = 0;
		mergematrix.col = 0;
		delete[]mergematrix.matrix;
		mergematrix.matrix = '\0';

		return mergematrix;
	}

	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col2; j++)
		{
			mergematrix.matrix[i][j] = 0;
		}
	}

		for (int i = 0; i < row; i++)
		{
			for (int j = 0; j < (col2/2); j++)
			{
				mergematrix.matrix[i][j] = matrix[i][j];
			}
			for (int k = (col2 / 2); k < col2; k++)
			{
				mergematrix.matrix[i][k] = m.matrix[i][k - col];
			}
		}

		return mergematrix;
	};