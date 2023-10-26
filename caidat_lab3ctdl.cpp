#include"thuvien_lab3ctdl.h"
void nhapMonHoc(MonHoc& mh) {
	cout << "nhap ma mh: ";
	cin >> mh.mamh;
	cout << "nhap ten mh :";
	cin.ignore();
	cin.getline(mh.tenmh, 30);
	cout << "nhap so tin chi :" << endl;
	cin >> mh.sotc;
}
void xuatMonHoc(MonHoc mh) {
	cout << " ma mh :" << "\t" << "ten mh" << "\t\t" << "so tc" << endl;
	cout << mh.mamh << "\t" << mh.tenmh << "\t\t" << mh.sotc << endl;

}
void nhapDanhSachMonHoc(DanhSachMonHoc& ds) {
	cout << " nhap so luong mh :" << endl;
	cin >> ds.so;
	cout << "nhap thong tin tung mh:" << endl;
	for (int i = 0; i < ds.so; i++) {
		cout << "thong tin mon hc thu :" << i + 1 << endl;
		nhapMonHoc(ds.data[i]);
	}

}
void xuatDanhSachMonHoc(DanhSachMonHoc ds) {
	cout << "danh sach cac mon hoc " << endl;
	for (int i = 0; i < ds.so; i++);
}
void them_MonHoc_Vitri(DanhSachMonHoc& ds, int vt, MonHoc mh) {
	if (vt<0 || vt>ds.so)
		cout << "vi tri khong hop le :";
	else {
		for (int i = ds.so - 1; i >= vt; i--)
			ds.data[i + 1] = ds.data[i];
		ds.data[vt] = mh;
		ds.so++;

	}
}
void  xoa_MonHoc_Vitri(DanhSachMonHoc ds, int vt) {
	if (vt<0 || vt>ds.so)
		cout << "vi tri kh hop le";
	else {
		for (int i = vt + 1; i <= ds.so; i++)
			ds.data[i - 1] = ds.data[i];
		ds.so--;
	}
}
void xoa_maMonHoc(DanhSachMonHoc &ds, char* mamh) {
	int index = -1;
	for (int i = 0; i < ds.so; i++) {
		if (strcmp(ds.data[i].mamh, mamh) == 0) {
			index = i;
			break;
		}
	}

	if (index == -1) {
		cout << "Khong tim thay ma mon hoc trong danh sach!" << endl;
	}
	else {
		for (int i = index; i < ds.so - 1; i++) {
			ds.data[i] = ds.data[i + 1];
		}
		ds.so--;
		cout << "Mon hoc da duoc xoa khoi danh sach!" << endl;
	}
}
int timkiem_tuantu(DanhSachMonHoc ds, char* ma) {
	int i = 0;
	while (i < ds.so && strcmp(ds.data[i].mamh, ma) != 0)
		i++;
	if (i == ds.so)
		return -1;
	return 1;
}
void selectionsort(DanhSachMonHoc& ds) {
	MonHoc mh;
	int min;
	for (int i = 0; i < ds.so - 1; i++) {
		min = i;
		for (int j = i + 1; j < ds.so; j++)
			if (ds.data[j].sotc < ds.data[min].sotc)
				min = j;
		mh = ds.data[i];
		ds.data[i] = ds.data[min];
		ds.data[min] = mh;

	}
}
void insertionsort(DanhSachMonHoc& ds) {
	for (int i = 1; i < ds.so; i++) {
		MonHoc key = ds.data[i];
		int j = i - 1;
		while (j >= 0 && ds.data[j].sotc < key.sotc) {
			ds.data[j + 1] = ds.data[j];
			j--;
		}
		ds.data[j + 1] = key;
	}
}