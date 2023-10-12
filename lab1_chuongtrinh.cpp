#include "lab1_thuvien.h"

//void main()
//{
//	int a, b;
//	double x;
//	cout << "\nGiai phuong trinh bac 1 (ax+b=0):";
//	cout << "\nNhap a=";
//	cin >> a;
//	cout << "\nNhap b=";
//	cin >> b;
//	giaiPTB1(a, b, x);
//	cout << "\n\nNghiem cua phuong trinh la: " << x;
//	int n;
//	cout << "\nTinh 2 mu n:";
//	cout << "\nNhap n=";
//	cin >> n;
//	cout << "\n2 mu" << n << " = " << tinh2MuN(n);
//	system("pause");
//}


int main()
{
	int a, b, c;
	double x1, x2;

	cout << "Nhap he so a: ";
	cin >> a;

	cout << "Nhap he so b: ";
	cin >> b;

	cout << "Nhap he so c: ";
	cin >> c;

	int ketQua = giaiPTB2(a, b, c, x1, x2);

	if (ketQua == 0) {
		cout << "Phuong trinh vo nghiem" << endl;
	}
	else if (ketQua == 1) {
		cout << "Phuong trinh co mot nghiem: x = " << x1 << endl;
	}
	else if (ketQua == 2) {
		cout << "Phuong trinh co hai nghiem: x1 = " << x1 << ", x2 = " << x2 << endl;
	}
	else if (ketQua == 3) {
		cout << "Phuong trinh vo so nghiem" << endl;
	}

	int x, y;
	cout << "Nhap gia tri x: ";
	cin >> x;

	cout << "Nhap gia tri y: ";
	cin >> y;

	double ketQuaMu = tinhMu(x, y);
	cout << x << " mu " << y << " = " << ketQuaMu << endl;

	return 0;
}