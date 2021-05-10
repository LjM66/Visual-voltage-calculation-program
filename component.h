#pragma once
//CONTENTS OF COMPONENT
#ifndef COMPONENT_H
#define COMPONENT_H
class component{
public:
	int type = 0;		//元件类型
	int fnode = 0;		//首结点
	int lnode = 0;		//尾结点
	double value = 0;	//数值
	int cfnode = 0;		//受控首结点
	int clnode = 0;		//受控尾结点
	double ratio = 0;	//控制比例因子
	int kind = 0;		//受控类型
	component(const int type, const int& fnode, const int& lnode,const double &value) //电流源、电压源、电阻构造函数
	{
		this->type = type;
		this->fnode = fnode;
		this->lnode = lnode;
		this->value = value;
	}
	component(const int& type, const int& fnode, const int& lnode,
		const int& cfnode, const int& clnode, const double& ratio, const int& kind)	//受控电流源、电压源的构造函数
	{
		this->type = type;
		this->fnode = fnode;
		this->lnode = lnode;
		this->cfnode = cfnode;
		this->clnode = clnode;
		this->ratio = ratio;
		this->kind = kind;
	}
	component(component&) {			//定义拷贝构造函数
		this->type = type;
		this->fnode = fnode;
		this->lnode = lnode;
		this->value = value;
		this->cfnode = cfnode;
		this->clnode = clnode;
		this->ratio = ratio;
		this->kind = kind;
	}
	component(){ };//默认构造函数
};
#endif // !COMPONENT_H