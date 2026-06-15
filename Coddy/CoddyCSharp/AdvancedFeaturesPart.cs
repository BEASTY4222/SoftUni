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
}