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
using System.Threading;

namespace TalkServer
{
	public partial class TalkServerForm : Form
	{
		bool serverIsRunning;
		Socket server;
		Thread connectingThread;
		Thread receivingMessagesThread;

		public TalkServerForm()
		{
			InitializeComponent();
			CheckForIllegalCrossThreadCalls = false;
			server = new Socket(AddressFamily.InterNetwork, SocketType.Stream, ProtocolType.Tcp);
			connectingThread = new Thread(new ThreadStart(() =>
			{
				// 연결될 클라이언트을 담을 리스트
				List<Socket> clients = new List<Socket>();
				// 계속해서 클라이언트를 연결한다.
				while (true)
				{
					// 클라이언트가 연결이 되면 리스트에 추가하고
					Socket handler = server.Accept();
					clients.Add(handler);
					// 그 클라이언트에게 지금까지의 대화 내용을 다 보낸다.
					handler.Send(Encoding.Default.GetBytes(consoleTextBox.Text));
					// 그럼 클라이언트에서는 "아무개님이 접속했습니다."가 날아온다.
					byte[] connectingMessage = new byte[1024];
					int receivedByte = handler.Receive(connectingMessage);
					printToConsole(Encoding.Default.GetString(connectingMessage, 0, receivedByte));

					// 이제 이 클라이언트에게 메서지가 날아오는 것을 계속 기다린다.
					receivingMessagesThread = new Thread(new ThreadStart(() =>
					{
						while (true)
						{
							// 메세지를 받으면 화면에 출력하고
							byte[] readReceive = new byte[handler.ReceiveBufferSize];
							try
							{
								handler.Receive(readReceive);
							}
							catch (SocketException)
							{
								MessageBox.Show("비정상적인 종료로 연결이 끊겼습니다.");
								handler.Shutdown(SocketShutdown.Both);
								handler.Close();
								clients.Remove(handler);
								break;
							}
							printToConsole(Encoding.Default.GetString(readReceive));

							// 혹시 받은 내용이 퇴장했다는 메세지면 종료시킨다. 
							if (Encoding.Default.GetString(readReceive).Contains("님이 퇴장하였습니다."))
							{
								handler.Shutdown(SocketShutdown.Both);
								handler.Close();
								clients.Remove(handler);
								break;
							}
							
							// 연결된 클라이언트 모두에게 대화내용을 다시 보낸다.
							foreach (Socket s in clients)
							{
								s.Send(Encoding.Default.GetBytes(consoleTextBox.Text));
							}
						}
					}));
					receivingMessagesThread.Start();
				}
			}));
		}

		private void startButton_Click(object sender, EventArgs e)
		{
			if (!serverIsRunning)
			{
				IPAddress ip = IPAddress.Parse(ipTextBox.Text);
				int port = int.Parse(portTextBox.Text);
				server.Bind(new IPEndPoint(ip, port));
				server.Listen(10);
				printToConsole("대화방이 만들어 졌습니다.");
				connectingThread.Start();

				serverIsRunning = true;
				startButton.Text = "Stop";
			}
			else
			{
				server.Close();
				connectingThread.Abort();

				serverIsRunning = false;
				startButton.Text = "Start";
			}
		}

		void printToConsole(string message)
		{
			consoleTextBox.AppendText(message);
			consoleTextBox.AppendText("\r\n");
		}

		private void TalkServerForm_FormClosing(object sender, FormClosingEventArgs e)
		{
			server.Close();
			connectingThread.Abort();
		}
	}
}
