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
	void setLinearEqu(const double* a, const double* b);//方程赋值（设置线性方程组）
	void setLinearEqu(const double* b);
	bool solve();//全选主元高斯消去法求解方程
	void printLinearEqu() const;//显示方程
	void printSolution(int len,power&) const;//显示方程的解
	double* Solution() const;  //返回方程的解
private:
	double* sums;//方程右端向量
	double* solution;//方程的解
};
#endif // _LINEAREQU_H_
#pragma once
