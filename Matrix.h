#pragma once
#ifndef _MATRIX_H_
#define _MATRIX_H_

class Matrix {
public:
	double* elements;//矩阵存放数组首地址
	Matrix(int size = 2);
	virtual ~Matrix();
	void setMatrix(const double* values);//矩阵赋初值
	void InitMatrix(int length);
	void printMatrix() const;//显示矩阵
	int getSize() const { return size; }//得到矩阵大小
	double& element(int i, int j) { return elements[i * size + j]; }
	double element(int i, int j) const { return elements[i * size + j]; }//取矩阵的第i行第j列的元素
private:
	int size;
};
#endif // _MATRIX_H_
