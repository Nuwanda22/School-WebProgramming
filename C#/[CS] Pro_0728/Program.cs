using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace _CS__Pro_0728
{
    //class Program
    //{
    //    static void Main(string[] args)
    //    {
    //        //Phone ob1 = new Phone();
    //        //Phone ob2 = new Phone("010 - 6974 - 1785");
    //        //Phone ob3 = new Phone("010 - 5877 - 4485", 100);

    //        //ob1.output();
    //        //ob2.output();
    //        //ob3.output();

    //        //ob3.input();
    //        //ob3.output();

    //        Mp3 ob4 = new Mp3();

    //        ob4.input1();
    //        ob4.play();

    //        ob4.input();
    //        ob4.output();
    //    }
    //}

    //public class Phone
    //{
    //    string number;
    //    int tonghwa_ryang;

    //    public Phone() 
    //    {
    //        number = "010 - 0000 -0000";
    //        tonghwa_ryang = 0;
    //    }

    //    public Phone(string number)
    //    {
    //        this.number = number;
    //        tonghwa_ryang = 0;
    //    }

    //    public Phone(string number, int tonghwa_ryang)
    //    {
    //        this.number = number;
    //        this.tonghwa_ryang = tonghwa_ryang;
    //    }

    //    public void input()
    //    {
    //        Console.Write("수신 전화번호 : ");
    //        number = Console.ReadLine();

    //        Console.Write("가능 통화량 : ");
    //        tonghwa_ryang = int.Parse(Console.ReadLine());
    //    }

    //    public void output()
    //    {
    //        Console.WriteLine("수신 전화 : " + number);
    //        Console.WriteLine("  통화량  : " + tonghwa_ryang);
    //    }
    //}

    //class Mp3 : Phone
    //{
    //    int track; string song_name; string singer;

    //    public void input1()
    //    {
    //        Console.Write("가수명 : ");
    //        singer = Console.ReadLine();
    //        Console.Write("노래제목 : ");
    //        song_name = Console.ReadLine();
    //        Console.Write("트랙 : ");
    //        track = int.Parse(Console.ReadLine());
    //    }

    //    public void play()
    //    {
    //        Console.WriteLine(track + "이(가) 재생됩니다.");
    //    }

    //    public void stop()
    //    {
    //        Console.WriteLine(track + "이(가) 정지됩니다.");
    //    }
    //}

    //class Smart : Mp3
    //{
    //    public void internet(string site)
    //    {
    //        Console.WriteLine(site + "에 접속합니다. ");
    //    }

    //    public void game(string game)
    //    {
    //        Console.WriteLine(game + "을(를) 시작합니다. ");
    //    }
    //}

    class Program
    {
        static void Main(string[] args)
        {
            string name, SN;
            int[] jumsu = new int[5];

            Console.Write("이름 : ");
            name = Console.ReadLine();
            Console.Write("학번 : ");
            SN = Console.ReadLine();
            Console.WriteLine("점수 3개를 입력하세요. ");
            int sum = 0;
            for(int i = 0; i<3; i++)
            {
                jumsu[i] = int.Parse(Console.ReadLine());
                sum = jumsu[i] + sum;
            }

            for (int i = 0; i < 3; i++)
            {
                Console.Write("  " + jumsu);
            }   Console.Write("  " + sum);

            int avg = sum / 3;
            Console.Write("  " + avg);
            
        }
    }
}
