#include <iostream>
#include<string.h>
using namespace std;
const int MAX = 50;
struct MonHoc {
	char mamh[10];
	char tenmh[30];
	int sotc;
};
struct DanhSachMonHoc {

	int so;
	MonHoc data[MAX];
};

void nhapMonHoc(MonHoc& mh);
void xuatMonHoc(MonHoc mh);
void nhapDanhSachMonHoc(DanhSachMonHoc& ds);
void  xuatDanhSachMonHoc(DanhSachMonHoc ds);
void them_MonHoc_Vitri(DanhSachMonHoc& ds, int vt, MonHoc mh);
void xoa_MonHoc_Vitri(DanhSachMonHoc ds, int vt);
void xoa_maMonHoc(DanhSachMonHoc &ds, char* mamh);
void selectionsort(DanhSachMonHoc& ds);
void insertionsort(DanhSachMonHoc& ds);
int timkiem_tuantu(DanhSachMonHoc ds, char* ma);
