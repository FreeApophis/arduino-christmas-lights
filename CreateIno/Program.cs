using System;
using System.IO;
using System.Linq;
using Funcky;

namespace CreateIno
{
    class Program
    {
        static void Main(string[] args)
        {
            var _ = args.Any()
                ? CreateInoFile(args)
                : MissingPath();
        }

        private static Unit MissingPath()
        {
            Console.WriteLine("no path set!");

            return new Unit();
        }

        private static Unit CreateInoFile(string[] args)
        {
            var ino = new InoCreator(args.First());


            ino.AddLine("#include <Adafruit_WS2801.h>");
            ino.AddLine("#include <SPI.h>");
            ino.AddLine("#include <WiFi101.h>");
            ino.AddLine("#include <MQTT.h>");
            ino.AddLine(string.Empty);
            ino.AddLine("#define AbstractLedStrip Adafruit_WS2801");
            ino.AddLine(string.Empty);

            DefineConstants(ino);
            AddHelpers(ino);
            AddAnimations(ino);
            AddClearances(ino);

            ino.AddLine(string.Empty);
            ino.AddLine("Adafruit_WS2801 strip = Adafruit_WS2801(pixelCount, dataPin, clockPin);");

            AddLogic(ino);

            ino.Save("christmas-lights.ino");

            return new Unit();
        }

        private static void DefineConstants(InoCreator ino)
        {
            ino.AddLine("const char ssid[] = \"ssid\";");
            ino.AddLine("const char pass[] = \"pass\";");
            ino.AddLine(string.Empty);
            ino.AddLine("uint8_t dataPin = 11;");
            ino.AddLine("uint8_t clockPin = 13;");
            ino.AddLine("uint8_t pixelCount = 100;");
            ino.AddLine(string.Empty);
        }

        private static void AddHelpers(InoCreator ino)
        {
            ino.AddLine("/* Helper */");

            ino.AddFileWithoutIncludes(Path.Combine("manipulation", "Clear.h"));
            ino.AddFileWithoutIncludes(Path.Combine("manipulation", "Clear.cpp"));

            ino.AddFileWithoutIncludes(Path.Combine("manipulation", "ColorManipulation.h"));
            ino.AddFileWithoutIncludes(Path.Combine("manipulation", "ColorManipulation.cpp"));

            ino.AddFileWithoutIncludes(Path.Combine("manipulation", "BrightnessManipulation.h"));
            ino.AddFileWithoutIncludes(Path.Combine("manipulation", "BrightnessManipulation.cpp"));

            ino.AddFileWithoutIncludes(Path.Combine("manipulation", "CrawlDirection.h"));
            ino.AddFileWithoutIncludes(Path.Combine("manipulation", "CrawlDirection.cpp"));

            ino.AddFileWithoutIncludes(Path.Combine("manipulation", "Crawl.h"));
            ino.AddFileWithoutIncludes(Path.Combine("manipulation", "Crawl.cpp"));
            
            ino.AddFileWithoutIncludes(Path.Combine("manipulation", "RandomWalk.h"));
            ino.AddFileWithoutIncludes(Path.Combine("manipulation", "RandomWalk.cpp"));
        }

