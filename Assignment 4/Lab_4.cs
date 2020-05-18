using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Xml.Linq;

class Lab4
{
    static IEnumerable<string> EnumerateFilesRecursively(string path)
    {
        var files = Directory.EnumerateFiles(path, "*", SearchOption.AllDirectories);
        foreach (var file in files)
            yield return file;
    }
    static string FormatByteSize(long byteSize)
    {
        string[] units = { "B", "kB", "MB", "GB", "TB", "PB", "EB", "ZB" };
        int order = 0;
        double size = (double)byteSize;
        while (size >= 1000 && order < units.Length - 1)
        {
            order++;
            size /= 1000;
        }
        return $"{size:0.00}{units[order]}";
    }
    static XDocument CreateReport(IEnumerable<string> files)
    {
        var ExtCounts = files
            .GroupBy(file => Path.GetExtension(file).ToLower())
            .Select(g => new
            {
                Type = g.Key,
                Count = g.Count()
            });
        var ExtSizes = files
            .GroupBy(file => Path.GetExtension(file).ToLower())
            .Select(g => new
            {
                Type = g.Key,
                Size = g.Sum(size => new FileInfo(size).Length)
            });
        var output = ExtCounts.Join(ExtSizes,
            c => c.Type, s => s.Type,
            (c, s) => new
            {
                c.Type,
                c.Count,
                s.Size
            }).OrderByDescending(g => g.Size);
        XDocument report = new XDocument(
            new XDeclaration("1.0", "utf-8", "no"),
            new XDocumentType("html", null, null, null),
            new XElement("html",
                new XElement("head",
                    new XElement("title", "File Report"),
                    new XElement("style", "table, th, td { border: 1px solid black; }")
                ),
                new XElement("body",
                    new XElement("table", new XAttribute("border", "1"),
                        new XElement("thead",
                            new XElement("tr",
                                new XElement("th", "Type"),
                                new XElement("th", "Count"),
                                new XElement("th", "Total Size")
                            )
                        ),
                        new XElement("tbody",
                            from o in output
                            select new XElement("tr",
                                new XElement("td", o.Type),
                                new XElement("td", o.Count, new XAttribute("align", "right")),
                                new XElement("td", FormatByteSize(o.Size), new XAttribute("align", "right"))
                            )
                        )
                    )
                )
            )
        );
        return report;
    }
    public static void Main(string[] args)
    {
        if (args.Length != 2)
        {
            Console.Out.WriteLine("2 arguments are needed.");
            return;
        }
        // arg1: input folder path, arg2: output folder path
        var report = CreateReport(EnumerateFilesRecursively(args[0]));
        report.Save(Path.Combine(args[1], "report.html"));
    }
}