using System;
using System.Buffers;
using System.Globalization;

class Program
{

    private static void StringMethodsPartTwo()
    {
        string res = Console.ReadLine();
        string delimiter = Console.ReadLine();

        res = res.Replace(" ", delimiter);

        Console.WriteLine(res);
    }

    private static void StringFormatting(string productName, int quantity, double unitPrice)
    {
        productName = char.ToUpper(productName[0]) + productName.Substring(1);
        Console.WriteLine($"Product: {productName}, Quantity: {quantity:F1}, Unit Price: {unitPrice:F5}");
    }

    private static void UsingForLoop()
    {
        string text = Console.ReadLine();
        string[] arr = text.Split(',');

        List<string> result = new List<string>();
        for (int i = 0; i < arr.Length; i++)
            if (arr[i].Length > 5)
                result.Add(arr[i]);

        Console.WriteLine(string.Join(", ", result));
    }

    private static void ForeachLoop()
    {
        string[] arr = { "apple", "banana", "orange", "grape", "kiwi" };
        foreach (var word in arr) Console.WriteLine(word.ToUpper());
    }

    //Common Array Operations
    private static double[] CalculateStats(int[] arr)
    {
        double[] resArr = new double[4];
        double max = arr[0];
        double min = arr[0];
        double sum = arr[0];
        for (int i = 1; i < arr.Length; i++)
        {
            sum += arr[i];
            if (arr[i] > max) max = arr[i];
            if (arr[i] < min) min = arr[i];
        }

        resArr[0] = sum;
        resArr[1] = (double)sum / arr.Length;
        resArr[2] = max;
        resArr[3] = min;

        return resArr;
    }

    private static void NumberPatern()
    {
        int n = int.Parse(Console.ReadLine());
        for (int i = 1; i <= n; i += 2) Console.WriteLine(new string('*', i));
    }

    private static void PatternFinder()
    {
        string arrString1 = Console.ReadLine();
        string arrString2 = Console.ReadLine();
        string[] str1 = arrString1.Split(",");
        string[] str2 = arrString2.Split(",");
        Console.WriteLine(arrString1.Contains(arrString2));
    }

    private static double CalculateAverageGrade(int[] grades)
    {
        int sum = 0;
        foreach (var item in grades) sum += item;
        return (double)sum / grades.Length;
    }

    private static int GetElement(int[][] array, int row, int col)
    {
        try
        {
            return array[row][col];
        }
        catch (IndexOutOfRangeException)
        {
            return -1;
        }
    }

    private static void PrintMatrix(int[][] matrix)
    {
        for (int i = 0; i < matrix.Length; i++)
        {
            for (int j = 0; j < matrix[i].Length; j++)
                Console.Write(matrix[i][j] + " ");
            Console.WriteLine();
        }
    }

    private static int[][] createTriangle(int size)
    {
        int[][] res = new int[size][];
        for (int i = 0; i < size; i++)
        {
            res[i] = new int[i + 1];
            for (int j = 0; j < res[i].Length; j++)
                res[i][j] = i + j;
        }

        return res;
    }

    private static int[][] multiplyMatrices(int[][] matrix1, int[][] matrix2)
    {
        int rows = matrix1.Length;
        int cols = matrix2[0].Length;
        int inner = matrix2.Length;

        int[][] result = new int[rows][];
        for (int i = 0; i < rows; i++)
        {
            result[i] = new int[cols];
            for (int j = 0; j < cols; j++)
            {
                int sum = 0;
                for (int k = 0; k < inner; k++)
                {
                    sum += matrix1[i][k] * matrix2[k][j];
                }

                result[i][j] = sum;
            }
        }

        return result;
    }

    private static int findDiagonalDifference(int[][] matrix)
    {
        int rightSum = 0, leftSum = 0;

        // RIGHT DIAGONAL(PRIMARY)
        for (int i = 0; i < matrix.Length; i++)
        {
            for (int j = 0; j < matrix[i].Length; j++)
            {
                if (i == j) rightSum += matrix[i][j];
            }
        }

        // LEFT DIAGONAL
        for (int i = 0; i < matrix.Length; i++)
        {
            for (int j = matrix.Length - 1; j >= 0; j--)
            {
                if (j == (matrix.Length - 1) - i) leftSum += matrix[i][j];
            }
        }

        return Math.Abs(rightSum - leftSum);
    }

