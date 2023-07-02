using CypherWPF.cypher;
using Microsoft.Win32;
using System;
using System.Collections.Generic;
using System.Diagnostics;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows;
using System.Windows.Controls;
using System.Windows.Data;
using System.Windows.Documents;
using System.Windows.Input;
using System.Windows.Media;
using System.Windows.Media.Animation;
using System.Windows.Media.Imaging;
using System.Windows.Navigation;
using System.Windows.Shapes;

namespace CypherWPF
{
    /// <summary>
    /// Логика взаимодействия для MainWindow.xaml
    /// </summary>
    public partial class MainWindow : Window
    {
        public int method = 0;
        public FileInfo opFile, buffFile;

        public MainWindow()
        {
            Exit = new RoutedCommand("Exit", typeof(MainWindow));
            Open = new RoutedCommand("Open", typeof(MainWindow));
            Save = new RoutedCommand("Save", typeof(MainWindow));
            Encrypt = new RoutedCommand("Encrypt", typeof(MainWindow));
            Decrypt = new RoutedCommand("Decrypt", typeof(MainWindow));
            GenerateKey = new RoutedCommand("GenerateKey", typeof(MainWindow));
            CopyKey = new RoutedCommand("CopyKey", typeof(MainWindow));
            ChooseMethod = new RoutedCommand("ChooseMethod", typeof(MainWindow));
            Help = new RoutedCommand("Help", typeof(MainWindow));
            HotKeys = new RoutedCommand("HotKeys", typeof(MainWindow));
            AboutProgram = new RoutedCommand("AboutProgram", typeof(MainWindow));
            AboutAuthor = new RoutedCommand("AboutAuthor", typeof(MainWindow));

            InitializeComponent();
        }

        public static KeyBinding ExitKeyBind { get; set; }
        public static CommandBinding ExitBin { get; set; }
        public static RoutedCommand Exit { get; set; }
        public static RoutedCommand Open { get; set; }
        public static RoutedCommand Save { get; set; }
        public static RoutedCommand Encrypt { get; set; }
        public static RoutedCommand Decrypt { get; set; }
        public static RoutedCommand GenerateKey { get; set; }
        public static RoutedCommand CopyKey { get; set; }
        public static RoutedCommand ChooseMethod { get; set; }
        public static RoutedCommand Help { get; set; }
        public static RoutedCommand HotKeys { get; set; }
        public static RoutedCommand AboutProgram { get; set; }
        public static RoutedCommand AboutAuthor { get; set; }

        private void Window_Closing(object sender, System.ComponentModel.CancelEventArgs e)
        {
            if (MessageBox.Show("Do you want to exit?", "Exit", MessageBoxButton.YesNo, MessageBoxImage.Warning) == MessageBoxResult.No)
            {
                e.Cancel = true;
            }
        }

        private void MMExit_Click(object sender, RoutedEventArgs e)
        {
            Close();
        }

        private void MMOpen_Click(object sender, RoutedEventArgs e)
        {
            OpenFileDialog ofd = new OpenFileDialog();
            ofd.Filter = "All files|*.txt;*.doc;*.docx;*.html;*.pdf;*.rtf;*.jpg;*.jpeg;*.bmp;*.png;*.mp3;*.mp4;*.avi;*.mov;*.flv;*.vma|Encrypted files (.vma)|*.vma|Text files (.txt, .doc, .docx, .html, .pdf, .rtf)|*.txt;*.doc;*.docx;*.html;*.pdf;*.rtf|Images (.jpg, .jpeg, .bmp, .png)|*.jpg;*.jpeg;*.bmp;*.png|Audio files (.mp3)|*.mp3|Video files (.mp4, .avi, .mov, .flv)|*.mp4;*.avi;*.mov;*.flv";

            if (ofd.ShowDialog() == true) {
                BrowseTextBox.Text = opFile.FullName;
            }
        }

        private void MMSave_Click(object sender, RoutedEventArgs e)
        {

        }

        private void MMEncrypt_Click(object sender, RoutedEventArgs e)
        {
            if (BrowseTextBox.Text.Length == 0)
            {
                MessageBox.Show("Please select file for encryption.", "Error", MessageBoxButton.OK, MessageBoxImage.Error);
            }
            else 
            {
                buffFile = Cypher.executeEncryption();
            }
        }

