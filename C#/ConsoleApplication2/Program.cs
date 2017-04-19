using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.IO;

namespace ConsoleApplication2
{
    class Program
    {
        static void Main(string[] args)
        {
            StreamReader sr = new StreamReader(@"C:\Users\전성우\Desktop\a.txt", Encoding.Default);
            StreamWriter sw = new StreamWriter(@"C:\Users\전성우\Desktop\b.txt");
            int a = 1;
            int i = 0;
            string[] name = sr.ReadLine().Split(' ');
            for (i = 0; i < 9; i++)
            {
                sw.WriteLine("|-\r\n|0" + (a++) + "\r\n|[[" + name[i] + "]]");
                sw.WriteLine("|[[" + name[i + 21] + "]]");
                sw.WriteLine("|[[" + name[i + 41] + "]]");
                sw.WriteLine("|[[" + name[i + 61] + "]]");
            }
            for (i = 9; i < 20; i++)
            {
                sw.WriteLine("|-\r\n|" + (a++) + "\r\n|[[" + name[i] + "]]");
                sw.WriteLine("|[[" + name[i + 21] + "]]");
                sw.WriteLine("|[[" + name[i + 41] + "]]");
                sw.WriteLine("|[[" + name[i + 61] + "]]");
            }
            sr.Close();
            sw.Close();

        }
    }
}
