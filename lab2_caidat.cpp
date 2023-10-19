#include"lab2_thuvien.h"
void nhap(DaySo& a) {
	do
	{
		cout << "nhap so phan tu :" << endl;
		cin >> a.n;
		for (int i = 0; i < a.n; i++) {
			cout << "a[" << i << "]=";
			cin >> a.list[i];
		}

	} while (a.n <= 0);

}
void xuat(DaySo a) {

	for (int i = 0; i < a.n; i++)
		cout << a.list;
}
int tinhTongDs(DaySo a) {

	int t = 0;
	for (int i = 0; i < a.n; i++)
		t += a.list[i];
	return t;
}
double tinhTichDs(DaySo a) {

	int  Tich = 1;
	for (int i = 0; i < a.n; i++)
		Tich *= a.list[i];
	return Tich;
}
int demPTDuong(DaySo a) {
	int dem = 0;
	for (int i = 0; i < a.n; i++) {
		if (a.list[i] > 0)
			dem++;
	}
	return dem;
}
int TinhTongChan(DaySo a) {
	int s = 0;
	for (int i = 0; i < a.n; i++) {

		if (a.list[i] % 2 == 0) {

			s += a.list[i];


		}

	}
	return s;


}
int TinhTichChan(DaySo a) {
	int tichChan = 1;
	for (int i = 0; i < a.n; i++) {

		if (a.list[i] % 2 == 0) {
			tichChan *= a.list[i];

		}


	}
	return tichChan;


}
int demPTchiahet3vs5(DaySo a) {
	int demPT = 0;
	for (int i = 0; i < a.n; i++) {
		if (a.list[i] % 3 == 0 && a.list[i] % 5 == 0) {
			demPT++;

		}
	}
		return demPT;

}


