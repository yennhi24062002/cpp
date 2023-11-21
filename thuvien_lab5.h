#define CRT SECURE NO WARNINGS
#include <iostream>
#include <iomanip>
#include "string.h"
#include <cstring>
using namespace std;
typedef struct Node *Nodeptr;
struct SinhVien
{
    char masv[10];
    char tensv[30];
    float diem;
    float toan,ly,hoa;
};
struct Node
{
    SinhVien data;
    Nodeptr link;
};
void khoiTao(Nodeptr &list);
int isEmpty(Nodeptr list);
void giaiPhong(Nodeptr &list);
Nodeptr tao_Node_SinhVien(SinhVien x);
Nodeptr them_Dau(Nodeptr &list, SinhVien x);
bool kiemTra_TrungMa(Nodeptr &list, char *ma);
void nhap_DSSV(Nodeptr &list);
void xuat_DSSV(Nodeptr list);
void tim_Sv_Masv(Nodeptr list, char* masv);
void xoa_Cuoi(Nodeptr &list);
void xoa_Dau(Nodeptr &list);
void xoa_Sv_diem_be_5(Nodeptr &list);
void reverseList_Sv(Nodeptr &list);
void splitList_Sv(Nodeptr &list);
void sortList(Nodeptr &list);
int tinh_TB(SinhVien a);