        private static void AddAnimations(InoCreator ino)
        {
            ino.AddLine("/* Animations */");

            ino.AddFileWithoutIncludes(Path.Combine("animation", "Animation.h"));
            ino.AddFileWithoutIncludes(Path.Combine("animation", "Animation.cpp"));

            ino.AddFileWithoutIncludes(Path.Combine("animation", "Drop.h"));

            ino.AddFileWithoutIncludes(Path.Combine("animation", "Worm.h"));

            ino.AddFileWithoutIncludes(Path.Combine("animation", "CenterRun.h"));
            ino.AddFileWithoutIncludes(Path.Combine("animation", "CenterRun.cpp"));

            ino.AddFileWithoutIncludes(Path.Combine("animation", "CollideOne.h"));
            ino.AddFileWithoutIncludes(Path.Combine("animation", "CollideOne.cpp"));

            ino.AddFileWithoutIncludes(Path.Combine("animation", "ColorSwing.h"));
            ino.AddFileWithoutIncludes(Path.Combine("animation", "ColorSwing.cpp"));

            ino.AddFileWithoutIncludes(Path.Combine("animation", "ColorWalk.h"));
            ino.AddFileWithoutIncludes(Path.Combine("animation", "ColorWalk.cpp"));

            ino.AddFileWithoutIncludes(Path.Combine("animation", "ColorWave.h"));
            ino.AddFileWithoutIncludes(Path.Combine("animation", "ColorWave.cpp"));

            ino.AddFileWithoutIncludes(Path.Combine("animation", "ColorWipe.h"));
            ino.AddFileWithoutIncludes(Path.Combine("animation", "ColorWipe.cpp"));

            ino.AddFileWithoutIncludes(Path.Combine("animation", "EvenOdd.h"));
            ino.AddFileWithoutIncludes(Path.Combine("animation", "EvenOdd.cpp"));

            ino.AddFileWithoutIncludes(Path.Combine("animation", "FlashSeven.h"));
            ino.AddFileWithoutIncludes(Path.Combine("animation", "FlashSeven.cpp"));

            ino.AddFileWithoutIncludes(Path.Combine("animation", "Interference.h"));
            ino.AddFileWithoutIncludes(Path.Combine("animation", "Interference.cpp"));

            ino.AddFileWithoutIncludes(Path.Combine("animation", "LightHouse.h"));
            ino.AddFileWithoutIncludes(Path.Combine("animation", "LightHouse.cpp"));

            ino.AddFileWithoutIncludes(Path.Combine("animation", "LightUp.h"));
            ino.AddFileWithoutIncludes(Path.Combine("animation", "LightUp.cpp"));

            ino.AddFileWithoutIncludes(Path.Combine("animation", "MergeOne.h"));
            ino.AddFileWithoutIncludes(Path.Combine("animation", "MergeOne.cpp"));

            ino.AddFileWithoutIncludes(Path.Combine("animation", "MergeWave.h"));
            ino.AddFileWithoutIncludes(Path.Combine("animation", "MergeWave.cpp"));

            ino.AddFileWithoutIncludes(Path.Combine("animation", "NeoFire.h"));
            ino.AddFileWithoutIncludes(Path.Combine("animation", "NeoFire.cpp"));

            ino.AddFileWithoutIncludes(Path.Combine("animation", "RainBlend.h"));
            ino.AddFileWithoutIncludes(Path.Combine("animation", "RainBlend.cpp"));

            ino.AddFileWithoutIncludes(Path.Combine("animation", "Rainbow.h"));
            ino.AddFileWithoutIncludes(Path.Combine("animation", "Rainbow.cpp"));

            ino.AddFileWithoutIncludes(Path.Combine("animation", "RainCycle.h"));
            ino.AddFileWithoutIncludes(Path.Combine("animation", "RainCycle.cpp"));

            ino.AddFileWithoutIncludes(Path.Combine("animation", "RainFull.h"));
            ino.AddFileWithoutIncludes(Path.Combine("animation", "RainFull.cpp"));

            ino.AddFileWithoutIncludes(Path.Combine("animation", "RandomCreep.h"));
            ino.AddFileWithoutIncludes(Path.Combine("animation", "RandomCreep.cpp"));

            ino.AddFileWithoutIncludes(Path.Combine("animation", "RandomDrops.h"));
            ino.AddFileWithoutIncludes(Path.Combine("animation", "RandomDrops.cpp"));

            ino.AddFileWithoutIncludes(Path.Combine("animation", "RandomFade.h"));
            ino.AddFileWithoutIncludes(Path.Combine("animation", "RandomFade.cpp"));

            ino.AddFileWithoutIncludes(Path.Combine("animation", "RandomFill.h"));
            ino.AddFileWithoutIncludes(Path.Combine("animation", "RandomFill.cpp"));

            ino.AddFileWithoutIncludes(Path.Combine("animation", "ShineFlash.h"));
            ino.AddFileWithoutIncludes(Path.Combine("animation", "ShineFlash.cpp"));

            ino.AddFileWithoutIncludes(Path.Combine("animation", "ShineSeven.h"));
            ino.AddFileWithoutIncludes(Path.Combine("animation", "ShineSeven.cpp"));

            ino.AddFileWithoutIncludes(Path.Combine("animation", "SingleColorSwing.h"));
            ino.AddFileWithoutIncludes(Path.Combine("animation", "SingleColorSwing.cpp"));

            ino.AddFileWithoutIncludes(Path.Combine("animation", "SingleWave.h"));
            ino.AddFileWithoutIncludes(Path.Combine("animation", "SingleWave.cpp"));

            ino.AddFileWithoutIncludes(Path.Combine("animation", "SolitonCreep.h"));
            ino.AddFileWithoutIncludes(Path.Combine("animation", "SolitonCreep.cpp"));

            ino.AddFileWithoutIncludes(Path.Combine("animation", "Sparks.h"));
            ino.AddFileWithoutIncludes(Path.Combine("animation", "Sparks.cpp"));

            ino.AddFileWithoutIncludes(Path.Combine("animation", "StaticColor.h"));
            ino.AddFileWithoutIncludes(Path.Combine("animation", "StaticColor.cpp"));

            ino.AddFileWithoutIncludes(Path.Combine("animation", "Toward.h"));
            ino.AddFileWithoutIncludes(Path.Combine("animation", "Toward.cpp"));

            ino.AddFileWithoutIncludes(Path.Combine("animation", "TowardRain.h"));
            ino.AddFileWithoutIncludes(Path.Combine("animation", "TowardRain.cpp"));

            ino.AddFileWithoutIncludes(Path.Combine("animation", "WalkAcross.h"));
            ino.AddFileWithoutIncludes(Path.Combine("animation", "WalkAcross.cpp"));

            ino.AddFileWithoutIncludes(Path.Combine("animation", "WalkSeven.h"));
            ino.AddFileWithoutIncludes(Path.Combine("animation", "WalkSeven.cpp"));

            ino.AddFileWithoutIncludes(Path.Combine("animation", "WalkToCenter.h"));
            ino.AddFileWithoutIncludes(Path.Combine("animation", "WalkToCenter.cpp"));

            ino.AddFileWithoutIncludes(Path.Combine("animation", "Worms.h"));
            ino.AddFileWithoutIncludes(Path.Combine("animation", "Worms.cpp"));

            ino.AddFileWithoutIncludes(Path.Combine("animation", "ChristmasWave.h"));
            ino.AddFileWithoutIncludes(Path.Combine("animation", "ChristmasWave.cpp"));

            ino.AddFileWithoutIncludes(Path.Combine("animation", "WarmWhiteShimmer.h"));
            ino.AddFileWithoutIncludes(Path.Combine("animation", "WarmWhiteShimmer.cpp"));

            ino.AddFileWithoutIncludes(Path.Combine("animation", "Fire.h"));
            ino.AddFileWithoutIncludes(Path.Combine("animation", "Fire.cpp"));
        }

