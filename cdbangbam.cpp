#include "thuvienbangbam.h"
int funcHash(TYPEINFO a, int n)
{
	return a % n;
}
void initht(OpenHashTable& ht)
{
	for (int i = 0; i < MAX; i++)
		ht.ds[i] = NULL;
}
Node* create_Node(TYPEINFO a)
{
	Node* p = new Node;
	p->info = a;
	p->link = NULL;
	return p;
}
int themds(Node*& list, TYPEINFO a)
{
	/*if (list == NULL)
	{
		list = create_Node(a);
		return 1;
	}
	else if (list->info == a)
		return 0;
	else
		return themds(list->link, a);*/
		// Handle empty list
	if (list == NULL) {
		list = create_Node(a);
		return 1;
	}
	Node* current = list;
	while (current->link != NULL) {
		if (current->info == a) {
			return 0;
		}
		current = current->link;
	}
	current->link = create_Node(a);
	return 1;
}
void xuatds(Node* list)
{
	while (list != NULL)
	{
		cout << list->info << "\t";
		list = list->link;
	}
}
int timds(Node* list, TYPEINFO a)
{
	/*if (list == NULL)
		return 0;
	if (list->info == a)
		return 1;
	return timds(list->link, a);*/
	while (list != NULL) {
		if (list->info == a) {
			return 1;
		}
		list = list->link;
	}
	return 0;
}
int xoads(Node*& list, TYPEINFO a)
{
	/*if (list == NULL)
		return 0;
	if (list->info == a)
	{
		Node* p = list;
		list = p->link;
		delete p;
		return 1;
	}
	return xoads(list->link, a);*/
	if (list == NULL) {
		return 0;
	}


	if (list->info == a) {
		Node* temp = list;
		list = list->link;
		delete temp;
		return 1;
	}

	Node* current = list;
	while (current->link != NULL) {
		if (current->link->info == a) {
			Node* temp = current->link;
			current->link = temp->link;
			delete temp;
			return 1;
		}
		current = current->link;
	}
	return 0;
}
int demds(Node* plist)
{
	/*if (plist == NULL)
		return 0;
	else
		return 1 + demds(plist->link);*/
	int count = 0;
	Node* current = plist;

	while (current != NULL) {
		count++;
		current = current->link;
	}

	return count;
}
void Nhapht(OpenHashTable& ht)
{
	int a, k;
	do
	{
		cout << "\nNhap phan tu them (-99 de dung):";
		cin >> a;
		if (a == -99)
			return;
		k = funcHash(a, ht.n);
		themds(ht.ds[k], a);
	} while (1);
}
int themht(OpenHashTable& ht, TYPEINFO a)
{
	int k;
	k = funcHash(a, ht.n);
	return themds(ht.ds[k], a);
}
void xuatht(OpenHashTable ht)
{
	cout << "\n- - Danh sach:";
	for (int i = 0; i < ht.n; i++)
	{
		cout << "\n<" << i << ">:";
		xuatds(ht.ds[i]);
	}
}
int xoaht(OpenHashTable& ht, TYPEINFO a)
{
	int k;
	k = funcHash(a, ht.n);
	return xoads(ht.ds[k], a);
}
int timht(OpenHashTable ht, TYPEINFO a)
{
	int k = funcHash(a, ht.n);
	return timds(ht.ds[k], a);
}
int demht(OpenHashTable ht)
{
	int spt = 0;
	for (int i = 0; i < ht.n; i++)
	{
		NODE_PTR p = ht.ds[i];
		spt += demds(p);
	}
	return spt;
}
int ghifile(char* tenfile, OpenHashTable ht)
{
	FILE* f;
	int spt;
	NODE_PTR p;
	fopen_s(&f, tenfile, "wb");
	if (f == NULL)
		return 0;
	fwrite(&ht.n, sizeof(int), 1, f);
	spt = demht(ht);
	fwrite(&spt, sizeof(int), 1, f);
	for (int i = 0; i < ht.n; i++)
	{
		p = ht.ds[i];
		while (p != NULL)
		{
			fwrite(&p->info, sizeof(TYPEINFO), 1, f);
			p = p->link;
		}
	}
	fclose(f);
	return 1;
}
int docfile(char* tenfile, OpenHashTable& ht)
{
	FILE* f;
	int spt;
	TYPEINFO temp;
	fopen_s(&f, tenfile, "rb");
	if (f == NULL)
		return 0;
	fread(&ht.n, sizeof(int), 1, f);
	initht(ht);
	fread(&spt, sizeof(int), 1, f);
	for (int i = 0; i < spt; i++)
	{
		fread(&temp, sizeof(TYPEINFO), 1, f);
		themht(ht, temp);
	}
	fclose(f);
	return 1;
}
int timMaxht(OpenHashTable ht) {

	if (ht.n == 0) {
		return -1;
	}


	int maxValue = ht.ds[0]->info;
	Node* maxNode = ht.ds[0];


	for (int i = 1; i < ht.n; i++) {
		Node* current = ht.ds[i];


		while (current != NULL) {

			if (current->info > maxValue) {
				maxValue = current->info;
				maxNode = current;
			}
			current = current->link;
		}
	}

	return maxValue;
}
int tonght(OpenHashTable ht) {
	int sum = 0;
	for (int i = 0; i < ht.n; i++) {
		Node* current = ht.ds[i];

		while (current != NULL) {
			sum += current->info;
			current = current->link;
		}
	}

	return sum;
}
void sapxepds(Node*& list) {
	if (list == NULL || list->link == NULL) {
		return;
	}

	Node* sorted = NULL;
	Node* current = list;

	while (current != NULL) {
		Node* temp = current->link;
		current->link = sorted;
		sorted = current;

		current = temp;
	}


	list = sorted;
}

void sapxepht(OpenHashTable& ht) {
	for (int i = 0; i < ht.n; i++) {
		sapxepds(ht.ds[i]);
	}
}
void xuatDanhsachlonnhat(OpenHashTable ht) {
	int maxListSize = 0;
	int maxListIndex = -1;


	for (int i = 0; i < ht.n; i++) {
		int currentListSize = demds(ht.ds[i]);
		if (currentListSize > maxListSize) {
			maxListSize = currentListSize;
			maxListIndex = i;
		}
	}

	if (maxListSize == 0) {
		cout << "\n- Khong co phan tu nao trong bang bam.\n";
		return;
	}

	cout << "\n- Danh sach co nhieu phan tu nhat:\n";
	cout << "<" << maxListIndex << ">: ";
	xuatds(ht.ds[maxListIndex]);
}
int timMaxChan(OpenHashTable ht) {

	if (ht.n == 0) {
		return -1;
	}


	int maxValue = -1;


	for (int i = 0; i < ht.n; i++) {
		Node* current = ht.ds[i];


		while (current != NULL) {

			if (current->info % 2 == 0 && current->info > maxValue) {
				maxValue = current->info;
			}
			current = current->link;
		}
	}

	return maxValue;
}
void xuatsnt(OpenHashTable ht) {

	if (ht.n == 0) {
		cout << "\n- Khong co phan tu nao trong bang bam.\n";
		return;
	}


	for (int i = 0; i < ht.n; i++) {
		Node* current = ht.ds[i];


		while (current != NULL) {

			if (ktsnt(current->info)) {
				cout << current->info << " ";
			}
			current = current->link;
		}
	}
}


bool ktsnt(int n) {
	if (n <= 1) {
		return false;
	}

	for (int i = 2; i <= sqrt(n); i++) {
		if (n % i == 0) {
			return false;
		}
	}

	return true;
}
