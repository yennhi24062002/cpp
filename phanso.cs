using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace phanso
{
    internal class phanso
    {
        private int tuSo;
        private int mauSo;

        public phanso()
        {
            this.tuSo = 0;
            this.mauSo = 1;
        }
        public phanso(int tuSo, int mauSo)
        {
            this.tuSo = tuSo;
            this.mauSo = mauSo;
            if (this.mauSo == 0)
            {
                throw new ArgumentException("Mau so khong the bang 0");
            }
        }

        public int TuSo
        {
            get { return this.tuSo; }
            set { this.tuSo = value; }
        }

        public int MauSo
        {
            get { return this.mauSo; }
            set
            {
                if (value == 0)
                {
                    throw new ArgumentException("Mau so khong the bang 0");
                }
                this.mauSo = value;
            }
        }

        public void Nhap()
        {
            Console.Write("Nhap tu so: ");
            this.tuSo = int.Parse(Console.ReadLine());
            Console.Write("Nhap mau so: ");
            this.mauSo = int.Parse(Console.ReadLine());
            if (this.mauSo == 0)
            {
                throw new ArgumentException("Mau so khong the bang 0");
            }
        }

        public string Xuat()
        {
            return this.tuSo + "/" + this.mauSo;
        }

        public phanso cong(phanso ps2)
        {
            phanso tong = new phanso();
            tong.tuSo = this.tuSo * ps2.mauSo + this.mauSo * ps2.tuSo;
            tong.mauSo = this.mauSo * ps2.mauSo;
            return tong.RutGon();
        }

        public phanso tru(phanso ps2)
        {
            phanso hieu = new phanso();
            hieu.tuSo = this.tuSo * ps2.mauSo - this.mauSo * ps2.tuSo;
            hieu.mauSo = this.mauSo * ps2.mauSo;
            return hieu.RutGon();
        }

        public phanso nhan(phanso ps2)
        {
            phanso tich = new phanso();
            tich.tuSo = this.tuSo * ps2.tuSo;
            tich.mauSo = this.mauSo * ps2.mauSo;
            return tich.RutGon();
        }

        public phanso chia(phanso ps2)
        {
            phanso thuong = new phanso();
            thuong.tuSo = this.tuSo * ps2.mauSo;
            thuong.mauSo = this.mauSo * ps2.tuSo;
            return thuong.RutGon();
        }

        public phanso RutGon()
        {
            int ucln = UCLN(this.tuSo, this.mauSo);
            this.tuSo /= ucln;
            this.mauSo /= ucln;
            return this;
        }

        private int UCLN(int a, int b)
        {
            if (b == 0) return a;
            return UCLN(b, a % b);
        }

        public static bool operator >(phanso ps1, phanso ps2)
        {
            return ps1.tuSo * ps2.mauSo > ps2.tuSo * ps1.mauSo;
        }

        public static bool operator <(phanso ps1, phanso ps2)
        {
            return ps1.tuSo * ps2.mauSo < ps2.tuSo * ps1.mauSo;
        }

        public static phanso operator +(phanso ps1, phanso ps2)
        {
            return ps1.cong(ps2);
        }

        public static phanso operator -(phanso ps1, phanso ps2)
        {
            return ps1.tru(ps2);
        }

        public static phanso operator *(phanso ps1, phanso ps2)
        {
            return ps1.nhan(ps2);
        }

        public static phanso operator /(phanso ps1, phanso ps2)
        {
            return ps1.chia(ps2);
        }
    }
}
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace phanso
{
    internal class Program
    {
        static void Main(string[] args)
        {
            phanso ps1 = new phanso(1, 2);
            phanso ps2 = new phanso(3, 4);

            // Cong hai phan so
            phanso tong = ps1 + ps2;
            Console.WriteLine("Tong la: " + tong.Xuat());

            // Tru hai phan so
            phanso hieu = ps1 - ps2;
            Console.WriteLine("Hieu la: " + hieu.Xuat());

            // Nhan hai phan so
            phanso tich = ps1 * ps2;
            Console.WriteLine("Tich la: " + tich.Xuat());

            // Chia hai phan so
            phanso thuong = ps1 / ps2;
            Console.WriteLine("Thuong la: " + thuong.Xuat());

            // So sanh hai phan so
            if (ps1 > ps2)
                Console.WriteLine("Phan so 1 > Phan so 2");
            else
                Console.WriteLine("Phan so 1 < Phan so 2");

            Console.ReadLine();
        }
    }
}

