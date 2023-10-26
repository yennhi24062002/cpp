#include <iostream>
using namespace std;
const int MAX = 50;
struct DAYSO
{
	int list[MAX];
	int n;
};
void nhapDS(DAYSO &a);
void xuatDS(DAYSO a);
int timMin(DAYSO a);
int hamA(DAYSO a);
void BubbleSort(DAYSO &a);
DAYSO tronDS(DAYSO a, DAYSO b);
void tachDS(DAYSO a, int index, DAYSO &a1, DAYSO &a2);
DAYSO ghepDS(DAYSO a, DAYSO b);
void daoNguocDS(DAYSO &a);
void xoaPhanTuX(DAYSO &a, int x);
