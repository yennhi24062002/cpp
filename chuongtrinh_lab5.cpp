#include "thuvien_lab5.h"
void main()
{
    Nodeptr dssv;
    nhap_DSSV(dssv);
    xuat_DSSV(dssv);

    xoa_Dau(dssv);
    xuat_DSSV(dssv);

    xoa_Cuoi(dssv);
    xuat_DSSV(dssv);


    char* masv;
    cout<<"nhap ma sv can tim: \n";
    cin.getline(masv, 10);
    tim_Sv_Masv(dssv,masv);

    cout<<"xoa sv duoi 5\n";
    xoa_Sv_diem_be_5(dssv);
    xuat_DSSV(dssv);

    cout<<" dao danh sach:\n";
    reverseList_Sv(dssv);
    xuat_DSSV(dssv);
    

    cout<<"chia ds\n";
    splitList_Sv(dssv);

    cout<<"sap xep\n";
    sortList(dssv);
    xuat_DSSV(dssv);

    giaiPhong(dssv);
    system("pause");
}