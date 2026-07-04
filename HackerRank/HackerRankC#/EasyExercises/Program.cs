using System;
using System.Collections;
using System.Runtime.ConstrainedExecution;
public class Program
{
    public static string kangaroo(int x1, int v1, int x2, int v2)
    {
        if(x2 > x1 && v2 > v1) return "NO";
        for(int i = 0;i < 5000;++i){
            if(x1 == x2) return "YES";
            x1 += v1;
            x2 += v2;
        }
        return "NO";
    }

    public static void countApplesAndOranges(int s, int t, int a, int b, List<int> apples, List<int> oranges)
    {
        int applesLanded = 0;
        int orangesLanded = 0;

        for(int i = 0;i < apples.Count;++i) apples[i] += a;
        for(int i = 0;i < oranges.Count;++i) oranges[i] += b;

        for(int i = 0;i < apples.Count; ++i)
        {
            if(apples[i] >= s && t >= apples[i]) applesLanded++;
        }

        for (int i = 0;i < oranges.Count;++i)
        {
            if(oranges[i] >= s && t >= oranges[i]) orangesLanded++;
        }

        Console.WriteLine(applesLanded);
        Console.WriteLine(orangesLanded);
    }
    public static void Main(string[] args)
    {
        string[] firstMultipleInput = Console.ReadLine().TrimEnd().Split(' ');
        int s = Convert.ToInt32(firstMultipleInput[0]);
        int t = Convert.ToInt32(firstMultipleInput[1]);

        string[] secondMultipleInput = Console.ReadLine().TrimEnd().Split(' ');
        int a = Convert.ToInt32(secondMultipleInput[0]);
        int b = Convert.ToInt32(secondMultipleInput[1]);

        string[] thirdMultipleInput = Console.ReadLine().TrimEnd().Split(' ');
        int m = Convert.ToInt32(thirdMultipleInput[0]);
        int n = Convert.ToInt32(thirdMultipleInput[1]);
        
        List<int> apples = Console.ReadLine().TrimEnd().Split(' ').ToList().Select(applesTemp => Convert.ToInt32(applesTemp)).ToList();
        List<int> oranges = Console.ReadLine().TrimEnd().Split(' ').ToList().Select(orangesTemp => Convert.ToInt32(orangesTemp)).ToList();
        countApplesAndOranges(s, t, a, b, apples, oranges);
    }
}
