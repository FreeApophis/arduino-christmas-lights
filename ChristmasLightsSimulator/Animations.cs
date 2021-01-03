using System.Collections.Generic;
using Funcky.Extensions;

namespace ChristmasLightsSimulator
{
    static class Animations
    {
        public static Dictionary<ushort, string> AllAnimations { get; } = new()
        {
            {0x0000, "Off"},
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
            {0x0111, "Rainbow"},
            {0x0112, "RandomCreep"},
            {0x0113, "RandomDrops"},
            {0x0114, "RandomFade"},
            {0x0115, "RandomFill"},
            {0x0116, "ShineFlash"},
            {0x0117, "ShineSeven"},
            {0x0118, "SingleColorSwing"},
            {0x0119, "SingleWave"},
            {0x011a, "SolitonCreep"},
            {0x011b, "Sparks"},
            {0x011c, "Toward"},
            {0x011d, "TowardRain"},
            {0x011e, "WalkAcross"},
            {0x011f, "WalkSeven"},
            {0x0120, "WalkToCenter"},
            {0x0121, "Worms"},
            {0xaf00, "Static Red"},
            {0xa0f0, "Static Green"},
            {0xa00f, "Static Blue"},
            {0xb000, "Christmas Wave"},
            {0xb001, "Warm White Shimmer"},
            {0xb002, "Fire" },
        };

        public static string ToAnimationName(ushort currentAnimationId)
            => AllAnimations
                .TryGetValue(key: currentAnimationId)
                .GetOrElse("N/A!");
    }
}
