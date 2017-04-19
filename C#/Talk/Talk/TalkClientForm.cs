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

namespace Talk
{
	public partial class TalkClientForm : Form
	{
		Socket client;
		Thread receivingMessageThread;

		public TalkClientForm()
		{
			InitializeComponent();
			CheckForIllegalCrossThreadCalls = false;
			client = new Socket(AddressFamily.InterNetwork, SocketType.Stream, ProtocolType.Tcp);
			receivingMessageThread = new Thread(new ThreadStart(() =>
			{
				while (true)
				{
					byte[] message = new byte[1024];
					int temp = client.Receive(message);
					consoleTextBox.Text = Encoding.Default.GetString(message, 0, temp);
					//printToConsole(Encoding.Default.GetString(message, 0, temp));
				}
			}));
		}

		private void connectButton_Click(object sender, EventArgs e)
		{
			// 연결 버튼을 누르면
			if (!client.Connected)
			{
				// 연결을 하고
				try
				{
					IPAddress ip = IPAddress.Parse(ipTextBox.Text);
					int port = int.Parse(portTextBox.Text);
					client.Connect(new IPEndPoint(ip, port));
				}
				catch(Exception ex)
				{
					MessageBox.Show(ex.Message);
					return;
				}
				// 연결이 되면
				if (client.Connected)
				{
					// 연결이 됨을 알린다.
					statusLabel.Text = "Connected";
					// 그리고 이 버튼을 연결끊기버튼으로 바꾼다.
					connectButton.Text = "Disconnect";

					// 이제 연결이 됐으니까 대화창의 내용을 다 가져온다.
					byte[] messages = new byte[1024];
					int receivedByte = client.Receive(messages);
					consoleTextBox.Text = Encoding.Default.GetString(messages, 0, receivedByte);
					// 그리고 자신이 접속했다는 메세지를 보낸다.
					client.Send(Encoding.Default.GetBytes(nameTextBox.Text+"님이 접속하셨습니다. "));
					printToConsole(nameTextBox.Text + "님이 접속하셨습니다. ");
					
					// 이제 메세지를 받는 쓰레드를 돌린다
					receivingMessageThread.Start();
				}
				// 그래도 연결이 안되면
				else
				{
					// 경고 메세지를 띄운다.
					MessageBox.Show("Connecting Failed!", "Error", MessageBoxButtons.OK, MessageBoxIcon.Error);
				}
			}
			// 연결 끊기 버튼을 누르면
			else
			{
				// 연결 종료 메세지를 보내고
				client.Send(Encoding.Default.GetBytes(nameTextBox.Text + "님이 퇴장하였습니다."));
				// 소켓을 닫고
				client.Shutdown(SocketShutdown.Both);
				client.Close();
				// 메세지 수신 쓰레드도 닫고
				receivingMessageThread.Abort();
				// 연결이 종료됨을 표시하고
				statusLabel.Text = "Disconnected";
				// 이 버튼을 연결 버튼으로 바꾼다.
				connectButton.Text = "Connect";
			}
		}

		void printToConsole(string message)
		{
			consoleTextBox.AppendText(message);
			consoleTextBox.AppendText("\r\n");
		}

		private void sendButton_Click(object sender, EventArgs e)
		{
			send();
		}

		private void sendButton_KeyUp(object sender, KeyEventArgs e)
		{
			send();
		}

		void send()
		{
			// 연결이 되어 있으면
			if (client.Connected)
			{
				// 메세지를 보내고
				client.Send(Encoding.Default.GetBytes(nameTextBox.Text + ": " + messageTextBox.Text));
				// 화면에 출력한다.
				printToConsole(nameTextBox.Text + ": " + messageTextBox.Text);
			}
			// 아니면
			else
			{
				// 경고를 띄운다.
				MessageBox.Show("It have to connect!", "Error", MessageBoxButtons.OK, MessageBoxIcon.Error);
			}
		}

		private void TalkClientForm_KeyUp(object sender, KeyEventArgs e)
		{
			send();
		}

		private void messageTextBox_KeyUp(object sender, KeyEventArgs e)
		{
			
		}
	}
}
