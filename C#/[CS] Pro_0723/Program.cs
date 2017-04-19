using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace _CS__Pro_0723
{
    class Program
    {
        /*
        // 계산기 메소드
        public static int calculator(int a, char ch, int b)
        {
            switch (ch)
            {
                case '+':
                    return (a + b);
                case '-':
                    return a - b;
                case '*':
                    return a * b;
                case '/':
                    return a / b;
                default:
                    return -1;
            }
        }

        static void Main(string[] args)
        {
            Console.WriteLine(calculator(1, '+' , 2));
        }
        */
        /*
        //넓이 구하기 메소드 오버로딩

        //원의 넓이
        static double area(int r)
        {
            double area;
            area = r * r * 3.14;

            return area;
        }

        //사각형 넓이
        static int area(int w, int h)
        {
            int area;
            area = w * h;

            return area;
        }

        //삼각형 넓이
        static double _area(int w, int h)
        {
            double area;
            area = w * h / 2.0;

            return area;
        }

        //구의 부피
        static double volume(int r)
        {
            double voulume;
            voulume = (4 / 3.0) * 3.14 * r * r * r;

            return voulume;
        }

        static void Main(string[] args)
        {
            Console.WriteLine(area(10));
            Console.WriteLine(area(10, 10));
            Console.WriteLine(_area(10, 10));
            Console.WriteLine(volume(10));
        }
        */

        static void swap(int x, int y)
        {
            Console.WriteLine("before swap : X = " + x + " Y = " + y);
            
            int temp = x;
            x = y;
            y = temp;

            Console.WriteLine("after swap : X = " + x + " Y = " + y);
        }

        static void earth_from_the_sun()
        {
            const int v = 30;    // 만 km/s
            const int d = 14960; // 만 km
            int t = v * d; // 초

            int hour, min, sec;

            hour = t / 3600;
            min = (t % 3600) / 60;
            sec = ((t % 3600) % 60) / 60;

            Console.WriteLine(hour + "시간 " + min + "분 " + sec + "초");
        }

        static void Main(string[] args)
        {
            swap(10, 20);
            earth_from_the_sun();
        }
    }
}
