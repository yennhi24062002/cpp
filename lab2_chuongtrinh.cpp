#include"lab2_thuvien.h"
void main() {
	DaySo d;
	nhap(d);
	xuat(d);
	double Tong = tinhTongDs(d);
	cout << " tong cua day so :" << Tong << endl;
	double Tich = tinhTichDs(d);
	cout << "tich cua day so :" << Tich << endl;
	int soLuong = demPTDuong(d);
	cout << "So luong cua phan tu co trong mang :" << soLuong << endl;
	int TongChan = TinhTongChan(d);
	cout << "tong chan la :" << TongChan << endl;
	int TichChan = TinhTichChan(d);
	cout << "tich chan la :" << TichChan << endl;
	int soLuongchiahetcho3vs5 = demPTchiahet3vs5(d);
	cout << " so luong phan tu chia het cho 3 vs 5 la :" << soLuongchiahetcho3vs5 << endl;
	system("pause");


}