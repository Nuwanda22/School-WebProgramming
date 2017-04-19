using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace _CS__Pro_0729
{
    class Program : Form
    {
        static void Main(string[] args)
        {
            Program ob = new Program();
            ob.Text = "Talk to Mirim";
            ob.Width = 800;
            ob.Height = 600;

            Button bt1 = new Button();
            Button bt2 = new Button();
            Button bt3 = new Button();

            bt1.Text = "1번";
            bt1.Top = 300;
            bt1.Left = 200;

            bt2.Text = "2번";
            bt2.Top = 300;
            bt2.Left = 300;

            bt3.Text = "3번";
            bt3.Top = 300;
            bt3.Left = 400;

            bt1.Click += (object sender, EventArgs e) =>
                {
                    MessageBox.Show("1번을 클릭했습니다.");
                };
            bt2.Click += (object sender, EventArgs e) =>
            {
                MessageBox.Show("2번을 클릭했습니다.");
            };
            bt3.Click += (object sender, EventArgs e) =>
            {
                MessageBox.Show("3번을 클릭했습니다.");
            };

            ob.Controls.Add(bt1);
            ob.Controls.Add(bt2);
            ob.Controls.Add(bt3);

            Application.Run(ob);
        }
    }
}
