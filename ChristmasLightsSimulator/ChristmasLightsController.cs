using System;
using System.Collections.Generic;
using System.Linq;
using System.Runtime.InteropServices;
using System.Windows.Media;
using Funcky.Extensions;
using Funcky.Monads;

namespace ChristmasLightsSimulator
{
    public static class ChristmasLightsController

    {
        private const int ColorIntSize = 4;
        private const int Red = 2;
        private const int Green = 1;
        private const int Blue = 0;

        [DllImport("ChristmasLightsController.dll", EntryPoint = "setup")]
        public static extern ushort Setup();

        [DllImport("ChristmasLightsController.dll", EntryPoint = "loop")]
        private static extern IntPtr PointerLoop(long millis);

        [DllImport("ChristmasLightsController.dll", EntryPoint = "setAnimation")]
        public static extern void SetAnimation(ushort animationId);

        [DllImport("ChristmasLightsController.dll", EntryPoint = "currentAnimationId")]
        public static extern ushort CurrentAnimationId();

        public static IEnumerable<Color> Loop(int count, long millis)
            => TransformLeds(count, PointerLoop(millis));

        private static IEnumerable<Color> TransformLeds(int count, IntPtr leds)
            => Enumerable.Range(0, count)
                .WhereSelect(ExtractPixelColor(leds));

        private static Func<int, Option<Color>> ExtractPixelColor(IntPtr leds)
            => index => ToColor(leds.At(index));

        private static IntPtr At(this IntPtr leds, int index)
            => IntPtr.Add(leds, index * ColorIntSize);

        private static Option<Color> ToColor(IntPtr led)
            => from r in ExtractColor(led, Red)
               from g in ExtractColor(led, Green)
               from b in ExtractColor(led, Blue)
               select Color.FromRgb(r, g, b);

        private static Option<byte> ExtractColor(IntPtr led, int position)
            => ColorValue(led).AndThen(ExtractByte(position));

        private static Option<uint> ColorValue(IntPtr led)
            => Marshal.PtrToStructure(led, typeof(uint)) is uint colorValue
                ? Option.Some(colorValue)
                : Option<uint>.None();

        private static Func<uint, byte> ExtractByte(int position)
            => l
                => (byte)((l >> (position * 8)) % ByteSize);

        private static uint ByteSize
            => byte.MaxValue + 1;
    }
}
