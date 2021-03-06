﻿using System;
using System.Collections.Generic;
using System.Linq;
using System.Windows;
using System.Windows.Controls;
using System.Windows.Media;
using System.Windows.Shapes;
using System.Windows.Threading;
using Funcky.Extensions;
using Funcky.Monads;
using static ChristmasLightsSimulator.Animations;

namespace ChristmasLightsSimulator
{
    /// <summary>
    /// Interaction logic for MainWindow.xaml
    /// </summary>
    public partial class MainWindow : Window
    {
        public MainWindow()
        {
            InitializeComponent();

            CreateLeds(ChristmasLightsController.Setup());

            AnimationDropDown.ItemsSource = AllAnimations.Values;

            var x = string.Join("\n", AllAnimations.Select(a => $"{a.Key}:{a.Value}"));

            _lastLoop = DateTime.Now;
            _timer = new DispatcherTimer { Interval = TimeSpan.FromMilliseconds(50) };
            _timer.Tick += Loop;
            _timer.Start();
        }

        private DateTime _lastLoop;
        private readonly DispatcherTimer _timer;
        private readonly List<Ellipse> _ellipses = new();
        private int _frame;



        private void Loop(object? sender, EventArgs e)
        {
            FrameLabel.Content = $"Frame: {++_frame} / Animation {ToAnimationName(ChristmasLightsController.CurrentAnimationId())}";
            var elapsed = DateTime.Now - _lastLoop;
            _lastLoop = DateTime.Now;
            foreach (var (color, index) in ChristmasLightsController.Loop(_ellipses.Count, elapsed.Milliseconds).Select((c, i) => (c, i)))
            {
                _ellipses[index].Fill = new SolidColorBrush(color);
            }
        }

        private void CreateLeds(ushort pixelCount)
        {
            foreach (var index in Enumerable.Range(0, pixelCount))
            {
                var led = CreateLed();

                Canvas.SetLeft(led, LeftFromIndex(index));
                Canvas.SetTop(led, TopFromIndex(index));
                MainCanvas.Children.Add(led);
                _ellipses.Add(led);
            }
        }

        private double TopFromIndex(int index)
        {
            var x = Math.Abs(index % 10 - 4.5);
            var y = x * 20;

            return 8 + y;
        }

        private double LeftFromIndex(int index)
            => index * 8 + (index + 5) / 5 * 12;

        private Ellipse CreateLed()
            => new() { Width = 15, Height = 15, Fill = Brushes.Red, Stroke = Brushes.Black };

        private void OnAnimationChanged(object sender, SelectionChangedEventArgs e)
        {
            if (e.AddedItems.Count == 1)
            {
                AnimationId(e.AddedItems[0] as string)
                    .AndThen(ChristmasLightsController.SetAnimation);
            }
        }

        private static Option<ushort> AnimationId(string? animationName)
            => AllAnimations
                .Where(a => a.Value == animationName)
                .FirstOrNone()
                .AndThen(a => a.Key);
    }
}
