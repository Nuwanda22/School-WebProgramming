namespace Talk
{
	partial class TalkClientForm
	{
		/// <summary>
		/// 필수 디자이너 변수입니다.
		/// </summary>
		private System.ComponentModel.IContainer components = null;

		/// <summary>
		/// 사용 중인 모든 리소스를 정리합니다.
		/// </summary>
		/// <param name="disposing">관리되는 리소스를 삭제해야 하면 true이고, 그렇지 않으면 false입니다.</param>
		protected override void Dispose(bool disposing)
		{
			if (disposing && (components != null))
			{
				components.Dispose();
			}
			base.Dispose(disposing);
		}

		#region Windows Form 디자이너에서 생성한 코드

		/// <summary>
		/// 디자이너 지원에 필요한 메서드입니다. 
		/// 이 메서드의 내용을 코드 편집기로 수정하지 마세요.
		/// </summary>
		private void InitializeComponent()
		{
			this.consoleTextBox = new System.Windows.Forms.TextBox();
			this.messageTextBox = new System.Windows.Forms.TextBox();
			this.sendButton = new System.Windows.Forms.Button();
			this.statusLabel = new System.Windows.Forms.Label();
			this.connectButton = new System.Windows.Forms.Button();
			this.label1 = new System.Windows.Forms.Label();
			this.label2 = new System.Windows.Forms.Label();
			this.ipTextBox = new System.Windows.Forms.TextBox();
			this.portTextBox = new System.Windows.Forms.TextBox();
			this.nameTextBox = new System.Windows.Forms.TextBox();
			this.SuspendLayout();
			// 
			// consoleTextBox
			// 
			this.consoleTextBox.Location = new System.Drawing.Point(12, 64);
			this.consoleTextBox.Multiline = true;
			this.consoleTextBox.Name = "consoleTextBox";
			this.consoleTextBox.ScrollBars = System.Windows.Forms.ScrollBars.Both;
			this.consoleTextBox.Size = new System.Drawing.Size(260, 158);
			this.consoleTextBox.TabIndex = 0;
			// 
			// messageTextBox
			// 
			this.messageTextBox.Location = new System.Drawing.Point(12, 228);
			this.messageTextBox.Name = "messageTextBox";
			this.messageTextBox.Size = new System.Drawing.Size(231, 21);
			this.messageTextBox.TabIndex = 1;
			this.messageTextBox.KeyUp += new System.Windows.Forms.KeyEventHandler(this.messageTextBox_KeyUp);
			// 
			// sendButton
			// 
			this.sendButton.Location = new System.Drawing.Point(249, 226);
			this.sendButton.Name = "sendButton";
			this.sendButton.Size = new System.Drawing.Size(23, 23);
			this.sendButton.TabIndex = 2;
			this.sendButton.Text = "<";
			this.sendButton.UseVisualStyleBackColor = true;
			this.sendButton.Click += new System.EventHandler(this.sendButton_Click);
			this.sendButton.KeyUp += new System.Windows.Forms.KeyEventHandler(this.sendButton_KeyUp);
			// 
			// statusLabel
			// 
			this.statusLabel.AutoSize = true;
			this.statusLabel.Location = new System.Drawing.Point(100, 40);
			this.statusLabel.Name = "statusLabel";
			this.statusLabel.Size = new System.Drawing.Size(82, 12);
			this.statusLabel.TabIndex = 3;
			this.statusLabel.Text = "Disconnected";
			// 
			// connectButton
			// 
			this.connectButton.Location = new System.Drawing.Point(188, 35);
			this.connectButton.Name = "connectButton";
			this.connectButton.Size = new System.Drawing.Size(84, 23);
			this.connectButton.TabIndex = 4;
			this.connectButton.Text = "Connect";
			this.connectButton.UseVisualStyleBackColor = true;
			this.connectButton.Click += new System.EventHandler(this.connectButton_Click);
			// 
			// label1
			// 
			this.label1.AutoSize = true;
			this.label1.Location = new System.Drawing.Point(10, 9);
			this.label1.Name = "label1";
			this.label1.Size = new System.Drawing.Size(16, 12);
			this.label1.TabIndex = 5;
			this.label1.Text = "IP";
			// 
			// label2
			// 
			this.label2.AutoSize = true;
			this.label2.Location = new System.Drawing.Point(155, 9);
			this.label2.Name = "label2";
			this.label2.Size = new System.Drawing.Size(27, 12);
			this.label2.TabIndex = 6;
			this.label2.Text = "Port";
			// 
			// ipTextBox
			// 
			this.ipTextBox.Location = new System.Drawing.Point(34, 6);
			this.ipTextBox.Name = "ipTextBox";
			this.ipTextBox.Size = new System.Drawing.Size(115, 21);
			this.ipTextBox.TabIndex = 7;
			this.ipTextBox.Text = "127.0.0.1";
			// 
			// portTextBox
			// 
			this.portTextBox.Location = new System.Drawing.Point(188, 6);
			this.portTextBox.Name = "portTextBox";
			this.portTextBox.Size = new System.Drawing.Size(84, 21);
			this.portTextBox.TabIndex = 8;
			this.portTextBox.Text = "4709";
			// 
			// nameTextBox
			// 
			this.nameTextBox.Location = new System.Drawing.Point(12, 37);
			this.nameTextBox.Name = "nameTextBox";
			this.nameTextBox.Size = new System.Drawing.Size(82, 21);
			this.nameTextBox.TabIndex = 9;
			this.nameTextBox.Text = "Name";
			// 
			// TalkClientForm
			// 
			this.AutoScaleDimensions = new System.Drawing.SizeF(7F, 12F);
			this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
			this.ClientSize = new System.Drawing.Size(284, 261);
			this.Controls.Add(this.nameTextBox);
			this.Controls.Add(this.portTextBox);
			this.Controls.Add(this.ipTextBox);
			this.Controls.Add(this.label2);
			this.Controls.Add(this.label1);
			this.Controls.Add(this.connectButton);
			this.Controls.Add(this.statusLabel);
			this.Controls.Add(this.sendButton);
			this.Controls.Add(this.messageTextBox);
			this.Controls.Add(this.consoleTextBox);
			this.Name = "TalkClientForm";
			this.Text = "Talk";
			this.KeyUp += new System.Windows.Forms.KeyEventHandler(this.TalkClientForm_KeyUp);
			this.ResumeLayout(false);
			this.PerformLayout();

		}

		#endregion

		private System.Windows.Forms.TextBox consoleTextBox;
		private System.Windows.Forms.TextBox messageTextBox;
		private System.Windows.Forms.Button sendButton;
		private System.Windows.Forms.Label statusLabel;
		private System.Windows.Forms.Button connectButton;
		private System.Windows.Forms.Label label1;
		private System.Windows.Forms.Label label2;
		private System.Windows.Forms.TextBox ipTextBox;
		private System.Windows.Forms.TextBox portTextBox;
		private System.Windows.Forms.TextBox nameTextBox;
	}
}

