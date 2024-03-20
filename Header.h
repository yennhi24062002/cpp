#pragma once
#include <iostream>
using namespace std;
typedef int TYPEINFO;
struct Node
{
	TYPEINFO data;
	Node* left;
	Node* right;
};
typedef Node* Nodeptr;
typedef Nodeptr BST_TREE;

void init(Nodeptr& root);
Node* TaoNode(int x);
void NhapCay(Nodeptr& root);
void ThemNodeVaoCay(Nodeptr& root, int x);
Node* TimNode(Nodeptr root, int x);
void NodeTheMang(Nodeptr& X, Nodeptr& Y);
void XoaNode(Nodeptr& root, int x);
int DemSoNode(Nodeptr root);
char KiemTraNodeLa(Nodeptr p);
int DemNodeLa(Nodeptr root);
int Max(int a, int b);
int TinhChieuCaoCay(Nodeptr root);
void NLR(Node* Root);
void LNR(Node* Root);
void LRN(Node* Root);
int TinhTong(Nodeptr root);
void TachCay(Nodeptr root, Nodeptr& cayChan, Nodeptr& cayLe);