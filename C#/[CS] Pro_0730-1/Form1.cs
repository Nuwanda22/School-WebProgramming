using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace _CS__Pro_0730_1
{
    public partial class Form1 : Form
    {
        int menu = 1, money, input;

        public Form1()
        {
            InitializeComponent();
        }

        private void Form1_Load(object sender, EventArgs e)
        {

        }

        private void button1_Click(object sender, EventArgs e)
        {
            if (menu == 1) 
            { 
                textBox3.Text = "불고기 버거 세트";
                textBox4.Text = "5400원";
                money += 5400;
            }
            else if (menu == 2)
            {
                textBox5.Text = "불고기 버거 세트";
                textBox6.Text = "5400원";
                money += 5400;
            }
            else if (menu == 3)
            {
                textBox8.Text = "불고기 버거 세트";
                textBox9.Text = "5400원";
                money += 5400;
            }
            else if (menu == 4)
            {
                textBox10.Text = "불고기 버거 세트";
                textBox11.Text = "5400원";
                money += 5400;
            }
            menu++;
        }

        private void button2_Click(object sender, EventArgs e)
        {
            if (menu == 1)
            {
                textBox3.Text = "한우 불고기 버거 세트";
                textBox4.Text = "7400원";
                money += 7400;
            }
            else if (menu == 2)
            {
                textBox5.Text = "한우 불고기 버거 세트";
                textBox6.Text = "7400원";
                money += 7400;
            }
            else if (menu == 3)
            {
                textBox8.Text = "한우 불고기 버거 세트";
                textBox9.Text = "7400원";
                money += 7400;
            }
            else if (menu == 4)
            {
                textBox10.Text = "한우 불고기 버거 세트";
                textBox11.Text = "7400원";
                money += 7400;
            }
            menu++;
        }

        private void button3_Click(object sender, EventArgs e)
        {
            if (menu == 1)
            {
                textBox3.Text = "핫 크리스피 버거 세트";
                textBox4.Text = "6300원";
                money += 6300;
            }
            else if (menu == 2)
            {
                textBox5.Text = "핫 크리스피 버거 세트";
                textBox6.Text = "6300원";
                money += 6300;
            }
            else if (menu == 3)
            {
                textBox8.Text = "핫 크리스피 버거 세트";
                textBox9.Text = "6300원";
                money += 6300;
            }
            else if (menu == 4)
            {
                textBox10.Text = "핫 크리스피 버거 세트";
                textBox11.Text = "6300원";
                money += 6300;
            }
            menu++;
        }

        private void button4_Click(object sender, EventArgs e)
        {
            if (menu == 1)
            {
                textBox3.Text = "랏츠 버거 세트";
                textBox4.Text = "6500원";
                money += 6500;
            }
            else if (menu == 2)
            {
                textBox5.Text = "랏츠 버거 세트";
                textBox6.Text = "6500원";
                money += 6500;
            }
            else if (menu == 3)
            {
                textBox8.Text = "랏츠 버거 세트";
                textBox9.Text = "6500원";
                money += 6500;
            }
            else if (menu == 4)
            {
                textBox10.Text = "랏츠 버거 세트";
                textBox11.Text = "6500원";
                money += 6500;
            }
            menu++;
            
        }

        private void textBox7_TextChanged(object sender, EventArgs e)
        {
            
        }

        private void textBox2_TextChanged(object sender, EventArgs e)
        {

        }

        private void textBox8_TextChanged(object sender, EventArgs e)
        {

        }

        private void button5_Click(object sender, EventArgs e)
        {
            textBox1.Text = Convert.ToString(money) + '원';
        }

        private void button6_Click(object sender, EventArgs e)
        {
            input = Convert.ToInt32(textBox7.Text);
            textBox2.Text = Convert.ToString(input - money) + '원';
        }

        private void button7_Click(object sender, EventArgs e)
        {
            textBox1.Text = "0원";
            textBox2.Text = "0원";
            textBox3.Text = "";
            textBox4.Text = "";
            textBox5.Text = "";
            textBox6.Text = "";
            textBox7.Text = "0";
            textBox8.Text = "";
            textBox9.Text = "";
            textBox10.Text = "";
            textBox11.Text = "";

            money = 0;
            menu = 1;
            input = 0;
        }
    }
}
