using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using Funcky.Extensions;

namespace CreateIno
{
    internal class InoCreator
    {
        private const int NoIncludesOffset = 1;
        private const int NoIncludesNextLine = 1;

        private readonly string _sourcePath;
        private readonly List<string> _lines = new();

        public InoCreator(string sourcePath)
        {
            _sourcePath = sourcePath;
        }

        public void AddFile(string relativeFilename, int? from = null, int? to = null)
            => _lines.AddRange(LinesFromFile(relativeFilename, from, to));

        private IEnumerable<string> LinesFromFile(string relativeFilename, int? from, int? to)
            => File
                .ReadAllLines(SourceDirectory(relativeFilename), Encoding.UTF8)
                .Select((line, index) => (line, index))
                .Where(l => IsSelectedLine(l.index, from, to))
                .Select(l => l.line);

        public void AddFileWithoutIncludes(string relativeFilename)
            => AddFile(relativeFilename, LastInclude(relativeFilename) + NoIncludesOffset + NoIncludesNextLine);

        private int LastInclude(string relativeFilename)
            => File
                .ReadAllLines(SourceDirectory(relativeFilename), Encoding.UTF8)
                .Select((line, index) => (line, index))
                .LastOrDefault(l => l.line.StartsWith("#include"))
                .index;

        private string SourceDirectory(string relativeFilename)
            => Path.Combine(_sourcePath, "ChristmasLightsController", relativeFilename);

        private static bool IsSelectedLine(int index, int? from, int? to)
            => (!from.HasValue || from.Value <= index + 1) &&
               (!to.HasValue || to.Value >= index);

        public void AddLine(string line)
            => _lines.Add(line);

        public void Save(string relativeFilename)
            => File.WriteAllLines(TargetDirectory(relativeFilename), _lines);

        private string TargetDirectory(string relativeFilename)
            => Path.Combine(_sourcePath, "christmas-lights", relativeFilename);

        internal void YieldHeaderAndSource(string path, List<string> files)
            => files.ForEach(file => ConcatHeaderAndCpp(path, file));

        private void ConcatHeaderAndCpp(string path, string file)
        {
            AddFileWithoutIncludes(Path.Combine(path, $"{file}.h"));
            AddFileWithoutIncludes(Path.Combine(path, $"{file}.cpp"));
        }

        private static string ToCamelCase(string variable)
            => char.ToLowerInvariant(variable[0]) + variable.Substring(1);

        internal void YieldInstances(IEnumerable<string> animations) 
            => animations.ForEach(animation => AddLine($"{animation} {ToCamelCase(animation)}(&strip);"));

        private static string YieldPointer(IEnumerable<string> animations)
            => string.Join(",\n", animations.Select(animation => $"    &{ToCamelCase(animation)}"));

        internal void YieldArrays(string type, IEnumerable<string> animations)
        {
            AddLine(string.Empty);
            AddLine($"{type}* {type.ToLower()}s[] = {{");
            AddLine(YieldPointer(animations));
            AddLine("}");
            AddLine(string.Empty);
        }
    }
}