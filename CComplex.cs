using System;

namespace SoPhuc
{
    class CComplex
    {
        private double phanThuc;
        private double phanAo;

        // Ham tao khong tham so
        public CComplex()
        {
            this.phanThuc = 0;
            this.phanAo = 0;
        }

        // Ham tao co 2 tham so dau vao
        public CComplex(double phanThuc, double phanAo)
        {
            this.phanThuc = phanThuc;
            this.phanAo = phanAo;
        }

        // Phuong thuc cap nhat
        public void DatPhanThuc(double phanThuc)
        {
            this.phanThuc = phanThuc;
        }

        public void DatPhanAo(double phanAo)
        {
            this.phanAo = phanAo;
        }

        public void DatSoPhuc(double phanThuc, double phanAo)
        {
            this.phanThuc = phanThuc;
            this.phanAo = phanAo;
        }

        public double LayPhanThuc()
        {
            return this.phanThuc;
        }

        public double LayPhanAo()
        {
            return this.phanAo;
        }

        // Phuong thuc Norm tra ve modul cua so phuc
        public double Norm()
        {
            return Math.Sqrt(this.phanThuc * this.phanThuc + this.phanAo * this.phanAo);
        }

        // Phuong thuc Print dung de xuat so phuc ra mot chuoi
        public string Print()
        {
            return $"{this.phanThuc} + {this.phanAo}i";
        }

        // Toan tu cong 2 so phuc
        public static CComplex operator +(CComplex sp1, CComplex sp2)
        {
            return new CComplex(sp1.phanThuc + sp2.phanThuc, sp1.phanAo + sp2.phanAo);
        }

        // Toan tu tru 2 so phuc
        public static CComplex operator -(CComplex sp1, CComplex sp2)
        {
            return new CComplex(sp1.phanThuc - sp2.phanThuc, sp1.phanAo - sp2.phanAo);
        }

        // Toan tu nhan 2 so phuc
        public static CComplex operator *(CComplex sp1, CComplex sp2)
        {
            double thuc = sp1.phanThuc * sp2.phanThuc - sp1.phanAo * sp2.phanAo;
            double ao = sp1.phanThuc * sp2.phanAo + sp1.phanAo * sp2.phanThuc;
            return new CComplex(thuc, ao);
        }

        // Toan tu chia 2 so phuc
        public static CComplex operator /(CComplex sp1, CComplex sp2)
        {
            double mau = sp2.phanThuc * sp2.phanThuc + sp2.phanAo * sp2.phanAo;
            double thuc = (sp1.phanThuc * sp2.phanThuc + sp1.phanAo * sp2.phanAo) / mau;
            double ao = (sp1.phanAo * sp2.phanThuc - sp1.phanThuc * sp2.phanAo) / mau;
            return new CComplex(thuc, ao);
        }

        // Toan tu so sanh bang 2 so phuc
        public static bool operator ==(CComplex sp1, CComplex sp2)
        {
            return sp1.phanThuc == sp2.phanThuc && sp1.phanAo == sp2.phanAo;
        }

        // Toan tu so sanh khac 2 so phuc
        public static bool operator !=(CComplex sp1, CComplex sp2)
        {
            return !(sp1 == sp2);
        }

        // Toan tu ep kieu tu int thanh so phuc
        public static implicit operator CComplex(int x)
        {
            return new CComplex(x, 0);
        }

        // Toan tu ep kieu tu float thanh so phuc
        public static implicit operator CComplex(float x)
        {
            return new CComplex((double)x, 0);
        }

        // Toan tu ep kieu nguoc lai tu so phuc thanh int (chi lay phan thuc)
        public static explicit operator int(CComplex sp)
        {
            return (int)sp.phanThuc;
        }

        // Toan tu ep kieu nguoc lai tu so phuc thanh float (chi lay phan thuc)
        public static explicit operator float(CComplex sp)
        {
            return (float)sp.phanThuc;
        }

        // Toan tu tang 1 so phuc (tang phan thuc 1 don vi)
        public static CComplex operator ++(CComplex sp)
        {
            sp.phanThuc += 1;
            return sp;
        }

        // Toan tu giam 1 so phuc (giam phan thuc 1 don vi)
        public static CComplex operator --(CComplex sp)
        {
            sp.phanThuc -= 1;
            return sp;
        }

        // Ghi de ham Equals va GetHashCode (khi su dung == hoac !=)
        public override bool Equals(object obj)
        {
            if (obj is CComplex)
            {
                CComplex other = (CComplex)obj;
                return this == other;
            }
            return false;
        }

        public override int GetHashCode()
        {
            return this.phanThuc.GetHashCode() ^ this.phanAo.GetHashCode();
        }
    }
}
