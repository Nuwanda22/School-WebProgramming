using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using System.IO;

namespace 성적_관리_프로그램
{
    public partial class Form1 : Form
    {
        OpenFileDialog ofd = new OpenFileDialog(); 
        //SaveFileDialog sfd = new SaveFileDialog();
        //TextBox[] tb = new TextBox[] { textBox1, textBox2, textBox3, textBox4, textBox5, textBox6, textBox7, textBox8, textBox9 };
        const int GRADE = 7;
        string openFile;
        string[] gradeTemp;
        double[] grade = new double[7];

        public Form1()
        {
            InitializeComponent();
        }

        private double round(double x, double digit)
        {
            double inverseDight = Math.Pow(digit, -1);

            return Math.Round(x * inverseDight) / inverseDight;
        }

        private void button1_Click(object sender, EventArgs e)
        {
            ofd.Title = "이벤트 참가자 명단을 열어주세요.";
            ofd.Filter = "Text Files|*.txt";

            if (ofd.ShowDialog() == DialogResult.OK)
            {
                StreamReader sr = new StreamReader(ofd.FileName, Encoding.Default, true);
                openFile = sr.ReadToEnd();
                gradeTemp = openFile.Split(' ');

                int i = 0;

                textBox1.Text = gradeTemp[i++];
                textBox2.Text = gradeTemp[i++];
                textBox3.Text = gradeTemp[i++];
                textBox4.Text = gradeTemp[i++];
                textBox5.Text = gradeTemp[i++];
                textBox6.Text = gradeTemp[i++];
                textBox7.Text = gradeTemp[i++];

                sr.Close();
                sr.Dispose();
            }
        }

        private void button2_Click(object sender, EventArgs e)
        {
            double sum = 0.0, avg = 0.0;

            for (int i = 0; i < GRADE; i++)
            {
                grade[i] = Convert.ToDouble(gradeTemp[i]);
            }

            for (int i = 0; i < GRADE; i++)
            {
                sum += grade[i];
            }

            avg = sum / GRADE;
            
            textBox8.Text = Convert.ToString(sum);
            textBox9.Text = Convert.ToString(round(avg, 0.01));
        }
    }
}
