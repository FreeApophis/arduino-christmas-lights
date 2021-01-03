using System;
using System.Collections.Generic;
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

            return new();
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

            return new();
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


            var helpers = new List<string>{
                "Clear",
                "ColorManipulation",
                "BrightnessManipulation",
                "CrawlDirection",
                "Crawl",
                "RandomWalk"
            };

            ino.YieldHeaderAndSource("manipulation", helpers);
        }

        private static void AddAnimations(InoCreator ino)
        {
            ino.AddLine("/* Animations */");

            // Base Interface

            ino.YieldHeaderAndSource("animation", new List<string> { "Animation" });

            // Needed Helpers
            ino.AddFileWithoutIncludes(Path.Combine("animation", "Drop.h"));
            ino.AddFileWithoutIncludes(Path.Combine("animation", "Worm.h"));

            ino.YieldHeaderAndSource("animation", ChristmasAnimations.Animations);

            // Animations with non-default constructors

            ino.YieldHeaderAndSource("animation", new List<string> { "StaticColor" });
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
            ino.AddLine(string.Empty);

            Animations(ino);
            Clearances(ino);

            // The arduino specific code
            ino.AddFile("arduino.template");
        }

        private static void Animations(InoCreator ino)
        {
            ino.AddLine("// Instantiate Animations");
            ino.YieldInstances(ChristmasAnimations.Animations);

            ino.AddLine("StaticColor off(&strip, ToColor(0, 0, 0), 0x0000);");
            ino.AddLine("StaticColor redColor(&strip, ToColor(255, 0, 0), 0xaf00);");
            ino.AddLine("StaticColor greenColor(&strip, ToColor(0, 255, 0), 0xa0f0);");
            ino.AddLine("StaticColor blueColor(&strip, ToColor(0, 0, 255), 0xa00f);");

            var otherAnimations = new List<string> { "Off", "RedColor", "GreenColor", "BlueColor" };

            ino.YieldArrays("Animation", ChristmasAnimations.Animations.Concat(otherAnimations));
        }

        private static void Clearances(InoCreator ino)
        {
            ino.AddLine("// Instantiate Clearances");
            ino.YieldInstances(ChristmasAnimations.Clearances);
            ino.YieldArrays("Clearance", ChristmasAnimations.Clearances);
        }
    }
}
