#include"Matrix.h"
#include<iostream>
using namespace std;

Matrix::Matrix(int size) :size(size)
{
    elements = new double[size * size];
}

Matrix::~Matrix()
{
    delete[]elements;
}

void Matrix::setMatrix(const double* values)
{
    for (int i = 0; i < size * size; i++)
    {
        elements[i] = values[i];
    }
}
void Matrix::InitMatrix(int length)
{
    delete[]elements;
    size = length;
    elements = new double[length * length];
    for (int i = 0; i < length * length; i++)
    {
        elements[i] = 0;
    }
}
void Matrix::printMatrix() const {
    cout << "The Matrix is:" << endl;
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++)
            cout << element(i, j) << " ";
        cout << endl;
    }
}
