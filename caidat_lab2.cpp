#include "thuvien_lab2.h"
//Ham khoi tao
void khoiTao(DaySo & x)
{
	x.n = 0;
}
//Ham kiem tra rong
int isEmpty(DaySo x)
{
	return (x.n == 0 ? 1 : 0);
}
//Ham kiem tra day
int isFull(DaySo x)
{
	return(x.n == MAX ? 1 : 0);
}
//Ham tra ve so nut cua ds dac
int listSize(DaySo x)
{
	return (x.n);
}
/********Ham nhap day so vao ds dac********/
void doc_DanhSach(DaySo & x)
{
	cout << "\nNhap vao so phan tu cua DS:";
	cin >> x.n;
	for (int i = 0; i < x.n; i++) {
		cout << "\nNhap vao phan tu thu" << i + 1 << ":";
		cin >> x.ds[i];
	}
}/*******Ham xuat ra ds dac********/
void xuat_DanhSach(DaySo x)
{
	cout << "\nPhan tu trong DS:";
	for (int i = 0; i < x.n ; i++)
		cout << x.ds[i] << "";
}
void chen_ViTri(DaySo &x, int pos, int a) 
{
	if (pos<0 || pos>listSize(x))
		cout << "\n Vi tri " <<  pos <<  " khong hop le";
	else
		if (isEmpty(x) == 1) {
			if (pos == 0) {
				x.ds[0] = a;
				x.n++;
			}
			else
				cout << "\n Vi tri khong hop le";
		}
		else if (isFull(x) == 1)
		cout << "\n Danh sach day";
		else {
			for (int i = listSize(x) - 1; i >= pos; i--)
				x.ds[i + 1] = x.ds[i];
			x.ds[pos] = a;
			x.n++;
		}

}
void xoa_ViTri(DaySo &x, int pos) 
{
	int i;
	if (pos<0 || pos>listSize(x) - 1)
		cout << "Vi tri" << pos <<" khong hop le ! ";
	else
		if (isEmpty(x))
			cout << "DS bi rong"; 
		else {
			for (i = pos + 1; i <= listSize(x); i++)
				x.ds[i - 1] = x.ds[i];
			x.n--;
		}
}

void xoa_GiaTri_K(DaySo & x, int k)
{
	for (int i = 0; i < x.n; i++) {
		if (x.ds[i] == k) {
			for (int j = i; j < x.n - 1; j++)
				x.ds[j] = x.ds[j + 1];
			x.n--;
		}

	}

}

int timkiem_TuanTu(DaySo x, int a)
{
	int i = 0; 
	while (i < x.n && x.ds[i] != a)
		i++; 
	if (i == x.n)
		return -1;//Khong tim thay
	return i;

}

void sapXep(DaySo & x)
{
	for (int i = 0; i < x.n - 1; i++)
		for (int j = i + 1; j < x.n; j++)
			if (x.ds[j] < x.ds[i]) {
				int tam = x.ds[i];
				x.ds[i] = x.ds[j];
				x.ds[j] = tam;
			}
}

int timKiemNhiPhan(const DaySo & x, int k)
{
	int left = 0;
	int right = x.n - 1;
	while (left <= right) {
		int middle = (left + right) / 2;
		if (x.ds[middle] == k) {
			return middle; // Trả về vị trí của phần tử nếu tìm thấy
		}
		else if (x.ds[middle] < k) {
			left = middle + 1; // Tìm phần tử bên phải của middle
		}
		else {
			right = middle - 1; // Tìm phần tử bên trái của middle
		}
	}
	return -1; // Trả về -1 nếu không tìm thấy phần tử
}


		




