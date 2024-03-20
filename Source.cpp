#include "Header.h"

void init(Nodeptr& root)
{
	root = NULL;
}

Node*TaoNode(int x)
{
	Nodeptr p;
	p = new Node;
	p->data = x;
	p->left = NULL;
	p->right = NULL;
	return p;
}
void ThemNodeVaoCay(Nodeptr& root, int x) {
	if (root == NULL)
		root = TaoNode(x);
	else {
		if (x == root->data) {
			cout << "\n Co node roi";
			return;
		}
		else
			if (x < root->data)
				ThemNodeVaoCay(root->left, x);
			else
				ThemNodeVaoCay(root->right, x);

	}
}
void NhapCay(Nodeptr& root) {
	int x;
	while (1) {
		cout << "\nNhap DL cho cay(thoat nhan -99): ";
		cin >> x;
		if (x == -99)
			break;
		ThemNodeVaoCay(root, x);
	}
}

Nodeptr TimNode(Nodeptr root, int x)
{
	if (root == NULL || root->data == x) {
		return root;
	}
	else {
		if (root->data > x) {
			return TimNode(root->left, x);
		}
		else
		{
			return TimNode(root->right, x);
		}
	}
}
void NodeTheMang(Nodeptr& X, Nodeptr& Y)
{
	if (Y->left != NULL)
	{
		NodeTheMang(X, Y->left);
	}
	else
	{
		X->data = Y->data;
		X = Y;
		Y = Y->right;
	}
}
void XoaNode(Nodeptr& root, int x)
{
	if (root == NULL) {
		return;
	}
	else
	{
		if (root->data > x)
		{
			XoaNode(root->left, x);
		}
		else if (root->data < x)
		{
			XoaNode(root->right, x);
		}
		else
		{
			Node* NodeTheMang = root;
			if (root->left == NULL)
			{
				root = root->right;
			}
			else if (root->right == NULL)
			{
				root = root->left;
			}
			delete NodeTheMang;
		}
	}
}

int DemSoNode(Nodeptr root)
{
	{
		if (root == NULL)
			return 0;
		else
			return 1 + DemSoNode(root->left) + DemSoNode(root->right);
	}
}
char KiemTraNodeLa(Nodeptr p) {
	return (p->left == NULL) && (p->right == NULL);
}
//Dem nut la
int DemNodeLa(Nodeptr root) {
	if (root == NULL)
		return 0;
	else
		if (KiemTraNodeLa(root))
			return 1;
		else
			return DemNodeLa(root->left) + DemNodeLa(root->right);
}

int Max(int a, int b)
{
	if (a > b)
		return a;
	else
		return b;
}

int TinhChieuCaoCay(Nodeptr root)
{
	if (root == NULL)
		return 0;
	else
		return Max(TinhChieuCaoCay(root->left), TinhChieuCaoCay(root->right)) + 1;
}
void NLR(Node* Root)
{
	if (Root != NULL)
	{
		cout << " ( " << Root->data << " ) ";
		NLR(Root->left);
		NLR(Root->right);
	}
}
void LNR(Node* Root)
{
	if (Root != NULL)
	{
		LNR(Root->left);
		cout << " ( " << Root->data << " ) ";
		LNR(Root->right);
	}
}
void LRN(Node*Root)
{
	if (Root != NULL)
	{
		LNR(Root->left);
		LNR(Root->right);
		cout << " ( " << Root->data << " ) ";
	}
}
//tinh tong so khoa cua cay
int TinhTong(Nodeptr root) {
	if (root == NULL)
		return 0;
	else
		return root->data + TinhTong(root->left) + TinhTong(root->right);
}
//tach cay lam 2 
void TachCay(Nodeptr root, Nodeptr& cayChan, Nodeptr& cayLe) {
	if (root == NULL)
		return;

	if (root->data % 2 == 0) {
		ThemNodeVaoCay(cayChan, root->data);
	}
	else {
		ThemNodeVaoCay(cayLe, root->data);
	}

	TachCay(root->left, cayChan, cayLe);
	TachCay(root->right, cayChan, cayLe);
}
