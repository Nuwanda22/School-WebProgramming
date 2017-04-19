namespace FileServer
{
	partial class ServerForm
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
			this.progressBar = new System.Windows.Forms.ProgressBar();
			this.folderBrowserDialog = new System.Windows.Forms.FolderBrowserDialog();
			this.SuspendLayout();
			// 
			// startButton
			// 
			this.startButton.Location = new System.Drawing.Point(275, 12);
			this.startButton.Name = "startButton";
			this.startButton.Size = new System.Drawing.Size(75, 23);
			this.startButton.TabIndex = 0;
			this.startButton.Text = "Start";
			this.startButton.UseVisualStyleBackColor = true;
			this.startButton.Click += new System.EventHandler(this.startButton_Click);
			// 
			// consoleTextBox
			// 
			this.consoleTextBox.Location = new System.Drawing.Point(12, 41);
			this.consoleTextBox.Multiline = true;
			this.consoleTextBox.Name = "consoleTextBox";
			this.consoleTextBox.Size = new System.Drawing.Size(338, 208);
			this.consoleTextBox.TabIndex = 2;
			// 
			// progressBar
			// 
			this.progressBar.Location = new System.Drawing.Point(12, 12);
			this.progressBar.Name = "progressBar";
			this.progressBar.Size = new System.Drawing.Size(257, 23);
			this.progressBar.TabIndex = 3;
			// 
			// folderBrowserDialog
			// 
			this.folderBrowserDialog.Description = "저장할 폴더를 선택하세요.";
			// 
			// ServerForm
			// 
			this.AutoScaleDimensions = new System.Drawing.SizeF(7F, 12F);
			this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
			this.ClientSize = new System.Drawing.Size(362, 261);
			this.Controls.Add(this.progressBar);
			this.Controls.Add(this.consoleTextBox);
			this.Controls.Add(this.startButton);
			this.Name = "ServerForm";
			this.Text = "Server";
			this.FormClosing += new System.Windows.Forms.FormClosingEventHandler(this.ServerForm_FormClosing);
			this.ResumeLayout(false);
			this.PerformLayout();

		}

		#endregion

		private System.Windows.Forms.Button startButton;
		private System.Windows.Forms.TextBox consoleTextBox;
		private System.Windows.Forms.ProgressBar progressBar;
		private System.Windows.Forms.FolderBrowserDialog folderBrowserDialog;
	}
}

