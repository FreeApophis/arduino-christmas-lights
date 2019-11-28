using System;
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

            ino.AddFile("AbstractLedStrip.h");

            ino.Save("ChristmasLightsController.ino");

            return new Unit();
        }
    }
}
