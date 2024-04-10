#include "thuviencaynghieng.h"
void main()
{
	/*SkewHeap *sh = new SkewHeap;
	Init(sh);
	sh = Insert(sh);
	SkewHeap *sh2 = new SkewHeap;
	Init(sh2);
	sh2 = Insert(sh2);
	SkewHeap *temp = new SkewHeap;
	temp = Merge(sh, sh2);
	PrintHeap(temp);
	system("pause");*/
	SkewHeap *sh = new SkewHeap;

	Init(sh);
	cout << "Nhập cây 1/n";
	createSkewHeap(sh);

	SkewHeap *sh2 = new SkewHeap;

	Init(sh2);
	cout << "Nhập cây 2/n";
	createSkewHeap(sh2);

	SkewHeap *temp = Merge(sh, sh2);
	cout << "xuất cây gộp/n";
	PrintHeap(temp);
	cout << "xuất cây giảm/n";

	DecreaseKey(temp, 5, 2); // Giả sử giảm key từ 5 xuống còn 2

	PrintHeap(temp);

	//delete sh;/*

	//delete sh2;*/

	delete temp;
}
