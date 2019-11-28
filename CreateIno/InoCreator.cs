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
                    .ReadAllLines(SourceDirectory(relativeFilename), Encoding.UTF8)
                    .Select((line, index) => (line, index))
                    .Where(l => IsSelectedLine(l.index, from, to))
                    .Select(l => l.line)
                );
        }

        public void AddFileWithoutIncludes(string relativeFilename)
        {
            var offset = 1;
            var nextLine = 1;

            var lastInclude = File
                .ReadAllLines(SourceDirectory(relativeFilename), Encoding.UTF8)
                .Select((line, index) => (line, index))
                .LastOrDefault(l => l.line.StartsWith("#include"))
                .index;

            AddFile(relativeFilename, lastInclude + offset + nextLine);
        }

        private string SourceDirectory(string relativeFilename)
        {
            return Path.Combine(_sourcePath, "ChristmasLightsController", relativeFilename);
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
            File.WriteAllLines(TargetDirectory(relativeFilename), _lines);
        }

        private string TargetDirectory(string relativeFilename)
        {
            return Path.Combine(_sourcePath, "christmas-lights", relativeFilename);
        }
    }
}