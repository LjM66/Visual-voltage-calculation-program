#pragma once
//CONTENTS OF COMPONENT
#ifndef COMPONENT_H
#define COMPONENT_H
class component{
public:
	int type = 0;		//Ԫ������
	int fnode = 0;		//�׽��
	int lnode = 0;		//β���
	double value = 0;	//��ֵ
	int cfnode = 0;		//�ܿ��׽��
	int clnode = 0;		//�ܿ�β���
	double ratio = 0;	//���Ʊ�������
	int kind = 0;		//�ܿ�����
	component(const int type, const int& fnode, const int& lnode,const double &value) //����Դ����ѹԴ�����蹹�캯��
	{
		this->type = type;
		this->fnode = fnode;
		this->lnode = lnode;
		this->value = value;
	}
	component(const int& type, const int& fnode, const int& lnode,
		const int& cfnode, const int& clnode, const double& ratio, const int& kind)	//�ܿص���Դ����ѹԴ�Ĺ��캯��
	{
		this->type = type;
		this->fnode = fnode;
		this->lnode = lnode;
		this->cfnode = cfnode;
		this->clnode = clnode;
		this->ratio = ratio;
		this->kind = kind;
	}
	component(component&) {			//���忽�����캯��
		this->type = type;
		this->fnode = fnode;
		this->lnode = lnode;
		this->value = value;
		this->cfnode = cfnode;
		this->clnode = clnode;
		this->ratio = ratio;
		this->kind = kind;
	}
	component(){ };//Ĭ�Ϲ��캯��
};
#endif // !COMPONENT_H