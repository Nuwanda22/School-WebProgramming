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
using System.IO;
using System.Threading;

namespace FileUploader
{
	public partial class UploaderForm : Form
	{
		Socket client;
		Thread clientThread;

		public UploaderForm()
		{
			InitializeComponent();
			CheckForIllegalCrossThreadCalls = false;
			clientThread = new Thread(new ThreadStart(() => 
			{

			}));
		}

		private void sendButton_Click(object sender, EventArgs e)
		{
			if(openFileDialog.ShowDialog() == DialogResult.OK)
			{
				client = new Socket(AddressFamily.InterNetwork, SocketType.Stream, ProtocolType.Tcp);
				client.Connect(new IPEndPoint(IPAddress.Loopback, 4709));

				byte[] ACK = new byte[1024];

				// Send File Name
				client.Send(Encoding.Default.GetBytes("N:" + openFileDialog.SafeFileName));
				printToConsole("Server: Send File / " + openFileDialog.SafeFileName);				
				// Receive ACK
				printToConsole("Client: " + Encoding.ASCII.GetString(ACK, 0, client.Receive(ACK)));
				
				// Send File Size
				client.Send(Encoding.Default.GetBytes("S:" + /*File.Open(openFileDialog.FileName, FileMode.Open)*/new FileInfo(openFileDialog.FileName).Length.ToString())); 
				// Receive ACK
				printToConsole("Client: " + Encoding.ASCII.GetString(ACK, 0, client.Receive(ACK)));

				new Thread(new ThreadStart(() => 
				{
					// Send File
					using (FileStream fs = File.OpenRead(openFileDialog.FileName))
					{
						byte[] file = new byte[fs.Length];
						fs.Read(file, 0, file.Length);

						int count = 0;
						while (count < file.Length)
						{
							byte[] sending = new byte[1024];
							int temp = file.Length - count;
							if (temp < 1024)
							{
								Array.Copy(file, count, sending, 0, temp);
								count += 1024;
							}
							else
							{
								Array.Copy(file, count, sending, 0, sending.Length);
								count += 1024;
							}
							client.Send(sending);
						}
					}

					// Receive ACK
					printToConsole("Client: " + Encoding.ASCII.GetString(ACK, 0, client.Receive(ACK)));

					//client.Disconnect(true);
					client.Shutdown(SocketShutdown.Both);
					client.Close();
				})).Start();
			}
		}

		private void printToConsole(string message)
		{
			consoleTextBox.AppendText(message);
			consoleTextBox.AppendText("\r\n");
		}
	}
}
