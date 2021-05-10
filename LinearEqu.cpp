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

//������̵Ľ�
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

//���ط��̵Ľ�
double* LinearEqu::Solution()const
{
	return solution;
}

//��������ʵ��
inline void swap(double& v1, double& v2)
{
	double temp = v1;
	v1 = v2;
	v2 = temp;
}

bool LinearEqu::solve()          //ȫѡ��Ԫ�ظ�˹��ȥ����ⷽ��
{
	int* js = new int[getSize()];//�洢��Ԫ�������кŵ�����

	//ѡ��Ԫ��
	for (int k = 0; k < getSize() - 1; k++)
	{
		int is;//��Ԫ�������к�
		double max = 0;//����Ԫ�ص����ֵ
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
			//ͨ�����н���������Ԫ�ؽ�������k�е�k����
			if (js[k] != k)//��Ԫ�ز��ڵ�k���ϣ�����һ��
				for (int i = 0; i < getSize(); i++)
					swap(element(i, k), element(i, js[k]));
			if (is != k) {//��Ԫ�ز��ڵ�k���ϣ�����һ��
				for (int j = k; j < getSize(); j++)
					swap(element(is, j), element(k, j));
				swap(sums[k], sums[is]);
			}
		}

		//��ȥ����
		double major = element(k, k);
		for (int j = k + 1; j < getSize(); j++)
			element(k, j) /= major;
		sums[k] /= major;
		for (int i = k + 1; i < getSize(); i++) {
			for (int j = k + 1; j < getSize(); j++)
				element(i, j) -= element(i, k) * element(k, j);//��֮��Ĳ���
			sums[i] -= element(i, k) * sums[k];
		}
	}

	//�ж�ʣ�µ�һ��Ԫ���Ƿ����0������0�������Ȳ����ھ�������������޽⣩
	double d = element(getSize() - 1, getSize() - 1);
	if (fabs(d) < 1e-15) {
		delete[] js;
		return false;
	}

	//�����֮ǰ��֤һ�����ջ�����
/*	printMatrix();
	cout << "Output right end matrix:" << endl;
	for (int i = 0; i < getSize(); i++)
		cout << sums[i] << " ";
	cout << endl << endl;
*/
//�ش�����
	solution[getSize() - 1] = sums[getSize() - 1] / d;
	for (int i = getSize() - 2; i >= 0; i--)
	{
		double t = 0.0;
		for (int j = i + 1; j <= getSize() - 1; j++)
			t += element(i, j) * solution[j];//ʵ���ϲ��ǵ�λ����
		solution[i] = sums[i] - t;
	}
	js[getSize() - 1] = getSize() - 1;//���һ�����һ����Ԫ�ؾ��Ǳ���
	for (int k = getSize() - 1; k >= 0; k--)
		if (js[k] != k) swap(solution[k], solution[js[k]]);
	delete[] js;
	return true;
}
