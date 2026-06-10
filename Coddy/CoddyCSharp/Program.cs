using System;
using System.IO;
using System.Buffers;
using System.Diagnostics;
using System.Globalization;
using System.Linq.Expressions;
using System.Collections;
using System.Text.RegularExpressions;


class Program
{

    private static void StringMethodsPartTwo()
    {
        string? res = Console.ReadLine();
        string? delimiter = Console.ReadLine();

        res = res?.Replace(" ", delimiter);

        Console.WriteLine(res);
    }

    private static void StringFormatting(string productName, int quantity, double unitPrice)
    {
        productName = char.ToUpper(productName[0]) + productName.Substring(1);
        Console.WriteLine($"Product: {productName}, Quantity: {quantity:F1}, Unit Price: {unitPrice:F5}");
    }

    private static void UsingForLoop()
    {
        string? text = Console.ReadLine();
        string[]? arr = text?.Split(',');

        List<string> result = new List<string>();
        for (int i = 0; i < arr?.Length; i++)
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
        int? n = int.Parse(Console.ReadLine());
        for (int i = 1; i <= n; i += 2) Console.WriteLine(new string('*', i));
    }

    private static void PatternFinder()
    {
        string? arrString1 = Console.ReadLine();
        string? arrString2 = Console.ReadLine();
        string[]? str1 = arrString1?.Split(",");
        string[]? str2 = arrString2?.Split(",");
        Console.WriteLine(arrString1?.Contains(arrString2));
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

    private static int optimizedSum(int[] numbers)
    {
        int sum = 0, length = numbers.Length;
        for(int i = 0;i < length;i++) sum += numbers[i];
        return sum;
    }

    private static int countElements(string[][] nestedArray)
    {
        // Write your code here
        int count = 0, length = nestedArray.Length;
        for(int  i = 0;i < length;i++) 
            for(int j = 0;j < nestedArray[i].Length;j++)
                count++;
        return count;
    }

    private static int BinarySearch(int[] numbers, int target)
    {
        // Write your code here
        Array.Sort(numbers);

        int leftSide = 0, rightSide = numbers.Length-1, middle = leftSide + (rightSide - leftSide) / 2;
        while(leftSide <= rightSide)
        {
            middle = leftSide + (rightSide - leftSide) / 2;
            if(numbers[middle] == target) return middle;
            else if(numbers[middle] < target) leftSide = middle + 1;
            else if(numbers[middle] > target) rightSide = middle - 1;
        }
        return -1;
    }

    public static int findWithDifferentLoops(int[] numbers, int target)
    {
        // Write your code here
        int index = -1;
        for(int i = 0; i < numbers.Length;i++) if(numbers[i] == target) index = i;
        return index;
    }

    private static int[] findElementOccurrences(int[] numbers, int target)
    {
        // Write your code here
        int occurrences = 0;
        for(int i = 0; i < numbers.Length;i++) if(numbers[i] == target) occurrences++;

        int[] result = new int[4];
        for(int  i = 0;i < 4;i++) result[i] = occurrences;

        return result;
    }

    public static int refactorArrayFilter(int[] numbers)
    {
        // Write your code here
        int count = 0;
        foreach(int number in numbers) if(number % 3 == 0) count++;
        return count;
    }

    public static int optimizeSearchAlgorithm(int[][] data, int target)
    {
        // Write your solution here
        int occurrences = 0, lenght = data.Length;
        for(int i = 0;i < lenght;i++)
            for(int j = 0;j < data[i].Length;j++)
                if(data[i][j] == target) occurrences++;
        return occurrences;
    }

    private static string ProcessPayment(decimal paymentAmount, decimal accountBalance, bool isAccountLocked)
    {
        // Write your code here
        string result = "Payment processed successfully";
        if(paymentAmount <= 0) result = "Error: Payment amount must be positive";
        else if(accountBalance < paymentAmount) result = "Error: Insufficient funds";
        else if(isAccountLocked) result = "Error: Account is locked";

        return result;
    }

    private static int DivideNumbers(int numerator, int denominator)
    {
        // Write your code here
        if(denominator == 0)
        {
            Console.WriteLine("Cannot divide by zero");
            return 0;    
        }
        return numerator / denominator;
    }

    private static bool validateRegistration(string username, string password, int age)
    {
        // Write your code here using guard clauses
        if (String.IsNullOrEmpty(username))
        {
            Console.WriteLine("Username cannot be empty");
            return false;
        }

        if(String.IsNullOrEmpty(password) || password.Length < 8)
        {
            Console.WriteLine("Password must be at least 8 characters");
            return false;
        }

        if (age < 18)
        {
            Console.WriteLine("User must be at least 18 years old");
            return  false;
        }

        Console.WriteLine("Registration successful");
        return true;
    }

    private static void ProcessCommands(string command)
    {
        // Write your code here
        switch (command)
        {
            case "start": Console.WriteLine("Starting process"); goto end;
            case "stop": Console.WriteLine("Stopping process"); goto end;
            case "pause": Console.WriteLine("Pausing process"); goto end;
            default: Console.WriteLine("Unknown command"); goto end;
        }

        end:
        Console.WriteLine("Command processed");
    }

    private static int ProcessNumbers(int[] numbers)
    {
        // Write your code here
        int lenght = numbers.Length, sum = 0;
        for (int i = 0; i < lenght;i++)
        {
            if(numbers[i] <= 0) continue;
            if(numbers[i] > 100) break;
            Console.WriteLine(numbers[i]);
            sum += numbers[i];
        }
        return sum;
    }

    public static int filterAndSum(int[] numbers, int threshold)
    {
        // Write your code here
        int count = 0;
        foreach(int number in numbers)
        {
            if(number < 0 || number > threshold) continue;
            if(number == threshold) break;

            Console.WriteLine(number);
            count++;
        }
        return count;
    }

    public static int DivideNumbersEx(int numerator, int denominator) {
        // Write your code here
        try
        {
            return numerator / denominator;
        }
        catch (DivideByZeroException)
        {
            Console.WriteLine("Cannot divide by zero!");
            return 0;
        }
    }

    private static int safeParseInt(string str, int defaultValue) {
        // Write your code here
        try
        {
            return int.Parse(str);
        }
        catch (FormatException)
        {
            Console.WriteLine("Invalid number format!");
            return defaultValue;
        }
        catch(OverflowException)
        {
            Console.WriteLine("Number out of range!");
            return defaultValue;
        }
        
    }

    public static int ProcessArray(int[] array, int index)
    {
        // Write your code here
        try
        {
            return array[index];
        }
        catch (IndexOutOfRangeException)
        {
            return -1;
        }
    }

    public static int DivideNumbersExEx(string numeratorStr, string denominatorStr)
    {
        // Write your code here
        try
        {
            return int.Parse(numeratorStr) / int.Parse(denominatorStr);

        }catch(FormatException)
        {
            Console.WriteLine("Invalid format");
            return 0;
        }
        catch (DivideByZeroException)
        {
            Console.WriteLine("Cannot divide by zero");
            return 0;
        }
    }

    private static int processArrayElement(string[] array, int index)
    {
        // Write your code here
        try
        {
            return 100 / int.Parse(array[index]);
        }
        catch (IndexOutOfRangeException)
        {
            Console.WriteLine("Array index out of bounds");
            return -1;
        }
        catch (FormatException)
        {
            Console.WriteLine("Cannot parse to number");
            return -1;
        }
        catch (DivideByZeroException)
        {
            Console.WriteLine("Cannot divide by zero");
            return -1;
        }
        catch 
        {
            Console.WriteLine("Unknown error occurred");
            return -1;
        }
    }

    public static void ReadFile(string filename)
    {
        // Write your code here
        StreamReader reader = new StreamReader(filename);
        string content = reader.ReadToEnd();
        Console.WriteLine(content);

        reader.Close();
    }

    public static void ProcessData(string filename)
    {
        // Write your code here
        StreamReader reader;
        try
        {
            reader = new StreamReader(filename);
        }
        catch (FileNotFoundException)
        {
            Console.WriteLine($"ERROR: File not found: {filename}");
        }
        catch (IOException ex)
        {
            Console.WriteLine($"ERROR: Could not read the file: {ex.Message}");
        }
        finally
        {
            Console.WriteLine("File operation completed.");
        }
    }

    private static void processTransaction(string transactionId)
    {
        // Write your code here
        Console.WriteLine("Opening connection");
        try
        {
            if(transactionId == "invalid") throw new ArgumentException("Invalid transaction ID");
            if(transactionId == "error") throw new Exception("Processing error");
            Console.WriteLine($"Processing transaction: {transactionId}");
        }
        catch (ArgumentException ex)
        {
            Console.WriteLine($"ERROR: {ex.Message}");
        }
        catch (Exception ex)
        {
            Console.WriteLine($"ERROR: {ex.Message}");
        }finally {Console.WriteLine("Connection closed");}
    }

    public static int processFile(string filename)
    {
        // Write your code here
        try
        {
            int count = 0;
            StreamReader reader = new StreamReader(filename);
            while(reader.ReadLine() != null) {reader.ReadLine(); count++;}
            return count;
        }catch(FileNotFoundException) {return -1;}
    }

    class InvalidTemperatureException : Exception
    {
        public InvalidTemperatureException() : base("emperature is not valid.")
        {
            
        }
        public InvalidTemperatureException(string message) : base(message)
        {
            
        } 
    }

    private static bool checkTemperature(int celsius)
    {
        // Write your code here
        if(-273 > celsius) throw new InvalidTemperatureException("Temperature below absolute zero!");

        return true;
    }

    class InvalidUserAgeException : Exception
    {
        public InvalidUserAgeException() : base("Age must be between 18 and 120") { }

        public InvalidUserAgeException(string message) : base(message){ }
    }
    
    private static string processUserData(string filePath, int userAge)
    {
        // Write your code here
        try
        {
            StreamReader reader = new StreamReader(filePath);
            if(userAge < 18 || userAge > 120) throw new InvalidUserAgeException();
            return reader.ReadToEnd();
        }
        catch (FileNotFoundException)
        {
            Console.WriteLine("User file not found");
            return "No data";
        }
        catch (IOException ex)
        {
            Console.WriteLine($"Error reading user data: {ex.Message}");
            return "No data";
        }
        catch (InvalidUserAgeException ex)
        {
            Console.WriteLine(ex.Message);
            return "No data";
        }
    }

    private static void ProcessName(string? name)
    {
        // Write your code here
        Console.WriteLine(name == null ? "Name is null" : $"Name length is {name.Length}");
    }
    
    private static void SafeProcessData(string? data, int maxLength)
    {
        // Write your code here
        Console.WriteLine(data == null ? "Invalid data: null reference" : data.Length > maxLength ? "Data too long" : $"Processing: {data}");
    }

    public static int? ProcessNullableAge(int? age)
    {
        if(age.HasValue)
        {
            Console.WriteLine($"Age is: {age} years");
            return age;
        }
        else
        {
            Console.WriteLine("Age not provided");
            return 0;
        }
    }
    
    public static string ProcessUserName(string userName)
    {
        // Write your code here
        if (String.IsNullOrWhiteSpace(userName))
        {
            if(userName == null) return "No user provided";

            return "Invalid username";
        }

        return $"Welcome, {userName}!";
    }
    
    public static string processPersonInfo(string name, string email, int? age)
    {
        // The string inputs may arrive as the literal text "null" — treat those as missing values
        // (same as an empty string or a missing integer)

        // If all inputs are missing/null, return "No information provided"

        // Otherwise, build a result string with the available fields:
        // "Name: <name>", "Email: <email>", "Age: <age>"
        // Separate each present field with ", "

        // Write your code here
        List<string> result = new List<string>();
        if (String.IsNullOrWhiteSpace(name) && String.IsNullOrWhiteSpace(email) && age == null)
            return "No information provided";
        if(name != "null" || name.Contains(" ")) { result.Add($"Name: {name}"); }
        if (email != "null") { result.Add($"Email: {email}"); }
        if(age.HasValue) { result.Add($"Age: {age}"); }
        
        return string.Join(", ", result);
    }
    
    public static void processUserData(string? userData)
    {
        // Hint: the string "null" should be treated as an actual null value
        // Write your code here
        if (userData == null || userData == "null")
        {
            Console.WriteLine("Error: User data is null");
            return;
        }else if (userData == "")
        {
            Console.WriteLine("Error: User data is empty");
            return;
        }

        Console.WriteLine($"Processing: {userData.ToUpper()}");
    }
    
    public static void validateUserInput(string username, string email, int? age)
    {
        // Write your code here
        if (String.IsNullOrWhiteSpace(username) || username == "null")
        {
            Console.WriteLine("ERROR: Invalid username");
            return;
        }
        if(String.IsNullOrWhiteSpace(email) || email == "null" || !email.Contains('@'))
        {
            Console.WriteLine("ERROR: Invalid email format");
            return;
        }
        if(age < 18 || age == null)
        {
            Console.WriteLine("ERROR: User must be 18 or older");
            return;
        }
        
        Console.WriteLine("User data validated successfully");
    }

    public static string SafelyProcessData(string? name, int? age)
    {
        if (name == null || name == "null")return "No name provided";
        if (String.IsNullOrWhiteSpace(name)) return "Invalid name";
        if (age == null) return $"Name: {name}, Age: Unknown";
        return $"Name: {name}, Age: {age}";
    } 
    
    public static void processUserInput(string input, int minLength)
    {
        // Write your code here
        Console.WriteLine(String.IsNullOrWhiteSpace(input) || input.Length < minLength ? "Invalid input" : $"Valid input: {input}");
    }
    
    public static void safeDataAccess(string[]? data, int index)
    {
        // Write your code here
        if (index < 0 || index >= data?.Length)
        {
            Console.WriteLine("Invalid access attempt");
            return;
        }
        if(String.IsNullOrWhiteSpace(data?[index]))
        {
            Console.WriteLine("Invalid access attempt");
            return;
        }
        
        Console.WriteLine($"Valid data: {data[index]}");
    }
    
    public static int getSafeValue(int? value, int defaultValue)
    {
        // Write your code here
        return value ?? defaultValue;
    }
    
    public static void processNames(string[] names)
    {
        // Write your solution here
        foreach (string name in names)
        {
            if(name == null || name == "null") Console.WriteLine("null is present");
            else Console.WriteLine($"\"{name}\" is present");
        }
    }
    
    public static string analyzeInput(string text, int? value, bool condition)
    {
        // Write your code here
        string result = "";
        if ((text != null || text != "null") && text?.Length > 3) result += "Text valid: True\n";
        else result += "Text valid: False\n";
        result += $"Value used: {value ?? 100}\n";
        result += $"Expression 1: {condition || text?.Length > 5 && value > 50}\n";
        result += $"Expression 1: {(condition || text?.Length > 5) && value > 50}";
        return result;
    }
    
    public static Dictionary<string, int> CreateFruitInventory()
    {
        // Write your code here
        Dictionary<string, int> fruitInventory = new Dictionary<string, int>()
        {
            { "Apple", 5 },
            { "Banana", 10 },
            { "Orange", 7}
        };
        
        return fruitInventory;
    }
    
    public static void CheckKeyExists(Dictionary<string, int> dictionary, string key)
    {
        // Write code here
        Console.WriteLine(dictionary.ContainsKey(key) ? "Key exists" : "Key does not exist");
    }
    
    public static void GetValueByKey(Dictionary<string, int> dictionary, string key)
    {
        // Write code here
        try
        {
            Console.WriteLine(dictionary[key]);
        }
        catch (KeyNotFoundException)
        {
            Console.WriteLine("Key not found");
        }
    }
    
    public static void UpdateInventory(Dictionary<string, int> inventory, string item, int quantity)
    {
        // Write your code here
        inventory[item] = quantity;
        // Print the updated inventory
        // Don't remove this
        foreach (KeyValuePair<string, int> entry in inventory)
        {
            Console.WriteLine($"{entry.Key}: {entry.Value}");
        }
    }
    
    public static Dictionary<string, int> ProcessDictionary(Dictionary<string, int> data, string[] operations)
    {
        // Write your code here
        foreach (string operation in operations)
        {
            string[] keyValue = operation.Split(' ');
            
            if (operation.Contains("GET"))
            {
                Console.WriteLine(data.ContainsKey(keyValue[1]) ? data[keyValue[1]].ToString() : "Key does not exist");
            }
            else if (operation.Contains("CHECK"))
            {
                Console.WriteLine(data.ContainsKey(keyValue[1]) ? "Exists" : "Not found");
            }
            else if (operation.Contains("MODIFY"))
            {
                if (data.ContainsKey(keyValue[1]))
                {
                    if (data[keyValue[1]] == int.Parse(keyValue[2]))
                    {
                        data[keyValue[1]]++;
                    }
                    else
                    {
                        data.Remove(keyValue[1]);
                    }
                }
                else
                {
                    data[keyValue[1]] =  int.Parse(keyValue[2]);
                }
            }
        }
        
        return data;
    }

    static void ProcessDictionary(Dictionary<string, int> dict)
    {
        // Write your code here
        Dictionary<string, int>.KeyCollection keys = dict.Keys;
        Console.WriteLine("Keys: ");
        foreach (string name in keys)
        {
            Console.WriteLine(name);
        }
        
        // Get all values
        Console.WriteLine("Values: ");
        Dictionary<string, int>.ValueCollection values = dict.Values;
        foreach (int score in values)
        {
            Console.WriteLine(score);
        }

        Console.WriteLine($"Contains 'total': {dict.ContainsKey("total")}");
        
        dict.Remove("temp");
        
        Console.WriteLine($"Count: {dict.Count}");
    }
    
    public static void AddCourseGrade(Dictionary<string, Dictionary<string, int>> grades, string student, string course, int grade)
    {
        // Write your code here
        try
        {
            grades[student][course] = grade;
        }
        catch (KeyNotFoundException)
        {
            Dictionary<string, int> studentGrades = new Dictionary<string, int>();
            studentGrades.Add(course, grade);
            grades.Add(student, studentGrades);
        }
        
        Console.WriteLine($"Added {course} grade for {student}: {grade}");
    }
    
    public static Dictionary<string, int> ManageWarehouse(Dictionary<string, int> inventory)
    {
        // Your code here
        foreach (var elem in inventory)
        {
            Console.WriteLine($"Item: {elem.Key}, Quantity: {elem.Value}");
        }

        Console.WriteLine($"Apples in stock: {inventory.ContainsKey("apples")}");
        if (inventory.ContainsKey("bananas")) inventory["bananas"] += 10;
        
        var keysToRemove = new List<string>();

        foreach (var elem in inventory)
        {
            if (elem.Value <= 0)
            {
                keysToRemove.Add(elem.Key);
            }
        }

        foreach (var key in keysToRemove)
        {
            inventory.Remove(key);
        }

        Console.WriteLine($"Total distinct items: {inventory.Count}");
        
        return inventory;
    }

    public static Dictionary<string, int> ProcessDictionary(Dictionary<string, int> inventory, List<string> operations)
    {
        // Your code here
        foreach(string fullOp in operations)
        {
            string[] ops = fullOp.Split(' ');

            if (ops[0] == "COUNT")
            {
                Console.WriteLine($"Total items: {inventory.Count}");
                Console.WriteLine("Operation COUNT performed successfully");
            }else if (ops[0] == "ADD")
            {
                if (inventory.ContainsKey(ops[1]))
                {
                    inventory[ops[1]] += int.Parse(ops[2]);
                    Console.WriteLine("Operation ADD performed successfully");
                }
                else
                {
                    inventory.Add(ops[1] ,int.Parse(ops[2]));
                }
            }else if (ops[0] == "REMOVE")
            {
                if (inventory.ContainsKey(ops[1]))
                {
                    inventory.Remove(ops[1]);
                    Console.WriteLine("Operation REMOVE performed successfully");
                }else Console.WriteLine("Operation REMOVE failed: Item not found");
            }else if (ops[0] == "UPDATE")
            {
                if (inventory.ContainsKey(ops[1]))
                {
                    inventory[ops[1]] += int.Parse(ops[2]);
                    Console.WriteLine("Operation UPDATE performed successfully");                
                }
            }else if (ops[0] == "FIND")
            {
                if (inventory.ContainsKey(ops[1]))
                {
                    Console.WriteLine($"{ops[1]}: {inventory[ops[1]]}");
                    Console.WriteLine("Operation UPDATE performed successfully");
                }
            }
        }
        
        return inventory;
    }

    public static void AddElement(HashSet<string> set, string element)
    {
        // Write your code here
        set.Add(element);

        Console.WriteLine("{"+String.Join(", ",set)+"}");
    }

    public static void RemoveElement(HashSet<string> set, string element)
    {
        // Write your code here
        Console.WriteLine($"Element removed: {set.Remove(element)}");
        Console.WriteLine(String.Join(", ",set));
    }

    public static string ElementExists(HashSet<string> set, string element)
    {
        // Write your code here
        string result = $"The element '{element}'";
        if(set.Contains(element)) result += " exists in the set";
        else result += " does not exist in the set";
        return result;
    }

    public static void CountAndCheck(HashSet<string> set)
    {
        // Write your code here
        if(set.Count == 0) Console.WriteLine("Empty set");
        else Console.WriteLine($"Set contains {set.Count} elements");
    }

    public static HashSet<string> ProcessHashSet()
    {
        // Write your code here
        HashSet<string> set = new HashSet<string>();
        set.Add("Apple");
        set.Add("Banana");
        set.Add("Orange");

        Console.WriteLine($"Contains Mango: {set.Contains("Mango")}");
        Console.WriteLine($"Added Apple again: {set.Add("Apple")}");
        Console.WriteLine($"Removed Banana: {set.Remove("Banana")}");
        Console.WriteLine($"Count: {set.Count}");

        return set;
    }
    
    //*******************************************************************************************
    // OOP MODULE FROM HERE DOWN
    //*******************************************************************************************
    public class Car
    {
        public string Brand { get; set; }
        public int Year { get; set; }
    
        // TODO: Add a constructor that takes brand and year parameters
        public Car(string brand, int year)
        {
            Brand = brand;
            Year = year;
        }
        // TODO: Add a Drive() method that returns a string
        public string Drive()
        {
            return $"The {Brand} is driving!";
        }
    }
    
    public class Product
    {
        public string Name { get; set; }
        public decimal Price { get; set; }
    
        // TODO: Create a constructor with parameters 'name' and 'price'
        // Use 'this' keyword to assign values to properties
        public Product(string name, decimal price)
        {
            this.Name = name;
            this.Price = price;
        }
    
        public string GetDescription()
        {
            // TODO: Use 'this' keyword to access Name and Price
            return $"{this.Name} costs ${this.Price}";
        }
    }
    
    public class CalculatorA
    {
        // TODO: Create an Add method that takes two int parameters and returns their sum
        public int Add(int num1, int num2)
        {
            return num1 + num2;
        }
        // TODO: Create a Subtract method that takes two int parameters and returns their difference
        public int Subtract(int num1, int num2)
        {
            return num1 - num2;
        }
        // TODO: Create a Multiply method that takes two int parameters and returns their product
        public int Multiply(int num1, int num2)
        {
            return num1 * num2;
        }
    }
    
    public class BankAccount
    {
        // TODO: Create a private field 'balance' of type decimal
        private decimal balance;
        // TODO: Create an auto-implemented property 'AccountName' (string)
        public string AccountName { get; set; }
        // TODO: Create a property 'Balance' with only a get accessor that returns the balance field
        public decimal Balance { get; }

        public BankAccount(string accountName, decimal initialBalance)
        {
            // TODO: Set AccountName and balance field
            AccountName = accountName;
            balance = initialBalance;
        }
    
        public void Deposit(decimal amount)
        {
            // TODO: Add amount to balance field if amount > 0
            if (0 < amount) balance +=  amount;
        }
    
        public string Withdraw(decimal amount)
        {
            // TODO: If amount > 0 and amount <= balance, subtract from balance and return "Success"
            // Otherwise return "Insufficient funds"
            string result = "Success";
            if (amount > 0 && amount <= balance) balance -= amount;
            else result = "Insufficient funds";
            return result;
        }
    }
    
    public class ProductA
    {
        public string Name { get; set; }
        public decimal Price { get; set; }
        public int Stock { get; set; }
    
        // TODO: Create a constructor with three parameters (string name, decimal price, int stock)
        // Initialize all properties
        public ProductA(string name, decimal price, int stock)
        {
            this.Name = name;
            this.Price = price;
            this.Stock = stock;
        }
    
        // TODO: Create a constructor with two parameters (string name, decimal price)
        // Use constructor chaining with 'this' to call the first constructor with stock = 0
        public ProductA(string name, decimal price)
        {
            this.Name = name;
            this.Price = price;
            this.Stock = 0;
        }
    
        // TODO: Create a default constructor with no parameters
        // Use constructor chaining with 'this' to call the second constructor with name = "Unknown" and price = 0
        public ProductA()
        {
            this.Name = "Unknown";
            this.Price = 0;
        }
    }
    
    
    public class Calculator
    {
        // TODO: Create a private field 'memory' to store a decimal value
        private decimal memory;
        // TODO: Create a private field 'operationCount' to track number of operations
        private int operationCount;
        // TODO: Create an auto-implemented property 'Name' (string)
        public string Name { get; set; }
        // TODO: Create a read-only property 'Memory' that returns the memory field
        public decimal Memory => memory;
        
        // TODO: Create a read-only property 'OperationCount' that returns the operationCount field
        public int OperationCount => operationCount;
        // TODO: Create a constructor with parameter 'name' that initializes Name and sets memory and operationCount to 0
        public Calculator(string name)
        {
            this.Name = name;
            this.memory = 0;
            this.operationCount = 0;
        }
        // TODO: Create a default constructor that uses 'this' to call the other constructor with "Default" as name
        public Calculator() : this("Default")
        { 
            
        }
        // TODO: Create an Add method that takes two decimal parameters and returns their sum
        // Increment operationCount and store result in memory
        public decimal Add(decimal num1, decimal num2)
        {
            memory = num1 + num2;
            operationCount++;
            return num1 + num2;
        }
        // TODO: Create a Subtract method that takes two decimal parameters and returns their difference
        // Increment operationCount
        public decimal Subtract(decimal num1, decimal num2)
        {
            operationCount++;
            return num1 - num2;
        }
        // TODO: Create a Multiply method that takes two decimal parameters and returns their product
        // Increment operationCount
        public decimal Multiply(decimal num1, decimal num2)
        {
            operationCount++;
            return num1 * num2;
        }
        // TODO: Create a Divide method that takes two decimal parameters and returns their quotient
        // Increment operationCount and handle division by zero (return 0 if divisor is 0)
        public decimal Divide(decimal num1, decimal num2)
        {
            if (num2 == 0) return 0;
            operationCount++;
            return num1 / num2;
        }
        // TODO: Create a Power method that takes two decimal parameters (base and exponent)
        // Returns base raised to the power of exponent using Math.Pow
        // Increment operationCount
        public decimal Power(decimal num, decimal exponent)
        {
            operationCount++;
            return (decimal)Math.Pow((double)num, (double)exponent);
        }
        // TODO: Create a SquareRoot method that takes one decimal parameter
        // Returns the square root using Math.Sqrt
        // Increment operationCount
        public decimal SquareRoot(decimal num)
        {
            operationCount++;
            return (decimal)Math.Sqrt((double)num);
        }
    }

    
    public static void Main(String[] args)
    {
        string name = Console.ReadLine();
        decimal num1 = decimal.Parse(Console.ReadLine());
        decimal num2 = decimal.Parse(Console.ReadLine());
        
        // Create calculator using constructor with name
        Calculator calc = new Calculator(name);
        
        Console.WriteLine($"Calculator: {calc.Name}");
        Console.WriteLine($"Memory: {calc.Memory}");
        
        // Perform operations
        decimal addResult = calc.Add(num1, num2);
        Console.WriteLine($"Add: {addResult}");
        
        decimal subtractResult = calc.Subtract(num1, num2);
        Console.WriteLine($"Subtract: {subtractResult}");
        
        decimal multiplyResult = calc.Multiply(num1, num2);
        Console.WriteLine($"Multiply: {multiplyResult}");
        
        decimal divideResult = calc.Divide(num1, num2);
        Console.WriteLine($"Divide: {divideResult}");
        
        Console.WriteLine($"Memory after operations: {calc.Memory}");
        
        decimal powerResult = calc.Power(num1, num2);
        Console.WriteLine($"Power: {powerResult}");
        
        decimal sqrtResult = calc.SquareRoot(num2);
        Console.WriteLine($"Square Root: {sqrtResult}");
        
        Console.WriteLine($"History: {calc.OperationCount} operations");
    }
}
