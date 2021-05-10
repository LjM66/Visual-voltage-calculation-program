#include<iostream>
#include"circuit.h"
#include"component.h"
#include<conio.h>
#include<graphics.h>

using namespace std;

circuit base(500);				//创建一个最多存储500个元件的circuit结构
power answer(1000);				//创建一个最多存储1000个结点电压的power结构

void graph();					    //图形绘制函数

int main() {
//	double temp[30] = { 0,-1.1,2.2,-3.3,4.4,-5.5,6.6,-7.7,8.8,-9.9,0,-1.1,2.2,-3.3,4.4,-5.5,6.6,-7.7,8.8,-9.9,0,-1.1,2.2,-3.3,4.4,-5.5,6.6,-7.7,8.8,-9.9 };
//	answer.copy(30, temp);
	graph();
	cout << "666";
	system("pause");
	return 0;
}

void graph() {

	//设置特定坐标
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
	int flag = 1, type = 0, lflag = 0, fflag = 0, vflag = 0,fnode, lnode;		//绘制元件操作顺序
	int flag1 = 0, flag2 = 0, flag3 = 0, flag4 = 0 ,calflag = 0;
	int cfnode, clnode, kind;
	double ratio,value;
	TCHAR pagestring[100],answerpagestring[100];
	MOUSEMSG m;

	//初始化图形
	initgraph(800, 600, EW_DBLCLKS);
	setbkcolor(WHITE);
	settextstyle(25, 0, _T("微软雅黑"));
	settextcolor(BLACK);
	setlinecolor(BLACK);
	cleardevice();
	//整体划分为三个框架
	rectangle(0, 0, 800, 600);
	rectangle(10, 10, 500, 295);
	rectangle(10, 305, 500, 590);
	rectangle(510, 10, 790, 590);
	//输出部分
	rectangle(calculate[0], calculate[1], calculate[2], calculate[3]);
	outtextxy(calculate[0] + 20, calculate[1] + 3, L"计算");
	rectangle(restart[0], restart[1], restart[2], restart[3]);
	outtextxy(restart[0] + 20, restart[1]+3, L"清空");
	//绘制元件显示部分
	for (int i = 0;i < 4; i++)
		rectangle(showinputx1[i], showinputy1[i], showinputx2[i], showinputy2[i]);
	rectangle(pageup[0], pageup[1], pageup[2], pageup[3]);
	rectangle(page[0], page[1], page[2], page[3]);
	rectangle(pagedown[0], pagedown[1], pagedown[2], pagedown[3]);
	outtextxy(pageup[0] + 10, pageup[1] + 3, L"上一页");
	outtextxy(pagedown[0] + 10, pagedown[1] + 3, L"下一页");
	_stprintf_s(pagestring, _T("第%d页/共%d页"), nowpage, totpage);
	outtextxy(page[0] + 25, page[1] + 3, pagestring);
	//绘制元件图上部分
	rectangle(cptext[0], cptext[1], cptext[2], cptext[3]);
	settextstyle(40, 0, _T("微软雅黑"));
	outtextxy(cptext[0] + 23, cptext[1] + 5, L"元件类型选择区");
	settextstyle(25, 0, _T("微软雅黑"));
	for (int i = 0; i < 5; i++)
		rectangle(cpx1[i], cpy1[i], cpx2[i], cpy2[i]);
	outtextxy(cpx1[0] + 33, cpy1[0] + 3, L"独立电压源");
	outtextxy(cpx1[1] + 33, cpy1[1] + 3, L"独立电流源");
	outtextxy(cpx1[2] + 33, cpy1[2] + 3, L"受控电压源");
	outtextxy(cpx1[3] + 33, cpy1[3] + 3, L"受控电流源");
	outtextxy(cpx1[4] + 45, cpy1[4] + 3, L"线性电阻");
	for (int i = 0; i < 5; i++)
		rectangle(bx1[i], by1[i], bx2[i], by2[i]);
	//绘制元件图中间部分
	line(510, 300, 790, 300);
	rectangle(inputtext[0], inputtext[1], inputtext[2], inputtext[3]);
	settextstyle(40, 0, _T("微软雅黑"));
	outtextxy(inputtext[0] + 23, inputtext[1] + 5, L"元件位置选择区");
	settextstyle(25, 0, _T("微软雅黑"));
	rectangle(inputscreen[0], inputscreen[1], inputscreen[2], inputscreen[3]);
	outtextxy(inputscreen[0] + 5, inputscreen[1] + 15, L"首结点：");
	rectangle(node1[0], node1[1], node1[2], node1[3]);
	outtextxy(inputscreen[0] + 120, inputscreen[1] + 15, L"末结点：");
	rectangle(node2[0], node2[1], node2[2], node2[3]);
	//绘制元件图下部分
	line(510, 415, 790, 415);
	//绘制元件图底层
	line(510, 540, 790, 540);
	rectangle(inbutton[0], inbutton[1], inbutton[2], inbutton[3]);
	rectangle(rebutton[0], rebutton[1], rebutton[2], rebutton[3]);
	outtextxy(inbutton[0] + 23, inbutton[1] + 3, L"插入");
	outtextxy(rebutton[0] + 23, rebutton[1] + 3, L"重置");


	//用户操作界面
	while (true) {
		//...............................载入元件展示..........................
		//页码
		totpage = (base.getlen() - 1) / 4 + 1;
		_stprintf_s(pagestring, _T("第%d页/共%d页"), nowpage, totpage);
		outtextxy(page[0] + 25, page[1] + 3, pagestring);
		//元件
		for (int i = 0; i < 4; i++) {
			component sea;
			base.search((nowpage - 1) * 4 + i + 1, sea);
			if ((nowpage - 1) * 4 + i < base.getlen()) {
				if (sea.type == 0) {
					_stprintf_s(inf, _T("元件编号:%d  元件类型:独立电压源 "), (nowpage - 1) * 4 + i + 1 );
					outtextxy(showinputx1[i] + 5, showinputy1[i] + 5, inf);
					_stprintf_s(inf, _T("首尾结点:%d->%d    值:%6.3lfV"),  sea.fnode, sea.lnode, -sea.value);
					outtextxy(showinputx1[i] + 5, showinputy1[i] + 30, inf);
				}
				else if (sea.type == 1) {
					_stprintf_s(inf, _T("元件编号:%d  元件类型:独立电流源 "), (nowpage - 1) * 4 + i + 1);
					outtextxy(showinputx1[i] + 5, showinputy1[i] + 5, inf);
					_stprintf_s(inf, _T("首尾结点:%d->%d    值:%6.3lfA"), sea.fnode, sea.lnode, sea.value);
					outtextxy(showinputx1[i] + 5, showinputy1[i] + 30, inf);
				}
				else if (sea.type == 2) {
					_stprintf_s(inf, _T("元件编号:%d  元件类型:受控电压源  受控类型:%c"), (nowpage - 1) * 4 + i + 1,21 * sea.kind + 65);
					outtextxy(showinputx1[i] + 5, showinputy1[i] + 5, inf);
					_stprintf_s(inf, _T("首尾结点:%d->%d  受控首尾结点:%d->%d  比例系数:%6.3lf"), sea.fnode, sea.lnode,sea.cfnode,sea.clnode,sea.ratio);
					outtextxy(showinputx1[i] + 5, showinputy1[i] + 30, inf);
				}
				else if (sea.type == 3) {
					_stprintf_s(inf, _T("元件编号:%d  元件类型:受控电流源  受控类型:%c"), (nowpage - 1) * 4 + i + 1, 21 * sea.kind + 65);
					outtextxy(showinputx1[i] + 5, showinputy1[i] + 5, inf);
					_stprintf_s(inf, _T("首尾结点:%d->%d  受控首尾结点:%d->%d  比例系数:%6.3lf"), sea.fnode, sea.lnode, sea.cfnode, sea.clnode, sea.ratio);
					outtextxy(showinputx1[i] + 5, showinputy1[i] + 30, inf);
				}
				else if (sea.type == 4) {
					_stprintf_s(inf, _T("元件编号:%d  元件类型:电阻 "), (nowpage - 1) * 4 + i + 1 );
					outtextxy(showinputx1[i] + 5, showinputy1[i] + 5, inf);
					_stprintf_s(inf, _T("首尾结点:%d->%d    值:%6.3lfΩ"),  sea.fnode, sea.lnode, sea.value);
					outtextxy(showinputx1[i] + 5, showinputy1[i] + 30, inf);
				}	
				fillrectangle(showinputx1[i] + 420, showinputy1[i] + 5, showinputx1[i] + 460, showinputy1[i] + 25);
				settextstyle(18, 0, _T("微软雅黑"));
				outtextxy(showinputx1[i] + 428, showinputy1[i] + 7, L"删除");
				settextstyle(25, 0, _T("微软雅黑"));
			}
		}
		//..............................答案显示界面..............................
		antotpage = (answer.getlen() - 1) / 10 + 1;
		if (calflag == 1) {
			for (int i = 0; i < 10; i++) {
				if (i + 10 * (annowpage - 1) < answer.getlen()) {
					_stprintf_s(an, _T("结点%d:%0.4lfV"), i + 10 * (annowpage - 1), answer.getvalue(i + 10 * (annowpage - 1)));
					outtextxy(answerx[i], answery[i], an);
				}
				else {
					clearrectangle(answerx[i], answery[i], answerx[i] + 100, answery[i] + 30);
				}
			}
			rectangle(pageup[0], pageup[1] - y, pageup[2], pageup[3] - y);
			rectangle(page[0], page[1] - y, page[2], page[3] - y);
			rectangle(pagedown[0], pagedown[1] - y, pagedown[2], pagedown[3] - y);
			outtextxy(pageup[0] + 10, pageup[1] + 3 - y, L"上一页");
			outtextxy(pagedown[0] + 10, pagedown[1] + 3 - y, L"下一页");
			_stprintf_s(answerpagestring, _T("第%d页/共%d页"), annowpage, antotpage);
			outtextxy(page[0] + 25, page[1] + 3 - y, answerpagestring);
		}
		
		//..............................读入数据显示界面...........................
		if (fflag == 1 && lflag == 1) flag = 3;
		if ((flag1 == 1 && flag2 == 1 && flag3 == 1 && flag4 == 1) || vflag == 1)flag = 4;
		//首结点内容显示
		if (fflag == 1) {
			outtextxy(node1[0]+15, node1[1],fn);
		}
		else {
			fillrectangle(node1[0], node1[1], node1[2], node1[3]);
		}
		//尾结点内容显示
		if (lflag == 1) {
			outtextxy(node2[0] + 15, node2[1], ln);
		}
		else {
			fillrectangle(node2[0], node2[1], node2[2], node2[3]);
		}
		//数值大小内容显示
		if (flag >= 3 && (type == 0) ){
			outtextxy(lblock3[0]+10, lblock3[1]+10,L"请输入电压源电压(V):");
		}
		else if (flag >= 3 && type == 1) {
			outtextxy(lblock3[0] + 10, lblock3[1] + 10, L"请输入电流源电流(A):");
		}
		else if (flag >= 3 && type == 2) {
			outtextxy(lblock3[0] + 10, lblock3[1] + 10, L"请输入电压源受控系数:");
			rectangle(input1[0], input1[1],input1[2],input1[3]);
			outtextxy(lblock3[0] + 10, lblock3[1] + 40, L"请输入受控首结点:");
			rectangle(input2[0], input2[1], input2[2], input2[3]);
			outtextxy(lblock3[0] + 10, lblock3[1] + 70, L"请输入受控尾结点:");
			rectangle(input3[0], input3[1], input3[2], input3[3]);
			outtextxy(lblock3[0] + 10, lblock3[1] + 100, L"请输入控制类型:");
			rectangle(input4[0], input4[1], input4[2], input4[3]);
		}
		else if (flag >= 3 && type == 3) {
			outtextxy(lblock3[0] + 10, lblock3[1] + 10, L"请输入电流源受控系数:");
			rectangle(input1[0], input1[1], input1[2], input1[3]);
			outtextxy(lblock3[0] + 10, lblock3[1] + 40, L"请输入受控首结点:");
			rectangle(input2[0], input2[1], input2[2], input2[3]);
			outtextxy(lblock3[0] + 10, lblock3[1] + 70, L"请输入受控尾结点:");
			rectangle(input3[0], input3[1], input3[2], input3[3]);
			outtextxy(lblock3[0] + 10, lblock3[1] + 100, L"请输入控制类型:");
			rectangle(input4[0], input4[1], input4[2], input4[3]);
		}
		else if (flag >= 3 && type == 4) {
			outtextxy(lblock3[0] + 10, lblock3[1] + 10, L"请输入电阻阻值(Ω):");
		}
		else {
			fillrectangle(lblock3[0], lblock3[1], lblock3[2], lblock3[3]);
		}
		//补充输入内容显示
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
		//........................鼠标监测...................
		if (flag == 1 && m.uMsg == WM_LBUTTONDOWN && m.x >= lblock1[0] 
			&& m.x <= lblock1[2] && m.y >= lblock1[1] && m.y <= lblock1[3]) {
			for (int i = 0; i <= 4; i++) {
				if (m.x >= bx1[i] && m.x <= bx2[i] && m.y >= by1[i] && m.y <= by2[i]) {
					//颜色改变标记
					setfillcolor(RGB(200, 200, 200));
					fillrectangle(bx1[i], by1[i], bx2[i], by2[i]);
					setfillcolor(WHITE);
					type = i;			//记录类型
					flag = 2;
				}
			}
		}
		//重置
		else if (flag != 1 && m.uMsg == WM_LBUTTONDOWN && m.x >= rebutton[0] && m.x <= rebutton[2] && m.y >= rebutton[1] && m.y <= rebutton[3]) {
			flag = 1; lflag = 0, fflag = 0; flag1 = 0; flag2 = 0; flag3 = 0; flag4 = 0; vflag = 0;
			//..............................刷新.................................
			cleardevice();
			//整体划分为三个框架
			rectangle(0, 0, 800, 600);
			rectangle(10, 10, 500, 295);
			rectangle(10, 305, 500, 590);
			rectangle(510, 10, 790, 590);
			//输出部分
			rectangle(calculate[0], calculate[1], calculate[2], calculate[3]);
			outtextxy(calculate[0] + 20, calculate[1] + 3, L"计算");
			rectangle(restart[0], restart[1], restart[2], restart[3]);
			outtextxy(restart[0] + 20, restart[1] + 3, L"清空");
			//绘制元件显示部分
			for (int i = 0; i < 4; i++)
				rectangle(showinputx1[i], showinputy1[i], showinputx2[i], showinputy2[i]);
			rectangle(pageup[0], pageup[1], pageup[2], pageup[3]);
			rectangle(page[0], page[1], page[2], page[3]);
			rectangle(pagedown[0], pagedown[1], pagedown[2], pagedown[3]);
			outtextxy(pageup[0] + 10, pageup[1] + 3, L"上一页");
			outtextxy(pagedown[0] + 10, pagedown[1] + 3, L"下一页");
			_stprintf_s(pagestring, _T("第%d页/共%d页"), nowpage, totpage);
			outtextxy(page[0] + 25, page[1] + 3, pagestring);
			//绘制元件图上部分
			rectangle(cptext[0], cptext[1], cptext[2], cptext[3]);
			settextstyle(40, 0, _T("微软雅黑"));
			outtextxy(cptext[0] + 23, cptext[1] + 5, L"元件类型选择区");
			settextstyle(25, 0, _T("微软雅黑"));
			for (int i = 0; i < 5; i++)
				rectangle(cpx1[i], cpy1[i], cpx2[i], cpy2[i]);
			outtextxy(cpx1[0] + 33, cpy1[0] + 3, L"独立电压源");
			outtextxy(cpx1[1] + 33, cpy1[1] + 3, L"独立电流源");
			outtextxy(cpx1[2] + 33, cpy1[2] + 3, L"受控电压源");
			outtextxy(cpx1[3] + 33, cpy1[3] + 3, L"受控电流源");
			outtextxy(cpx1[4] + 45, cpy1[4] + 3, L"线性电阻");
			for (int i = 0; i < 5; i++)
				rectangle(bx1[i], by1[i], bx2[i], by2[i]);
			//绘制元件图中间部分
			line(510, 300, 790, 300);
			rectangle(inputtext[0], inputtext[1], inputtext[2], inputtext[3]);
			settextstyle(40, 0, _T("微软雅黑"));
			outtextxy(inputtext[0] + 23, inputtext[1] + 5, L"元件位置选择区");
			settextstyle(25, 0, _T("微软雅黑"));
			rectangle(inputscreen[0], inputscreen[1], inputscreen[2], inputscreen[3]);
			outtextxy(inputscreen[0] + 5, inputscreen[1] + 15, L"首结点：");
			rectangle(node1[0], node1[1], node1[2], node1[3]);
			outtextxy(inputscreen[0] + 120, inputscreen[1] + 15, L"末结点：");
			rectangle(node2[0], node2[1], node2[2], node2[3]);
			//绘制元件图下部分
			line(510, 415, 790, 415);
			//绘制元件图底层
			line(510, 540, 790, 540);
			rectangle(inbutton[0], inbutton[1], inbutton[2], inbutton[3]);
			rectangle(rebutton[0], rebutton[1], rebutton[2], rebutton[3]);
			outtextxy(inbutton[0] + 23, inbutton[1] + 3, L"插入");
			outtextxy(rebutton[0] + 23, rebutton[1] + 3, L"重置");
		}
		//结点输入
		else if (flag == 2 && m.uMsg == WM_LBUTTONDOWN && m.x >= lblock2[0]
			&& m.x <= lblock2[2] && m.y >= lblock2[1] && m.y <= lblock2[3]) {
			//结点的输入
			if (fflag == 0 && m.x >= node1[0] && m.x <= node1[2] && m.y >= node1[1] && m.y <= node1[3]) {
				InputBox(fn, 10, L"请输入首结点(第一个结点为0号):",L"结点输入", NULL,200,0, true);
				fnode = _wtoi(fn);
				while (fnode < 0) {
					InputBox(fn, 10, L"输入不正确，请重新输入首结点(第一个结点为0号):", L"结点输入", NULL, 200, 0, true);
					fnode = _wtoi(fn);
				}
				fflag = 1;
			}
			else if (lflag == 0 && m.x >= node2[0] && m.x <= node2[2] && m.y >= node2[1] && m.y <= node2[3]) {
				InputBox(ln, 10, L"请输入尾结点(第一个结点为0号):", L"结点输入", NULL, 200, 0, true);
				lnode = _wtoi(ln);
				while (lnode < 0) {
					InputBox(ln, 10, L"输入不正确，请重新输入尾结点(第一个结点为0号):", L"结点输入", NULL, 200, 0, true);
					lnode = _wtoi(ln);
				}
				lflag = 1;
			}
		}
		//补充输入
		else if ((flag == 3 && m.uMsg == WM_LBUTTONDOWN && m.x >= lblock3[0]
			&& m.x <= lblock3[2] && m.y >= lblock3[1] && m.y <= lblock3[3]) && (type == 2 ||type ==3)) {
			if (flag1 == 0 && m.x >= input1[0] && m.x <= input1[2] && m.y >= input1[1] && m.y <= input1[3]) {
				InputBox(ra, 10, L"请输入控制比例系数:", L"系数输入", NULL, 200, 0, true);
				ratio = _tstof(ra);
				flag1 = 1;
			}
			else if (flag2 == 0 && m.x >= input2[0] && m.x <= input2[2] && m.y >= input2[1] && m.y <= input2[3]) {
				InputBox(cf, 10, L"请输入控制首结点:", L"控制结点输入", NULL, 200, 0, true);
				cfnode = _wtoi(cf);
				flag2 = 1;
			}
			else if (flag3 == 0 && m.x >= input3[0] && m.x <= input3[2] && m.y >= input3[1] && m.y <= input3[3]) {
				InputBox(cl, 10, L"请输入控制尾结点:", L"控制结点输入", NULL, 200, 0, true);
				clnode = _wtoi(cl);
				flag3 = 1;
			}
			else if (flag4 == 0 && m.x >= input4[0] && m.x <= input4[2] && m.y >= input4[1] && m.y <= input4[3]) {
				InputBox(ki, 10, L"请输入控制类型(0-电流 1-电压):", L"控制类型输入(输入数字0或1)", NULL, 200, 0, true);
				kind = _wtoi(ki);
				flag4 = 1;
			}
		}
		else if ((flag == 3 && vflag == 0 && m.uMsg == WM_LBUTTONDOWN && m.x >= lblock3[0]
			&& m.x <= lblock3[2] && m.y >= lblock3[1] && m.y <= lblock3[3]) && (type == 4 || type == 0 || type == 1)) {
				InputBox(va, 10, L"请输入数值:", L"数值输入", NULL, 200, 0, true);
				value = _tstof(va);
				if (type == 0)value = -value;
				vflag = 1;
		}
		//插入操作
		else if (flag == 4 && m.uMsg == WM_LBUTTONDOWN && m.x >= inbutton[0] && m.x <= inbutton[2] && m.y >= inbutton[1] && m.y <= inbutton[3]) {
			//写入
			if (type == 0 || type == 1 || type == 4) {
				component comp(type, fnode, lnode, value);
				base.append(comp);
			}
			else if (type == 2 || type == 3) {
				component comp(type, fnode, lnode, cfnode,clnode,ratio,kind);
				base.append(comp);
			}
			//重置
			flag = 1; lflag = 0, fflag = 0; flag1 = 0; flag2 = 0; flag3 = 0; flag4 = 0; vflag = 0;
			//..............................刷新.................................
			cleardevice();
			//整体划分为三个框架
			rectangle(0, 0, 800, 600);
			rectangle(10, 10, 500, 295);
			rectangle(10, 305, 500, 590);
			rectangle(510, 10, 790, 590);
			//输出部分
			rectangle(calculate[0], calculate[1], calculate[2], calculate[3]);
			outtextxy(calculate[0] + 20, calculate[1] + 3, L"计算");
			rectangle(restart[0], restart[1], restart[2], restart[3]);
			outtextxy(restart[0] + 20, restart[1] + 3, L"清空");
			//绘制元件显示部分
			for (int i = 0; i < 4; i++)
				rectangle(showinputx1[i], showinputy1[i], showinputx2[i], showinputy2[i]);
			rectangle(pageup[0], pageup[1], pageup[2], pageup[3]);
			rectangle(page[0], page[1], page[2], page[3]);
			rectangle(pagedown[0], pagedown[1], pagedown[2], pagedown[3]);
			outtextxy(pageup[0] + 10, pageup[1] + 3, L"上一页");
			outtextxy(pagedown[0] + 10, pagedown[1] + 3, L"下一页");
			_stprintf_s(pagestring, _T("第%d页/共%d页"), nowpage, totpage);
			outtextxy(page[0] + 25, page[1] + 3, pagestring);
			//绘制元件图上部分
			rectangle(cptext[0], cptext[1], cptext[2], cptext[3]);
			settextstyle(40, 0, _T("微软雅黑"));
			outtextxy(cptext[0] + 23, cptext[1] + 5, L"元件类型选择区");
			settextstyle(25, 0, _T("微软雅黑"));
			for (int i = 0; i < 5; i++)
				rectangle(cpx1[i], cpy1[i], cpx2[i], cpy2[i]);
			outtextxy(cpx1[0] + 33, cpy1[0] + 3, L"独立电压源");
			outtextxy(cpx1[1] + 33, cpy1[1] + 3, L"独立电流源");
			outtextxy(cpx1[2] + 33, cpy1[2] + 3, L"受控电压源");
			outtextxy(cpx1[3] + 33, cpy1[3] + 3, L"受控电流源");
			outtextxy(cpx1[4] + 45, cpy1[4] + 3, L"线性电阻");
			for (int i = 0; i < 5; i++)
				rectangle(bx1[i], by1[i], bx2[i], by2[i]);
			//绘制元件图中间部分
			line(510, 300, 790, 300);
			rectangle(inputtext[0], inputtext[1], inputtext[2], inputtext[3]);
			settextstyle(40, 0, _T("微软雅黑"));
			outtextxy(inputtext[0] + 23, inputtext[1] + 5, L"元件位置选择区");
			settextstyle(25, 0, _T("微软雅黑"));
			rectangle(inputscreen[0], inputscreen[1], inputscreen[2], inputscreen[3]);
			outtextxy(inputscreen[0] + 5, inputscreen[1] + 15, L"首结点：");
			rectangle(node1[0], node1[1], node1[2], node1[3]);
			outtextxy(inputscreen[0] + 120, inputscreen[1] + 15, L"末结点：");
			rectangle(node2[0], node2[1], node2[2], node2[3]);
			//绘制元件图下部分
			line(510, 415, 790, 415);
			//绘制元件图底层
			line(510, 540, 790, 540);
			rectangle(inbutton[0], inbutton[1], inbutton[2], inbutton[3]);
			rectangle(rebutton[0], rebutton[1], rebutton[2], rebutton[3]);
			outtextxy(inbutton[0] + 23, inbutton[1] + 3, L"插入");
			outtextxy(rebutton[0] + 23, rebutton[1] + 3, L"重置");
		}
		if (m.x >= 10 && m.x <= 500 && m.y >= 305 && m.y <= 590 &&(m.uMsg == WM_LBUTTONDOWN || m.uMsg == WM_MOUSEWHEEL)) {
			//上下翻页
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
				//删除操作
				for (int i = 0; i <= 4; i++) {
					if (m.uMsg == WM_LBUTTONDOWN && (nowpage - 1) * 4 + i + 1 <= base.getlen() && m.x >= showinputx1[i] + 420 && m.x <= showinputx1[i] + 460 && m.y >= showinputy1[i] + 5 && m.y <= showinputy1[i] + 25) {
						base.remove((nowpage - 1) * 4 + i + 1);
					}
				}
			}
			//..............................刷新.................................
			cleardevice();
			//整体划分为三个框架
			rectangle(0, 0, 800, 600);
			rectangle(10, 10, 500, 295);
			rectangle(10, 305, 500, 590);
			rectangle(510, 10, 790, 590);
			//输出部分
			rectangle(calculate[0], calculate[1], calculate[2], calculate[3]);
			outtextxy(calculate[0] + 20, calculate[1] + 3, L"计算");
			rectangle(restart[0], restart[1], restart[2], restart[3]);
			outtextxy(restart[0] + 20, restart[1] + 3, L"清空");
			//绘制元件显示部分
			for (int i = 0; i < 4; i++)
				rectangle(showinputx1[i], showinputy1[i], showinputx2[i], showinputy2[i]);
			rectangle(pageup[0], pageup[1], pageup[2], pageup[3]);
			rectangle(page[0], page[1], page[2], page[3]);
			rectangle(pagedown[0], pagedown[1], pagedown[2], pagedown[3]);
			outtextxy(pageup[0] + 10, pageup[1] + 3, L"上一页");
			outtextxy(pagedown[0] + 10, pagedown[1] + 3, L"下一页");
			_stprintf_s(pagestring, _T("第%d页/共%d页"), nowpage, totpage);
			outtextxy(page[0] + 25, page[1] + 3, pagestring);
			//绘制元件图上部分
			rectangle(cptext[0], cptext[1], cptext[2], cptext[3]);
			settextstyle(40, 0, _T("微软雅黑"));
			outtextxy(cptext[0] + 23, cptext[1] + 5, L"元件类型选择区");
			settextstyle(25, 0, _T("微软雅黑"));
			for (int i = 0; i < 5; i++)
				rectangle(cpx1[i], cpy1[i], cpx2[i], cpy2[i]);
			outtextxy(cpx1[0] + 33, cpy1[0] + 3, L"独立电压源");
			outtextxy(cpx1[1] + 33, cpy1[1] + 3, L"独立电流源");
			outtextxy(cpx1[2] + 33, cpy1[2] + 3, L"受控电压源");
			outtextxy(cpx1[3] + 33, cpy1[3] + 3, L"受控电流源");
			outtextxy(cpx1[4] + 45, cpy1[4] + 3, L"线性电阻");
			for (int i = 0; i < 5; i++)
				rectangle(bx1[i], by1[i], bx2[i], by2[i]);
			//绘制元件图中间部分
			line(510, 300, 790, 300);
			rectangle(inputtext[0], inputtext[1], inputtext[2], inputtext[3]);
			settextstyle(40, 0, _T("微软雅黑"));
			outtextxy(inputtext[0] + 23, inputtext[1] + 5, L"元件位置选择区");
			settextstyle(25, 0, _T("微软雅黑"));
			rectangle(inputscreen[0], inputscreen[1], inputscreen[2], inputscreen[3]);
			outtextxy(inputscreen[0] + 5, inputscreen[1] + 15, L"首结点：");
			rectangle(node1[0], node1[1], node1[2], node1[3]);
			outtextxy(inputscreen[0] + 120, inputscreen[1] + 15, L"末结点：");
			rectangle(node2[0], node2[1], node2[2], node2[3]);
			//绘制元件图下部分
			line(510, 415, 790, 415);
			//绘制元件图底层
			line(510, 540, 790, 540);
			rectangle(inbutton[0], inbutton[1], inbutton[2], inbutton[3]);
			rectangle(rebutton[0], rebutton[1], rebutton[2], rebutton[3]);
			outtextxy(inbutton[0] + 23, inbutton[1] + 3, L"插入");
			outtextxy(rebutton[0] + 23, rebutton[1] + 3, L"重置");
		}
		else if ((m.uMsg == WM_LBUTTONDOWN || m.uMsg == WM_MOUSEWHEEL) && m.x >= 10 && m.x <= 500 && m.y >= 10 && m.y <= 295) {
			if (m.x >= restart[0] && m.x <= restart[2] && m.y >= restart[1] && m.y <= restart[3]) {//清空
				base.clear();
				answer.clear();
				nowpage = 1;
				annowpage = 1;
				calflag = 0;
				flag = 1; lflag = 0, fflag = 0; flag1 = 0; flag2 = 0; flag3 = 0; flag4 = 0; vflag = 0;
			}
			else if (m.x >= calculate[0] && m.x <= calculate[2] && m.y >= calculate[1] && m.y <= calculate[3]) {//计算
				if (base.getlen() > 0) {
					base.calculate(base.getlen(), answer);
					/*插入计算的函数*/
					calflag = 1;
				}	
			}
			else if ((m.x >= pageup[0] && m.x <= pageup[2] && m.y >= pageup[1] - y && m.y <= pageup[3] - y)||m.wheel > 0) {
				if (annowpage > 1) {//上一页
					annowpage--;
				}
			}
			else if ((m.x >= pagedown[0] && m.x <= pagedown[2] && m.y >= pagedown[1] - y && m.y <= pagedown[3] - y)||m.wheel < 0) {
				if (annowpage < antotpage) {//下一页
					annowpage++;
				}
			}
			//..............................刷新.................................
			cleardevice();
			//整体划分为三个框架
			rectangle(0, 0, 800, 600);
			rectangle(10, 10, 500, 295);
			rectangle(10, 305, 500, 590);
			rectangle(510, 10, 790, 590);
			//输出部分
			rectangle(calculate[0], calculate[1], calculate[2], calculate[3]);
			outtextxy(calculate[0] + 20, calculate[1] + 3, L"计算");
			rectangle(restart[0], restart[1], restart[2], restart[3]);
			outtextxy(restart[0] + 20, restart[1] + 3, L"清空");
			//绘制元件显示部分
			for (int i = 0; i < 4; i++)
				rectangle(showinputx1[i], showinputy1[i], showinputx2[i], showinputy2[i]);
			rectangle(pageup[0], pageup[1], pageup[2], pageup[3]);
			rectangle(page[0], page[1], page[2], page[3]);
			rectangle(pagedown[0], pagedown[1], pagedown[2], pagedown[3]);
			outtextxy(pageup[0] + 10, pageup[1] + 3, L"上一页");
			outtextxy(pagedown[0] + 10, pagedown[1] + 3, L"下一页");
			_stprintf_s(pagestring, _T("第%d页/共%d页"), nowpage, totpage);
			outtextxy(page[0] + 25, page[1] + 3, pagestring);
			//绘制元件图上部分
			rectangle(cptext[0], cptext[1], cptext[2], cptext[3]);
			settextstyle(40, 0, _T("微软雅黑"));
			outtextxy(cptext[0] + 23, cptext[1] + 5, L"元件类型选择区");
			settextstyle(25, 0, _T("微软雅黑"));
			for (int i = 0; i < 5; i++)
				rectangle(cpx1[i], cpy1[i], cpx2[i], cpy2[i]);
			outtextxy(cpx1[0] + 33, cpy1[0] + 3, L"独立电压源");
			outtextxy(cpx1[1] + 33, cpy1[1] + 3, L"独立电流源");
			outtextxy(cpx1[2] + 33, cpy1[2] + 3, L"受控电压源");
			outtextxy(cpx1[3] + 33, cpy1[3] + 3, L"受控电流源");
			outtextxy(cpx1[4] + 45, cpy1[4] + 3, L"线性电阻");
			for (int i = 0; i < 5; i++)
				rectangle(bx1[i], by1[i], bx2[i], by2[i]);
			//绘制元件图中间部分
			line(510, 300, 790, 300);
			rectangle(inputtext[0], inputtext[1], inputtext[2], inputtext[3]);
			settextstyle(40, 0, _T("微软雅黑"));
			outtextxy(inputtext[0] + 23, inputtext[1] + 5, L"元件位置选择区");
			settextstyle(25, 0, _T("微软雅黑"));
			rectangle(inputscreen[0], inputscreen[1], inputscreen[2], inputscreen[3]);
			outtextxy(inputscreen[0] + 5, inputscreen[1] + 15, L"首结点：");
			rectangle(node1[0], node1[1], node1[2], node1[3]);
			outtextxy(inputscreen[0] + 120, inputscreen[1] + 15, L"末结点：");
			rectangle(node2[0], node2[1], node2[2], node2[3]);
			//绘制元件图下部分
			line(510, 415, 790, 415);
			//绘制元件图底层
			line(510, 540, 790, 540);
			rectangle(inbutton[0], inbutton[1], inbutton[2], inbutton[3]);
			rectangle(rebutton[0], rebutton[1], rebutton[2], rebutton[3]);
			outtextxy(inbutton[0] + 23, inbutton[1] + 3, L"插入");
			outtextxy(rebutton[0] + 23, rebutton[1] + 3, L"重置");
		}
		else if (m.uMsg == WM_RBUTTONDBLCLK) {
				break;
		}
	}
	// 关闭图形窗口
	closegraph();
}