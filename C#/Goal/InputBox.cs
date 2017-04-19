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
	public partial class InputBox : Form
	{
		public string goalName { get; set; }
		public double goalValue { get; set; }
		public double curValue { get; set; }
		public string unit { get; set; }

		public InputBox()
		{
			InitializeComponent();
		}

		private void OKbuttonClick(object sender, EventArgs e)
		{
			try
			{
				if (GoalNameTextBox.Text.CompareTo("") == 0 || GoalValueTextBox.Text.CompareTo("") == 0 || CurValueTextBox.Text.CompareTo("") == 0)
				{
					MessageBox.Show("입력하렴", "%~");
					return;
				}
				
				goalName = GoalNameTextBox.Text;
				goalValue = Convert.ToDouble(GoalValueTextBox.Text);
				curValue = Convert.ToDouble(CurValueTextBox.Text);
				OKbutton.DialogResult = DialogResult.OK;
				unit = UnitComboBox.Text;
			}
			catch (FormatException ex)
			{
				MessageBox.Show(ex.Message);
			}
		}
	}
}
