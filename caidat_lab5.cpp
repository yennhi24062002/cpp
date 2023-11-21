#include "thuvien_lab5.h"
void khoiTao(Nodeptr &list)
{
    list = NULL;
}
int isEmpty(Nodeptr list)
{
    return list == NULL ? 1 : 0;
}
void giaiPhong(Nodeptr &list)
{
    Nodeptr p = list;
    while (p != NULL)
    {
        list = list->link;
        delete p;
    }
    p = list;
}
Nodeptr tao_Node_Sv(SinhVien x)
{
    Nodeptr p;
    p = new Node;
    p->data = x;
    p->link = NULL;
    return p;
}
// Ham Them 1 sinh vien
Nodeptr them_Dau(Nodeptr &list, SinhVien x)
{
    Nodeptr p = tao_Node_Sv(x);
    p->link = list;
    list = p;
    return p;
}
bool kiemTra_TrungMa(Nodeptr &list, char *ma)
{
    Nodeptr p = list;
    while (p != NULL)
    {
        if (strcmp(p->data.masv, ma) == 0)
            return true;
        p = p->link;
    }
    return false;
}
// Nhap DSSV
void nhap_DSSV(Nodeptr &list)
{
    // khoiTao(list);
    ////char x[10];
    SinhVien sv;
    khoiTao(list);
    do
    {
        cout << "\n Nhap MaSV (NHAPO DE THOAT):";
        cin.getline(sv.masv, 10);
        while (kiemTra_TrungMa(list, sv.masv))
        {
            cout << "\n Ma so sv bi trung";
            cout << "\n Nhap lai ma so sv:";
            cin.getline(sv.masv, 10);
        }
        if (strcmp(sv.masv, "0") == 0) // NHAP MA SO = 0 DE THOAT
            break;
        cout << "\n Nhap Ten SV:";
        cin.getline(sv.tensv, 30);
        cout << "\n Nhap Diem SV:";
        cin >> sv.diem;
        cout << "\n Nhap Diem toan SV:";
        cin >> sv.toan;
        cout << "\n Nhap Diem ly SV:";
        cin >> sv.ly;
        cout << "\n Nhap Diem hoa SV:";
        cin >> sv.hoa;
        cin.ignore();
        them_Dau(list, sv);
    } while (1);
}
void xuat_DSSV(Nodeptr list)
{
    cout << setw(0) << "MASV" << setw(15) << "TEN SV" << setw(20) << "Diem" << setw(5) << "Toan"<< setw(5) << "Ly"<< setw(5) << "Hoa"<< endl;
    while (list != NULL)
    {
        cout << setw(0) << list->data.masv << setw(15) << list->data.tensv << setw(20) 
        << list->data.diem << setw(5) << list->data.toan<< setw(5) << list->data.ly<< setw(5) << list->data.hoa<< endl;
        list = list->link;
    }
}

void tim_Sv_Masv(Nodeptr list, char *masv)
{
    Nodeptr p = list;
    while (p != NULL)
    {
        if (strcmp(p->data.masv, masv))
        {
            cout << "Co sinh vien: ";
            cout << setw(0) << list->data.masv << setw(15) << list->data.tensv << setw(20) << list->data.diem << endl;
            return;
        }
        p = p->link;
    }
    cout << "khong tim thay";
}
void xoa_Dau(Nodeptr &list)
{
    Nodeptr p;
    if (list != NULL)
    {
        p = list;
        list = p->link;
        delete p;
    }
}
void xoa_Cuoi(Nodeptr &list)
{
    Nodeptr p = list;
    Nodeptr q;
    while (p->link != NULL)
    {
        q = p;
        p = p->link;
    }
    q->link = NULL;
    delete p;
}
void xoa_Sv_Masv(Nodeptr &list, SinhVien sv)
{
    if (strcmp(list->data.masv, sv.masv) == 0)
    {
        Nodeptr p = list;
        list = list->link;
        delete p;
    }
    else
    {
        Nodeptr p, before;
        p = list;
        before = list;
        while (p != NULL && strcmp(p->data.masv, sv.masv) != 0)
        {
            before = p;
            p = p->link;
            if (p != NULL)
            {
                before->link = p->link;
                delete p;
            }
        }
    }
}
void xoa_Sv_diem_be_5(Nodeptr &list)
{
    Nodeptr p = list;
    Nodeptr q;
    while (p != NULL)
    {
        q = p;
        if (p->data.diem < 5)
        {
            q->link = p->link;
            delete p;
            p = q;
        }

        p = p->link;
    }
}
void reverseList_Sv(Nodeptr &list)
{
    Nodeptr current = list;
    Nodeptr prev = NULL;
    Nodeptr link = NULL;

    while (current != NULL)
    {
        link = current->link;
        current->link = prev;
        prev = current;
        current = link;
    }
    list = prev;
}

void splitList_Sv(Nodeptr &list)
{
    Nodeptr lonHon5, beHon5;
    Nodeptr a, b;

    Nodeptr current = list;
    while (current != NULL)
    {
        if (current->data.diem > 5)
        {
            if (lonHon5 == NULL)
            {
                lonHon5 = current;
                a = lonHon5;
            }
            else
            {
                a->link = current;
                a = current;
            }
        }
        else
        {
            if (beHon5 == NULL)
            {
                beHon5 = current;
                b = beHon5;
            }
            else
            {
                b->link = current;
                b = current;
            }
        }
    }
    cout << "danh sach lon hon 5: \n";
    xuat_DSSV(lonHon5);

    cout << "danh sach be hon 5: \n";
    xuat_DSSV(beHon5);
}
int tinh_TB(SinhVien a)
{
    return (a.toan + a.hoa + a.ly) / 3;
}
void sortList(Nodeptr &list)
{
    Nodeptr prev = list;
    Nodeptr curr = list->link;

    while (curr != NULL)
    {
        if (tinh_TB(curr->data) < tinh_TB(prev->data))
        {
            prev->link = curr->link;

            curr->link = list;
            list = curr;

            curr = prev;
        }

        else
            prev = curr;

        curr = curr->link;
    }
}