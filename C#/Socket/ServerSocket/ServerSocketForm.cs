using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using System.Threading;
using System.Net;
using System.Net.Sockets;

namespace ServerSocket
{
	public partial class ServerSocketForm : Form
	{
		Thread serverSocket;
		Socket listener;

		public ServerSocketForm()
		{
			InitializeComponent();

			serverSocket = new Thread(new ThreadStart(this.runServer));
		}

		private void runServer()
		{
			listener = new Socket(AddressFamily.InterNetwork, SocketType.Stream, ProtocolType.Tcp);
			listener.Bind(new IPEndPoint(IPAddress.Loopback, 4709));
			listener.Listen(10);

			while (true)
			{
				printToConsole("Waiting for a connection...");
				Socket handler = listener.Accept();

				// receive data and print
				byte[] readReceive = new byte[handler.ReceiveBufferSize];
				handler.Receive(readReceive);
				printToConsole("" + Encoding.ASCII.GetString(readReceive));

				handler.Send(Encoding.ASCII.GetBytes("Good :)"));
				handler.Shutdown(SocketShutdown.Both);
				handler.Close();
			}
		}

		private void runButton_Click(object sender, EventArgs e)
		{
			// Start Server Thread
			CheckForIllegalCrossThreadCalls = false;
			if (!serverSocket.IsAlive)
			{
				serverSocket.Start();
			}
			else
			{
				MessageBox.Show("Already run!", "error", MessageBoxButtons.OK, MessageBoxIcon.Error);
			}
		}

		private void printToConsole(string message)
		{
			consoleTextBox.AppendText(message);
			consoleTextBox.AppendText("\n");
		}

		private void ServerSocketForm_FormClosing(object sender, FormClosingEventArgs e)
		{
			// when program close, kill thread
			listener?.Close();
			serverSocket.Abort();
		}
	}
}
