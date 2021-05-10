#pragma once
//CONTENTS OF CIRCUIT
#include"component.h"
#include<iostream>

#ifndef POWER_H
#define POWER_H
class power {
private:
	int maxnode;					    	//����������
	int cntnode;							//��ǰ������
	double* Array;
public:
	power(int);								//���캯������һ������n�����ĺ���
	~power();
	void copy(int, double*);			    //��0�Ž�㿪ʼ����double�����еĵ�ѹֵ����Array��
	double getvalue(int);					//����n���ĵ�ѹ
	int getlen();							//���ؽ�����
	void setlen(int);						//���ؽ�����
	void setvalue(int, double);				//��ֵ
	void clear();							//���
};
#endif // !POWER_H

#ifndef CIRCUIT_H
#define CIRCUIT_H
class circuit {
private:
	int maxSize;							//���֧��Ԫ������
	int listSize;							//��ǰԪ������
	component* Array;
public:
	circuit(int);							//���캯���������·
	~circuit();								//��������
	bool remove(int);						//ɾ��int��Ԫ��
	bool append(const component&);			//���Ԫ��
	bool search(int, component&);			//��ѯint��Ԫ��
	int getlen();							//��ѯԪ������
	void clear();							//��Ԫ������
	void calculate(int,power&);				//�������ѹ
};
#endif // !CIRCUIT_H