    private static int[][] ProcessMatrix(int[][] matrix)
    {
        int[][] result = new int[matrix.Length][];

        for (int i = 0; i < matrix.Length; i++)
        {
            result[i] = new int[matrix[i].Length];

            for (int j = 0; j < matrix[i].Length; j++)
            {
                int sum = 0;

                // up
                if (i > 0)
                    sum += matrix[i - 1][j];

                // down
                if (i < matrix.Length - 1)
                    sum += matrix[i + 1][j];

                // left
                if (j > 0)
                    sum += matrix[i][j - 1];

                // right
                if (j < matrix[i].Length - 1)
                    sum += matrix[i][j + 1];

                result[i][j] = sum;
            }
        }

        return result;
    }

    private static string evaluateApplication(int age, int score, bool hasPriorExperience)
    {
        /*Returns a string based on these multiple conditions:
        "Accepted" if the applicant is at least 18 years old AND has a score above 70
        "Accepted with Merit" if the applicant meets the above conditions AND has prior experience
        "Provisionally Accepted" if the applicant is at least 18 years old AND has a score between 50 and 70 inclusive
        "Rejected" in all other cases*/

        string result = "";

        if (age >= 18 && score > 70 && hasPriorExperience) result = "Accepted with Merit";
        else if (age >= 18 && score >= 50 && score <= 70) result = "Provisionally Accepted";
        else if (age >= 18 && score > 70) result = "Accepted";
        else result = "Rejected";

        return result;
    }

    private static void CheckMovieRestriction(int age, bool withParent, string movieRating)
    {
        switch (movieRating)
        {
            case "G":
                Console.WriteLine("Allowed");
                break;

            case "PG":
                if (age >= 8 || withParent)
                {
                    Console.WriteLine("Allowed");
                }
                else
                {
                    Console.WriteLine("Not Allowed");
                }

                break;

            case "PG-13":
                if (age >= 13 || (withParent && age >= 10))
                {
                    Console.WriteLine("Allowed");
                }
                else
                {
                    Console.WriteLine("Not Allowed");
                }

                break;

            case "R":
                if (age >= 17 || (withParent && age >= 15))
                {
                    Console.WriteLine("Allowed");
                }
                else
                {
                    Console.WriteLine("Not Allowed");
                }

                break;

            default:
                Console.WriteLine("Invalid rating");
                break;
        }
    }

    public static bool determineAccess(bool isAdmin, bool isLoggedIn, int timeOfDay, bool isMaintenanceMode,
        bool hasEmergencyAccess)
    {
        // Write your code here
        return (isAdmin && isLoggedIn) || ((timeOfDay >= 9 && timeOfDay <= 17) && isLoggedIn && !isMaintenanceMode) ||
               hasEmergencyAccess;
    }

    public static bool ValidateUserAccess(bool isAuthenticated, bool hasAdminRole,
        bool hasValidToken, bool isInOfficeNetwork,
        bool isWorkingHours)
    {
        // Write your code here
        if ((isAuthenticated && hasAdminRole) ||
            ((isAuthenticated && hasValidToken) && (isInOfficeNetwork || isWorkingHours)))
        {
            Console.WriteLine("Access granted");
            return true;
        }

        Console.WriteLine("Access denied");
        return false;
    }

    public static int convertGradeToPoints(string letterGrade)
    {
        // Write your code here
        int result = 0;
        if (!String.IsNullOrEmpty(letterGrade))
        {
            letterGrade = letterGrade.ToLower();
            switch (letterGrade)
            {
                case "a":
                    result = 4;
                    break;
                case "b":
                    result = 3;
                    break;
                case "c":
                    result = 2;
                    break;
                case "d":
                    result = 1;
                    break;
                case "f":
                    result = 0;
                    break;
                default:
                    result = -1;
                    break;
            }
        }
        else result = -1;

        return result;
    }
    
