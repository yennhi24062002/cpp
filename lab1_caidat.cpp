#include "lab1_thuvien.h"
//void giaiPTB1(int a, int b, double &x)
//{
//	x =1.0* -b / a;
//}
void giaiPTB1(int a, int b, double& x)
{
	if (a != 0) {
		x = 1.0*-b /(a);
	}
	else {
		cout << "Khong chia cho so 0" << endl;
	}
}
//
//double tinh2MuN(int n)
//{
//	double s = 1;
//	for (int i = 1; i <= n; i++)
//		s *= 2;
//	return s;
//}
//
//double tinh2MuN(int n)
//{
//	double s = 1;
//	int i = 0;
//	while (i < n) {
//		s *= 2;
//		i++;
//	}
//	return s;
//}
double tinh2MuN(int n)
{
	double s = 1;
	if (n >= 0) {
		for (int i = 0; i < n; i++) {
			s *= 2;
		}
	}
	else {
		for (int i = 0; i > n; i--) {
			s /= 2;
		}
	}
	return s;
}
int giaiPTB2(int a, int b, int c, double& x1, double& x2)
{
	if (a == 0) {
		if (b == 0) {
			if (c == 0) {
				return 3; // Phương trình vô số nghiệm
			}
			else {
				return 0; // Phương trình vô nghiệm
			}
		}
		else {
			x1 = 1.0 *-c /(b);
			return 1; // Phương trình có 1 nghiệm
		}
	}
	else {
		int delta = b * b - 4 * a * c;
		if (delta > 0) {
			x1 = (-b + sqrt(delta)) / (2 * a);
			x2 = (-b - sqrt(delta)) / (2 * a);
			return 2; // Phương trình có 2 nghiệm
		}
		else if (delta == 0) {
			x1 = -b / (2 * a);
			return 1; // Phương trình có 1 nghiệm
		}
		else {
			return 0; // Phương trình vô nghiệm
		}
	}
}
double tinhMu(int x, int y)
{
	return pow(x, y);
}