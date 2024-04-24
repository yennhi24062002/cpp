#pragma once
#include <iostream>
using namespace std;
const int MAX = 100;
typedef int TYPEINFO;
struct Node
{
	TYPEINFO info;
	Node* link;
};
typedef Node* NODE_PTR;
struct OpenHashTable
{
	Node* ds[MAX];
	int n;
};
int funcHash(TYPEINFO a, int n);
void initht(OpenHashTable& ht);
Node* create_Node(TYPEINFO a);
int themds(Node*& list, TYPEINFO a);
void xuatds(Node* list);
int timds(Node* list, TYPEINFO a);
int xoads(Node*& list, TYPEINFO a);
int demds(Node* plist);
void Nhapht(OpenHashTable& ht);
int themht(OpenHashTable& ht, TYPEINFO a);
void xuatht(OpenHashTable ht);
int xoaht(OpenHashTable& ht, TYPEINFO a);
int timht(OpenHashTable ht, TYPEINFO a);
int demht(OpenHashTable ht);
int ghifile(char* tenfile, OpenHashTable ht);
int docfile(char* tenfile, OpenHashTable& ht);
int timMaxht(OpenHashTable ht);
int tonght(OpenHashTable ht);
void sapxepds(Node*& list);
void sapxepht(OpenHashTable& ht);
void xuatDanhsachlonnhat(OpenHashTable ht);
int timMaxChan(OpenHashTable ht);
void xuatsnt(OpenHashTable ht);
bool ktsnt(int n);
