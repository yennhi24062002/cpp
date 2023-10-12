#include"thuvien_lab1.h"

//void main() {
//
//	int a[KTM], n;
//
//	nhapMang(a, n);
//	xuatMang(a, n);
//}

void main() {
	int a[KTM], n, x;
	nhapMang(a, n);
	xuatMang(a, n);

	cout << "\n Nhap phan tu can tim:";
	cin >> x;

	/*if (timKiem_TuanTu(a, n, x) >= 0)
		cout << "\n tim thay " << x;

	else

		cout << "\n Khong tim thay " << x;
	int viTri = timKiem_TuanTu(a, n, x);
	if (viTri >= 0)
		cout << "\nTim thay " << x << " tai vi tri " << viTri;
	else
		cout << "\nKhong tim thay " << x;*/

	if (timKiem_NhiPhan(a, n, x) >= 0)
		cout << "\nTim thay " << x;
	else
		cout << "\nKhong tim thay " << x;
	sapXep(a, n);
}
//int main() {
//	int a[KTM], n;
//
//	cout << "Nhap so phan tu mang: ";
//	cin >> n;
//
//	nhapMang(a, n);
//	xuatMang(a, n);
//
//	return 0;
//}