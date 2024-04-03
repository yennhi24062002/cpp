#include <iostream> 
#include "thuviencaytanloe.h"
using namespace std;
int main()
{
	NodePtr r = NULL;
	// Tạo cây tán loe với các phần tử 6, 2, 10, 1, 5, 15
	r = insertAndSplay(r, 6);
	r = insertAndSplay(r, 2);
	r = insertAndSplay(r, 10);
	preOrder(r);
	cout << endl;
	// Thêm các phần tử 1, 5, 15 vào cây và in ra kết quả
	r = insertAndSplay(r, 1);
	preOrder(r);
	cout << endl;
	r = insertAndSplay(r, 5);
	preOrder(r);
	cout << endl;
	r = insertAndSplay(r, 15);
	preOrder(r);
	cout << endl;
	// Xóa phần tử 5 khỏi cây
	r = deleteNodeAndSplay(r, 5);
	preOrder(r);
	cout << endl;
	return 0;
}
