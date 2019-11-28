using System;
using System.Collections.Generic;
using System.Linq;
using System.Windows;
using System.Windows.Controls;
using System.Windows.Media;
using System.Windows.Shapes;
using System.Windows.Threading;

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

            _lastLoop = DateTime.Now;
            _timer = new DispatcherTimer { Interval = TimeSpan.FromMilliseconds(50) };
            _timer.Tick += Loop;
            _timer.Start();
        }

        private DateTime _lastLoop;
        private readonly DispatcherTimer _timer;
        private readonly List<Ellipse> _ellipses = new List<Ellipse>();
        private int _frame = 0;

        private readonly Dictionary<ushort, string> _animations = new Dictionary<ushort, string>
        {
            {0x0100, "CenterRun"},
            {0x0101, "CollideOne"},
            {0x0102, "ColorSwing"},
            {0x0103, "ColorWalk"},
            {0x0104, "ColorWave"},
            {0x0105, "ColorWipe"},
            {0x0106, "EvenOdd"},
            {0x0107, "FlashSeven"},
            {0x0108, "Interference"},
            {0x0109, "LightHouse"},
            {0x010a, "LightUp"},
            {0x010b, "MergeOne"},
            {0x010c, "MergeWave"},
            {0x010d, "NeoFire"},
            {0x010e, "RainBlend"},
            {0x010f, "RainCycle"},
            {0x0110, "RainFull"},
            {0x0100, "Rainbow"},
            {0x0100, "RandomCreep"},
            {0x0100, "RandomDrops"},
            {0x0100, "RandomFade"},
            {0x0100, "RandomFill"},
            {0x0100, "ShineFlash"},
            {0x0100, "ShineSeven"},
            {0x0100, "SingleColorSwing"},
            {0x0100, "SingleWave"},
            {0x0100, "SolitonCreep"},
            {0x0100, "Sparks"},
            {0x0100, "StaticColor"},
            {0x0100, "Toward"},
            {0x0100, "TowardRain"},
            {0x0100, "WalkAcross"},
            {0x0100, "WalkSeven"},
            {0x0100, "WalkToCenter"},
            {0x0100, "Worms"},
        };

        private void Loop(object sender, EventArgs e)
        {
            FrameLabel.Content = $"Frame: {++_frame} / Animation: {ToAnimationName(ChristmasLightsController.CurrentAnimationId())}";
            var elapsed = DateTime.Now - _lastLoop;
            _lastLoop = DateTime.Now;
            foreach (var (color, index) in ChristmasLightsController.Loop(_ellipses.Count, elapsed.Milliseconds).Select((c, i) => (c, i)))
            {
                _ellipses[index].Fill = new SolidColorBrush(color);
            }
        }

        private string ToAnimationName(ushort currentAnimationId)
        {

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
        {
            return index * 8 + ((index + 5) / 5) * 12;
        }

        private Ellipse CreateLed()
        {
            return new Ellipse { Width = 15, Height = 15, Fill = Brushes.Red, Stroke = Brushes.Black };
        }
    }
}
