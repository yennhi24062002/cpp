#include "Header.h"

void nhapMH(monHoc & mh)
{
	cout << "\nNhap Ma Mon Hoc: ";
	cin.ignore();
	getline(cin, mh.maMH);
	cout << "\nNhap Ten Mon Hoc: ";
	//cin.ignore();
	getline(cin, mh.tenMH);
	cout << "Nhap so Tin Chi: ";
	cin >> mh.soTC;
}

void xuatMH(monHoc mh)
{
	cout << mh.maMH << "\t\t\t" << mh.tenMH << "\t\t" << mh.soTC << endl;
}

void khoiTao(dsMonHoc & dsMH)
{
	cout << "Nhap So Luong mon hoc ( >=1 )";
	do {
		cin >> dsMH.SLmhTD;
	} while (dsMH.SLmhTD < 1);
	dsMH.list = new monHoc[dsMH.SLmhTD];
}

void nhapMangMH(monHoc list[], int SLmhHT)
{
	for (int i = 0; i < SLmhHT; i++) {
		nhapMH(list[i]);
	}
}

void xuatMangMH(monHoc list[], int SLmhHT)
{
	cout << "Ma Mon Hoc" << "\t\t" << "Ten Mon Hoc" << "\t\t" << "So Tin chi" << endl;

	for (int i = 0; i < SLmhHT; i++) {
		xuatMH(list[i]);
	}
}
int xdSLmhHT(int SLmhTD)
{
	int SLmhHT;
	cout << "Nhap so luong mon hoc: ";
	do {
		cin >> SLmhHT;
	} while (SLmhHT<1 && SLmhHT>SLmhTD);
	return SLmhHT;
}
void nhapDSMH(dsMonHoc & dsMH)
{
	if (dsMH.SLmhTD == 0) {
		khoiTao(dsMH);
		dsMH.SLmhHT = xdSLmhHT(dsMH.SLmhTD);
		nhapMangMH(dsMH.list, dsMH.SLmhHT);
	}
	else if (dsMH.SLmhTD > 0)
	{
		if (dsMH.SLmhHT == 0)
		{
			dsMH.SLmhHT = xdSLmhHT(dsMH.SLmhTD);
			nhapMangMH(dsMH.list, dsMH.SLmhHT);
		}
		else if (dsMH.SLmhHT > 0)
		{
		}
		else
		{
		}
	}
	else {

	}
}
void them_MonHoc_ViTri(dsMonHoc & dsMH, int pos, monHoc mh)
{
	if (pos<0 || pos>dsMH.SLmhHT)
	{
		cout << "\nVi tri khong hop le";
	}
	else if (dsMH.SLmhHT == 0)
	{
		if (pos == 0)
		{
			dsMH.list[0] = mh;
		}
		else
		{
			cout << "\nVi tri khong hop le ";
		}
	}
	else if (dsMH.SLmhHT == dsMH.SLmhTD)
	{
		cout << "\nDanh sach mon hoc day";
	}
	else
	{
		for (int i = dsMH.SLmhHT - 1; i >= pos; i--)
		{
			dsMH.list[i + 1] = dsMH.list[i];
		}
		dsMH.list[pos] = mh;
		dsMH.SLmhHT++;
	}
}