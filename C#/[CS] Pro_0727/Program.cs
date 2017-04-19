using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace _CS__Pro_0727
{
    class Program
    {
        static void Main(string[] args)
        {
            Person ju = new Person("주민수", 17, "042 - 123 - 4567", "대전 동구 용운동");
            ju.prn();
            ju.wake();

            Student cho = new Student("조익현");
            cho.prn();
            cho.wake();
            cho.toilet();
        }
    }

    public class Person
    {
        //구성요소
        public string name;
        public int age;
        public string address;
        public string tel;

        //생성자 - 객체 선언시 초기화하는 특별한 메소드
        public Person()
        {
            name = "나방";
            age = 17;
            tel = "043 - 123 - 4567";
            address = "충청북도 청주시 청원구 내덕동 롯데삼성아파트 E동 504호";
        }
        
        public Person(string name)
        {
            this.name = name;
        }

        public Person(string name, int age)
        {
            this.name = name;
            this.age = age;
        }

        public Person(string name, int age, string tel)
        {
            this.name = name;
            this.age = age;
            this.tel = tel;
        }

        public Person(string name, int age, string tel, string address)
        {
            this.name = name;
            this.age = age;
            this.tel = tel;
            this.address = address;
        }


        //메소드
        public void prn()
        {
            Console.WriteLine("이름 : " + name);
            Console.WriteLine("나이 : " + age);
            Console.WriteLine("번호 : " + tel);
            Console.WriteLine("주소 : " + address);
        }

        public void eat()
        {
            Console.WriteLine("먹는다!");
        }

        public void toilet()
        {
            Console.WriteLine("싼다!");
        }

        public void sleep()
        {
            Console.WriteLine("잔다!");
        }

        public void wake()
        {
            Console.WriteLine("일어난다!");
        }
    }

    class Student:Person
    {
        int study_time;

        Student()
        {
            study_time = 5;
        }

        public Student(string name)
        {
            study_time = 10;
            this.name = name;
        }

        public void prn() //오버라이딩
        {
            Console.WriteLine("학생의 출력구문");
            Console.WriteLine("이름 : " + name);
            Console.WriteLine("공부시간 : " + study_time);
        }
    }

    class Officer:Person
    {
        int work_time;
        int income;
        double time_fee;

        Officer()
        {
            work_time = 8;
        }
    }
}
