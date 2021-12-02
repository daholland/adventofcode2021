namespace adventofcode;

public class DayTwo
{
    public static List<(string, int)> ReadDayTwoInput()
    {
        var commands = new List<(string, int)>();
        foreach (string line in System.IO.File.ReadLines("../../../inputdata/day2input.txt"))
        {
            var splitline = line.Split(" ", StringSplitOptions.TrimEntries | StringSplitOptions.RemoveEmptyEntries);
            commands.Add((splitline[0], int.Parse(splitline[1])));
        }

        return commands;
    }

    public static int PartOne()
    {
        var commands = ReadDayTwoInput();

        var depth = 0;
        var position = 0;

        foreach (var c in commands)
        {
            switch (c)
            {
                case (string command, int x) when command == "forward": 
                    position += x;
                    Console.WriteLine($"Forward: {x}");
                    break;
                case (string command, int x) when command == "up": 
                    depth -= x;
                    Console.WriteLine($"Up: {x}");
                    break;
                case (string command, int x) when command == "down": 
                    depth += x;
                    Console.WriteLine($"Down: {x}");
                    break;

            };
        }
        Console.WriteLine($"Position: {position}");
        Console.WriteLine($"Depth: {depth}");
        
        return depth * position;
    }
    
    public static int PartTwo()
    {
        var commands = ReadDayTwoInput();

        var depth = 0;
        var position = 0;
        var aim = 0;

        foreach (var c in commands)
        {
            switch (c)
            {
                case (string command, int x) when command == "forward": 
                    position += x;
                    depth += aim * x;
                    Console.WriteLine($"Forward: {x}");
                    break;
                case (string command, int x) when command == "up": 
                    aim -= x;
                    Console.WriteLine($"Up: {x}");
                    break;
                case (string command, int x) when command == "down": 
                    aim += x;
                    Console.WriteLine($"Down: {x}");
                    break;

            };
        }
        Console.WriteLine($"Position: {position}");
        Console.WriteLine($"Depth: {depth}");
        Console.WriteLine($"Aim: {aim}");
        return depth * position;
    }
}