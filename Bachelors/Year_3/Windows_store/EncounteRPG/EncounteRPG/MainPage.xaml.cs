﻿using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Runtime.InteropServices.WindowsRuntime;
using Windows.Foundation;
using Windows.Foundation.Collections;
using Windows.UI.Xaml;
using Windows.UI.Xaml.Controls;
using Windows.UI.Xaml.Controls.Primitives;
using Windows.UI.Xaml.Data;
using Windows.UI.Xaml.Input;
using Windows.UI.Xaml.Media;
using Windows.UI.Xaml.Navigation;

// The Blank Page item template is documented at http://go.microsoft.com/fwlink/?LinkId=402352&clcid=0x409

namespace EncounteRPG
{
    /// <summary>
    /// An empty page that can be used on its own or navigated to within a Frame.
    /// </summary>
    public sealed partial class MainPage : Page
    {
        public MainPage()
        {
            this.InitializeComponent();
            MyFrame.Navigate(typeof(Rpg));
        }

        private void HomeButton_OnClick(object sender, RoutedEventArgs e)
        {
            MyFrame.Navigate(typeof(Rpg));
        }
        private void BackButton_OnClickButton_OnClick(object sender, RoutedEventArgs e)
        {
            MyFrame.GoBack();
        }

        private void ForwardButton_OnClickButton_OnClick(object sender, RoutedEventArgs e)
        {
            if (MyFrame.CanGoForward)
            {
                MyFrame.GoForward();
            }
        }

        private void NavigateButton_OnClick(object sender, RoutedEventArgs e)
        {
            this.Frame.Navigate(typeof (Rpg));
        }
        private void HamburgerButton_Click(object sender, RoutedEventArgs e)
        {
            MySplitView.IsPaneOpen = !MySplitView.IsPaneOpen;
        }

        private void IconsListBox_SelectionChanged(object sender, SelectionChangedEventArgs e)
        {
            if (RpgListBoxItem.IsSelected) { ResultTextBlock.Text = "Tu będzie lista systemów rpg"; }
            else if (BiosListBoxItem.IsSelected) { ResultTextBlock.Text = "Tu będzie lista biomów"; }
            else if (CreaturesListBoxItem.IsSelected) { ResultTextBlock.Text = "Tu będzie lista stworów"; }
        }
    }
}