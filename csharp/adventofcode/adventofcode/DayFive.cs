namespace adventofcode;

public record struct Point(int X, int Y);

public class Canvas
{
    private int[,] cells;
    public Canvas()
    {
        cells = new int[1000,1000];
    }

    public void DrawLine(Point p1, Point p2)
    {
        //Console.WriteLine($"Writing Line! {p1} {p2}");
        if (p1.X == p2.X)
        {
            
            if (p1.Y > p2.Y)
            {
                for (var ycursor = p1.Y; ycursor >= p2.Y; ycursor--)
                {
                    cells[ycursor, p1.X] = cells[ycursor, p1.X] + 1;
                }
            } else if (p1.Y < p2.Y)
            {
                for (var ycursor = p1.Y; ycursor <= p2.Y; ycursor++)
                {
                    cells[ycursor, p1.X] = cells[ycursor, p1.X] + 1;
                }
            }

        } else if (p1.Y == p2.Y)
        {
            if (p1.X > p2.X)
            {
                for (var xcursor = p1.X; xcursor >= p2.X; xcursor--)
                {
                    cells[p1.Y, xcursor] = cells[p1.Y, xcursor] + 1;
                }
            } else if (p1.X < p2.X)
            {
                for (var xcursor = p1.X; xcursor <= p2.X; xcursor++)
                {
                    cells[p1.Y, xcursor] = cells[p1.Y, xcursor] + 1;
                }
            }    
        }
        else
        {
            //diagonal line
            if (p1.X < p2.X) {
                if (p1.Y < p2.Y)
                {
                    // x + 1 y + 1, DR
                    for (var i = 0; i <= Math.Abs(p2.X - p1.X); i++)
                    {
                        var x = p1.X + i;
                        var y = p1.Y + i;
                        cells[y, x] = cells[y, x] + 1;
                    }
                    
                }
                else
                {
                    // x + 1, y - 1, UR
                    for (var i = 0; i <= Math.Abs(p2.X - p1.X); i++)
                    {
                        var x = p1.X + i;
                        var y = p1.Y - i;
                        cells[y, x] = cells[y, x] + 1;
                    }
                }
            }
            else
            {
                if (p1.Y < p2.Y)
                {
                    // x - 1 y + 1, DL
                    for (var i = 0; i <= Math.Abs(p2.X - p1.X); i++)
                    {
                        var x = p1.X - i;
                        var y = p1.Y + i;
                        cells[y, x] = cells[y, x] + 1;
                    }
                }
                else
                {
                    // x - 1, y - 1, UL
                    for (var i = 0; i <= Math.Abs(p2.X - p1.X); i++)
                    {
                        var x = p1.X - i;
                        var y = p1.Y - i;
                        cells[y, x] = cells[y, x] + 1;
                    }
                }
            }
        }
    }

    public int CountGreaterThanN(int n)
    {
        var sum = 0;
        foreach (var i in cells)
        {
            if (i > n)
            {
                sum += 1;
            }
        }

        return sum;
    }
}


public class DayFive
{
    public static List<(Point, Point)> ReadDayFiveInput()
    {
        var lines = new List<(Point, Point)>();
        foreach (string line in System.IO.File.ReadLines("../../../inputdata/day5input.txt"))
        {
            var splitline = line.Split(" -> ", StringSplitOptions.TrimEntries | StringSplitOptions.RemoveEmptyEntries);
            var split1 = splitline[0].Split(",");
            var p1 = new Point(int.Parse(split1[0]), int.Parse(split1[1]));
            var split2 = splitline[1].Split(",");
            var p2 = new Point(int.Parse(split2[0]), int.Parse(split2[1]));
            lines.Add((p1, p2));

        }

        return lines;
    }

    public static int PartOne()
    {
        var lines = ReadDayFiveInput();

        var horizvertlines = lines.Where((l) => l.Item1.X == l.Item2.X || l.Item1.Y == l.Item2.Y).ToList();

        var canvas = new Canvas();
        
        
        foreach (var l in horizvertlines)
        {
            //only vert and horiz lines
            canvas.DrawLine(l.Item1, l.Item2);
           
        }

        var twoorgreater = canvas.CountGreaterThanN(1);
        
        
        return twoorgreater;
    }
    
    public static int PartTwo()
    {
        var lines = ReadDayFiveInput();
        
        var canvas = new Canvas();
        
        
        foreach (var l in lines)
        {
            //only vert and horiz lines
            canvas.DrawLine(l.Item1, l.Item2);
           
        }

        var twoorgreater = canvas.CountGreaterThanN(1);
        
        return twoorgreater;
    }
}