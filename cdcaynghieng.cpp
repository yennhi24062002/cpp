#include "thuviencaynghieng.h"
void Init(SkewHeap *sh)
{
	sh->key = 0;
	sh->left = NULL;
	sh->right = NULL;
}
SkewHeap* Merge(SkewHeap *h1, SkewHeap *h2)
{
	SkewHeap *temp = new SkewHeap;
	if (h1 == NULL)
		return h2;
	else if (h2 == NULL)
		return h1;
	else
	{
		if (h1->key < h2->key)
		{
			temp = h1;
			h1 = h2;
			h2 = temp;
		}
		temp = h1->left;
		h1->left = h1->right;
		h1->right = temp;
		h1->left = Merge(h2, h1->left);
	}
	return h1;
}
SkewHeap* Insert(SkewHeap *root)
{
	int value;
	cout << "Nhap gia tri can chen:";
	cin >> value;
	SkewHeap *temp = new SkewHeap;
	Init(temp);
	temp->key = value;
	root = Merge(root, temp);
	return root;
}
SkewHeap* DeleteMax(SkewHeap *root)
{
	if (root == NULL)
	{
		cout << "Skew Heap rong!";
		return NULL;
	}
	SkewHeap *temp1;
	SkewHeap *temp2;
	temp1 = root->left;
	temp2 = root->right;
	temp1 = Merge(temp1, temp2);
	return temp1;
}
void PreOrder(SkewHeap *root)
{
	if (root == NULL)
		return;
	cout << root->key << " ";
	PreOrder(root->left);
	PreOrder(root->right);
}
void InOrder(SkewHeap *root)
{
	if (root == NULL)
		return;
	InOrder(root->left);
	cout << root->key << " ";
	InOrder(root->right);
}
void PostOrder(SkewHeap *root)
{
	if (root == NULL)
		return;
	PostOrder(root->left);
	PostOrder(root->right);
	cout << root->key << " ";
}
void PrintHeap(SkewHeap *root)
{
	if (root == NULL)
	{
		cout << "Cay Nghieng rong." << endl;
		return;
	}
	cout << "Cay Nghieng: " << endl;
	InOrder(root);
	cout << endl;
	cout << "Cay Nghieng sau PostOrder: " << endl;
	PostOrder(root);
	cout << endl;
}
void createSkewHeap(SkewHeap *&root) {
	int value;
	do {
		cout << "Nhap gia tri (nhap 0 de thoat): ";
		cin >> value;
		if (value != 0) {
			SkewHeap *temp = new SkewHeap();
			temp->key = value;
			temp->left = NULL;
			temp->right = NULL;
			root = Merge(root, temp);
		}
	} while (value != 0);
}
void DecreaseKey(SkewHeap *&root, int target, int newKey) {
	if (root == NULL) {
		cout << "Cay nghieng rong!";
		return;
	}
	DecreaseKeyUtil(root, target, newKey);
}
void DecreaseKeyUtil(SkewHeap *&node, int target, int newKey) {
	if (node == NULL) {
		return;
	}
	if (node->key == target) {
		node->key = newKey;
		if (node->left != NULL)
			DecreaseKeyUtil(node->left, target, newKey);
		if (node->right != NULL)
			DecreaseKeyUtil(node->right, target, newKey);
	}
	else {
		DecreaseKeyUtil(node->left, target, newKey);
		DecreaseKeyUtil(node->right, target, newKey);
	}
}		

