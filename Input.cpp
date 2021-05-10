#include "Input.h"
#include <iostream>
using namespace std;

void Input::AddSize_1()
{
    double** ele;
    ele = new double* [size];
    for (int k = 0; k < size; k++)
        ele[k] = new double[size];
    for (int k = 0; k < size; k++)
    {
        for (int j = 0; j < size; j++)
            ele[k][j] = element(k, j);
    }
    InitMatrix(size + 1);
    for (int k = 0; k < size; k++)
    {
        for (int j = 0; j < size; j++)
            element(k, j) = ele[k][j];
    }
    for (int k = 0; k < size; k++)
        delete[]ele[k];
    delete[]ele;

    double* r = new double[size];
    for (int k = 0; k < size; k++)
        r[k] = right[k];
    delete[]right;
    right = new double[size + 1];
    for (int k = 0; k < size; k++)
        right[k] = r[k];
    right[size] = 0;

    delete[]r;
    size++;
}

void Input::AddSize_2()
{
    double** ele;
    ele = new double* [size];
    for (int k = 0; k < size; k++)
        ele[k] = new double[size];
    for (int k = 0; k < size; k++)
    {
        for (int j = 0; j < size; j++)
            ele[k][j] = element(k, j);
    }
    InitMatrix(size + 2);
    for (int k = 0; k < size; k++)
    {
        for (int j = 0; j < size; j++)
            element(k, j) = ele[k][j];
    }
    for (int k = 0; k < size; k++)
        delete[]ele[k];
    delete[]ele;

    double* r = new double[size];
    for (int k = 0; k < size; k++)
        r[k] = right[k];
    delete[]right;
    right = new double[size + 2];
    for (int k = 0; k < size; k++)
        right[k] = r[k];
    right[size] = 0;
    right[size + 1] = 0;
    delete[]r;
    size += 2;
}

