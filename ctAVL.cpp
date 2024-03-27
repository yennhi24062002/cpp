#include "thuvienAVL.h"
void main()
{
	AVLTREE T;

	int chon, x, tong;

	init(T);

	do {

		InMenu(chon);

		switch (chon) {

		case 1:

			cout << "Nhap gia tri can them: ";

			cin >> x;

			T = InsertNode(T, x);

			break;

		case 2:

			cout << "Nhap gia tri can xoa: ";

			cin >> x;

			if (DeleteNode(T, x))

				cout << "Xoa thanh cong!" << endl;

			else

				cout << "Khong tim thay gia tri can xoa!" << endl;

			break;

		case 3:

			cout << "Nhap gia tri can tim: ";

			cin >> x;

			if (search(T, x) != NULL)

				cout << "Gia tri " << x << " ton tai trong cay" << endl;

			else

				cout << "Khong tim thay gia tri " << x << " trong cay" << endl;

			break;

		case 4:

			cout << "Duyet theo thu tu NLR: ";

			NLR(T);

			cout << endl;

			break;

		case 5:

			cout << "Duyet theo thu tu LNR: ";

			LNR(T);

			cout << endl;

			break;

		case 6:

			cout << "Duyet theo thu tu LRN: ";

			LRN(T);

			cout << endl;

			break;

		case 7:

			cout << "Chieu cao cua cay AVL: " << height(T) << endl;

			break;

		case 8:

			cout << "So luong khoa le trong cay: " << demKhoaLe(T) << endl;

			break;

		case 9:

			cout << "Cac khoa la so nguyen to trong cay: ";

			xuatCacKhoaLaSNT(T);

			cout << endl;

			break;

		case 10:

			tong = tongCacKhoaLaSNT(T);

			cout << "Tong cac khoa la so nguyen to trong cay: " << tong << endl;

			break;

		case 11:

			cout << "Nhap so nguyen X: ";

			cin >> x;

			cout << "Cac khoa la boi cua " << x << " trong cay: ";

			cacKhoaLaBoiCuaSoNguyenX(T, x);

			cout << endl;

			break;

		default:

			cout << "Thoat chuong trinh!" << endl;

			break;

		}

		system("pause");

		system("cls");

	} while (chon != 0);

	

}