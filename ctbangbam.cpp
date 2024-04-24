#include "thuvienbangbam.h"
void main()
{
	OpenHashTable ht;
	int n;
	TYPEINFO a;
	do {
		cout << "\nNhap so phan hoach:";
		cin >> ht.n;
	} while (ht.n < 1);
	initht(ht);
	do {
		cout << "\n= = = = = = = = = = = = =";
		cout << "\n1. Nhap mot day so vao bang bam";
		cout << "\n2. Xuat bang bam ra man hinh";
		cout << "\n3. Them mot so vao bang bam";
		cout << "\n4. Xoa mot so khoi bang bam";
		cout << "\n5. Tim kiem mot so trong bang bam";
		cout << "\n6. tim MAX trong mang bang";
		cout << "\n7. Tim Tong danh sach trong bang bam";
		cout << "\n8. sap xep danh sach tang dan trong bang bam";
		cout << "\n9. Xuat danh sach nhieu phan tu trong bang bam";
		cout << "\n10. Tim  phan tu chan lon nhat trong bang bam";
		cout << "\n11. Xuat so nguyen to trong bang bam";
		cout << "\n0. Ket thuc chuong trinh";
		cout << "\nBan hay lua chon [0,1,2,3,4,5,6,7]:";
		cin >> n;
		switch (n)
		{
		case 1:
			Nhapht(ht);
			xuatht(ht);
			break;
		case 2:
			xuatht(ht);
			break;
		case 3:
			cout << "\nNhap phan tu can them:";
			cin >> a;
			if (themht(ht, a) == 1)
				cout << "\n Them thanh cong";
			else
				cout << "\n Da co phan tu nay";
			break;
		case 4:
			cout << "\nNhap phan tu can xoa:";
			cin >> a;
			if (xoaht(ht, a) == 1)
				cout << "\n Xoa thanh cong";
			else
				cout << "\n Khong co phan tu can xoa";
			xuatht(ht);
			break;
		case 5:
			cout << "\nNhap phan tu can tim:";
			cin >> a;
			if (timht(ht, a) == 1)
				cout << "\n Tim thay";
			else
				cout << "\n Khong tim thay";
			break;
		case 6:
			cout << "\nPhan tu lon nhat la: " << timMaxht(ht);
			break;
		case 7:
			cout << "\nTong phan tu trong mang la: " << tonght(ht);
			break;
		case 8:
			sapxepht(ht);
			cout << "\nBang bam sau khi sap xep la:";
			xuatht(ht);
			break;
		case 9:
			xuatDanhsachlonnhat(ht);
			break;
		case 10:
			cout << "\nPhan tu chan lon nhat trong bang bam la:" << timMaxChan(ht);
			break;
		case 11:
			xuatsnt(ht);
			break;
		case 0:
			exit(0);
		default:
			cout << "\nNhap sai";
			break;
		}
	} while (n != 0);
}
