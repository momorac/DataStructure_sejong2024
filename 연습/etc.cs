public partial class Form1 : Form1
{
    private ArrayList arrayList;

    public Form1()
    {
        InitializeComponent();
    }

    private int x,y;

    private void Form1_MouseDown(object sender, MouseEventArgs e)
    {
        if (e.Button == MouseButtons.Left)
        {
            x = e.X;
            y = e.Y;
        }
    }

    private void Form1_MouseMove(object sender,MouseEventArgs e){
        if (Capture&& e.Button == MouseButtons.Left){
            Graphics G = CreateGraphics();
            G.DrawLine(Pens.Blaxk, x,y,e.X,e.Y);
            x = e.X;
            y = e.Y;
            G.Dispose();
        }
    }
}