using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace TEST
{
    class F
    {
        public void g()
        {
            Console.WriteLine("Hello, World");
        }
    }

    class Program
    {
        static void Main(string[] args)
        {
            F f = new F();

            f.g();
        }
    }
}
