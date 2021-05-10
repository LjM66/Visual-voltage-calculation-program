#pragma once
#ifndef _INPUT_H
#define _INPUT_H
#include <iostream>
#include <cstring>
#include <string>
#include <cmath>
#include "Matrix.h"
using namespace std;

class Input:public Matrix
{
private:
    string name[100];
    double a[100][6];
    int len;
public:
    int size;
    double* right;
    Input(int size, string* n, double(*p)[6]) :Matrix(size)
    {
        this->size = size;
        for (int i = 0; i < size; i++)
        {
            for (int j = 0; j < size; j++)
            {
                element(i, j) = 0;
            }

        }
        right = new double[size];
        for (int i = 0; i < size; i++)
            right[i] = 0;

        for (int i = 0; n[i] != "END"; i++)
        {
            len = i;
            name[i] = n[i];
            for (int j = 0; j < 6; j++)
                a[i][j] = p[i][j];
        }
        name[len + 1] = "END";

    }
    ~Input()
    {
        delete[]right;
    }
    void SetUp();
    void AddSize_1();
    void AddSize_2();
};
#endif // _INPUT_H