    public static string DescribeShapeUsingIf(int sides) {
        // Implement using if-else statements
        string result = "";
        if (sides == 3) result = "Triangle";
        else if (sides == 4) result = "Quadrilateral";
        else if (sides == 5) result = "Pentagon";
        else if (sides == 6) result = "Hexagon";
        else result = $"Polygon with {sides} sides";
        
        return result;
    }
    
    public static string DescribeShapeUsingSwitch(int sides) {
        // Implement using switch statement
        string result = "";
        switch (sides)
        {
            case 3: result = "Triangle"; break;
            case 4: result = "Quadrilateral"; break;
            case 5: result = "Pentagon"; break;
            case 6: result = "Hexagon"; break;
            default: result = $"Polygon with {sides} sides"; break;
        }
        return result;
    }
    
    public static int calculatePrice(string productType, string productTier, int basePrice)
    {
        // Write your code here
        int price = basePrice;
        switch (productType)
        {
            case "Electronics":
                switch (productTier)
                {
                    case "Basic": price += 50; break;
                    case "Premium":  price += 100; break;
                    case "Luxury": price += 250; break;
                }

                break;
            case "Clothing":
                switch (productTier)
                {
                    case "Basic": price += 10; break;
                    case "Premium":  price += 50; break;
                    case "Luxury": price += 100; break;
                }

                break;
            case "Food":
                switch (productTier)
                {
                    case "Basic": price += 0; break;
                    case "Premium":  price += 15; break;
                    case "Luxury": price += 30; break;
                }

                break;
        }
        return price;
    }
    
    public static void GetSportRecommendation(string weather, string preferredLocation)
    {
        // Write your code here
        string result = "";

        switch (weather)
        {
            case "Sunny":
                switch (preferredLocation)
                {
                    case "Indoor": result = "Basketball at an indoor court is a good choice."; break;
                    case "Outdoor": result = "Soccer is perfect for sunny days outside."; break;
                    default: result = $"No recommendation available for {preferredLocation}"; break;

                }

                break;
            case "Rainy":
                switch (preferredLocation)
                {
                    case "Indoor": result = "Swimming in an indoor pool is recommended."; break;
                    case "Outdoor": result = "Rugby is often played in the rain."; break;
                    default: result = $"No recommendation available for {preferredLocation}"; break;

                }

                break;
            case "Snowy":
                switch (preferredLocation)
                {
                    case "Indoor": result = "Ice hockey at an indoor rink is ideal."; break;
                    case "Outdoor": result = "Skiing would be great in the snow."; break;
                    default: result = $"No recommendation available for {preferredLocation}"; break;

                }

                break;
            default: result = $"No recommendation available for {weather}"; break;
                
        }

        Console.WriteLine(result);
    }
    
    public static string analyzeCandidateProfile(int age, int experienceYears, string skillLevel, bool hasReferences)
    {
        // Write your code here
        /*
        "Interview Further" if:
            Candidate is 22+ years old AND has 3+ years experience AND is at least "Intermediate" level
            OR candidate is 18+ years old AND has 7+ years experience
        "Consider for Internship" if:
            Candidate is 18+ years old AND is "Beginner" level
            OR candidate is under 22 years old but has references
            "Reject" in all other cases
         */
        string result = "";
        if (((age >= 25 && age <= 40) && experienceYears >= 5 && skillLevel == "Expert") || (experienceYears >= 10 && hasReferences)) result = "Hire Immediately";
        else if((age >= 22 && experienceYears >= 3 && skillLevel == "Intermediate") || (age >= 18 && experienceYears >= 7)) result = "Interview Further";
        else if ((age >= 18 && skillLevel == "Beginner") || (age <= 22 && hasReferences)) result = "Consider for Internship";
        else result = "Reject";
        
        return result;
    }

    public static void Main(String[] args)
    {
        string weather = Console.ReadLine();
        string preferredLocation = Console.ReadLine();
        
        GetSportRecommendation(weather, preferredLocation);
        
    }
}
