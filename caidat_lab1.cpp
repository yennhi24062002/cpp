#include"thuvien_lab1.h"

void nhapMang(int b[], int &m) { 
	do {

		cout << "\nNhap so phan tu mang:";

		cin >> m;

	} while (m<=0 || m>KTM);
	cout << "\nNhap gia tri cho mang:";

	for (int i = 0; i < m; i++) {
		cout << "\nNhap phan tu thu ;" << i << ": ";

		cin >> b[i];

	}

}
//int timKiem_TuanTu(int a[], int n, int x) {
//	int i = 0;
//	while (i < n && a[i] != x)
//		i++;
//	if (i == n)
//		return -1;
//}
int timKiem_NhiPhan(int a[], int n, int x)
{
	int left = 0;
	int right = n - 1;
	while (left <= right) {
		int mid = (left + right) / 2;
		if (a[mid] == x) {
			return mid;
		}
		else if (a[mid] < x) {
			left = mid + 1;
		}
		else {
			right = mid - 1;
		}
	}
	return -1;
}
void sapXep(int a[], int n) {
	for (int i = 0; i < n - 1; i++)
		for (int j = i + 1; j < n; j++)
			if (a[j] < a[i]) {
				int tam = a[i];
				a[i] = a[j];
				a[j] = tam;
			}
}
//void nhapMang(int b[], int &m) {
//
//	cout << "\nNhap gia tri cho mang:";
//	for (int i = 0; i < m; i++) {
//		cout << "\nNhap phan tu thu :" << i << " : ";
//		cin >> b[i];
//	}
//}
//void xuatMang(int b[], int n) {
//		cout << "\nMang la:";
//		for (int i = 0; i < n; i++)
//			cout << b[i] << setw(3);
//}


void xuatMang(int b[], int n) {

	cout << "\nMang la:";
	for (int i = 0; i < n; i++)
		cout << b[i] << setw(3);

}