void Input::SetUp()
{
    for (int i = 0; name[i] != "END"; i++)
    {
        int a0 = static_cast<int> (a[i][0]);
        int a1 = static_cast<int> (a[i][1]);

        if (name[i] == "R")
        {
            if (a0 && a1)
            {
                element(a0 - 1, a0 - 1) += 1 / a[i][2];
                element(a0 - 1, a1 - 1) -= 1 / a[i][2];
                element(a1 - 1, a0 - 1) -= 1 / a[i][2];
                element(a1 - 1, a1 - 1) += 1 / a[i][2];
            }
            else if (a0)
                element(a0 - 1, a0 - 1) += 1 / a[i][2];
            else
                element(a1 - 1, a1 - 1) += 1 / a[i][2];
        }

        if (name[i] == "S")
        {
            if (a0 && a1)
            {
                element(a0 - 1, a0 - 1) += a[i][2];
                element(a0 - 1, a1 - 1) -= a[i][2];
                element(a1 - 1, a0 - 1) -= a[i][2];
                element(a1 - 1, a1 - 1) += a[i][2];
            }
            else if (a0)
                element(a0 - 1, a0 - 1) += a[i][2];
            else
                element(a1 - 1, a1 - 1) += a[i][2];
        }

        else if (name[i] == "DC")
        {
            if (a0 && a1)
            {
                right[a0 - 1] -= a[i][2];
                right[a1 - 1] += a[i][2];
            }
            else if (a0)
                right[a0 - 1] -= a[i][2];
            else
                right[a1 - 1] += a[i][2];
        }

        else if (name[i] == "DV")
        {
            if (abs(a[i][2]) < 1e-6)
                continue;
            AddSize_1();
            right[size - 1] += a[i][2];

            if (a0 && a1)
            {
                element(a0 - 1, size - 1) += 1;
                element(a1 - 1, size - 1) -= 1;
                element(size - 1, a0 - 1) += 1;
                element(size - 1, a1 - 1) -= 1;
            }
            else if (a0)
            {
                element(a0 - 1, size - 1) += 1;
                element(size - 1, a0 - 1) += 1;
            }
            else
            {
                element(a1 - 1, size - 1) -= 1;
                element(size - 1, a1 - 1) -= 1;
            }
        }

        int a2 = static_cast<int> (a[i][2]);
        int a3 = static_cast<int> (a[i][3]);

        if (name[i] == "VCCS")
        {
            AddSize_1();
            if (a0 && a1)
            {
                element(a0 - 1, size - 1) += a[i][4];
                element(a1 - 1, size - 1) -= a[i][4];
                element(size - 1, size - 1) -= 1;
            }
            else if (a0)
            {
                element(a0 - 1, size - 1) += a[i][4];
                element(size - 1, size - 1) -= 1;
            }
            else
            {
                element(a1 - 1, size - 1) -= a[i][4];
                element(size - 1, size - 1) -= 1;
            }

            if (a2 && a3)
            {
                element(size - 1, a2 - 1) += 1;
                element(size - 1, a3 - 1) -= 1;
            }
            else if (a2)
                element(size - 1, a3 - 1) += 1;
            else
                element(size - 1, a3 - 1) -= 1;

        }

        else if (name[i] == "VCVS")
        {
            AddSize_2();
            if (a0 && a1)
            {
                element(a0 - 1, size - 2) += 1;
                element(a1 - 1, size - 2) -= 1;
                element(size - 2, a0 - 1) += 1;
                element(size - 2, a1 - 1) -= 1;
                element(size - 2, size - 1) -= a[i][4];
            }
            else if (a0)
            {
                element(a0 - 1, size - 2) += 1;
                element(size - 2, a0 - 1) += 1;
                element(size - 2, size - 1) -= a[i][4];
            }
            else
            {
                element(a1 - 1, size - 2) -= 1;
                element(size - 2, a1 - 1) -= 1;
                element(size - 2, size - 1) -= a[i][4];
            }

            if (a2 && a3)
            {
                element(size - 1, a2 - 1) += 1;
                element(size - 1, a3 - 1) -= 1;
                element(size - 1, size - 1) -= 1;
            }
            else if (a2)
            {
                element(size - 1, a2 - 1) += 1;
                element(size - 1, size - 1) -= 1;
            }
            else
            {
                element(size - 1, a3 - 1) -= 1;
                element(size - 1, size - 1) -= 1;
            }
        }

        else if (name[i] == "CCVS")
        {
            AddSize_2();

            if (a0 && a1)
            {
                element(a0 - 1, size - 2) += 1;
                element(a1 - 1, size - 2) -= 1;
                element(size - 2, a0 - 1) += 1;
                element(size - 2, a1 - 1) -= 1;
                element(size - 2, size - 1) -= a[i][4];
            }
            else if (a0)
            {
                element(a0 - 1, size - 2) += 1;
                element(size - 2, a0 - 1) += 1;
                element(size - 2, size - 1) -= a[i][4];
            }
            else
            {
                element(a1 - 1, size - 2) -= 1;
                element(size - 2, a1 - 1) -= 1;
                element(size - 2, size - 1) -= a[i][4];
            }

            if (a2 && a3)
            {
                element(size - 1, a2 - 1) += 1;
                element(size - 1, a3 - 1) -= 1;
                element(a2 - 1, size - 1) += 1;
                element(a3 - 1, size - 1) -= 1;
            }
            else if (a2)
            {
                element(size - 1, a2 - 1) += 1;
                element(a2 - 1, size - 1) += 1;
            }
            else
            {
                element(size - 1, a3 - 1) -= 1;
                element(a3 - 1, size - 1) -= 1;
            }

        }

        else if (name[i] == "CCCS")
        {
            AddSize_1();

            if (a0 && a1)
            {
                element(a0 - 1, size - 1) += a[i][4];
                element(a1 - 1, size - 1) -= a[i][4];
            }
            else if (a0)
                element(a0 - 1, size - 1) += a[i][4];
            else
                element(a0 - 1, size - 1) -= a[i][4];

            if (a2 && a3)
            {
                element(size - 1, a2 - 1) += 1;
                element(size - 1, a3 - 1) -= 1;
                element(a2 - 1, size - 1) += 1;
                element(a3 - 1, size - 1) -= 1;
            }
            else if (a2)
            {
                element(size - 1, a2 - 1) += 1;
                element(a2 - 1, size - 1) += 1;
            }
            else
            {
                element(size - 1, a3 - 1) -= 1;
                element(a3 - 1, size - 1) -= 1;
            }
        }
    }
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            cout << element(i,j) << endl;
        }
        cout << endl;
    }
}
