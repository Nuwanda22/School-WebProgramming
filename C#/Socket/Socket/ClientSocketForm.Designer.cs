namespace ClientSocket
{
	partial class ClientSocketForm
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
			this.sendTextBox = new System.Windows.Forms.TextBox();
			this.sendButton = new System.Windows.Forms.Button();
			this.SuspendLayout();
			// 
			// consoleTextBox
			// 
			this.consoleTextBox.Location = new System.Drawing.Point(12, 12);
			this.consoleTextBox.Multiline = true;
			this.consoleTextBox.Name = "consoleTextBox";
			this.consoleTextBox.Size = new System.Drawing.Size(260, 208);
			this.consoleTextBox.TabIndex = 0;
			// 
			// sendTextBox
			// 
			this.sendTextBox.Location = new System.Drawing.Point(12, 228);
			this.sendTextBox.Name = "sendTextBox";
			this.sendTextBox.Size = new System.Drawing.Size(179, 21);
			this.sendTextBox.TabIndex = 1;
			// 
			// sendButton
			// 
			this.sendButton.Location = new System.Drawing.Point(197, 226);
			this.sendButton.Name = "sendButton";
			this.sendButton.Size = new System.Drawing.Size(75, 23);
			this.sendButton.TabIndex = 2;
			this.sendButton.Text = "Send";
			this.sendButton.UseVisualStyleBackColor = true;
			this.sendButton.Click += new System.EventHandler(this.sendButton_Click);
			// 
			// ClientSocketForm
			// 
			this.AutoScaleDimensions = new System.Drawing.SizeF(7F, 12F);
			this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
			this.ClientSize = new System.Drawing.Size(284, 261);
			this.Controls.Add(this.sendButton);
			this.Controls.Add(this.sendTextBox);
			this.Controls.Add(this.consoleTextBox);
			this.Name = "ClientSocketForm";
			this.Text = "Client";
			this.ResumeLayout(false);
			this.PerformLayout();

		}

		#endregion

		private System.Windows.Forms.TextBox consoleTextBox;
		private System.Windows.Forms.TextBox sendTextBox;
		private System.Windows.Forms.Button sendButton;
	}
}

