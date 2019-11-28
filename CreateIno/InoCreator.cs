using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;

namespace CreateIno
{
    internal class InoCreator
    {
        private readonly string _sourcePath;
        private readonly List<string> _lines = new List<string>();

        public InoCreator(string sourcePath)
        {
            _sourcePath = sourcePath;
        }

        public void AddFile(string relativeFilename, int from, int to)
        {
            foreach (var (line, index) in File.ReadAllLines(Path.Combine(_sourcePath, relativeFilename), Encoding.UTF8).Select((line, index) => (line, index)))
            {
                if (from <= index + 1 && index < to)
                {
                    _lines.Add(line);
                }
            }
        }

        public void AddLine(string line)
        {
            _lines.Add(line);
        }

        public void Save(string relativeFilename)
        {
            File.WriteAllLines(Path.Combine(_sourcePath, relativeFilename), _lines);
        }
    }
}