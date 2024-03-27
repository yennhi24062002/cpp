#include <iostream>
using namespace std;
typedef int TYPEINFO;
typedef struct NODEAVL {
	TYPEINFO info;
	struct NODEAVL *left;
	struct NODEAVL *right;
	int height;
};
typedef NODEAVL* AVLTREE;
void init(AVLTREE &T); //ham khoi tao cay AVL
AVLTREE CreateNodeAVL(int info); // tao 1 NODEAVL moi 
void NLR(AVLTREE T); //duyet NLR
void LNR(AVLTREE T); //duyet LNR
void LRN(AVLTREE T); //duyet LRN
int Max(int a, int b); // ham tim gia tri lon nhat trong 2 so
int height(AVLTREE T);
int getCB(AVLTREE T); // ham tra ve height_left - height_right
void RotateRight(AVLTREE &T); // quay phai tai NODEAVL T
void RotateLeft(AVLTREE &T); // quay trai tai NODEAVL T
void RotateRightLeft(AVLTREE &T); //quay kep RL
void RotateLeftRight(AVLTREE &T); // quay kep LR
AVLTREE search(AVLTREE T, int x); //tim NODEAVL co gia tri x
AVLTREE minValueNODEAVL(AVLTREE T);
AVLTREE InsertNode(AVLTREE &T, int x); // chen khoa x vao cay
int DeleteNode(AVLTREE &T, int x);
void InMenu(int &chon);
int demKhoaLe(AVLTREE T);
bool KTSNT(int n);
void xuatCacKhoaLaSNT(AVLTREE T);
int tongCacKhoaLaSNT(AVLTREE T);
void cacKhoaLaBoiCuaSoNguyenX(AVLTREE T, int X);