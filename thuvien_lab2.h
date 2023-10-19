#include <iostream>
using namespace std;
const int MAX = 50;
//Cấu trúc DS DAC
struct DaySo {
	int ds[MAX];
	int n;      //So phan tu ds adc
};
void khoiTao(DaySo &x);
int isEmpty(DaySo x);
int isFull(DaySo x);
int listSize(DaySo x);
void doc_DanhSach(DaySo &x);
void xuat_DanhSach(DaySo x);
void chen_ViTri(DaySo &x, int pos, int a);
void xoa_ViTri(DaySo &x, int pos);
void xoa_GiaTri_K(DaySo &x, int k);
int timkiem_TuanTu(DaySo x, int a);
void sapXep(DaySo &x);
int timKiemNhiPhan(const DaySo& x, int k);
