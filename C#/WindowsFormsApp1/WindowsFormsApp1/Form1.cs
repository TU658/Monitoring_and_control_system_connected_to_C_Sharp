using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace WindowsFormsApp1
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private void splitContainer3_Panel2_Paint(object sender, PaintEventArgs e)
        {

        }

        private void splitContainer3_Panel1_Paint(object sender, PaintEventArgs e)
        {

        }

        private void Form1_Load(object sender, EventArgs e)
        {
            
        }

        private void button1_Click(object sender, EventArgs e)
        {
            if ((comboBox2.Text == "") || (comboBox1.Text == "")) 
            {
                listBox1.Items.Add("Bạn chưa nhập/chọn cổng COM hoặc Baudrate");
                button1.Text = "CONNECT";
            }
            else
            {
                
                if (serialPort1.IsOpen == true)
                {
                    serialPort1.Close();
                    button1.Text = "CONNECT";
                    listBox1.Items.Add("chưa được kết nối");
                    pictureBox5.Image = global::WindowsFormsApp1.Properties.Resources.temp_off;
                    pictureBox5.SizeMode = System.Windows.Forms.PictureBoxSizeMode.StretchImage;
                }
                else
                {
                    serialPort1.PortName = comboBox1.Text;
                    serialPort1.BaudRate = int.Parse(comboBox2.Text);
                    serialPort1.Open();
                    button1.Text = "CONNECTED";
                    listBox1.Items.Add("kết nối thành công");
                    pictureBox5.Image = global::WindowsFormsApp1.Properties.Resources.temp_on;
                    pictureBox5.SizeMode = System.Windows.Forms.PictureBoxSizeMode.StretchImage;
                }
            }

        }
        private void button2_Click(object sender, EventArgs e)
        {
            
            if (button2.Text == "ON")
            {
                serialPort1.Write("1");
                button2.Text = "OFF";
                pictureBox3.Image = global::WindowsFormsApp1.Properties.Resources.switch_on;
                pictureBox3.SizeMode = System.Windows.Forms.PictureBoxSizeMode.StretchImage;
            }
            else
            { 
                serialPort1.Write("2");
                button2.Text = "ON";
                pictureBox3.Image = global::WindowsFormsApp1.Properties.Resources.switch_off;
                pictureBox3.SizeMode = System.Windows.Forms.PictureBoxSizeMode.StretchImage;
            }

        }

        private void button3_Click(object sender, EventArgs e)
        {
            if (button3.Text == "ON")
            {
                serialPort1.Write("3");
                button3.Text = "OFF";
                pictureBox4.Image = global::WindowsFormsApp1.Properties.Resources.router_on;
                pictureBox4.SizeMode = System.Windows.Forms.PictureBoxSizeMode.StretchImage;
            }
            else
            {
                serialPort1.Write("4");
                button3.Text = "ON";
                pictureBox4.Image = global::WindowsFormsApp1.Properties.Resources.router_off;
                pictureBox4.SizeMode = System.Windows.Forms.PictureBoxSizeMode.StretchImage;
            }
        }
        string data = "";
        string nhietdo = "";
        private void serialPort1_DataReceived(object sender, System.IO.Ports.SerialDataReceivedEventArgs e)
        {
            data = serialPort1.ReadTo(" ");
            this.Invoke(new EventHandler(serialFunction));
        }
        private void serialFunction(object sender, EventArgs e)
        {
            nhietdo = data.Substring(0, 2);
            label13.Text = nhietdo + "°C";
        }
    

        private void pictureBox1_Click(object sender, EventArgs e)
        {
            
        }

        private void label13_Click(object sender, EventArgs e)
        {

        }

        private void tableLayoutPanel1_Paint(object sender, PaintEventArgs e)
        {

        }

        private void pictureBox7_Click(object sender, EventArgs e)
        {

        }

        private void pictureBox3_Click(object sender, EventArgs e)
        {

        }

        private void button4_Click(object sender, EventArgs e)
        {
            if (button4.Text == "ON")
            {
                serialPort1.Write("5");
                button4.Text = "OFF";
                pictureBox7.Image = global::WindowsFormsApp1.Properties.Resources.printer_on;
                pictureBox7.SizeMode = System.Windows.Forms.PictureBoxSizeMode.StretchImage;
            }
            else
            {
                serialPort1.Write("6");
                button4.Text = "ON";
                pictureBox7.Image = global::WindowsFormsApp1.Properties.Resources.printer_off;
                pictureBox7.SizeMode = System.Windows.Forms.PictureBoxSizeMode.StretchImage;
            }
        }

        private void button5_Click(object sender, EventArgs e)
        {
            if (button5.Text == "ON")
            {
                serialPort1.Write("7");
                button5.Text = "OFF";
                pictureBox8.Image = global::WindowsFormsApp1.Properties.Resources.medical_on;
                pictureBox8.SizeMode = System.Windows.Forms.PictureBoxSizeMode.StretchImage;
            }
            else
            {
                serialPort1.Write("8");
                button5.Text = "ON";
                pictureBox8.Image = global::WindowsFormsApp1.Properties.Resources.medical_off;
                pictureBox8.SizeMode = System.Windows.Forms.PictureBoxSizeMode.StretchImage;
            }
        }

        private void pictureBox5_Click(object sender, EventArgs e)
        {

        }
    }
}
