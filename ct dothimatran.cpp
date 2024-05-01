#include "thuviendothimatran.h"
void main() {
	int ok, dinh;
	AdjacencyMatrix g;
	ArrayEdge tapcanh;
	do {
		cout << "\n===================================";
		cout << "\n0. Ket thuc";
		cout << "\n1. Doc file do thi vo huong";
		cout << "\n2. Doc file do thi co huong";
		cout << "\n3. Ghi file";
		cout << "\n4. Tinh so bac vao cua dinh";
		cout << "\n5. Lay tap canh cua do thi co huong";
		cout << "\n Moi ban chon: ";
		cin >> ok;
		cin.ignore();
		switch (ok)
		{
		case 1:
			Read("dothi1.txt", g);
			Xuat(g);
			break;
		case 2:
			Read("dothi2.txt", g);
			Xuat(g);
			break;
		case 3:
			cout << "\n Ghi file";
			Write("dothi3.txt", g);
			Xuat(g);
			break;
		case 4:
			cout << "\n Nhap dinh can tinh bac vao:";
			cin >> dinh;
			cout << "\n So bac vao cua dinh " << dinh << "la: " << TinhBacVaoDTCoHuong(g, dinh);
			break;
		case 5:
			tapcanh = TapCanhDTCH(g);
			if (tapcanh.count == 0) cout << "Do thi ko co canh nao.";
			else
			{
				cout << "\nTap canh cua do thi: ";
				for (int i = 0; i < tapcanh.count; i++)
					cout << "\n(" << tapcanh.ds[i].org
					<< " - " << tapcanh.ds[i].des << ", " << tapcanh.ds[i].wei <<
					")";
			}
			cout << "\n";
			break;
		}
	} while (ok != 0);
}