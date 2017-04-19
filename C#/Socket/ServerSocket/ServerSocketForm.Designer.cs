namespace ServerSocket
{
	partial class ServerSocketForm
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
			this.runButton = new System.Windows.Forms.Button();
			this.consoleTextBox = new System.Windows.Forms.TextBox();
			this.SuspendLayout();
			// 
			// runButton
			// 
			this.runButton.Location = new System.Drawing.Point(271, 12);
			this.runButton.Name = "runButton";
			this.runButton.Size = new System.Drawing.Size(75, 23);
			this.runButton.TabIndex = 3;
			this.runButton.Text = "Run";
			this.runButton.UseVisualStyleBackColor = true;
			this.runButton.Click += new System.EventHandler(this.runButton_Click);
			// 
			// consoleTextBox
			// 
			this.consoleTextBox.Location = new System.Drawing.Point(12, 41);
			this.consoleTextBox.Multiline = true;
			this.consoleTextBox.Name = "consoleTextBox";
			this.consoleTextBox.Size = new System.Drawing.Size(334, 208);
			this.consoleTextBox.TabIndex = 2;
			// 
			// ServerSocketForm
			// 
			this.AutoScaleDimensions = new System.Drawing.SizeF(7F, 12F);
			this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
			this.ClientSize = new System.Drawing.Size(360, 261);
			this.Controls.Add(this.runButton);
			this.Controls.Add(this.consoleTextBox);
			this.Name = "ServerSocketForm";
			this.Text = "Server";
			this.FormClosing += new System.Windows.Forms.FormClosingEventHandler(this.ServerSocketForm_FormClosing);
			this.ResumeLayout(false);
			this.PerformLayout();

		}

		#endregion

		private System.Windows.Forms.Button runButton;
		private System.Windows.Forms.TextBox consoleTextBox;
	}
}

