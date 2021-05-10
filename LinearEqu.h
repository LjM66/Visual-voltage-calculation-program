#pragma once
#ifndef _LINEAREQU_H_
#define _LINEAREQU_H_
#include"Matrix.h"
#include"circuit.h"
class LinearEqu :public Matrix
{
public:
	LinearEqu(int size);
	~LinearEqu();
	void setLinearEqu(const double* a, const double* b);//���̸�ֵ���������Է����飩
	void setLinearEqu(const double* b);
	bool solve();//ȫѡ��Ԫ��˹��ȥ����ⷽ��
	void printLinearEqu() const;//��ʾ����
	void printSolution(int len,power&) const;//��ʾ���̵Ľ�
	double* Solution() const;  //���ط��̵Ľ�
private:
	double* sums;//�����Ҷ�����
	double* solution;//���̵Ľ�
};
#endif // _LINEAREQU_H_
#pragma once
