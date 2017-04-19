using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace _CS__Pro_0730
{
    public partial class Form1 : Form
    {
        string id, name, hakjum;
        int score1, score2, score3, total;
        double avg;

        public Form1()
        {
            InitializeComponent();
        }

        private void Form1_Load(object sender, EventArgs e)
        {

        }

        private void label3_Click(object sender, EventArgs e)
        {

        }

        private void textBox6_TextChanged(object sender, EventArgs e)
        {

        }

        private void label4_Click(object sender, EventArgs e)
        {

        }

        private void label8_Click(object sender, EventArgs e)
        {

        }

        private void textBox7_TextChanged(object sender, EventArgs e)
        {

        }

        private void label7_Click(object sender, EventArgs e)
        {

        }

        private void button1_Click(object sender, EventArgs e)
        {
            // 초기화 하기
            id = "10101";
            name = "홍길동";
            score1 = 0; score2 = 0; score3 = 0;
            total = 0; avg = 0;

            textBox1.Text = id;
            textBox2.Text = name;
            textBox3.Text = Convert.ToString(score1);
            textBox4.Text = Convert.ToString(score2);
            textBox5.Text = Convert.ToString(score3);
            textBox6.Text = "";
            textBox7.Text = "";
        }

        private void button2_Click(object sender, EventArgs e)
        {
            //성적 처리하기
            score1 = Convert.ToInt32(textBox3.Text);
            score2 = Convert.ToInt32(textBox4.Text);
            score3 = Convert.ToInt32(textBox5.Text);

            avg = (score1 + score2 + score3) / 3.0;

            if (avg >= 90)
                hakjum = "A";
            else if (avg >= 80)
                hakjum = "B";
            else if (avg >= 60)
                hakjum = "C";
            else
                hakjum = "F";

            textBox6.Text = Convert.ToString(avg);
            textBox7.Text = hakjum;
        }
    }
}
