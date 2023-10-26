#include "thuvien_lab3.h"

void nhapDS(DAYSO &a)
{
	cout << "\nNhap so phan tu : ";
	cin >> a.n;
	for (int i = 0; i < a.n; i++)
	{
		cout << "a[" << i << "] = ";
		cin >> a.list[i];
	}
}
void xuatDS(DAYSO a)
{
	for (int i = 0; i < a.n; i++)
		cout << a.list[i] << " ";

}
int timMin(DAYSO a)
{
	int min = a.list[0];
	for (int i = 0; i < a.n; i++)
		if (a.list[i] < min)
			min = a.list[i];

	return min;
}
int hamA(DAYSO a)
{
	int flag = 0;
	int kq;
	for (int i = 0; i < a.n; i++)
		if (a.list[i] > 0)
			if (flag == 0) {
				kq = a.list[i];
				flag = 1;
			}
			else if (a.list[i] > kq)
				kq = a.list[i];

	return kq;
}
////bai1d
//int hamA(DAYSO a)
//{
//	int flag = 0;
//	int kq;
//	for (int i = 0; i < a.n; i++)
//		if (a.list[i] % 2 == 0) // Kiểm tra số chẵn
//			if (flag == 0) {
//				kq = a.list[i];
//				flag = 1;
//			}
//			else if (a.list[i] < kq) // So sánh và cập nhật số chẵn nhỏ nhất
//				kq = a.list[i];
//
//	return kq;
//}
////bai1e
//void BubbleSort(DAYSO &a)
//{
//	int i, j, x;
//	for (i = 0; i < a.n - 1; i++)
//		for (j = a.n - 1; j > i; j--)
//			if (a.list[j] > a.list[j - 1]) // Thay đổi dấu so sánh thành >
//			{
//				x = a.list[j];
//				a.list[j] = a.list[j - 1];
//				a.list[j - 1] = x;
//			}
//}
////bai2a
//int hamA(DAYSO a)
//{
// int flag = 0;
// int kq;
// for (int i = 0; i < a.n; i++)
//  if (a.list[i] % 3 == 0) // kiểm tra số chia hết cho 3
//   if (flag == 0) {
//    kq = a.list[i];
//    flag = 1;
//   }
//   else if (a.list[i] > kq)// so sánh và cập nhât số chia hết cho 3 lớn nhất 
//    kq = a.list[i];
//
// return kq;
//}
////bai2b 
//void tachDS(DAYSO a, int index, DAYSO &a1, DAYSO &a2)
//{
//	if (index < 0 || index >= a.n)
//	{
//		// Nếu index nằm ngoài phạm vi của dãy số a, không thực hiện tách dãy
//		a1.n = 0;
//		a2.n = 0;
//		return;
//	}
//
//	 //Tách dãy số a thành a1 và a2
//	a1.n = index + 1;
//	a2.n = a.n - a1.n;
//
//	for (int i = 0; i < a1.n; i++)
//		a1.list[i] = a.list[i];
//
//	for (int i = 0; i < a2.n; i++)
//		a2.list[i] = a.list[index + 1 + i];
//}
////3.a
//DAYSO ghepDS(DAYSO a, DAYSO b) {
//	DAYSO c;
//	c.n = a.n + b.n;
//
//	for (int i = 0; i < a.n; i++)
//		c.list[i] = a.list[i];
//
//	for (int i = 0; i < b.n; i++)
//		c.list[a.n + i] = b.list[i];
//
//	return c;
//}
//
////3.b
//void daoNguocDS(DAYSO &a) {
//	int left = 0;
//	int right = a.n - 1;
//
//	while (left < right) {
//		int temp = a.list[left];
//		a.list[left] = a.list[right];
//		a.list[right] = temp;
//
//		left++;
//		right--;
//	}
//}
////3.c
//void xoaPhanTuX(DAYSO &a, int x) {
//	int count = 0; // Số lượng phần tử cần xóa
//
//	for (int i = 0; i < a.n; i++) {
//		if (a.list[i] == x) {
//			count++;
//		}
//		else {
//			a.list[i - count] = a.list[i];
//		}
//	}
//
//	a.n -= count; // Giảm số phần tử của dãy
//}


void BubbleSort(DAYSO &a)
{
	int i, j, x;
	for (i = 0; i < a.n - 1; i++)
		for (j = a.n - 1; j > i; j--)
			if (a.list[j] < a.list[j - 1])
			{
				x = a.list[j];
				a.list[j] = a.list[j - 1];
				a.list[j - 1] = x;
			}
}
DAYSO tronDS(DAYSO a, DAYSO b)
{
	DAYSO c;
	int i = 0, j = 0, k = 0;
	c.n = a.n + b.n;
	while (i < a.n && j < b.n)
	{
		if (a.list[i] < b.list[j])
		{
			c.list[k] = a.list[i];
			i++;
		}
		else
		{
			c.list[k] = b.list[j];
			j++;
		}
		k++;
	}
	while (i < a.n)
	{
		c.list[k] = a.list[i];
		i++;
		k++;
	}
	while (j < b.n)
	{
		c.list[k] = b.list[j];
		j++;
		k++;
	}
	return c;
}
