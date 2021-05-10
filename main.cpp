#include<iostream>
#include"circuit.h"
#include"component.h"
#include<conio.h>
#include<graphics.h>

using namespace std;

circuit base(500);				//����һ�����洢500��Ԫ����circuit�ṹ
power answer(1000);				//����һ�����洢1000������ѹ��power�ṹ

void graph();					    //ͼ�λ��ƺ���

int main() {
//	double temp[30] = { 0,-1.1,2.2,-3.3,4.4,-5.5,6.6,-7.7,8.8,-9.9,0,-1.1,2.2,-3.3,4.4,-5.5,6.6,-7.7,8.8,-9.9,0,-1.1,2.2,-3.3,4.4,-5.5,6.6,-7.7,8.8,-9.9 };
//	answer.copy(30, temp);
	graph();
	cout << "666";
	system("pause");
	return 0;
}

void graph() {

	//�����ض�����
	const int showinputx1[4] = { 15,15,15,15 };
	const int showinputx2[4] = { 490,490,490,490 };
	const int showinputy1[4] = { 310,370,430,490 };
	const int showinputy2[4] = { 365,425,485,545 };
	const int pageup[4] = { 45,550,125,580 };
	const int page[4] = { 170,550,330,580 };
	const int pagedown[4] = { 375,550,455,580 };
	const int cptext[4] = { 520,15,780,66 };
	const int cpx1[5] = { 540,540,540,540,540 };
	const int cpx2[5] = { 700,700,700,700,700 };
	const int cpy1[5] = { 91,126,161,196,231 };
	const int cpy2[5] = { 121,156,191,226,261 };
	const int bx1[5] = { 720,720,720,720,720 };
	const int bx2[5] = { 740,740,740,740,740 };
	const int by2[5] = { 116,151,186,221,256 };
	const int by1[5] = { 96,131,166,201,236 };
	const int inputtext[4] = { 520,305,780,355 };
	const int inputscreen[4] = { 520,360,780,410 };
	const int inbutton[4] = { 550,550,630,580 };
	const int rebutton[4] = { 670,550,750,580 };
	const int lblock1[4] = { 510,10,790,300 };
	const int lblock2[4] = { 510,300,790,415 };
	const int lblock3[4] = { 510,415,790,540 };
	const int node1[4] = { 595,378,635,398 };
	const int node2[4] = { 710,378,750,398 };
	const int input1[4] = { 720,lblock3[1] + 12,760,lblock3[1] + 32 };
	const int input2[4] = { 720,lblock3[1] + 42,760,lblock3[1] + 62 };
	const int input3[4] = { 720,lblock3[1] + 72,760,lblock3[1] + 92 };
	const int input4[4] = { 720,lblock3[1] + 102,760,lblock3[1] + 122 };
	const int restart[4] = { 405,255,485,285 };
	const int calculate[4] = { 310,255,390,285 };
	const int answerx[10] = {50,50,50,50,50,300,300,300,300,300};
	const int answery[10] = {50,80,110,140,170,50,80,110,140,170};
	const int y = 340;


	wchar_t fn[10] = L"", ln[10] = L"", cf[10] = L"", cl[10] = L"",ki[10]=L"",ra[10]=L"",va[10]=L"",inf[100]=L"",an[100] =L"";
	int nowpage = 1, totpage = (base.getlen() - 1) / 4 + 1,annowpage = 1,antotpage = (answer.getlen() - 1) / 10 + 1;
	int flag = 1, type = 0, lflag = 0, fflag = 0, vflag = 0,fnode, lnode;		//����Ԫ������˳��
	int flag1 = 0, flag2 = 0, flag3 = 0, flag4 = 0 ,calflag = 0;
	int cfnode, clnode, kind;
	double ratio,value;
	TCHAR pagestring[100],answerpagestring[100];
	MOUSEMSG m;

	//��ʼ��ͼ��
	initgraph(800, 600, EW_DBLCLKS);
	setbkcolor(WHITE);
	settextstyle(25, 0, _T("΢���ź�"));
	settextcolor(BLACK);
	setlinecolor(BLACK);
	cleardevice();
	//���廮��Ϊ�������
	rectangle(0, 0, 800, 600);
	rectangle(10, 10, 500, 295);
	rectangle(10, 305, 500, 590);
	rectangle(510, 10, 790, 590);
	//�������
	rectangle(calculate[0], calculate[1], calculate[2], calculate[3]);
	outtextxy(calculate[0] + 20, calculate[1] + 3, L"����");
	rectangle(restart[0], restart[1], restart[2], restart[3]);
	outtextxy(restart[0] + 20, restart[1]+3, L"���");
	//����Ԫ����ʾ����
	for (int i = 0;i < 4; i++)
		rectangle(showinputx1[i], showinputy1[i], showinputx2[i], showinputy2[i]);
	rectangle(pageup[0], pageup[1], pageup[2], pageup[3]);
	rectangle(page[0], page[1], page[2], page[3]);
	rectangle(pagedown[0], pagedown[1], pagedown[2], pagedown[3]);
	outtextxy(pageup[0] + 10, pageup[1] + 3, L"��һҳ");
	outtextxy(pagedown[0] + 10, pagedown[1] + 3, L"��һҳ");
	_stprintf_s(pagestring, _T("��%dҳ/��%dҳ"), nowpage, totpage);
	outtextxy(page[0] + 25, page[1] + 3, pagestring);
	//����Ԫ��ͼ�ϲ���
	rectangle(cptext[0], cptext[1], cptext[2], cptext[3]);
	settextstyle(40, 0, _T("΢���ź�"));
	outtextxy(cptext[0] + 23, cptext[1] + 5, L"Ԫ������ѡ����");
	settextstyle(25, 0, _T("΢���ź�"));
	for (int i = 0; i < 5; i++)
		rectangle(cpx1[i], cpy1[i], cpx2[i], cpy2[i]);
	outtextxy(cpx1[0] + 33, cpy1[0] + 3, L"������ѹԴ");
	outtextxy(cpx1[1] + 33, cpy1[1] + 3, L"��������Դ");
	outtextxy(cpx1[2] + 33, cpy1[2] + 3, L"�ܿص�ѹԴ");
	outtextxy(cpx1[3] + 33, cpy1[3] + 3, L"�ܿص���Դ");
	outtextxy(cpx1[4] + 45, cpy1[4] + 3, L"���Ե���");
	for (int i = 0; i < 5; i++)
		rectangle(bx1[i], by1[i], bx2[i], by2[i]);
	//����Ԫ��ͼ�м䲿��
	line(510, 300, 790, 300);
	rectangle(inputtext[0], inputtext[1], inputtext[2], inputtext[3]);
	settextstyle(40, 0, _T("΢���ź�"));
	outtextxy(inputtext[0] + 23, inputtext[1] + 5, L"Ԫ��λ��ѡ����");
	settextstyle(25, 0, _T("΢���ź�"));
	rectangle(inputscreen[0], inputscreen[1], inputscreen[2], inputscreen[3]);
	outtextxy(inputscreen[0] + 5, inputscreen[1] + 15, L"�׽�㣺");
	rectangle(node1[0], node1[1], node1[2], node1[3]);
	outtextxy(inputscreen[0] + 120, inputscreen[1] + 15, L"ĩ��㣺");
	rectangle(node2[0], node2[1], node2[2], node2[3]);
	//����Ԫ��ͼ�²���
	line(510, 415, 790, 415);
	//����Ԫ��ͼ�ײ�
	line(510, 540, 790, 540);
	rectangle(inbutton[0], inbutton[1], inbutton[2], inbutton[3]);
	rectangle(rebutton[0], rebutton[1], rebutton[2], rebutton[3]);
	outtextxy(inbutton[0] + 23, inbutton[1] + 3, L"����");
	outtextxy(rebutton[0] + 23, rebutton[1] + 3, L"����");


	//�û���������
	while (true) {
		//...............................����Ԫ��չʾ..........................
		//ҳ��
		totpage = (base.getlen() - 1) / 4 + 1;
		_stprintf_s(pagestring, _T("��%dҳ/��%dҳ"), nowpage, totpage);
		outtextxy(page[0] + 25, page[1] + 3, pagestring);
		//Ԫ��
		for (int i = 0; i < 4; i++) {
			component sea;
			base.search((nowpage - 1) * 4 + i + 1, sea);
			if ((nowpage - 1) * 4 + i < base.getlen()) {
				if (sea.type == 0) {
					_stprintf_s(inf, _T("Ԫ�����:%d  Ԫ������:������ѹԴ "), (nowpage - 1) * 4 + i + 1 );
					outtextxy(showinputx1[i] + 5, showinputy1[i] + 5, inf);
					_stprintf_s(inf, _T("��β���:%d->%d    ֵ:%6.3lfV"),  sea.fnode, sea.lnode, -sea.value);
					outtextxy(showinputx1[i] + 5, showinputy1[i] + 30, inf);
				}
				else if (sea.type == 1) {
					_stprintf_s(inf, _T("Ԫ�����:%d  Ԫ������:��������Դ "), (nowpage - 1) * 4 + i + 1);
					outtextxy(showinputx1[i] + 5, showinputy1[i] + 5, inf);
					_stprintf_s(inf, _T("��β���:%d->%d    ֵ:%6.3lfA"), sea.fnode, sea.lnode, sea.value);
					outtextxy(showinputx1[i] + 5, showinputy1[i] + 30, inf);
				}
				else if (sea.type == 2) {
					_stprintf_s(inf, _T("Ԫ�����:%d  Ԫ������:�ܿص�ѹԴ  �ܿ�����:%c"), (nowpage - 1) * 4 + i + 1,21 * sea.kind + 65);
					outtextxy(showinputx1[i] + 5, showinputy1[i] + 5, inf);
					_stprintf_s(inf, _T("��β���:%d->%d  �ܿ���β���:%d->%d  ����ϵ��:%6.3lf"), sea.fnode, sea.lnode,sea.cfnode,sea.clnode,sea.ratio);
					outtextxy(showinputx1[i] + 5, showinputy1[i] + 30, inf);
				}
				else if (sea.type == 3) {
					_stprintf_s(inf, _T("Ԫ�����:%d  Ԫ������:�ܿص���Դ  �ܿ�����:%c"), (nowpage - 1) * 4 + i + 1, 21 * sea.kind + 65);
					outtextxy(showinputx1[i] + 5, showinputy1[i] + 5, inf);
					_stprintf_s(inf, _T("��β���:%d->%d  �ܿ���β���:%d->%d  ����ϵ��:%6.3lf"), sea.fnode, sea.lnode, sea.cfnode, sea.clnode, sea.ratio);
					outtextxy(showinputx1[i] + 5, showinputy1[i] + 30, inf);
				}
				else if (sea.type == 4) {
					_stprintf_s(inf, _T("Ԫ�����:%d  Ԫ������:���� "), (nowpage - 1) * 4 + i + 1 );
					outtextxy(showinputx1[i] + 5, showinputy1[i] + 5, inf);
					_stprintf_s(inf, _T("��β���:%d->%d    ֵ:%6.3lf��"),  sea.fnode, sea.lnode, sea.value);
					outtextxy(showinputx1[i] + 5, showinputy1[i] + 30, inf);
				}	
				fillrectangle(showinputx1[i] + 420, showinputy1[i] + 5, showinputx1[i] + 460, showinputy1[i] + 25);
				settextstyle(18, 0, _T("΢���ź�"));
				outtextxy(showinputx1[i] + 428, showinputy1[i] + 7, L"ɾ��");
				settextstyle(25, 0, _T("΢���ź�"));
			}
		}
		//..............................����ʾ����..............................
		antotpage = (answer.getlen() - 1) / 10 + 1;
		if (calflag == 1) {
			for (int i = 0; i < 10; i++) {
				if (i + 10 * (annowpage - 1) < answer.getlen()) {
					_stprintf_s(an, _T("���%d:%0.4lfV"), i + 10 * (annowpage - 1), answer.getvalue(i + 10 * (annowpage - 1)));
					outtextxy(answerx[i], answery[i], an);
				}
				else {
					clearrectangle(answerx[i], answery[i], answerx[i] + 100, answery[i] + 30);
				}
			}
			rectangle(pageup[0], pageup[1] - y, pageup[2], pageup[3] - y);
			rectangle(page[0], page[1] - y, page[2], page[3] - y);
			rectangle(pagedown[0], pagedown[1] - y, pagedown[2], pagedown[3] - y);
			outtextxy(pageup[0] + 10, pageup[1] + 3 - y, L"��һҳ");
			outtextxy(pagedown[0] + 10, pagedown[1] + 3 - y, L"��һҳ");
			_stprintf_s(answerpagestring, _T("��%dҳ/��%dҳ"), annowpage, antotpage);
			outtextxy(page[0] + 25, page[1] + 3 - y, answerpagestring);
		}
		
		//..............................����������ʾ����...........................
		if (fflag == 1 && lflag == 1) flag = 3;
		if ((flag1 == 1 && flag2 == 1 && flag3 == 1 && flag4 == 1) || vflag == 1)flag = 4;
		//�׽��������ʾ
		if (fflag == 1) {
			outtextxy(node1[0]+15, node1[1],fn);
		}
		else {
			fillrectangle(node1[0], node1[1], node1[2], node1[3]);
		}
		//β���������ʾ
		if (lflag == 1) {
			outtextxy(node2[0] + 15, node2[1], ln);
		}
		else {
			fillrectangle(node2[0], node2[1], node2[2], node2[3]);
		}
		//��ֵ��С������ʾ
		if (flag >= 3 && (type == 0) ){
			outtextxy(lblock3[0]+10, lblock3[1]+10,L"�������ѹԴ��ѹ(V):");
		}
		else if (flag >= 3 && type == 1) {
			outtextxy(lblock3[0] + 10, lblock3[1] + 10, L"���������Դ����(A):");
		}
		else if (flag >= 3 && type == 2) {
			outtextxy(lblock3[0] + 10, lblock3[1] + 10, L"�������ѹԴ�ܿ�ϵ��:");
			rectangle(input1[0], input1[1],input1[2],input1[3]);
			outtextxy(lblock3[0] + 10, lblock3[1] + 40, L"�������ܿ��׽��:");
			rectangle(input2[0], input2[1], input2[2], input2[3]);
			outtextxy(lblock3[0] + 10, lblock3[1] + 70, L"�������ܿ�β���:");
			rectangle(input3[0], input3[1], input3[2], input3[3]);
			outtextxy(lblock3[0] + 10, lblock3[1] + 100, L"�������������:");
			rectangle(input4[0], input4[1], input4[2], input4[3]);
		}
		else if (flag >= 3 && type == 3) {
			outtextxy(lblock3[0] + 10, lblock3[1] + 10, L"���������Դ�ܿ�ϵ��:");
			rectangle(input1[0], input1[1], input1[2], input1[3]);
			outtextxy(lblock3[0] + 10, lblock3[1] + 40, L"�������ܿ��׽��:");
			rectangle(input2[0], input2[1], input2[2], input2[3]);
			outtextxy(lblock3[0] + 10, lblock3[1] + 70, L"�������ܿ�β���:");
			rectangle(input3[0], input3[1], input3[2], input3[3]);
			outtextxy(lblock3[0] + 10, lblock3[1] + 100, L"�������������:");
			rectangle(input4[0], input4[1], input4[2], input4[3]);
		}
		else if (flag >= 3 && type == 4) {
			outtextxy(lblock3[0] + 10, lblock3[1] + 10, L"�����������ֵ(��):");
		}
		else {
			fillrectangle(lblock3[0], lblock3[1], lblock3[2], lblock3[3]);
		}
		//��������������ʾ
		if (flag >= 3 && flag1 == 1 && (type == 2 || type == 3)) {
			fillrectangle(input1[0], input1[1], input1[2], input1[3]);
			outtextxy(input1[0] + 5, input1[1], ra);
		}
		else if(flag >= 3 && (type == 2 || type == 3)){
			fillrectangle(input1[0], input1[1], input1[2], input1[3]);
		}
		if (flag >= 3 && flag2 == 1 && (type == 2 || type == 3)) {
			fillrectangle(input2[0], input2[1], input2[2], input2[3]);
			outtextxy(input2[0] + 15, input2[1], cf);
		}
		else if (flag >= 3 && (type == 2 || type == 3)) {
			fillrectangle(input2[0], input2[1], input2[2], input2[3]);
		}
		if (flag >= 3 && flag3 == 1 && (type == 2 || type == 3)) {
			fillrectangle(input3[0], input3[1], input3[2], input3[3]);
			outtextxy(input3[0] + 15, input3[1], cl);
		}
		else if (flag >= 3 && (type == 2 || type == 3)) {
			fillrectangle(input3[0], input3[1], input3[2], input3[3]);
		}
		if (flag >= 3 && flag4 == 1 && (type == 2 || type == 3)) {
			fillrectangle(input4[0], input4[1], input4[2], input4[3]);
			outtextxy(input4[0] + 15, input4[1], ki);
		}
		else if (flag >= 3 && (type == 2 || type == 3)) {
			fillrectangle(input4[0], input4[1], input4[2], input4[3]);
		}
		if (flag >= 3 && vflag == 1 && type != 2 && type != 3) {
			fillrectangle(input1[0], input1[1], input1[2], input1[3]);
			outtextxy(input1[0] + 5, input1[1], va);
		}
		else if (flag >= 3 && type != 2 && type != 3) {
			fillrectangle(input1[0], input1[1], input1[2], input1[3]);
		}
		

		m = GetMouseMsg();
		//........................�����...................
		if (flag == 1 && m.uMsg == WM_LBUTTONDOWN && m.x >= lblock1[0] 
			&& m.x <= lblock1[2] && m.y >= lblock1[1] && m.y <= lblock1[3]) {
			for (int i = 0; i <= 4; i++) {
				if (m.x >= bx1[i] && m.x <= bx2[i] && m.y >= by1[i] && m.y <= by2[i]) {
					//��ɫ�ı���
					setfillcolor(RGB(200, 200, 200));
					fillrectangle(bx1[i], by1[i], bx2[i], by2[i]);
					setfillcolor(WHITE);
					type = i;			//��¼����
					flag = 2;
				}
			}
		}
		//����
		else if (flag != 1 && m.uMsg == WM_LBUTTONDOWN && m.x >= rebutton[0] && m.x <= rebutton[2] && m.y >= rebutton[1] && m.y <= rebutton[3]) {
			flag = 1; lflag = 0, fflag = 0; flag1 = 0; flag2 = 0; flag3 = 0; flag4 = 0; vflag = 0;
			//..............................ˢ��.................................
			cleardevice();
			//���廮��Ϊ�������
			rectangle(0, 0, 800, 600);
			rectangle(10, 10, 500, 295);
			rectangle(10, 305, 500, 590);
			rectangle(510, 10, 790, 590);
			//�������
			rectangle(calculate[0], calculate[1], calculate[2], calculate[3]);
			outtextxy(calculate[0] + 20, calculate[1] + 3, L"����");
			rectangle(restart[0], restart[1], restart[2], restart[3]);
			outtextxy(restart[0] + 20, restart[1] + 3, L"���");
			//����Ԫ����ʾ����
			for (int i = 0; i < 4; i++)
				rectangle(showinputx1[i], showinputy1[i], showinputx2[i], showinputy2[i]);
			rectangle(pageup[0], pageup[1], pageup[2], pageup[3]);
			rectangle(page[0], page[1], page[2], page[3]);
			rectangle(pagedown[0], pagedown[1], pagedown[2], pagedown[3]);
			outtextxy(pageup[0] + 10, pageup[1] + 3, L"��һҳ");
			outtextxy(pagedown[0] + 10, pagedown[1] + 3, L"��һҳ");
			_stprintf_s(pagestring, _T("��%dҳ/��%dҳ"), nowpage, totpage);
			outtextxy(page[0] + 25, page[1] + 3, pagestring);
			//����Ԫ��ͼ�ϲ���
			rectangle(cptext[0], cptext[1], cptext[2], cptext[3]);
			settextstyle(40, 0, _T("΢���ź�"));
			outtextxy(cptext[0] + 23, cptext[1] + 5, L"Ԫ������ѡ����");
			settextstyle(25, 0, _T("΢���ź�"));
			for (int i = 0; i < 5; i++)
				rectangle(cpx1[i], cpy1[i], cpx2[i], cpy2[i]);
			outtextxy(cpx1[0] + 33, cpy1[0] + 3, L"������ѹԴ");
			outtextxy(cpx1[1] + 33, cpy1[1] + 3, L"��������Դ");
			outtextxy(cpx1[2] + 33, cpy1[2] + 3, L"�ܿص�ѹԴ");
			outtextxy(cpx1[3] + 33, cpy1[3] + 3, L"�ܿص���Դ");
			outtextxy(cpx1[4] + 45, cpy1[4] + 3, L"���Ե���");
			for (int i = 0; i < 5; i++)
				rectangle(bx1[i], by1[i], bx2[i], by2[i]);
			//����Ԫ��ͼ�м䲿��
			line(510, 300, 790, 300);
			rectangle(inputtext[0], inputtext[1], inputtext[2], inputtext[3]);
			settextstyle(40, 0, _T("΢���ź�"));
			outtextxy(inputtext[0] + 23, inputtext[1] + 5, L"Ԫ��λ��ѡ����");
			settextstyle(25, 0, _T("΢���ź�"));
			rectangle(inputscreen[0], inputscreen[1], inputscreen[2], inputscreen[3]);
			outtextxy(inputscreen[0] + 5, inputscreen[1] + 15, L"�׽�㣺");
			rectangle(node1[0], node1[1], node1[2], node1[3]);
			outtextxy(inputscreen[0] + 120, inputscreen[1] + 15, L"ĩ��㣺");
			rectangle(node2[0], node2[1], node2[2], node2[3]);
			//����Ԫ��ͼ�²���
			line(510, 415, 790, 415);
			//����Ԫ��ͼ�ײ�
			line(510, 540, 790, 540);
			rectangle(inbutton[0], inbutton[1], inbutton[2], inbutton[3]);
			rectangle(rebutton[0], rebutton[1], rebutton[2], rebutton[3]);
			outtextxy(inbutton[0] + 23, inbutton[1] + 3, L"����");
			outtextxy(rebutton[0] + 23, rebutton[1] + 3, L"����");
		}
		//�������
		else if (flag == 2 && m.uMsg == WM_LBUTTONDOWN && m.x >= lblock2[0]
			&& m.x <= lblock2[2] && m.y >= lblock2[1] && m.y <= lblock2[3]) {
			//��������
			if (fflag == 0 && m.x >= node1[0] && m.x <= node1[2] && m.y >= node1[1] && m.y <= node1[3]) {
				InputBox(fn, 10, L"�������׽��(��һ�����Ϊ0��):",L"�������", NULL,200,0, true);
				fnode = _wtoi(fn);
				while (fnode < 0) {
					InputBox(fn, 10, L"���벻��ȷ�������������׽��(��һ�����Ϊ0��):", L"�������", NULL, 200, 0, true);
					fnode = _wtoi(fn);
				}
				fflag = 1;
			}
			else if (lflag == 0 && m.x >= node2[0] && m.x <= node2[2] && m.y >= node2[1] && m.y <= node2[3]) {
				InputBox(ln, 10, L"������β���(��һ�����Ϊ0��):", L"�������", NULL, 200, 0, true);
				lnode = _wtoi(ln);
				while (lnode < 0) {
					InputBox(ln, 10, L"���벻��ȷ������������β���(��һ�����Ϊ0��):", L"�������", NULL, 200, 0, true);
					lnode = _wtoi(ln);
				}
				lflag = 1;
			}
		}
		//��������
		else if ((flag == 3 && m.uMsg == WM_LBUTTONDOWN && m.x >= lblock3[0]
			&& m.x <= lblock3[2] && m.y >= lblock3[1] && m.y <= lblock3[3]) && (type == 2 ||type ==3)) {
			if (flag1 == 0 && m.x >= input1[0] && m.x <= input1[2] && m.y >= input1[1] && m.y <= input1[3]) {
				InputBox(ra, 10, L"��������Ʊ���ϵ��:", L"ϵ������", NULL, 200, 0, true);
				ratio = _tstof(ra);
				flag1 = 1;
			}
			else if (flag2 == 0 && m.x >= input2[0] && m.x <= input2[2] && m.y >= input2[1] && m.y <= input2[3]) {
				InputBox(cf, 10, L"����������׽��:", L"���ƽ������", NULL, 200, 0, true);
				cfnode = _wtoi(cf);
				flag2 = 1;
			}
			else if (flag3 == 0 && m.x >= input3[0] && m.x <= input3[2] && m.y >= input3[1] && m.y <= input3[3]) {
				InputBox(cl, 10, L"���������β���:", L"���ƽ������", NULL, 200, 0, true);
				clnode = _wtoi(cl);
				flag3 = 1;
			}
			else if (flag4 == 0 && m.x >= input4[0] && m.x <= input4[2] && m.y >= input4[1] && m.y <= input4[3]) {
				InputBox(ki, 10, L"�������������(0-���� 1-��ѹ):", L"������������(��������0��1)", NULL, 200, 0, true);
				kind = _wtoi(ki);
				flag4 = 1;
			}
		}
		else if ((flag == 3 && vflag == 0 && m.uMsg == WM_LBUTTONDOWN && m.x >= lblock3[0]
			&& m.x <= lblock3[2] && m.y >= lblock3[1] && m.y <= lblock3[3]) && (type == 4 || type == 0 || type == 1)) {
				InputBox(va, 10, L"��������ֵ:", L"��ֵ����", NULL, 200, 0, true);
				value = _tstof(va);
				if (type == 0)value = -value;
				vflag = 1;
		}
		//�������
		else if (flag == 4 && m.uMsg == WM_LBUTTONDOWN && m.x >= inbutton[0] && m.x <= inbutton[2] && m.y >= inbutton[1] && m.y <= inbutton[3]) {
			//д��
			if (type == 0 || type == 1 || type == 4) {
				component comp(type, fnode, lnode, value);
				base.append(comp);
			}
			else if (type == 2 || type == 3) {
				component comp(type, fnode, lnode, cfnode,clnode,ratio,kind);
				base.append(comp);
			}
			//����
			flag = 1; lflag = 0, fflag = 0; flag1 = 0; flag2 = 0; flag3 = 0; flag4 = 0; vflag = 0;
			//..............................ˢ��.................................
			cleardevice();
			//���廮��Ϊ�������
			rectangle(0, 0, 800, 600);
			rectangle(10, 10, 500, 295);
			rectangle(10, 305, 500, 590);
			rectangle(510, 10, 790, 590);
			//�������
			rectangle(calculate[0], calculate[1], calculate[2], calculate[3]);
			outtextxy(calculate[0] + 20, calculate[1] + 3, L"����");
			rectangle(restart[0], restart[1], restart[2], restart[3]);
			outtextxy(restart[0] + 20, restart[1] + 3, L"���");
			//����Ԫ����ʾ����
			for (int i = 0; i < 4; i++)
				rectangle(showinputx1[i], showinputy1[i], showinputx2[i], showinputy2[i]);
			rectangle(pageup[0], pageup[1], pageup[2], pageup[3]);
			rectangle(page[0], page[1], page[2], page[3]);
			rectangle(pagedown[0], pagedown[1], pagedown[2], pagedown[3]);
			outtextxy(pageup[0] + 10, pageup[1] + 3, L"��һҳ");
			outtextxy(pagedown[0] + 10, pagedown[1] + 3, L"��һҳ");
			_stprintf_s(pagestring, _T("��%dҳ/��%dҳ"), nowpage, totpage);
			outtextxy(page[0] + 25, page[1] + 3, pagestring);
			//����Ԫ��ͼ�ϲ���
			rectangle(cptext[0], cptext[1], cptext[2], cptext[3]);
			settextstyle(40, 0, _T("΢���ź�"));
			outtextxy(cptext[0] + 23, cptext[1] + 5, L"Ԫ������ѡ����");
			settextstyle(25, 0, _T("΢���ź�"));
			for (int i = 0; i < 5; i++)
				rectangle(cpx1[i], cpy1[i], cpx2[i], cpy2[i]);
			outtextxy(cpx1[0] + 33, cpy1[0] + 3, L"������ѹԴ");
			outtextxy(cpx1[1] + 33, cpy1[1] + 3, L"��������Դ");
			outtextxy(cpx1[2] + 33, cpy1[2] + 3, L"�ܿص�ѹԴ");
			outtextxy(cpx1[3] + 33, cpy1[3] + 3, L"�ܿص���Դ");
			outtextxy(cpx1[4] + 45, cpy1[4] + 3, L"���Ե���");
			for (int i = 0; i < 5; i++)
				rectangle(bx1[i], by1[i], bx2[i], by2[i]);
			//����Ԫ��ͼ�м䲿��
			line(510, 300, 790, 300);
			rectangle(inputtext[0], inputtext[1], inputtext[2], inputtext[3]);
			settextstyle(40, 0, _T("΢���ź�"));
			outtextxy(inputtext[0] + 23, inputtext[1] + 5, L"Ԫ��λ��ѡ����");
			settextstyle(25, 0, _T("΢���ź�"));
			rectangle(inputscreen[0], inputscreen[1], inputscreen[2], inputscreen[3]);
			outtextxy(inputscreen[0] + 5, inputscreen[1] + 15, L"�׽�㣺");
			rectangle(node1[0], node1[1], node1[2], node1[3]);
			outtextxy(inputscreen[0] + 120, inputscreen[1] + 15, L"ĩ��㣺");
			rectangle(node2[0], node2[1], node2[2], node2[3]);
			//����Ԫ��ͼ�²���
			line(510, 415, 790, 415);
			//����Ԫ��ͼ�ײ�
			line(510, 540, 790, 540);
			rectangle(inbutton[0], inbutton[1], inbutton[2], inbutton[3]);
			rectangle(rebutton[0], rebutton[1], rebutton[2], rebutton[3]);
			outtextxy(inbutton[0] + 23, inbutton[1] + 3, L"����");
			outtextxy(rebutton[0] + 23, rebutton[1] + 3, L"����");
		}
		if (m.x >= 10 && m.x <= 500 && m.y >= 305 && m.y <= 590 &&(m.uMsg == WM_LBUTTONDOWN || m.uMsg == WM_MOUSEWHEEL)) {
			//���·�ҳ
			if ((m.uMsg == WM_LBUTTONDOWN && m.x >= pageup[0]
				&& m.x <= pageup[2] && m.y >= pageup[1] && m.y <= pageup[3])||m.wheel > 0) {
				if (nowpage > 1) {
					nowpage--;
				}
			}
			else if ((m.uMsg == WM_LBUTTONDOWN && m.x >= pagedown[0]
				&& m.x <= pagedown[2] && m.y >= pagedown[1] && m.y <= pagedown[3])||m.wheel<0) {
				if (nowpage < totpage) {
					nowpage++;
				}
			}
			else {
				//ɾ������
				for (int i = 0; i <= 4; i++) {
					if (m.uMsg == WM_LBUTTONDOWN && (nowpage - 1) * 4 + i + 1 <= base.getlen() && m.x >= showinputx1[i] + 420 && m.x <= showinputx1[i] + 460 && m.y >= showinputy1[i] + 5 && m.y <= showinputy1[i] + 25) {
						base.remove((nowpage - 1) * 4 + i + 1);
					}
				}
			}
			//..............................ˢ��.................................
			cleardevice();
			//���廮��Ϊ�������
			rectangle(0, 0, 800, 600);
			rectangle(10, 10, 500, 295);
			rectangle(10, 305, 500, 590);
			rectangle(510, 10, 790, 590);
			//�������
			rectangle(calculate[0], calculate[1], calculate[2], calculate[3]);
			outtextxy(calculate[0] + 20, calculate[1] + 3, L"����");
			rectangle(restart[0], restart[1], restart[2], restart[3]);
			outtextxy(restart[0] + 20, restart[1] + 3, L"���");
			//����Ԫ����ʾ����
			for (int i = 0; i < 4; i++)
				rectangle(showinputx1[i], showinputy1[i], showinputx2[i], showinputy2[i]);
			rectangle(pageup[0], pageup[1], pageup[2], pageup[3]);
			rectangle(page[0], page[1], page[2], page[3]);
			rectangle(pagedown[0], pagedown[1], pagedown[2], pagedown[3]);
			outtextxy(pageup[0] + 10, pageup[1] + 3, L"��һҳ");
			outtextxy(pagedown[0] + 10, pagedown[1] + 3, L"��һҳ");
			_stprintf_s(pagestring, _T("��%dҳ/��%dҳ"), nowpage, totpage);
			outtextxy(page[0] + 25, page[1] + 3, pagestring);
			//����Ԫ��ͼ�ϲ���
			rectangle(cptext[0], cptext[1], cptext[2], cptext[3]);
			settextstyle(40, 0, _T("΢���ź�"));
			outtextxy(cptext[0] + 23, cptext[1] + 5, L"Ԫ������ѡ����");
			settextstyle(25, 0, _T("΢���ź�"));
			for (int i = 0; i < 5; i++)
				rectangle(cpx1[i], cpy1[i], cpx2[i], cpy2[i]);
			outtextxy(cpx1[0] + 33, cpy1[0] + 3, L"������ѹԴ");
			outtextxy(cpx1[1] + 33, cpy1[1] + 3, L"��������Դ");
			outtextxy(cpx1[2] + 33, cpy1[2] + 3, L"�ܿص�ѹԴ");
			outtextxy(cpx1[3] + 33, cpy1[3] + 3, L"�ܿص���Դ");
			outtextxy(cpx1[4] + 45, cpy1[4] + 3, L"���Ե���");
			for (int i = 0; i < 5; i++)
				rectangle(bx1[i], by1[i], bx2[i], by2[i]);
			//����Ԫ��ͼ�м䲿��
			line(510, 300, 790, 300);
			rectangle(inputtext[0], inputtext[1], inputtext[2], inputtext[3]);
			settextstyle(40, 0, _T("΢���ź�"));
			outtextxy(inputtext[0] + 23, inputtext[1] + 5, L"Ԫ��λ��ѡ����");
			settextstyle(25, 0, _T("΢���ź�"));
			rectangle(inputscreen[0], inputscreen[1], inputscreen[2], inputscreen[3]);
			outtextxy(inputscreen[0] + 5, inputscreen[1] + 15, L"�׽�㣺");
			rectangle(node1[0], node1[1], node1[2], node1[3]);
			outtextxy(inputscreen[0] + 120, inputscreen[1] + 15, L"ĩ��㣺");
			rectangle(node2[0], node2[1], node2[2], node2[3]);
			//����Ԫ��ͼ�²���
			line(510, 415, 790, 415);
			//����Ԫ��ͼ�ײ�
			line(510, 540, 790, 540);
			rectangle(inbutton[0], inbutton[1], inbutton[2], inbutton[3]);
			rectangle(rebutton[0], rebutton[1], rebutton[2], rebutton[3]);
			outtextxy(inbutton[0] + 23, inbutton[1] + 3, L"����");
			outtextxy(rebutton[0] + 23, rebutton[1] + 3, L"����");
		}
		else if ((m.uMsg == WM_LBUTTONDOWN || m.uMsg == WM_MOUSEWHEEL) && m.x >= 10 && m.x <= 500 && m.y >= 10 && m.y <= 295) {
			if (m.x >= restart[0] && m.x <= restart[2] && m.y >= restart[1] && m.y <= restart[3]) {//���
				base.clear();
				answer.clear();
				nowpage = 1;
				annowpage = 1;
				calflag = 0;
				flag = 1; lflag = 0, fflag = 0; flag1 = 0; flag2 = 0; flag3 = 0; flag4 = 0; vflag = 0;
			}
			else if (m.x >= calculate[0] && m.x <= calculate[2] && m.y >= calculate[1] && m.y <= calculate[3]) {//����
				if (base.getlen() > 0) {
					base.calculate(base.getlen(), answer);
					/*�������ĺ���*/
					calflag = 1;
				}	
			}
			else if ((m.x >= pageup[0] && m.x <= pageup[2] && m.y >= pageup[1] - y && m.y <= pageup[3] - y)||m.wheel > 0) {
				if (annowpage > 1) {//��һҳ
					annowpage--;
				}
			}
			else if ((m.x >= pagedown[0] && m.x <= pagedown[2] && m.y >= pagedown[1] - y && m.y <= pagedown[3] - y)||m.wheel < 0) {
				if (annowpage < antotpage) {//��һҳ
					annowpage++;
				}
			}
			//..............................ˢ��.................................
			cleardevice();
			//���廮��Ϊ�������
			rectangle(0, 0, 800, 600);
			rectangle(10, 10, 500, 295);
			rectangle(10, 305, 500, 590);
			rectangle(510, 10, 790, 590);
			//�������
			rectangle(calculate[0], calculate[1], calculate[2], calculate[3]);
			outtextxy(calculate[0] + 20, calculate[1] + 3, L"����");
			rectangle(restart[0], restart[1], restart[2], restart[3]);
			outtextxy(restart[0] + 20, restart[1] + 3, L"���");
			//����Ԫ����ʾ����
			for (int i = 0; i < 4; i++)
				rectangle(showinputx1[i], showinputy1[i], showinputx2[i], showinputy2[i]);
			rectangle(pageup[0], pageup[1], pageup[2], pageup[3]);
			rectangle(page[0], page[1], page[2], page[3]);
			rectangle(pagedown[0], pagedown[1], pagedown[2], pagedown[3]);
			outtextxy(pageup[0] + 10, pageup[1] + 3, L"��һҳ");
			outtextxy(pagedown[0] + 10, pagedown[1] + 3, L"��һҳ");
			_stprintf_s(pagestring, _T("��%dҳ/��%dҳ"), nowpage, totpage);
			outtextxy(page[0] + 25, page[1] + 3, pagestring);
			//����Ԫ��ͼ�ϲ���
			rectangle(cptext[0], cptext[1], cptext[2], cptext[3]);
			settextstyle(40, 0, _T("΢���ź�"));
			outtextxy(cptext[0] + 23, cptext[1] + 5, L"Ԫ������ѡ����");
			settextstyle(25, 0, _T("΢���ź�"));
			for (int i = 0; i < 5; i++)
				rectangle(cpx1[i], cpy1[i], cpx2[i], cpy2[i]);
			outtextxy(cpx1[0] + 33, cpy1[0] + 3, L"������ѹԴ");
			outtextxy(cpx1[1] + 33, cpy1[1] + 3, L"��������Դ");
			outtextxy(cpx1[2] + 33, cpy1[2] + 3, L"�ܿص�ѹԴ");
			outtextxy(cpx1[3] + 33, cpy1[3] + 3, L"�ܿص���Դ");
			outtextxy(cpx1[4] + 45, cpy1[4] + 3, L"���Ե���");
			for (int i = 0; i < 5; i++)
				rectangle(bx1[i], by1[i], bx2[i], by2[i]);
			//����Ԫ��ͼ�м䲿��
			line(510, 300, 790, 300);
			rectangle(inputtext[0], inputtext[1], inputtext[2], inputtext[3]);
			settextstyle(40, 0, _T("΢���ź�"));
			outtextxy(inputtext[0] + 23, inputtext[1] + 5, L"Ԫ��λ��ѡ����");
			settextstyle(25, 0, _T("΢���ź�"));
			rectangle(inputscreen[0], inputscreen[1], inputscreen[2], inputscreen[3]);
			outtextxy(inputscreen[0] + 5, inputscreen[1] + 15, L"�׽�㣺");
			rectangle(node1[0], node1[1], node1[2], node1[3]);
			outtextxy(inputscreen[0] + 120, inputscreen[1] + 15, L"ĩ��㣺");
			rectangle(node2[0], node2[1], node2[2], node2[3]);
			//����Ԫ��ͼ�²���
			line(510, 415, 790, 415);
			//����Ԫ��ͼ�ײ�
			line(510, 540, 790, 540);
			rectangle(inbutton[0], inbutton[1], inbutton[2], inbutton[3]);
			rectangle(rebutton[0], rebutton[1], rebutton[2], rebutton[3]);
			outtextxy(inbutton[0] + 23, inbutton[1] + 3, L"����");
			outtextxy(rebutton[0] + 23, rebutton[1] + 3, L"����");
		}
		else if (m.uMsg == WM_RBUTTONDBLCLK) {
				break;
		}
	}
	// �ر�ͼ�δ���
	closegraph();
}