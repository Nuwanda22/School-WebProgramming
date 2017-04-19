using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using System.Diagnostics;

namespace VPN
{
	public partial class MainForm : Form
	{
		private int check = 0;
		private bool run = false;
		private Process ps;
		private ProcessStartInfo psi;
		
		public MainForm()
		{
			InitializeComponent();
		}

		private void RunButtonClick(object sender, EventArgs e)
		{
			if (check == 0)
			{
				MessageBox.Show("VPN을 설정해주세요!");
				return;
			}
			ps = new Process();
			ps.StartInfo = psi;
			try	{ 
				ps.Start(); 
			}
			catch (Win32Exception ex)
			{
				MessageBox.Show(ex.Message);
				return;
			}
			ProgressBar.Visible = true;
			StatusTimer.Start();
			//ps.StandardOutput.Close();
			//MessageBox.Show(ps.StandardOutput.ReadToEnd());
			StatusLabel.Text = Status.Run;
			run = true;
			MessageBox.Show(ps.ProcessName);
		}

		private void Checked(object sender, EventArgs e)
		{
			psi = new ProcessStartInfo();
			psi.WorkingDirectory = OpenvpnInfo.WorkingDirectory;
			psi.FileName = OpenvpnInfo.RunFile;
			psi.Arguments = OpenvpnInfo.KoreaTcp;
			psi.WindowStyle = ProcessWindowStyle.Hidden;
			//psi.UseShellExecute = false;
			//psi.RedirectStandardOutput = true;
			//psi.RedirectStandardError = true;
			check++;
		}

		private void ExitButtonClick(object sender, EventArgs e)
		{
			if (!run)
			{
				MessageBox.Show("뭐하냐");
				return;
			}
			ps.Kill();
			StatusLabel.Text = Status.Exit;
			run = false;
		}

		private void TimerTick(object sender, EventArgs e)
		{
			if (ProgressBar.Value < ProgressBar.Maximum)
			{
				ProgressBar.Value += 1;
			}
			else
			{
				ProgressBar.Visible = false;
				StatusTimer.Stop();
			}
		}
	}

	class OpenvpnInfo
	{
		public static string WorkingDirectory = @"C:\Program Files\OpenVPN\bin";
		public static string RunFile = "openvpn.exe";
		public static string KoreaTcp = "vpngate_vpn915285861.opengw.net_tcp_995.ovpn";
	}

	class Status
	{
		public static string Run = "VPN is runnig.";
		public static string Exit = "VPN is not runnig.";
	}
}
