#include"circuit.h"
#include<iostream>
#include"component.h"
#include"Input.h"
#include"LinearEqu.h"

using namespace std;

circuit::circuit(int max)
{
	maxSize = max;
	listSize = 0;
	Array = new component[max];
	cout << "调用构造函数" << endl;
}

circuit::~circuit() {
	delete[] Array;
	cout << "调用析构函数" << endl;
}

bool circuit::remove(int n) {
	if (n > listSize || n < 1)return false;
	if (listSize >= 0) {
		for (int i = n; i < listSize; i++)
			Array[i] = Array[i + 1];
		listSize--;
		return true;
	}
	return false;
}

bool circuit::append(const component& m) {
	if (listSize < maxSize) {
		listSize++;
		Array[listSize] = m;
		return true;
	}
	return false;
}

bool circuit::search(int n, component& m) {
	if (n > 0 && n <= maxSize) {
		m = Array[n];
		return true;
	}
	return false;
}

int circuit::getlen() {
	return listSize;
}

void circuit::clear() {
	this->listSize = 0;
}

void circuit::calculate(int num,power&answer) {
	int size = 0;
	string name[100];
	double a[100][6] = { 0 };
	int port[2] = { 0 };          //save the equivalent node
	int sign = 0;             //mark the position of the equivalent node in the array
	double EqVoltage = 0.0;     //record the equivalent voltage
	double EqResistance = 0.0;
	for (int i = 0; i < num; i++) {
		switch (Array[i + 1].type)
		{
		case 0: name[i] = "DV"; a[i][0] = Array[i + 1].fnode; a[i][1] = Array[i + 1].lnode; a[i][2] = Array[i + 1].value; break;
		case 1: name[i] = "DC"; a[i][0] = Array[i + 1].fnode; a[i][1] = Array[i + 1].lnode; a[i][2] = Array[i + 1].value; break;
		case 2: if (Array[i + 1].kind == 0) {
			name[i] = "CCVS"; a[i][0] = Array[i + 1].fnode; a[i][1] = Array[i + 1].lnode;
			a[i][2] = Array[i + 1].cfnode; a[i][3] = Array[i + 1].clnode; a[i][4] = Array[i + 1].ratio;
		}
			  else if (Array[i + 1].kind == 1) {
			name[i] = "VCVS"; a[i][0] = Array[i + 1].fnode; a[i][1] = Array[i + 1].lnode;
			a[i][2] = Array[i + 1].cfnode; a[i][3] = Array[i + 1].clnode; a[i][4] = Array[i + 1].ratio;
		}break;
		case 3:if (Array[i + 1].kind == 0) {
			name[i] = "CCCS"; a[i][0] = Array[i + 1].fnode; a[i][1] = Array[i + 1].lnode;
			a[i][2] = Array[i + 1].cfnode; a[i][3] = Array[i + 1].clnode; a[i][4] = Array[i + 1].ratio;
		}
			  else if (Array[i + 1].kind == 1) {
			name[i] = "VCCS"; a[i][0] = Array[i + 1].fnode; a[i][1] = Array[i + 1].lnode;
			a[i][2] = Array[i + 1].clnode; a[i][3] = Array[i + 1].cfnode; a[i][4] = Array[i + 1].ratio;
		}break;
		case 4:name[i] = "R"; a[i][0] = Array[i + 1].fnode; a[i][1] = Array[i + 1].lnode; a[i][2] = Array[i + 1].value; break;		  
		}	
	}
	name[num] = "END";
	size = a[0][0];
	//输入结束
	for (int i = 0; name[i] != "END"; i++)
	{
		if (size < a[i][0])
			size = a[i][0];
		if (size < a[i][1])
			size = a[i][1];
	}
	cout << num << endl;
	for (int i = 0; i < num; i++)
		cout << name[i] << endl;
	Input eq(size, name, a);
	eq.SetUp();
	LinearEqu equ(eq.size);
	equ.setLinearEqu(eq.elements, eq.right);
	equ.printLinearEqu();
	if (equ.solve())
	{
		cout << endl;
		equ.printSolution(size,answer);
	}
	else
		cout << "Fail" << endl;
	cout << endl;
}

power::power(int n)
{
	Array = new double[n];
	maxnode = n;
	cntnode = 0;
}

power::~power() {
	delete[] Array;
}

void power::copy(int n, double* p) {
	for (int i = 0; i < min(n, maxnode); i++) {
		Array[i] = *(p + i);
	}
	cntnode = n;
}

double power::getvalue(int n) {
	return Array[n];
}

int power::getlen() {
	return cntnode;
}

void power::clear() {
	cntnode = 0;
}

void power::setlen(int n) {
	cntnode = n;
}

void power::setvalue(int i, double va) {
	Array[i] = va;
}