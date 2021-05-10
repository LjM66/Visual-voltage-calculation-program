#pragma once
//CONTENTS OF CIRCUIT
#include"component.h"
#include<iostream>

#ifndef POWER_H
#define POWER_H
class power {
private:
	int maxnode;					    	//结点个数上限
	int cntnode;							//当前结点个数
	double* Array;
public:
	power(int);								//构造函数创建一个存有n个结点的函数
	~power();
	void copy(int, double*);			    //从0号结点开始，将double数组中的电压值传到Array中
	double getvalue(int);					//返回n结点的电压
	int getlen();							//返回结点个数
	void setlen(int);						//返回结点个数
	void setvalue(int, double);				//赋值
	void clear();							//清空
};
#endif // !POWER_H

#ifndef CIRCUIT_H
#define CIRCUIT_H
class circuit {
private:
	int maxSize;							//最多支持元件个数
	int listSize;							//当前元件个数
	component* Array;
public:
	circuit(int);							//构造函数：构造电路
	~circuit();								//析构函数
	bool remove(int);						//删除int号元件
	bool append(const component&);			//添加元件
	bool search(int, component&);			//查询int号元件
	int getlen();							//查询元件个数
	void clear();							//将元件归零
	void calculate(int,power&);				//计算结点电压
};
#endif // !CIRCUIT_H


