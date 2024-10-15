using System;

namespace SoPhuc
{
    class Program
    {
        static void Main(string[] args)
        {
            CComplex sp1 = new CComplex(3, 4); // So phuc 3 + 4i
            CComplex sp2 = new CComplex(1, -2); // So phuc 1 - 2i

            // Cong 2 so phuc
            CComplex tong = sp1 + sp2;
            Console.WriteLine("Tong: " + tong.Print());

            // Tru 2 so phuc
            CComplex hieu = sp1 - sp2;
            Console.WriteLine("Hieu: " + hieu.Print());

            // Nhan 2 so phuc
            CComplex tich = sp1 * sp2;
            Console.WriteLine("Tich: " + tich.Print());

            // Chia 2 so phuc
            CComplex thuong = sp1 / sp2;
            Console.WriteLine("Thuong: " + thuong.Print());

            // So sanh bang va khac
            if (sp1 == sp2)
                Console.WriteLine("Hai so phuc bang nhau");
            else
                Console.WriteLine("Hai so phuc khac nhau");

            // Ep kieu tu int thanh so phuc
            CComplex spInt = 5;
            Console.WriteLine("So phuc tu int: " + spInt.Print());

            // Tang va giam so phuc
            sp1++;
            Console.WriteLine("So phuc sau khi tang: " + sp1.Print());
            sp2--;
            Console.WriteLine("So phuc sau khi giam: " + sp2.Print());

            Console.ReadLine();
        }
    }
}
