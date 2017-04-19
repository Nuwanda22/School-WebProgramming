using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using System.Net;
using System.Net.Sockets;

namespace ClientSocket
{
	public partial class ClientSocketForm : Form
	{
		Socket sender;

		public ClientSocketForm()
		{
			InitializeComponent();
		}

		private void sendButton_Click(object sender, EventArgs e)
		{
			sendMessage();
		}

		void sendMessage()
		{
			sender = new Socket(AddressFamily.InterNetwork, SocketType.Stream, ProtocolType.Tcp);
			sender.Connect(new IPEndPoint(/*Dns.Resolve(Dns.GetHostName()).AddressList[0]*/IPAddress.Loopback, 4709));

			byte[] bytes = new byte[1024];

			byte[] message = Encoding.ASCII.GetBytes(sendTextBox.Text);
			int bytesSent = sender.Send(message);
			int bytesRec = sender.Receive(bytes);

			printToConsole("echo : " + Encoding.ASCII.GetString(bytes, 0, bytesRec));

			sender.Shutdown(SocketShutdown.Both);
			sender.Close();
		}

		void printToConsole(string message)
		{
			consoleTextBox.AppendText(message);
			consoleTextBox.AppendText("\n");
		}
	}
}
