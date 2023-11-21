#include"Header.h"
Node*taoNode() {
	Node*n = new Node;
	cout << "\nNhap gia tri:";
	cin >> n->Data;
	return n;
}
bool ktRong(Node* list) 
{
	return list == NULL  ? 1 : 0;
}
void themDau(Node*&list)
{
	Node*n = taoNode();
	if (ktRong(list))
	{
		list = n;

	}
	else
	{
		n->link = list;
		list = n;

	}
}


void nhapDayso(Node*&list)
{
	char kt = 'n';
	int i = 1;
	do
	{

		themDau(list);
		cout << "thoat(yes/no)";
		cin >> kt; 

	} while (kt != 'x'&& kt != 'Y');
	

	
}
void xuatDaySo(Node*list)
{
	if(ktRong(list))
	{
		cout << "danh sach rong";

	}
	else
	{
		Node*index = list;
		do
		{
			cout << "[" << index->Data << "]";
			index = index->link;
		} while (index != NULL);
	}
}  

void themCuoi(Node*list) {
	Node*p = taoNode();
	if (ktRong(list)) {
		list = p;
	}
	else {
		Node*index = list;
		while (index->link != NULL);
		{
			index = index->link;
		}
		index->link = p;
	}

}
void nhapDaysoCuoi(Node*&list)
{
	char kt = 'n';
	int i = 1;
	do
	{

		themCuoi(list);
		cout << "thoat(yes/no)";
		cin >> kt;

	} while (kt != 'x'&& kt != 'Y');



}