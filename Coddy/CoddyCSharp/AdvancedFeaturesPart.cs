using System.Buffers;

namespace AdvancedFeatures{
    public class Fraction
    {
        // TODO: Create read-only properties for Numerator and Denominator
        public readonly int Numerator;
        public readonly int Denominator;
        // TODO: Create a constructor that accepts numerator and denominator
        public Fraction(int numerator, int denominator)
        {
            Numerator = numerator;
            Denominator = denominator;
        }
        // TODO: Overload the + operator to add two fractions
        // Formula: (a/b) + (c/d) = (a*d + c*b) / (b*d)
        public static Fraction operator +(Fraction a, Fraction b)
        {
            return new Fraction(a.Numerator * b.Denominator + b.Numerator * a.Denominator, a.Denominator * b.Denominator);        
        }
        // TODO: Overload the * operator to multiply two fractions
        // Formula: (a/b) * (c/d) = (a*c) / (b*d)
        public static Fraction operator *(Fraction a, Fraction b)
        {
            return new Fraction(a.Numerator * b.Numerator, a.Denominator * b.Denominator);
        }
        // TODO: Overload the == operator to check equality
        // Use cross-multiplication: a*d == c*b
        public static bool operator ==(Fraction a, Fraction b)
        {
            return a.Numerator * b.Denominator == b.Numerator * a.Denominator;
        }

        // TODO: Overload the != operator (required when overloading ==)
        public static bool operator !=(Fraction a, Fraction b)
        {
            // This simply returns the opposite of the == operator
            return !(a == b);
        }
        // TODO: Overload the != operator (required when overloading ==)
        
        // TODO: Implement GetDisplay() method
        // Return format: "{Numerator}/{Denominator}"

        public string GetDisplay() => $"{Numerator}/{Denominator}";
    }
    
    public class Playlist
    {
        // TODO: Declare a private string array to store song titles
        private string[] _songTitles;
        // TODO: Create a constructor that accepts a comma-separated string
        // and splits it into the internal array
        public Playlist(string songs)
        {
            // TODO: Split the songs string by comma and store in the array
            _songTitles =  songs.Split(',');
        }

        // TODO: Create a read-only Count property that returns the number of songs
        public int Count
        {
            get
            {
                // TODO: Return the length of the songs array
                return _songTitles.Length;;
            }
        }

        // TODO: Create an indexer using this[int index] syntax
        // The indexer should allow both getting and setting songs
        public string this[int index]
        {
            get
            {
                // TODO: Return the song at the given index
                return _songTitles[index];
            }
            set
            {
                // TODO: Set the song at the given index to the new value
                _songTitles[index] = value;
            }
        }

        // TODO: Create a GetAllSongs() method that returns all songs joined by " | "
        public string GetAllSongs()
        {
            // TODO: Join all songs with " | " separator and return
            return String.Join(" | " ,_songTitles);
        }
    }
    
