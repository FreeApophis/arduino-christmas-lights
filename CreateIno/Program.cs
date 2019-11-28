using System;
using System.ComponentModel;
using System.Linq;
using System.Xml.Linq;

namespace CreateIno
{
    class Program
    {
        static void Main(string[] args)
        {
            InoCreator ino = new InoCreator(args.First());

            ino.AddFile("AbstractLedStrip.h", 4, 17);

            ino.Save("ChristmasLightsController.ino");
        }
    }
}
