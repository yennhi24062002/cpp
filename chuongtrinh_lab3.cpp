#include"thuvien_lab3.h"
void main()
{
	DAYSO d;
	nhapDS(d);
	xuatDS(d);
	cout << "\nMin la: " << timMin(d);
	int kq = hamA(d);
	cout << "\nHamA la: " << kq;
	DAYSO a1, a2, a3;
	cout << "\nNhap day so thu 1:";
	nhapDS(a1);
	xuatDS(a1);
	cout << "\nNhap day so thu 2:";
	nhapDS(a2);
	xuatDS(a2);
	cout << "\nDay so thu 1 sap tang dan:";
	BubbleSort(a1);
	xuatDS(a1);
	cout << "\nDay so thu 2 sap tang dan:";
	BubbleSort(a2);
	xuatDS(a2);
	a3 = tronDS(a1, a2);
	cout << "\nDay so da duoc tron tang dan:";
	xuatDS(a3);
	system("pause");
	/*DAYSO a, a1, a2;
	nhapDS(a);
	int index;
	cout << "Nhap vi tri index: ";
	cin >> index;
	tachDS(a, index, a1, a2);
	cout << "Day so a1: ";
	xuatDS(a1);
	cout << "Day so a2: ";
	xuatDS(a2);*/
	/*DAYSO a = { {1, 2, 3, 4, 5}, 5 };
	DAYSO b = { {6, 7, 8}, 3 };

	DAYSO c = ghepDS(a, b);
	cout << "Danh sach sau khi ghep: ";
	xuatDS(c);

	cout << "Danh sach sau khi dao nguoc: ";
	daoNguocDS(c);
	xuatDS(c);

	int x;
	cout << "Nhap gia tri x muon xoa: ";
	cin >> x;
	xoaPhanTuX(c, x);
	cout << "Danh sach sau khi xoa phan tu x: ";
	xuatDS(c);*/
}
	