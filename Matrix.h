#pragma once
#ifndef _MATRIX_H_
#define _MATRIX_H_

class Matrix {
public:
	double* elements;//�����������׵�ַ
	Matrix(int size = 2);
	virtual ~Matrix();
	void setMatrix(const double* values);//���󸳳�ֵ
	void InitMatrix(int length);
	void printMatrix() const;//��ʾ����
	int getSize() const { return size; }//�õ������С
	double& element(int i, int j) { return elements[i * size + j]; }
	double element(int i, int j) const { return elements[i * size + j]; }//ȡ����ĵ�i�е�j�е�Ԫ��
private:
	int size;
};
#endif // _MATRIX_H_