    public class Book
    {
        // TODO: Define three read-only properties: Title, Author, and Year
        public readonly string Title;
        public readonly string Author;
        public readonly int Year;
        // TODO: Create a constructor that accepts title, author, and year
        public Book(string title, string author, int year)
        {
            Title = title;
            Author = author;
            Year = year;
        }  
        // TODO: Override the ToString() method to return:
        // "{Title}" by {Author} ({Year})
        // Note: The title should be wrapped in double quotes!
        public override string ToString() => $@"""{Title}"" | {Author} | {Year}";
    }

    public static class IntExtensions
    {
        // TODO: Implement IsEven() extension method
        // Returns true if the number is even, false otherwise
        // Remember: extension methods use 'this' keyword before the first parameter
        public static bool IsEven(this int num)  => num % 2 == 0;


        // TODO: Implement Square() extension method
        // Returns the number multiplied by itself
        public static int Square(this int num) => num * num;

        // TODO: Implement IsInRange(int min, int max) extension method
        // Returns true if the number is between min and max (inclusive)
        public static bool IsInRange(this int num, int min, int max) => min <= num && num <= max;
    }

    public class CustomList
    {
        // TODO: Declare a private integer array to store items
        private int[] arr;
        private int _index = 0;
        // TODO: Create a Count property with a public getter and private setter
        public int Count{get{return _index;} private set;}
        // TODO: Create a constructor that accepts capacity and initializes the array
        public CustomList(int capacity) => arr = new int[capacity];
        // TODO: Create an Add(int item) method that adds an item to the next available position
        public void Add(int item)
        {
            arr[_index] = item;
            _index++;
        }
        // TODO: Create an indexer this[int index] for getting and setting items by position
        public int this[int index]
        {
            get{ return arr[index];}
            set{arr[index] = value;}
        }

        // TODO: Overload the + operator to combine two CustomLists into a new one
        public static CustomList operator +(CustomList a, CustomList b)
        {
            int newSize = a.Count + b.Count;
            CustomList result = new CustomList(newSize);

            for(int i = 0;i < a.Count; i++) result.Add(a[i]);
            
            for(int i = 0;i < b.Count; i++) result.Add(b[i]);

            return result;

        }
        // TODO: Override ToString() to return items in format [item1, item2, item3]
        public override string ToString()
        {
            return "["+String.Join(", ", arr)+"]";
        }
    }

    public static class ListExtensions
    {
        // TODO: Create an extension method Sum() for CustomList
        // that returns the sum of all items in the list (up to Count)
        public static int Sum(this CustomList a)
        {
            int sum = 0;
            for (int i = 0;i < a.Count;i++) sum += a[i];
            
            return sum;
        }
    }

    // TODO: Create FormattingBehavior class
    // It should have a Format(string message) method
    // that returns the message wrapped with "[ALERT] " at the start and " [END]" at the end
    public class FormattingBehavior
    {
        // TODO: Implement Format method
        public string Format(string message) => "[ALERT] " + message + " [END]"; 
    }

    // TODO: Create DeliveryBehavior class
    // It should have a Deliver(string channel, string message) method
    // that returns "Sending via {channel}: {message}"
    public class DeliveryBehavior
    {
        // TODO: Implement Deliver method
        public string Deliver(string channel, string message) => $"Sending via {channel}: {message}";
    }

    public class NotificationSender
    {
        // TODO: Add private fields for FormattingBehavior and DeliveryBehavior
        private FormattingBehavior formattingBehavior;
        private DeliveryBehavior deliveryBehavior;   
        // TODO: Add Channel property (string)
        public string Channel{get;set;}
        // TODO: Create constructor that accepts channel name
        // Initialize the behavior objects and set the Channel property
        public NotificationSender(string channel)
        {
            Channel = channel;
            formattingBehavior = new FormattingBehavior();
            deliveryBehavior = new DeliveryBehavior();
        }
        // TODO: Implement Send(string message) method
        // 1. First format the message using FormattingBehavior
        // 2. Then deliver it using DeliveryBehavior with the Channel
        // 3. Return the final result
        public string Send(string message) => deliveryBehavior.Deliver(Channel,formattingBehavior.Format(message));
    }
      // TODO: Create a generic Storage<T> class
    public class Storage<T>
    {
        // TODO: Declare a private array of type T to hold items
        private T[] arr;
        // TODO: Create a Count property to track how many items are stored
        public int Count{get;set;}
        // TODO: Create a constructor that accepts a capacity parameter
        // and initializes the internal array
        public Storage(int size) => arr = new T[size];
        // TODO: Implement Add(T item) method
        // Add an item if there's room in the storage
        public void Add(T item) => arr[Count++] = item;
        // TODO: Implement Get(int index) method
        // Return the item at the specified index
        public T Get(int index) => arr[index];
        // TODO: Implement GetAll() method
        // Return all stored items joined by ", "
        public string GetAll() => String.Join(", ", arr);
    }

    public class TemperatureMonitor
    {
        // TODO: Declare a private field to store the current temperature
        private int _temperature;
        // TODO: Declare an event using Action<int> called TemperatureChanged
        public event Action TemperatureChanged;
        // TODO: Create a Temperature property (int) where:
        //       - The getter returns the private field
        //       - The setter updates the private field and raises the event
        //       - Use ?.Invoke() pattern to safely raise the event
        public int Temperature{
            get => _temperature; 
            set{
                _temperature = value;
                TemperatureChanged?.Invoke();
            }
        }
    }
}