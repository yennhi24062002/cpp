#pragma once
#include <iostream>
using namespace std;
const int MAXV = 20;
const int MAXE = MAXV * MAXV;
typedef int VERTEX;
struct EDGE
{
	VERTEX org; //Origin
	VERTEX des; //Destination
	int wei; //weight
};
struct ArrayVertex
{
	VERTEX ds[MAXV];
	int count;
};
struct ArrayEdge
{
	EDGE ds[MAXE];
	int count;
};
struct AdjacencyMatrix
{
	int mt[MAXV][MAXV];
	int n;
};
void printVertex(VERTEX v);
void printEdge(EDGE e);
void printArrayVertex(ArrayVertex av);
void printArrayEdge(ArrayEdge ae);
int Read(const char* filename, AdjacencyMatrix& g);
int Write(const char* filename, AdjacencyMatrix g);
void Xuat(AdjacencyMatrix g);
int TinhBacVaoDTCoHuong(AdjacencyMatrix g, int dinh);
ArrayEdge TapCanhDTCH(AdjacencyMatrix g);