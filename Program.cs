using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace bai1_thlthdt
{
    class Program
    {
        static void NhapMang(int[,] a, out int n)
        {
            Console.Write("Nhap n=: ");
            n = Convert.ToInt32(Console.ReadLine());
            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < n; j++)
                {
                    Console.Write($"Nhap a[{i}, {j}] = ");
                    a[i, j] = Convert.ToInt32(Console.ReadLine());
                }
            }
        }

        static void XuatMang(int[,] a, int n)
        {
            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < n; j++)
                {
                    Console.Write(a[i, j] + "\t");
                }
                Console.WriteLine();
            }
        }

        static int KTNT(int n)
        {
            if (n < 2) return 0;
            for (int i = 2; i <= n / 2; i++)
                if (n % i == 0) return 0;
            return 1;
        }
        static void XuatDuongCheoChinh(int[,] a, int n)
        {
            for (int i = 0; i < n; i++)
            {
                Console.Write(a[i, i] + "\t");
            }
            Console.WriteLine();
        }
        static void XuatSoNguyenTo(int[,] a, int n)
        {
            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < n; j++)
                {
                    if (KTNT(a[i, j]) == 1)
                    {
                        Console.Write(a[i, j] + "\t");
                    }
                }
            }
            Console.WriteLine();
        }
        static int TinhTongMang(int[,] a, int n)
        {
            int tong = 0;
            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < n; j++)
                {
                    tong += a[i, j];
                }
            }
            return tong;
        }
        static int TongDongK(int[,] a, int n, int k)
        {
            int tong = 0;
            for (int j = 0; j < n; j++)
            {
                tong += a[k, j];
            }
            return tong;
        }
        static int DemPhanTuAm(int[,] a, int n)
        {
            int dem = 0;
            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < n; j++)
                {
                    if (a[i, j] < 0)
                        dem++;
                }
            }
            return dem;
        }

        static int DemPhanTuDuong(int[,] a, int n)
        {
            int dem = 0;
            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < n; j++)
                {
                    if (a[i, j] > 0)
                        dem++;
                }
            }
            return dem;
        }
        static int DemSoLanXuatHien(int[,] a, int n, int x)
        {
            int dem = 0;
            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < n; j++)
                {
                    if (a[i, j] == x)
                        dem++;
                }
            }
            return dem;
        }
        static bool KiemTraSoHoanThien(int n)
        {
            int tong = 0;
            for (int i = 1; i <= n / 2; i++)
            {
                if (n % i == 0)
                    tong += i;
                if (n < 2)
                    return false;
            }
            return tong == n;
        }
        static void XuatSoHoanThien(int[,] a, int n)
        {
            bool coSoHoanThien = false;
            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < n; j++)
                {
                    if (KiemTraSoHoanThien(a[i, j]))
                    {
                        Console.Write(a[i, j] + "\t");
                        coSoHoanThien = true;
                    }
                }
            }
            if (!coSoHoanThien)
            {
                Console.WriteLine("Khong co so hoan thien trong ma tran.");
            }
            else
            {
                Console.WriteLine(); 
            }
        }

        static void TimViTriPhanTu(int[,] a, int n, int x)
        {
            bool timThay = false;
            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < n; j++)
                {
                    if (a[i, j] == x)
                    {
                        Console.WriteLine($"Phan tu {x} tai vi tri: ({i}, {j})");
                        timThay = true;
                    }
                }
            }
            if (!timThay)
            {
                Console.WriteLine("Khong tim thay phan tu trong ma tran.");
            }
        }

        static int DemPhanTuNhoHonX(int[,] a, int n, int x)
        {
            int dem = 0;
            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < n; j++)
                {
                    if (a[i, j] < x)
                        dem++;
                }
            }
            return dem;
        }

        static int TinhTongDongChan(int[,] a, int n)
        {
            int tong = 0;
            for (int i = 0; i < n; i += 2)  // Chỉ lấy các dòng chẵn
            {
                for (int j = 0; j < n; j++)
                {
                    tong += a[i, j];
                }
            }
            return tong;
        }

        static bool KiemTraMaTranDonVi(int[,] a, int n)
        {
            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < n; j++)
                {
                    if (i == j && a[i, j] != 1) return false;
                    if (i != j && a[i, j] != 0) return false;
                }
            }
            return true;
        }

        static bool KiemTraMaTranDoiXung(int[,] a, int n)
        {
            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < i; j++)
                {
                    if (a[i, j] != a[j, i]) return false;
                }
            }
            return true;
        }

        static int[,] CongHaiMaTran(int[,] a, int[,] b, int n)
        {
            int[,] c = new int[n, n];
            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < n; j++)
                {
                    c[i, j] = a[i, j] + b[i, j];
                }
            }
            return c;
        }

        static int[,] NhanHaiMaTran(int[,] a, int[,] b, int n)
        {
            int[,] c = new int[n, n];
            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < n; j++)
                {
                    c[i, j] = 0;
                    for (int k = 0; k < n; k++)
                    {
                        c[i, j] += a[i, k] * b[k, j];
                    }
                }
            }
            return c;
        }

        static void HoanDoiCheoChinhCheoPhu(int[,] a, int n)
        {
            for (int i = 0; i < n; i++)
            {
                int temp = a[i, i];
                a[i, i] = a[i, n - i - 1];
                a[i, n - i - 1] = temp;
            }
        }

        static void Main(string[] args)
        {
            const int MAX = 10;
            int n;
            int[,] a = new int[MAX, MAX];
            int[,] b = new int[MAX, MAX];

            // Nhập và xuất ma trận a
            NhapMang(a, out n);
            Console.WriteLine("Ma tran vua nhap:");
            XuatMang(a, n);

            // Xuất đường chéo chính của ma trận
            Console.WriteLine("Duong cheo chinh cua ma tran:");
            XuatDuongCheoChinh(a, n);

            // Xuất các số nguyên tố trong ma trận
            Console.WriteLine("Cac so nguyen to trong ma tran:");
            XuatSoNguyenTo(a, n);

            // Tính tổng các phần tử trong ma trận
            Console.WriteLine("Tong cac phan tu trong ma tran: " + TinhTongMang(a, n));

            // Nhập dòng k và tính tổng dòng k
            Console.Write("Nhap dong k de tinh tong: ");
            int k = Convert.ToInt32(Console.ReadLine());
            Console.WriteLine($"Tong dong {k}: {TongDongK(a, n, k)}");

            // Đếm các phần tử âm và dương
            Console.WriteLine("So phan tu am: " + DemPhanTuAm(a, n));
            Console.WriteLine("So phan tu duong: " + DemPhanTuDuong(a, n));

            // Đếm số lần xuất hiện của một giá trị x
            Console.Write("Nhap gia tri x de dem so lan xuat hien: ");
            int x = Convert.ToInt32(Console.ReadLine());
            Console.WriteLine($"So lan xuat hien cua {x}: {DemSoLanXuatHien(a, n, x)}");

            // Xuất các số hoàn thiện trong ma trận
            Console.WriteLine("Cac so hoan thien trong ma tran:");
            XuatSoHoanThien(a, n);

            // Tìm vị trí của một phần tử x
            Console.Write("Nhap gia tri can tim: ");
            x = Convert.ToInt32(Console.ReadLine());
            TimViTriPhanTu(a, n, x);

            // Đếm số phần tử nhỏ hơn x
            Console.WriteLine($"So phan tu nho hon {x}: {DemPhanTuNhoHonX(a, n, x)}");

            // Tính tổng các phần tử trên dòng chẵn
            Console.WriteLine("Tong cac phan tu nam o dong chan: " + TinhTongDongChan(a, n));

            // Kiểm tra ma trận đơn vị
            Console.WriteLine(KiemTraMaTranDonVi(a, n) ? "Ma tran don vi" : "Khong phai ma tran don vi");

            // Kiểm tra ma trận đối xứng
            Console.WriteLine(KiemTraMaTranDoiXung(a, n) ? "Ma tran doi xung" : "Khong phai ma tran doi xung");

            // Nhập ma trận b để thực hiện phép cộng và nhân
            Console.WriteLine("Nhap ma tran thu 2:");
            NhapMang(b, out _);

            // Cộng hai ma trận
            Console.WriteLine("Tong hai ma tran:");
            int[,] tong = CongHaiMaTran(a, b, n);
            XuatMang(tong, n);

            // Nhân hai ma trận
            Console.WriteLine("Tich hai ma tran:");
            int[,] tich = NhanHaiMaTran(a, b, n);
            XuatMang(tich, n);

            // Hoán đổi đường chéo chính và phụ
            HoanDoiCheoChinhCheoPhu(a, n);
            Console.WriteLine("Ma tran sau khi hoan doi duong cheo chinh va duong cheo phu:");
            XuatMang(a, n);

            Console.ReadKey();
        }
    }
}