        private void MMDecrypt_Click(object sender, RoutedEventArgs e)
        {

        }

        private void MMGenerate_Click(object sender, RoutedEventArgs e)
        {
            PasswordTextBox.Text = GenerateRandomKey((new Random().Next() % 5) + 35);
        }

        private void MMCopyKey_Click(object sender, RoutedEventArgs e)
        {
            Clipboard.SetText(PasswordTextBox.Text);
            HintMsg("Key copied!");
        }

        private void MMMethod_Click(object sender, RoutedEventArgs e)
        {
            MethodChoosingWindow mcw = new MethodChoosingWindow();
            mcw.ShowDialog();

            if (mcw.method > -1) {
                this.method = mcw.method;
            }
        }

        private void MMHelp_Click(object sender, RoutedEventArgs e)
        {
            MessageBox.Show("   Click on folder image, \"Browse\" button or \"Browse\" button in main menu to " +
                    "open file. Click on key image to copy key. Click on \"Generate\" to generate a key.\n   Open file," +
                    "enter key and click on \"encrypt\\decrypt\" to encrypt\\decrypt file.", "How to use", MessageBoxButton.OK, MessageBoxImage.Information);
        }

        private void MMHotKeys_Click(object sender, RoutedEventArgs e)
        {
            MessageBox.Show("Alt + O - open file;\nAlt + S - save file;\nAlt + D - decrypt file;\n" +
                    "Alt+E - encrypt file;\nAlt+C - copy key;\nAlt+G - generate key;\nAlt+M - choose method;\nAlt+H - help;\n"
                    + "Alt+K - hot keys;\nAlt+P - about program;\nAlt+A - about author;\nEsc - exit.", "Hot keys", MessageBoxButton.OK, MessageBoxImage.Information);
        }

        private void MMAboutProgram_Click(object sender, RoutedEventArgs e)
        {
            MessageBox.Show("This application can encrypt and decrypt your text or media file.", "About program", MessageBoxButton.OK, MessageBoxImage.Information);
        }

        private void MMAboutAuthor_Click(object sender, RoutedEventArgs e)
        {
            MessageBox.Show("Application created by Matvey Vorivoda in 2020. Student of group 951007.", "About author", MessageBoxButton.OK, MessageBoxImage.Information);
        }

        private void EyeClose_MouseLeftButtonDown(object sender, MouseButtonEventArgs e)
        {
            PasswordBox.Visibility = Visibility.Hidden;
            EyeClose.Visibility = Visibility.Hidden;
            HintMsg("Password displayed!");
        }

        private void EyeOpen_MouseLeftButtonDown(object sender, MouseButtonEventArgs e)
        {
            PasswordBox.Visibility = Visibility.Visible;
            EyeClose.Visibility = Visibility.Visible;
            HintMsg("Password hidden!");
        }

        private void PasswordBox_PasswordChanged(object sender, RoutedEventArgs e)
        {
            PasswordTextBox.Text = PasswordBox.Password;
        }

        private void PasswordBox_Loaded(object sender, RoutedEventArgs e)
        {
            PasswordTextBox.TextChanged += PasswordTextBox_TextChanged;
        }

        private void PasswordTextBox_TextChanged(object sender, TextChangedEventArgs e)
        {
            PasswordBox.Password = PasswordTextBox.Text;
        }

        private void HintMsg(String text)
        {
            HintLabel.Opacity = 1;
            HintLabel.Content = text;

            DoubleAnimation doubleAnimation = new DoubleAnimation();
            doubleAnimation.From = 1;
            doubleAnimation.To = 0;
            doubleAnimation.Duration = TimeSpan.FromMilliseconds(1500);
            HintLabel.BeginAnimation(Label.OpacityProperty, doubleAnimation);
        }
        private String GenerateRandomKey(int keyLength)
        {
            String key = "";
            Random randomizer = new Random();
            for (int i = 0; i < keyLength; i++)
            {
                key = key + NextChar((byte)Math.Abs(randomizer.Next() % 128));
            }
            return key;
        }

        private char NextChar(byte chr)
        {
            if (chr > 57)
            {
                if (chr > 90)
                {
                    chr = (byte)(97 + chr % 26);
                }
                else
                {
                    chr = (byte)(65 + chr % 26);
                }
            }
            else
            {
                chr = (byte)(48 + chr % 10);
            }
            return (char)(chr);
        }
    }
}
