using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace hinhchunhat
{
    internal class Program
    {
        static void Main(string[] args)
        {
            hinhchunhat hcn= new hinhchunhat();
            hcn.Nhap();
            hcn.Xuat();
            
            float chuVi=hcn.TinhChuVi();
            float dienTich=hcn.TinhDienTich();

            Console.WriteLine("Chu vi la:" + chuVi);
            Console.WriteLine("Dien tich la:" + dienTich);
            Console.ReadLine();
        }
    }
}
