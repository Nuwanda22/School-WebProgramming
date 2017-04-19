namespace Goal
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
			System.ComponentModel.ComponentResourceManager resources = new System.ComponentModel.ComponentResourceManager(typeof(MainForm));
			this.PlusButton = new System.Windows.Forms.Button();
			this.PercentPanel = new System.Windows.Forms.Panel();
			this.CompleteLabel = new System.Windows.Forms.Label();
			this.ModifyTextBox = new System.Windows.Forms.TextBox();
			this.ModifyButton = new System.Windows.Forms.Button();
			this.GoalNameLabel = new System.Windows.Forms.Label();
			this.Cur = new System.Windows.Forms.Label();
			this.GoalValue = new System.Windows.Forms.Label();
			this.Complete = new System.Windows.Forms.Label();
			this.CurLabel = new System.Windows.Forms.Label();
			this.GoalValueLabel = new System.Windows.Forms.Label();
			this.SuspendLayout();
			// 
			// PlusButton
			// 
			this.PlusButton.Font = new System.Drawing.Font("NanumBarunpen", 8.999999F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
			this.PlusButton.Location = new System.Drawing.Point(301, 40);
			this.PlusButton.Name = "PlusButton";
			this.PlusButton.Size = new System.Drawing.Size(21, 21);
			this.PlusButton.TabIndex = 0;
			this.PlusButton.Text = "+";
			this.PlusButton.UseVisualStyleBackColor = true;
			this.PlusButton.Click += new System.EventHandler(this.PlusButtonClick);
			// 
			// PercentPanel
			// 
			this.PercentPanel.BorderStyle = System.Windows.Forms.BorderStyle.FixedSingle;
			this.PercentPanel.Location = new System.Drawing.Point(45, 40);
			this.PercentPanel.Name = "PercentPanel";
			this.PercentPanel.Size = new System.Drawing.Size(233, 26);
			this.PercentPanel.TabIndex = 1;
			this.PercentPanel.Visible = false;
			this.PercentPanel.VisibleChanged += new System.EventHandler(this.PercentPanelVisibleChanged);
			this.PercentPanel.Paint += new System.Windows.Forms.PaintEventHandler(this.PercentPanelPaint);
			// 
			// CompleteLabel
			// 
			this.CompleteLabel.AutoSize = true;
			this.CompleteLabel.Location = new System.Drawing.Point(90, 105);
			this.CompleteLabel.Name = "CompleteLabel";
			this.CompleteLabel.Size = new System.Drawing.Size(43, 12);
			this.CompleteLabel.TabIndex = 0;
			this.CompleteLabel.Text = "00.00%";
			this.CompleteLabel.Visible = false;
			// 
			// ModifyTextBox
			// 
			this.ModifyTextBox.Location = new System.Drawing.Point(150, 102);
			this.ModifyTextBox.Name = "ModifyTextBox";
			this.ModifyTextBox.Size = new System.Drawing.Size(100, 21);
			this.ModifyTextBox.TabIndex = 2;
			this.ModifyTextBox.Visible = false;
			// 
			// ModifyButton
			// 
			this.ModifyButton.Location = new System.Drawing.Point(256, 100);
			this.ModifyButton.Name = "ModifyButton";
			this.ModifyButton.Size = new System.Drawing.Size(21, 23);
			this.ModifyButton.TabIndex = 3;
			this.ModifyButton.Text = ">";
			this.ModifyButton.UseVisualStyleBackColor = true;
			this.ModifyButton.Visible = false;
			this.ModifyButton.Click += new System.EventHandler(this.ModifyButtonClick);
			// 
			// GoalNameLabel
			// 
			this.GoalNameLabel.AutoSize = true;
			this.GoalNameLabel.Location = new System.Drawing.Point(43, 21);
			this.GoalNameLabel.Name = "GoalNameLabel";
			this.GoalNameLabel.Size = new System.Drawing.Size(31, 12);
			this.GoalNameLabel.TabIndex = 4;
			this.GoalNameLabel.Text = "Goal";
			this.GoalNameLabel.Visible = false;
			// 
			// Cur
			// 
			this.Cur.AutoSize = true;
			this.Cur.Location = new System.Drawing.Point(43, 78);
			this.Cur.Name = "Cur";
			this.Cur.Size = new System.Drawing.Size(29, 12);
			this.Cur.TabIndex = 5;
			this.Cur.Text = "달성";
			this.Cur.Visible = false;
			// 
			// GoalValue
			// 
			this.GoalValue.AutoSize = true;
			this.GoalValue.Location = new System.Drawing.Point(180, 78);
			this.GoalValue.Name = "GoalValue";
			this.GoalValue.Size = new System.Drawing.Size(29, 12);
			this.GoalValue.TabIndex = 6;
			this.GoalValue.Text = "목표";
			this.GoalValue.Visible = false;
			// 
			// Complete
			// 
			this.Complete.AutoSize = true;
			this.Complete.Location = new System.Drawing.Point(43, 105);
			this.Complete.Name = "Complete";
			this.Complete.Size = new System.Drawing.Size(41, 12);
			this.Complete.TabIndex = 7;
			this.Complete.Text = "완성률";
			this.Complete.Visible = false;
			// 
			// CurLabel
			// 
			this.CurLabel.AutoSize = true;
			this.CurLabel.Location = new System.Drawing.Point(89, 78);
			this.CurLabel.Name = "CurLabel";
			this.CurLabel.Size = new System.Drawing.Size(47, 12);
			this.CurLabel.TabIndex = 8;
			this.CurLabel.Text = "00000일";
			this.CurLabel.Visible = false;
			// 
			// GoalValueLabel
			// 
			this.GoalValueLabel.AutoSize = true;
			this.GoalValueLabel.Location = new System.Drawing.Point(226, 78);
			this.GoalValueLabel.Name = "GoalValueLabel";
			this.GoalValueLabel.Size = new System.Drawing.Size(53, 12);
			this.GoalValueLabel.TabIndex = 9;
			this.GoalValueLabel.Text = "000000일";
			this.GoalValueLabel.Visible = false;
			// 
			// MainForm
			// 
			this.AutoScaleDimensions = new System.Drawing.SizeF(7F, 12F);
			this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
			this.ClientSize = new System.Drawing.Size(334, 161);
			this.Controls.Add(this.GoalValueLabel);
			this.Controls.Add(this.CurLabel);
			this.Controls.Add(this.Complete);
			this.Controls.Add(this.CompleteLabel);
			this.Controls.Add(this.GoalValue);
			this.Controls.Add(this.Cur);
			this.Controls.Add(this.GoalNameLabel);
			this.Controls.Add(this.ModifyButton);
			this.Controls.Add(this.ModifyTextBox);
			this.Controls.Add(this.PercentPanel);
			this.Controls.Add(this.PlusButton);
			this.Icon = ((System.Drawing.Icon)(resources.GetObject("$this.Icon")));
			this.Name = "MainForm";
			this.Text = "나의 목표";
			this.ResumeLayout(false);
			this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.Button PlusButton;
        private System.Windows.Forms.Panel PercentPanel;
        private System.Windows.Forms.TextBox ModifyTextBox;
        private System.Windows.Forms.Button ModifyButton;
		private System.Windows.Forms.Label CompleteLabel;
		private System.Windows.Forms.Label GoalNameLabel;
		private System.Windows.Forms.Label Cur;
		private System.Windows.Forms.Label GoalValue;
		private System.Windows.Forms.Label Complete;
		private System.Windows.Forms.Label CurLabel;
		private System.Windows.Forms.Label GoalValueLabel;
    }
}

