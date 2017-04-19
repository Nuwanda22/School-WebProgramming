using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace _CS__Pro_0726
{
    public partial class Form1 : Form
    {
        int temp = 0;
        int total = 0;
        int total2 = 0;
        int n1, n2;
        string nums = "";
        char calc;

        public Form1()
        {
            InitializeComponent();
        }

        private void Form1_Load(object sender, EventArgs e)
        {

        }

        private void label1_Click(object sender, EventArgs e)
        {
            
        }

        private void button1_Click(object sender, EventArgs e)
        {
            nums = nums + '1';
            textBox1.Text = nums;
        }

        private void button2_Click(object sender, EventArgs e)
        {
            nums = nums + '2';
            textBox1.Text = nums;
        }

        private void button3_Click(object sender, EventArgs e)
        {
            nums = nums + '3';
            textBox1.Text = nums;
        }

        private void button4_Click(object sender, EventArgs e)
        {
            n1 = Convert.ToInt32(nums);
            nums = " ";
            calc = '+';
        }

        private void button5_Click(object sender, EventArgs e)
        {
            n1 = Convert.ToInt32(nums);
            nums = " ";
            calc = '-';
        }

        private void button6_Click(object sender, EventArgs e)
        {
            n2 = Convert.ToInt32(nums);

            if (calc == '+')
            {
                total2 = n1 + n2;
                textBox1.Text = Convert.ToString(total2);
            }
            else if (calc == '-')
            {
                total2 = n1 - n2;
                textBox1.Text = Convert.ToString(total2);
            }
        }

        private void button7_Click(object sender, EventArgs e)
        {
            n1 = 0; n2 = 0; total2 = 0;
            nums = "";
            textBox1.Text = "0";
        }

        
    }
}
