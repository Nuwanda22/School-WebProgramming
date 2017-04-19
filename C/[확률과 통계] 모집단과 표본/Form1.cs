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

namespace _확률과_통계__모집단과_표본
{
    public partial class Form1 : Form
    {
        string input;
        string[] data1;
        char[] str = new char[3]{' ','\r','\n'};
        string data2;
        double[] data_ = new double[1000];
        OpenFileDialog ofd = new OpenFileDialog();
        SaveFileDialog sfd = new SaveFileDialog();

        public Form1()
        {
            InitializeComponent();
        }

        private void button1_Click(object sender, EventArgs e)
        {
            ofd.Title = "데이터 파일을 열어라!";
            ofd.Filter = "Text Files|*.txt";

            if (ofd.ShowDialog() == DialogResult.OK)
            {
                StreamReader sr = new StreamReader(ofd.FileName, Encoding.Default, true);
                input = sr.ReadToEnd();
                data1 = input.Split(str);
                
                for (int i = 0; i < data1.Length; i++)
                {
                    textBox1.Text += data1[i];
                }

                sr.Close();
                sr.Dispose();
            }
        }
    }
}
