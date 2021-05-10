#include"LinearEqu.h"
#include<iostream>
#include<cmath>
#include<iomanip>
#include"Input.h"

using namespace std;

LinearEqu::LinearEqu(int size) :Matrix(size)
{
	sums = new double[size];
	solution = new double[size];
}

LinearEqu::~LinearEqu()
{
	delete[] sums;
	delete[] solution;
}

void LinearEqu::setLinearEqu(const double* a, const double* b)
{
	setMatrix(a);
	for (int i = 0; i < getSize(); i++)
		sums[i] = b[i];
}
void LinearEqu::setLinearEqu(const double* b)
{
	for (int i = 0; i < getSize(); i++)
		sums[i] = b[i];
}
void LinearEqu::printLinearEqu() const
{
	cout << "The Linear equation is:" << endl;
	for (int i = 0; i < getSize(); i++) {
		for (int j = 0; j < getSize(); j++)
			cout << fixed << setprecision(2) << element(i, j) << " ";
		cout << "     " << sums[i] << endl;
	}
	cout << endl;
}

//输出方程的解
void LinearEqu::printSolution(int len,power&answer)const
{
	cout << "The Result equation is:" << endl;
	for (int i = 0; i < len; i++)
	{
		if (solution[i] < 1e-6 && solution[i] > -1e-6)
			solution[i] = 0;
		cout << fixed << setprecision(2)
			<< "U[" << i + 1 << "]=" << solution[i] << endl;
		answer.setvalue(i+1,solution[i]);
		answer.setlen(len+1);
	}
	answer.setvalue(0, 0);
}

//返回方程的解
double* LinearEqu::Solution()const
{
	return solution;
}

//交换两个实数
inline void swap(double& v1, double& v2)
{
	double temp = v1;
	v1 = v2;
	v2 = temp;
}

bool LinearEqu::solve()          //全选主元素高斯消去法求解方程
{
	int* js = new int[getSize()];//存储主元素所在列号的数组

	//选主元素
	for (int k = 0; k < getSize() - 1; k++)
	{
		int is;//主元素所在行号
		double max = 0;//所有元素的最大值
		for (int i = k; i < getSize(); i++) {
			for (int j = k; j < getSize(); j++) {
				double t = fabs(element(i, j));
				if (t > max) {
					max = t;
					js[k] = j;
					is = i;
				}
			}
		}

		if (max == 0) {
			delete[] js;
			return false;
		}
		else {
			//通过行列交换，把主元素交换到第k行第k列上
			if (js[k] != k)//主元素不在第k列上，交换一列
				for (int i = 0; i < getSize(); i++)
					swap(element(i, k), element(i, js[k]));
			if (is != k) {//主元素不在第k行上，交换一行
				for (int j = k; j < getSize(); j++)
					swap(element(is, j), element(k, j));
				swap(sums[k], sums[is]);
			}
		}

		//消去过程
		double major = element(k, k);
		for (int j = k + 1; j < getSize(); j++)
			element(k, j) /= major;
		sums[k] /= major;
		for (int i = k + 1; i < getSize(); i++) {
			for (int j = k + 1; j < getSize(); j++)
				element(i, j) -= element(i, k) * element(k, j);//行之间的操作
			sums[i] -= element(i, k) * sums[k];
		}
	}

	//判断剩下的一个元素是否等于0（等于0则矩阵的秩不等于矩阵的行数，则无解）
	double d = element(getSize() - 1, getSize() - 1);
	if (fabs(d) < 1e-15) {
		delete[] js;
		return false;
	}

	//求出解之前验证一下最终化简结果
/*	printMatrix();
	cout << "Output right end matrix:" << endl;
	for (int i = 0; i < getSize(); i++)
		cout << sums[i] << " ";
	cout << endl << endl;
*/
//回代过程
	solution[getSize() - 1] = sums[getSize() - 1] / d;
	for (int i = getSize() - 2; i >= 0; i--)
	{
		double t = 0.0;
		for (int j = i + 1; j <= getSize() - 1; j++)
			t += element(i, j) * solution[j];//实际上不是单位矩阵
		solution[i] = sums[i] - t;
	}
	js[getSize() - 1] = getSize() - 1;//最后一行最后一列主元素就是本列
	for (int k = getSize() - 1; k >= 0; k--)
		if (js[k] != k) swap(solution[k], solution[js[k]]);
	delete[] js;
	return true;
}
