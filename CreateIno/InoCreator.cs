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

        public void AddFile(string relativeFilename, int? from = null, int? to = null)
        {
            _lines.AddRange(
                File
                    .ReadAllLines(Path.Combine(_sourcePath, relativeFilename), Encoding.UTF8)
                    .Select((line, index) => (line, index))
                    .Where(l => IsSelectedLine(l.index, from, to))
                    .Select(l => l.line)
                );
        }

        private bool IsSelectedLine(int index, int? from, int? to)
        {
            return (!from.HasValue || from.Value <= index + 1) &&
                   (!to.HasValue || to.Value >= index);
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