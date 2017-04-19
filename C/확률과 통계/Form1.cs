using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace 확률과_통계
{
    public partial class Form1 : Form
    {
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

        private void label6_Click(object sender, EventArgs e)
        {
            
        }

        private void button1_Click(object sender, EventArgs e)
        {
            const int SIHANG = 1000; //button1.Text = Convert.ToString(SIHANG);
            int[] arr1 = new int[SIHANG];
            int[] arr2 = new int[10];
            double[] arr3 = new double[SIHANG];
            
            int sum = 0;
            double sum2 = 0;
            double avg, variance, standardDeviation;

            Random r = new Random();

            for (int i = 0; i < SIHANG; i++)
            {
                arr1[i] = r.Next(1,11);

                if (arr1[i] == 1) arr2[0]++;
                else if (arr1[i] == 2) arr2[1]++;
                else if (arr1[i] == 3) arr2[2]++;
                else if (arr1[i] == 4) arr2[3]++;
                else if (arr1[i] == 5) arr2[4]++;
                else if (arr1[i] == 6) arr2[5]++;
                else if (arr1[i] == 7) arr2[6]++;
                else if (arr1[i] == 8) arr2[7]++;
                else if (arr1[i] == 9) arr2[8]++;
                else if (arr1[i] == 10) arr2[9]++;

                sum += arr1[i];
            }

            avg = (double)sum / SIHANG;

            for (int j = 0; j < 10; j++)
            {
                arr3[j] = (arr1[j] - avg) * (arr1[j] - avg);
                sum2 += arr3[j];
            }

            variance = (double)sum2 / SIHANG;
            standardDeviation = Math.Sqrt(variance);

            textBox1.Text = Convert.ToString(arr2[0]);
            textBox2.Text = Convert.ToString(arr2[1]);
            textBox3.Text = Convert.ToString(arr2[2]);
            textBox4.Text = Convert.ToString(arr2[3]);
            textBox5.Text = Convert.ToString(arr2[4]);
            textBox6.Text = Convert.ToString(arr2[5]);
            textBox7.Text = Convert.ToString(arr2[6]);
            textBox8.Text = Convert.ToString(arr2[7]);
            textBox9.Text = Convert.ToString(arr2[8]);
            textBox10.Text = Convert.ToString(arr2[9]);

            textBox11.Text = Convert.ToString(avg);
            textBox12.Text = Convert.ToString(variance);
            textBox13.Text = Convert.ToString(standardDeviation);
        }
    }
}