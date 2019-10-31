﻿using System;
using System.Collections.Generic;
using System.Linq;
using System.Runtime.InteropServices;
using System.Windows.Media;

namespace ChristmasLightsSimulator
{
    public static class ChristmasLightsController

    {
        private const int ColorIntSize = 4;

        [DllImport("ChristmasLightsController.dll", EntryPoint = "setup")]
        public static extern ushort Setup();

        [DllImport("ChristmasLightsController.dll", EntryPoint = "loop")]
        private static extern IntPtr PointerLoop();

        public static List<Color> Loop(int count)
        {
            var result = new List<Color>();

            var leds = PointerLoop();

            foreach (var led in Enumerable.Range(0, count))
            {
                var ledColorPointer = IntPtr.Add(leds, led * ColorIntSize);
                var ledColor = (uint)Marshal.PtrToStructure(ledColorPointer, typeof(uint));

                result.Add(Color.FromRgb(
                    (byte)(ledColor / 256 / 256 % 256),
                    (byte)(ledColor / 256 % 256),
                    (byte)(ledColor % 256)));
            }


            return result;
        }

    }
}
