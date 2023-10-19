#include"thuvien_lab2.h"
//void main() {
//	DaySo x;
//	int pos, a, k;
//	khoiTao(x);
//	doc_DanhSach(x); 
//	xuat_DanhSach(x);
//	cout << "\n Nhap phan tu can chen:";
//	cin >> k;
//	cout << "\n Nhap vi tri can chen:";
//	cin >> pos;
//	chen_ViTri(x, pos, k);
//	xoa_ViTri(x, pos);
//	xuat_DanhSach(x);
//	xoa_GiaTri_K(x, k);
//	xuat_DanhSach(x);
//}
int main() {
	DaySo x;
	int pos, a, k;
	khoiTao(x);
	doc_DanhSach(x);
	xuat_DanhSach(x);
	/*cout << "\n Nhap phan tu k can tim:";
	cin >> k;
	if (timkiem_TuanTu(x, k) == -1)
		cout << "\n Khong tim thay";
	else
		cout << "\n Tim thay";*/

	cout << "\nNhap phan tu a can tim: ";
	cin >> a;

	int viTri = timkiem_TuanTu(x, a);

	if (viTri == -1) {
		cout << "\nKhong tim thay";
	}
	else {
		cout << "\nTim thay tai vi tri: " << viTri;
	}

	//// Khởi tạo và sắp xếp dãy số
	//DaySo x;
	//// ... Gán giá trị cho x.ds và x.n
	//sapXep(x);
	//// Gọi hàm tìm kiếm nhị phân
	//int k = 42; // Giá trị cần tìm
	//int viTri = timKiemNhiPhan(x, k);
	//if (viTri != -1) {
	//	cout << "Phan tu " << k << " duoc tim thay tai vi tri " << viTri << endl;
	//}
	//else {
	//	cout << "Phan tu " << k << " khong duoc tim thay trong day so" << endl;
	//}
	return 0;
}
