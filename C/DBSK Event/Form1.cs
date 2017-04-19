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

namespace DBSK_Event
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }
        string event_people;
        string[] person;
        OpenFileDialog ofd = new OpenFileDialog();
        SaveFileDialog sfd = new SaveFileDialog();

        private void button1_Click(object sender, EventArgs e)
        {
            ofd.Title = "이벤트 참가자 명단을 열어주세요.";
            ofd.Filter = "Text Files|*.txt";
            
            if (ofd.ShowDialog() == DialogResult.OK)
            {
                StreamReader sr = new StreamReader(ofd.FileName, Encoding.Default, true);
                event_people = sr.ReadToEnd();
                person = event_people.Split(' ');

                int i = 0;

                textBox1.Text = person[i++];
                textBox2.Text = person[i++];
                textBox3.Text = person[i++];
                textBox4.Text = person[i++];
                textBox5.Text = person[i++];
                textBox6.Text = person[i++];
                textBox7.Text = person[i++];
                textBox8.Text = person[i++];
                textBox9.Text = person[i++];
                textBox10.Text = person[i++];

                sr.Close();
                sr.Dispose();
            }
        }

        private void button2_Click(object sender, EventArgs e)
        {
            Random rd = new Random();
            int rd_num = rd.Next(10);

            MessageBox.Show("과연 당첨자는 누구일까요?", "당첨자 확인");
            MessageBox.Show("두구두국두구굳구두굳국두구...", "당첨자 확인");
            MessageBox.Show("당첨자는 " + person[rd_num] + "입니다!\n축하드려요~~", "당첨자 확인");

            textBox11.Text = person[rd_num];
        }

        private void button3_Click(object sender, EventArgs e)
        {
            sfd.Title = "이벤트 딩첨자를 저장할 공간을 골라주세요.";
            sfd.Filter = "Text Files|*.txt";

            if (sfd.ShowDialog() == DialogResult.OK)
            {
                StreamWriter sw = new StreamWriter(sfd.OpenFile(), Encoding.UTF8);

                sw.Write(textBox11.Text);

                sw.Dispose();
                sw.Close();
            }
        }

        
    }
}
