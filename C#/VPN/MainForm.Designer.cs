namespace VPN
{
	partial class MainForm
	{
		/// <summary>
		/// Required designer variable.
		/// </summary>
		private System.ComponentModel.IContainer components = null;

		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		/// <param name="disposing">true if managed resources should be disposed; otherwise, false.</param>
		protected override void Dispose(bool disposing)
		{
			if (disposing && (components != null))
			{
				components.Dispose();
			}
			base.Dispose(disposing);
		}

		#region Windows Form Designer generated code

		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		private void InitializeComponent()
		{
			this.components = new System.ComponentModel.Container();
			System.ComponentModel.ComponentResourceManager resources = new System.ComponentModel.ComponentResourceManager(typeof(MainForm));
			this.RunButton = new System.Windows.Forms.Button();
			this.KoreaRadioButton = new System.Windows.Forms.RadioButton();
			this.RadioGroup = new System.Windows.Forms.GroupBox();
			this.StatusLabel = new System.Windows.Forms.Label();
			this.Label = new System.Windows.Forms.Label();
			this.ExitButton = new System.Windows.Forms.Button();
			this.ProgressBar = new System.Windows.Forms.ProgressBar();
			this.StatusTimer = new System.Windows.Forms.Timer(this.components);
			this.RadioGroup.SuspendLayout();
			this.SuspendLayout();
			// 
			// RunButton
			// 
			this.RunButton.Anchor = ((System.Windows.Forms.AnchorStyles)((System.Windows.Forms.AnchorStyles.Bottom | System.Windows.Forms.AnchorStyles.Right)));
			this.RunButton.Location = new System.Drawing.Point(216, 126);
			this.RunButton.Name = "RunButton";
			this.RunButton.Size = new System.Drawing.Size(75, 23);
			this.RunButton.TabIndex = 0;
			this.RunButton.Text = "Start VPN";
			this.RunButton.UseVisualStyleBackColor = true;
			this.RunButton.Click += new System.EventHandler(this.RunButtonClick);
			// 
			// KoreaRadioButton
			// 
			this.KoreaRadioButton.AutoSize = true;
			this.KoreaRadioButton.Location = new System.Drawing.Point(17, 20);
			this.KoreaRadioButton.Name = "KoreaRadioButton";
			this.KoreaRadioButton.Size = new System.Drawing.Size(56, 16);
			this.KoreaRadioButton.TabIndex = 1;
			this.KoreaRadioButton.TabStop = true;
			this.KoreaRadioButton.Text = "Korea";
			this.KoreaRadioButton.UseVisualStyleBackColor = true;
			this.KoreaRadioButton.CheckedChanged += new System.EventHandler(this.Checked);
			// 
			// RadioGroup
			// 
			this.RadioGroup.Anchor = ((System.Windows.Forms.AnchorStyles)((((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Bottom) 
            | System.Windows.Forms.AnchorStyles.Left) 
            | System.Windows.Forms.AnchorStyles.Right)));
			this.RadioGroup.Controls.Add(this.KoreaRadioButton);
			this.RadioGroup.Location = new System.Drawing.Point(12, 12);
			this.RadioGroup.Name = "RadioGroup";
			this.RadioGroup.Size = new System.Drawing.Size(360, 108);
			this.RadioGroup.TabIndex = 2;
			this.RadioGroup.TabStop = false;
			this.RadioGroup.Text = "VPN";
			// 
			// StatusLabel
			// 
			this.StatusLabel.Anchor = ((System.Windows.Forms.AnchorStyles)((System.Windows.Forms.AnchorStyles.Bottom | System.Windows.Forms.AnchorStyles.Left)));
			this.StatusLabel.AutoSize = true;
			this.StatusLabel.Location = new System.Drawing.Point(59, 131);
			this.StatusLabel.Name = "StatusLabel";
			this.StatusLabel.Size = new System.Drawing.Size(108, 12);
			this.StatusLabel.TabIndex = 3;
			this.StatusLabel.Text = "VPN is not runnig.";
			// 
			// Label
			// 
			this.Label.Anchor = ((System.Windows.Forms.AnchorStyles)((System.Windows.Forms.AnchorStyles.Bottom | System.Windows.Forms.AnchorStyles.Left)));
			this.Label.AutoSize = true;
			this.Label.Location = new System.Drawing.Point(12, 131);
			this.Label.Name = "Label";
			this.Label.Size = new System.Drawing.Size(48, 12);
			this.Label.TabIndex = 4;
			this.Label.Text = "Status :";
			// 
			// ExitButton
			// 
			this.ExitButton.Anchor = ((System.Windows.Forms.AnchorStyles)((System.Windows.Forms.AnchorStyles.Bottom | System.Windows.Forms.AnchorStyles.Right)));
			this.ExitButton.Location = new System.Drawing.Point(297, 126);
			this.ExitButton.Name = "ExitButton";
			this.ExitButton.Size = new System.Drawing.Size(75, 23);
			this.ExitButton.TabIndex = 5;
			this.ExitButton.Text = "Exit VPN";
			this.ExitButton.UseVisualStyleBackColor = true;
			this.ExitButton.Click += new System.EventHandler(this.ExitButtonClick);
			// 
			// ProgressBar
			// 
			this.ProgressBar.Location = new System.Drawing.Point(61, 126);
			this.ProgressBar.Name = "ProgressBar";
			this.ProgressBar.Size = new System.Drawing.Size(149, 23);
			this.ProgressBar.TabIndex = 6;
			this.ProgressBar.Visible = false;
			// 
			// StatusTimer
			// 
			this.StatusTimer.Tick += new System.EventHandler(this.TimerTick);
			// 
			// MainForm
			// 
			this.AutoScaleDimensions = new System.Drawing.SizeF(7F, 12F);
			this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
			this.ClientSize = new System.Drawing.Size(384, 161);
			this.Controls.Add(this.ProgressBar);
			this.Controls.Add(this.ExitButton);
			this.Controls.Add(this.Label);
			this.Controls.Add(this.StatusLabel);
			this.Controls.Add(this.RadioGroup);
			this.Controls.Add(this.RunButton);
			this.FormBorderStyle = System.Windows.Forms.FormBorderStyle.FixedSingle;
			this.Icon = ((System.Drawing.Icon)(resources.GetObject("$this.Icon")));
			this.Name = "MainForm";
			this.Text = "OpenVPN Helper";
			this.RadioGroup.ResumeLayout(false);
			this.RadioGroup.PerformLayout();
			this.ResumeLayout(false);
			this.PerformLayout();

		}

		#endregion

		private System.Windows.Forms.Button RunButton;
		private System.Windows.Forms.RadioButton KoreaRadioButton;
		private System.Windows.Forms.GroupBox RadioGroup;
		private System.Windows.Forms.Label StatusLabel;
		private System.Windows.Forms.Label Label;
		private System.Windows.Forms.Button ExitButton;
		private System.Windows.Forms.ProgressBar ProgressBar;
		private System.Windows.Forms.Timer StatusTimer;
	}
}

