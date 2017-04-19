using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace Goal
{
    public partial class MainForm : Form
    {
		private string goal;
		private double percent;
		private double part;
		private double all;
		private string unit;

        public MainForm()
        {
            InitializeComponent();
        }

        private void PlusButtonClick(object sender, EventArgs e)
        {
			InputBox ib = new InputBox();
			if (ib.ShowDialog() == DialogResult.OK)
			{
				all = ib.goalValue;
				part = ib.curValue;
				percent = part / all * 100;

				goal = ib.goalName;
				unit = ib.unit;

				GoalNameLabel.Visible = true;
				GoalNameLabel.Text = goal;

				PercentPanel.Visible = true;

				Cur.Visible = true;
				CurLabel.Visible = true;
				CurLabel.Text = Convert.ToString(part) + unit;

				GoalValue.Visible = true;
				GoalValueLabel.Visible = true;
				GoalValueLabel.Text = Convert.ToString(all) + unit;

				Complete.Visible = true;
				CompleteLabel.Visible = true;
				CompleteLabel.Text = Convert.ToString(Round(percent, 0.01)) + '%';

				ModifyTextBox.Visible = true;
				ModifyTextBox.Text = CurLabel.Text;

				ModifyButton.Visible = true;

				PercentPanel.Invalidate();
			}
        }

		private double Round(double x, double digit)
		{
			if (x == 0)
			{
				return 0;
			}
			else
			{
				double inverseDight = Math.Pow(digit, -1);

				return Math.Round(x * inverseDight) / inverseDight;
			}
		}

		private void ModifyButtonClick(object sender, EventArgs e)
		{
			try
			{
				part = Convert.ToDouble(ModifyTextBox.Text);
				
				CompleteLabel.Text = Convert.ToString(percent) + "%";
			}
			catch (FormatException ex)
			{
				MessageBox.Show(ex.Message);
			}
		}

		private void PercentPanelVisibleChanged(object sender, EventArgs e)
		{
			PercentPanel.Invalidate();
		}

		private void PercentPanelPaint(object sender, PaintEventArgs e)
		{
			var p = sender as Panel;
			var g = e.Graphics;

			int width = (int)(p.Width * percent / 100);
			int height = p.Height;

			//g.FillRectangle(new SolidBrush(Color.FromArgb(0, Color.Black)), p.DisplayRectangle);

			Point[] points = new Point[4];

			points[0] = new Point(0, 0);
			points[1] = new Point(0, height);
			points[2] = new Point(width, height);
			points[3] = new Point(width, 0);

			Brush brush = new SolidBrush(Color.DarkGreen);

			g.FillPolygon(brush, points);
		}
    }
}
