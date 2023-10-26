#include"thuvien_lab3ctdl.h"
void main() {
	MonHoc mh;
	nhapMonHoc(mh);
	cout << "mon hoc cua ban vua nhap" << endl;
	xuatMonHoc(mh);
	DanhSachMonHoc ds;
	nhapDanhSachMonHoc(ds);
	xuatDanhSachMonHoc(ds);
	char mamh[10];
	cout << " nhap ma mon hoc muon tim :";
	cin >> mh.mamh;
	cout << "nhap ma mon hoc muon xoa: ";
	cin >> mamh;
	xoa_maMonHoc(ds, mamh);
	int k = timkiem_tuantu(ds, mh.mamh);
	if (k == -1)
		cout << " khong co ma mh trong ds !" << endl;
	else
	{
		cout << "co mon hoc ban can tim :" << endl;
		xuatMonHoc(ds.data[k]);

	}
	selectionsort(ds);
	cout << "Danh sach mon hoc sau khi sap xep theo so tin chi:" << endl;
	xuatDanhSachMonHoc(ds);
	insertionsort(ds);
	cout << "Danh sach mon hoc sau khi sap xep giam dan theo so tin chi:" << endl;
	xuatDanhSachMonHoc(ds);

}