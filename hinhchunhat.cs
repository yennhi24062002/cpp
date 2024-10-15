using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace hinhchunhat
{
    internal class hinhchunhat
    {
        private float chieuDai;
        private float chieuRong;

        public hinhchunhat()
        {

        }
        public hinhchunhat(float chieuDai, float cheuRong)
        {
            this.chieuDai = chieuDai;
            this.chieuRong = cheuRong;
        }
        public float ChieuDai
        {
            get { return chieuDai; }
            set { chieuDai = value; }
        }
        public float ChieuRong
        {
            get { return chieuRong; }
            set { chieuRong = value; }
        }
        public void Nhap()
        {
            Console.Write("Nhap chieu dai:");
            this.chieuDai=float.Parse(Console.ReadLine());
            Console.Write("Nhap chieu rong:");
            this.chieuRong=float.Parse(Console.ReadLine());
        }
        public void Xuat()
        {
            Console.WriteLine("Chieu dai:" + this.chieuDai);
            Console.WriteLine("Chieu rong:" + this.chieuRong);
        }
        public float TinhChuVi()
        {
            return (this.chieuDai + this.chieuRong) * 2 ;
        }
        public float TinhDienTich()
        {
            return (this.chieuDai * this.chieuRong);
        }
    }
}
