namespace TalkServer
{
	partial class TalkServerForm
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
			this.startButton = new System.Windows.Forms.Button();
			this.consoleTextBox = new System.Windows.Forms.TextBox();
			this.ipTextBox = new System.Windows.Forms.TextBox();
			this.portTextBox = new System.Windows.Forms.TextBox();
			this.label1 = new System.Windows.Forms.Label();
			this.label2 = new System.Windows.Forms.Label();
			this.SuspendLayout();
			// 
			// startButton
			// 
			this.startButton.Location = new System.Drawing.Point(197, 226);
			this.startButton.Name = "startButton";
			this.startButton.Size = new System.Drawing.Size(75, 23);
			this.startButton.TabIndex = 0;
			this.startButton.Text = "Start";
			this.startButton.UseVisualStyleBackColor = true;
			this.startButton.Click += new System.EventHandler(this.startButton_Click);
			// 
			// consoleTextBox
			// 
			this.consoleTextBox.BackColor = System.Drawing.SystemColors.Window;
			this.consoleTextBox.Location = new System.Drawing.Point(12, 39);
			this.consoleTextBox.Multiline = true;
			this.consoleTextBox.Name = "consoleTextBox";
			this.consoleTextBox.ReadOnly = true;
			this.consoleTextBox.ScrollBars = System.Windows.Forms.ScrollBars.Both;
			this.consoleTextBox.Size = new System.Drawing.Size(260, 181);
			this.consoleTextBox.TabIndex = 1;
			// 
			// ipTextBox
			// 
			this.ipTextBox.Location = new System.Drawing.Point(32, 12);
			this.ipTextBox.Name = "ipTextBox";
			this.ipTextBox.Size = new System.Drawing.Size(126, 21);
			this.ipTextBox.TabIndex = 2;
			this.ipTextBox.Text = "127.0.0.1";
			// 
			// portTextBox
			// 
			this.portTextBox.Location = new System.Drawing.Point(197, 12);
			this.portTextBox.Name = "portTextBox";
			this.portTextBox.Size = new System.Drawing.Size(75, 21);
			this.portTextBox.TabIndex = 3;
			this.portTextBox.Text = "4709";
			// 
			// label1
			// 
			this.label1.AutoSize = true;
			this.label1.Location = new System.Drawing.Point(10, 15);
			this.label1.Name = "label1";
			this.label1.Size = new System.Drawing.Size(16, 12);
			this.label1.TabIndex = 4;
			this.label1.Text = "IP";
			// 
			// label2
			// 
			this.label2.AutoSize = true;
			this.label2.Location = new System.Drawing.Point(164, 15);
			this.label2.Name = "label2";
			this.label2.Size = new System.Drawing.Size(27, 12);
			this.label2.TabIndex = 5;
			this.label2.Text = "Port";
			// 
			// TalkServerForm
			// 
			this.AutoScaleDimensions = new System.Drawing.SizeF(7F, 12F);
			this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
			this.ClientSize = new System.Drawing.Size(284, 261);
			this.Controls.Add(this.label2);
			this.Controls.Add(this.label1);
			this.Controls.Add(this.portTextBox);
			this.Controls.Add(this.ipTextBox);
			this.Controls.Add(this.consoleTextBox);
			this.Controls.Add(this.startButton);
			this.Name = "TalkServerForm";
			this.Text = "Talk Server";
			this.FormClosing += new System.Windows.Forms.FormClosingEventHandler(this.TalkServerForm_FormClosing);
			this.ResumeLayout(false);
			this.PerformLayout();

		}

		#endregion

		private System.Windows.Forms.Button startButton;
		private System.Windows.Forms.TextBox consoleTextBox;
		private System.Windows.Forms.TextBox ipTextBox;
		private System.Windows.Forms.TextBox portTextBox;
		private System.Windows.Forms.Label label1;
		private System.Windows.Forms.Label label2;
	}
}

