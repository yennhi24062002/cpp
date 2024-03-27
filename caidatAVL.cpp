#include "thuvienAVL.h"
void init(AVLTREE &T)
{
	T = NULL;
}
AVLTREE CreateNodeAVL(int info)
{
	AVLTREE p = new NODEAVL;
	p->info = info;
	p->left = NULL;
	p->right = NULL;
	p->height = 1;
	return p;
}
void NLR(AVLTREE T)
{
	if (T != NULL)

	{

		cout << T->info << " ";

		NLR(T->left);

		NLR(T->right);

	}
}
void LNR(AVLTREE T)
{
	if (T != NULL)

	{

		LNR(T->left);

		cout << T->info << " ";

		LNR(T->right);

	}
}
void LRN(AVLTREE T)
{
	if (T != NULL)

	{

		LRN(T->left);

		LRN(T->right);

		cout << T->info << " ";

	}

}
int Max(int a, int b)
{
	return (a > b) ? a : b;
}
int height(AVLTREE T)
{
if (T == NULL)
return 0;
return 1 + Max(height(T->left), height(T->right));
}
int getCB(AVLTREE T)
{
	if (T == NULL)
		return 0;
	return height(T->left) - height(T->right);
}
void RotateRight(AVLTREE &T)
{
	AVLTREE temp = T->left;

	T->left = temp->right;

	temp->right = T;

	T->height = Max(height(T->left), height(T->right)) + 1;

	temp->height = Max(height(temp->left), T->height) + 1;

	T = temp;
}
void RotateLeft(AVLTREE &T)
{

	AVLTREE temp = T->right;

	T->right = temp->left;

	temp->left = T;

	T->height = Max(height(T->left), height(T->right)) + 1;

	temp->height = Max(height(temp->right), T->height) + 1;

	T = temp;
}
void RotateRightLeft(AVLTREE &T)
{
	RotateRight(T->right);

	RotateLeft(T);

}
void RotateLeftRight(AVLTREE &T)
{
	RotateLeft(T->left);

	RotateRight(T);

}
AVLTREE minValueNODEAVL(AVLTREE T)
{
	AVLTREE current = T;
	while (current->left != NULL)
		current = current->left;
	return current;
}
AVLTREE search(AVLTREE T, int x)
{
	if (T == NULL || T->info == x)

		return T;

	if (T->info < x)

		return search(T->right, x);

	else

		return search(T->left, x);

}
AVLTREE InsertNode(AVLTREE &T, int x) 
{
	if (T == NULL)
	{
		T = CreateNodeAVL(x);
	}
	else if (x < T->info)
	{
		T->left = InsertNode(T->left, x);
	}
	else if (x > T->info)
	{
		T->right = InsertNode(T->right, x);
	}
	else
	{
		return T; // Node đã tồn tại
	}
	

	return T;


}
int DeleteNode(AVLTREE &T, int x) 
{
	if (T == NULL)
	{
		return 0; // Node không tồn tại
	}

	if (x < T->info)
	{
		return DeleteNode(T->left, x);
	}
	else if (x > T->info)
	{
		return DeleteNode(T->right, x);
	}
	else
	{
		if (T->left == NULL || T->right == NULL) // Node có 1 hoặc không có con
		{
			AVLTREE temp = T->left ? T->left : T->right;
			if (temp == NULL)
			{
				temp = T;
				T = NULL;
			}
			else
			{
				*T = *temp;
			}
			delete temp;
		}
		else // Node có cả 2 con
		{
			AVLTREE temp = minValueNODEAVL(T->right);
			T->info = temp->info;
			DeleteNode(T->right, temp->info);
		}

		getCB(T); // Cân bằng cây AVL sau khi xóa

		return 1; // Node đã được xóa

	}

}
int demKhoaLe(AVLTREE T) {

	if (T == NULL) {

		return 0;

	}

	int count = 0;

	if (T->info % 2 != 0) {

		count++;

	}

	count += demKhoaLe(T->left) + demKhoaLe(T->right);

	return count;

}
bool KTSNT(int n) {
	if (n < 2) {
		return false;
	}
	for (int i = 2; i <= n / 2; i++) {
		if (n % i == 0) {
			return false;
		}
	}
	return true;
}
void xuatCacKhoaLaSNT(AVLTREE T) {

	if (T != NULL) {

		xuatCacKhoaLaSNT(T->left);

		if (KTSNT(T->info)) {

			cout << T->info << " ";

		}

		xuatCacKhoaLaSNT(T->right);

	}

}
int tongCacKhoaLaSNT(AVLTREE T) {

	if (T == NULL) {

		return 0;

	}

	int tong = 0;

	if (KTSNT(T->info)) {

		tong += T->info;

	}

	tong += tongCacKhoaLaSNT(T->left) + tongCacKhoaLaSNT(T->right);

	return tong;

}
void cacKhoaLaBoiCuaSoNguyenX(AVLTREE T, int X) {

	if (T != NULL) {

		cacKhoaLaBoiCuaSoNguyenX(T->left, X);

		if (T->info % X == 0) {

			cout << T->info << " ";

		}

		cacKhoaLaBoiCuaSoNguyenX(T->right, X);

	}

}
void InMenu(int &chon)
{
	system("cls");
	cout << "\n-------MENU-------\n";
	cout << "\n Cac thao tac tren cay AVL";
	cout << "\n 1. Them NODEAVL vao cay AVL";
	cout << "\n 2. Loai NODEAVL tren cay AVL";
	cout << "\n 3. Tim NODEAVL tren cay AVL";
	cout << "\n 4. Duyet theo thu tu truoc";
	cout << "\n 5. Duyet theo thu tu giua";
	cout << "\n 6. Duyet theo thu tu sau";
	cout << "\n 7. chieu cao cua cay AVL";
	cout << "\n 8. So luong khoa le trong cay" << endl;
	cout << "\n 9. Cac khoa la so nguyen to trong cay" << endl;
	cout << "\n 10. Tong cac khoa la so nguyen to trong cay" << endl;
	cout << "\n 11. Cac khoa la boi cua X trong cay" << endl;
	cout << "\n 0. Thoat khoi chuong trinh";
	cout << "\n------------------------\n";
	cout << "\n Dua vao lua chon:";
	cin >> chon;
}