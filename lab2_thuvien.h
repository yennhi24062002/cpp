#pragma once
#include<iostream>
using namespace std;
const int MAX = 50;
struct DaySo
{

	int list[MAX];
	int n;
};
void nhap(DaySo& a);
void xuat(DaySo a);
int tinhTongDs(DaySo a);
double tinhTichDs(DaySo a);
int demPTDuong(DaySo a);
int TinhTongChan(DaySo a);
int TinhTichChan(DaySo a);
int demPTchiahet3vs5(DaySo a);