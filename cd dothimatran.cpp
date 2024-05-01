#include "thuviendothimatran.h"
void printVertex(VERTEX v) {
	cout << v;
}

void printEdge(EDGE e) {
	cout << "(" << e.org << "," << e.des << ")";
}

void printArrayVertex(ArrayVertex av) {
	for (int i = 0; i < av.count; i++)
	{
		cout << "\t";
		printVertex(av.ds[i]);
	}
}

void printArrayEdge(ArrayEdge ae) {
	for (int i = 0; i < ae.count; i++)
	{
		cout << "\t";
		printEdge(ae.ds[i]);
	}
}

int Read(const char* filename, AdjacencyMatrix& g)
{
	FILE* f;
	fopen_s(&f, filename, "rt");
	if (f == NULL) return 0;
	fscanf_s(f, "%d", &g.n);
	for (int i = 0; i < g.n; i++)
		for (int j = 0; j < g.n; j++)
			fscanf_s(f, "%d", &g.mt[i][j]);

	fclose(f);
	return 1;
}


int Write(const char* filename, AdjacencyMatrix g)
{
	FILE* f;
	fopen_s(&f, filename, "wt");
	if (f == NULL) return 0;
	fprintf(f, "%d", g.n);
	for (int i = 0; i < g.n; i++)
	{
		fprintf(f, "\n");
		for (int j = 0; j < g.n; j++)
			fprintf(f, "%d\t", g.mt[i][j]);
	}
}


void Xuat(AdjacencyMatrix g)
{
	cout << "\n Gia tri trong file la: ";
	cout << "\n" << g.n << "\n";
	for (int i = 0; i < g.n; i++)
	{
		for (int j = 0; j < g.n; j++)
			cout << g.mt[i][j] << " ";
		cout << "\n";
	}
}

int TinhBacVaoDTCoHuong(AdjacencyMatrix g, int dinh)
{
	int dem = 0;
	for (int i = 0; i < g.n; i++)
	{
		if (g.mt[i][dinh] != 0)
			dem++;
	}
	return dem;
}

ArrayEdge TapCanhDTCH(AdjacencyMatrix g)
{
	ArrayEdge tapcanh;
	tapcanh.count = 0;
	for (int i = 0; i < g.n; i++)
		for (int j = 0; j < g.n; j++)
			if (g.mt[i][j] != 0)
			{
				EDGE e;
				e.org = i;
				e.des = j;
				e.wei = g.mt[i][j];
				tapcanh.ds[tapcanh.count] = e;
				tapcanh.count++;
			}
	return tapcanh;
}