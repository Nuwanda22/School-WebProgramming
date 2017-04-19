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
using System.IO;

namespace FileServer
{
	public partial class ServerForm : Form
	{
		Thread serverSocket;
		Socket listener;
		List<byte[]> partsOfFile;
		bool isReceiving;
		string saveFolder;

		public ServerForm()
		{
			InitializeComponent();
			CheckForIllegalCrossThreadCalls = false;
			isReceiving = false;
			serverSocket = new Thread(new ThreadStart(()=> 
			{
				listener = new Socket(AddressFamily.InterNetwork, SocketType.Stream, ProtocolType.Tcp);
				listener.Bind(new IPEndPoint(IPAddress.Loopback, 4709));
				listener.Listen(10);

				while (true)
				{
					printToConsole("Waiting for a connection...");
					Socket handler = listener.Accept();
										
					byte[] receive = new byte[1024];
					string fileName = null;
					int fileSize = 0;
					progressBar.Value = 0;

					// read for file name and size
					receiveAndCheck(handler, ref receive, ref fileName, ref fileSize);
					receiveAndCheck(handler, ref receive, ref fileName, ref fileSize);

					// and receiving file
					partsOfFile = new List<byte[]>();
					using (FileStream fs = File.Create(Path.Combine(saveFolder, fileName)))
					{
						int i;
						for(i = 0; i < fileSize; i += 1024)
						{
							if (!isReceiving)
							{
								printToConsole("Server: Receiving File");
								isReceiving = true;
							}

							handler.Receive(receive);
							partsOfFile.Add(receive.Clone() as byte[]);
						}
						progressBar.Maximum = partsOfFile.Count;
						byte[] realFile = new byte[fileSize];
						int count = 0;
						foreach (byte[] part in partsOfFile.ToArray())
						{
							int temp = realFile.Length - count;
							if (temp < 1024)
							{
								Array.Copy(part, 0, realFile, count, temp);
							}
							else
							{
								Array.Copy(part, 0, realFile, count, part.Length);
							}
							count += 1024;
							progressBar.Value++;
						}
						
						fs.Write(realFile, 0, realFile.Length);
					}
					printToConsole("Server: Received File");
					isReceiving = false;
					handler.Send(Encoding.Default.GetBytes("ACK File"));

					handler.Shutdown(SocketShutdown.Both);
					handler.Close();
				}
			}));
		}

		private void receiveAndCheck(Socket handler, ref byte[] receive, ref string fileName, ref int fileSize)
		{

			string responce = Encoding.Default.GetString(receive, 0, handler.Receive(receive));

			// when responece is file name
			if (responce.Contains("N:"))
			{
				printToConsole("Server: Received File Name / " + responce.Split(':')[1]);
				fileName = responce.Split(':')[1];

				handler.Send(Encoding.Default.GetBytes("ACK File Name"));
			}
			// when responce is file size
			else if(responce.Contains("S:"))
			{
				printToConsole("Server: Received File Size / " + responce.Split(':')[1]);
				fileSize = int.Parse(responce.Split(':')[1]);

				handler.Send(Encoding.Default.GetBytes("ACK File Size"));
			}
		}

		private void printToConsole(string message)
		{
			consoleTextBox.AppendText(message);
			consoleTextBox.AppendText("\n");
		}

		private void startButton_Click(object sender, EventArgs e)
		{
			// Start Server Thread
			if (!serverSocket.IsAlive)
			{
				if (folderBrowserDialog.ShowDialog() == DialogResult.OK)
				{
					saveFolder = folderBrowserDialog.SelectedPath;
					serverSocket.Start();
				}
			}
			else
			{
				MessageBox.Show("Already run!", "error", MessageBoxButtons.OK, MessageBoxIcon.Error);
			}
		}

		private void ServerForm_FormClosing(object sender, FormClosingEventArgs e)
		{
			listener?.Close();
			serverSocket.Abort();
		}
	}
}