        private static void AddClearances(InoCreator ino)
        {
            ino.AddLine("/* Clearances */");

            ino.AddFileWithoutIncludes(Path.Combine("clearance", "Clearance.h"));
            ino.AddFileWithoutIncludes(Path.Combine("clearance", "Clearance.cpp"));

            ino.AddFileWithoutIncludes(Path.Combine("clearance", "ClearFade.h"));
            ino.AddFileWithoutIncludes(Path.Combine("clearance", "ClearFade.cpp"));

            ino.AddFileWithoutIncludes(Path.Combine("clearance", "ClearFromCenter.h"));
            ino.AddFileWithoutIncludes(Path.Combine("clearance", "ClearFromCenter.cpp"));

            ino.AddFileWithoutIncludes(Path.Combine("clearance", "ClearHalf.h"));
            ino.AddFileWithoutIncludes(Path.Combine("clearance", "ClearHalf.cpp"));

            ino.AddFileWithoutIncludes(Path.Combine("clearance", "ClearSide.h"));
            ino.AddFileWithoutIncludes(Path.Combine("clearance", "ClearSide.cpp"));

            ino.AddFileWithoutIncludes(Path.Combine("clearance", "EatFromCenter.h"));
            ino.AddFileWithoutIncludes(Path.Combine("clearance", "EatFromCenter.cpp"));
        }

        private static void AddLogic(InoCreator ino)
        {
            ino.AddLine("/* Logic */");

            ino.AddFileWithoutIncludes("AnimationManager.h");
            ino.AddFileWithoutIncludes("AnimationManager.cpp");

            // animation instances ...
            ino.AddFile("LightsController.cpp", 80, 223);

            // The arduino specific code
            ino.AddFile("arduino.template");
        }
    }
}
