#include "Header.h"
int main() {
	BST_TREE tree;
	init(tree);

	int choice, value;
	do {
		cout << "\n----- MENU -----";
		cout << "\n1. chen 1 node vao cay ";
		cout << "\n2. xoa 1 node khoi cay";
		cout << "\n3. dem so luong nut trong cay";
		cout << "\n4. tach cay thanh cay chan va cay le";
		cout << "\n5. in cay theo duyet truoc (NLR)";
		cout << "\n6. in cay theo duyet giua (LNR)";
		cout << "\n7.in cay theo duyet sau (LRN)";
		cout << "\n0. thoat";
		cout << "\nNhap lua chon: ";
		cin >> choice;

		switch (choice) {
		case 1:
			cout << "nhap gia tri de chen: ";
			cin >> value;
			ThemNodeVaoCay(tree, value);
			break;
		case 2:
			cout << "nhap gia tri de xoa: ";
			cin >> value;
			XoaNode(tree, value);
			break;
		case 3:
			cout << "tong so node trong cay la " << DemSoNode(tree) << endl;
			break;
		case 4: {
			Nodeptr cayChan = NULL;
			Nodeptr cayLe = NULL;
			TachCay(tree, cayChan, cayLe);
			cout << "Cay chan:";
			NLR(cayChan);
			cout << endl;
			cout << "Cay le:";
			NLR(cayLe);
			cout << endl;
			break;
		}
		case 5:
			cout << "duyet truoc (NLR): ";
			NLR(tree);
			cout << endl;
			break;
		case 6:
			cout << "duyet giua (LNR): ";
			LNR(tree);
			cout << endl;
			break;
		case 7:
			cout << "Duyet sau (LRN): ";
			LRN(tree);
			cout << endl;
			break;
		case 0:
			cout << "dang thoat...";
			break;
		default:
			cout << "lua chon khong hop le. vui long thu lai.";
			break;
		}
	} while (choice != 0);

	return 0;
}