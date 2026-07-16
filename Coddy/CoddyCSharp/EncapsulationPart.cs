using System.Numerics;

namespace Encapsulation
{
    public class UserProfile
    {
        // TODO: Declare a public property Username (string)
        // TODO: Declare a private field password (string)
        // TODO: Declare a protected field email (string)
        // TODO: Declare an internal field userId (int)
        public string Username{get;set;}
        private string _password{get;set;}
        protected string Email{get;set;}
        internal int UserId{get;set;}
        // TODO: Create a constructor that accepts username, password, email, and userId
        // and initializes all the fields/properties
        public UserProfile(string username, string password, string email, int userId)
        {
            // TODO: Initialize all fields and properties
            Username = username;
            _password = password;
            Email = email;
            UserId = userId;
        }

        // TODO: Create a public method GetPublicInfo() that returns "User: {Username}"
        public string GetPublicInfo()
        {
            // TODO: Return the formatted string
            return $"User: {Username}";
        }

        // TODO: Create a public method ValidatePassword(string input) 
        // that returns true if input matches password, false otherwise
        public bool ValidatePassword(string input)
        {
            // TODO: Compare input with the private password field
            return input == _password;
        }
    }

    // TODO: Create AdminProfile class that inherits from UserProfile
    public class AdminProfile : UserProfile
    {
        // TODO: Create a constructor that accepts username, password, email, and userId
        // and passes them to the base class constructor
        public AdminProfile(string username, string password, string email, int userId)
            : base(username, password, email, userId)
        {
            // Constructor body (can be empty if just passing to base)
        }

        // TODO: Create a public method GetAdminInfo() that returns 
        // "Admin: {Username}, Email: {email}"
        // Note: You can access the protected 'email' field here because this is a derived class
        public string GetAdminInfo()
        {
            // TODO: Return the formatted string using Username and the protected email field
            return $"Admin: {Username}, Email: {Email}";
        }
    }

    public class Product
    {
        // TODO: Declare private field for price (decimal)
        private decimal _price;
        // TODO: Declare private field for quantity (int)
        private int _quantity;
        // TODO: Create public Name property (auto-implemented)
        public string Name{get;set;}
        // TODO: Create public Price property with validation
        // - getter returns the private field
        // - setter ensures price never goes below 0 (negative values become 0)
        public decimal Price{get => _price; set => _price = value < 0 ? 0 : value;}
        // TODO: Create public Quantity property with validation
        // - getter returns the private field
        // - setter clamps values between 0 and 1000
        public int Quantity{get => _quantity;
            set
            {
                if(value < 0) value = 0;
                else if(value > 1000) value = 1000;
                _quantity = value;
            }
        }
        // TODO: Create read-only TotalValue property
        // - returns Price * Quantity
        public decimal TotalValue{get => Price * Quantity;}
        // TODO: Create constructor that accepts name, price, and quantity
        // - Set values through properties so validation is applied
        public Product(string name, decimal price, int quantity)
        {
            // Set properties here
            Name = name;
            Price = price;
            Quantity = quantity;
        }
    }

    public class Wallet
    {
        // TODO: Declare a private field to store the balance (decimal)
        private decimal _balance;
        // TODO: Implement a private method FormatBalance() that returns
        // the balance formatted as a currency string like "$123.45"
        private string FormatBalance() => $"${_balance:F2}";
        // TODO: Implement public method Deposit(decimal amount)
        // - Add to balance only if amount is positive
        // - Return true if successful, false otherwise
        public bool Deposit(decimal amount)
        {
            if(amount > 0) _balance += amount;
            else return false;

            return true;
        }
        
        // TODO: Implement public method Withdraw(decimal amount)
        // - Subtract from balance only if amount is positive AND doesn't exceed balance
        // - Return true if successful, false otherwise
        public bool Withdraw(decimal amount)
        {
            if(amount > 0 && amount <= _balance) _balance -= amount;
            else return false;
            return true;
        }
        
        // TODO: Implement public method CanAfford(decimal amount)
        // - Return true if balance >= amount, false otherwise
        public bool CanAfford(decimal amount)
        {
            return _balance >= amount;
        }
        // TODO: Implement public method GetStatement()
        // - Use the private FormatBalance() method internally
        // - Return "Current balance: {formatted balance}"
        public string GetStatement() => $"Current balance: {FormatBalance()}";
    }

    public class Money
    {
        // TODO: Declare readonly fields for Amount (decimal) and Currency (string)
        public readonly decimal Amount;
        public readonly string Currency;
        // TODO: Create a constructor that takes amount and currency parameters
        // and initializes the readonly fields
        public Money(decimal amount, string currency)
        {
            Amount = amount;
            Currency = currency;
        }
        // TODO: Implement Add(decimal value) method
        // This should return a NEW Money object with the increased amount
        // Do NOT modify the current object!
        public Money Add(decimal value) => new Money(value + Amount, Currency);
        
        // TODO: Implement Subtract(decimal value) method
        // This should return a NEW Money object with the decreased amount
        // Do NOT modify the current object!
        public Money Subtract(decimal value) => new Money(Amount - value, Currency);
        // TODO: Implement Convert(string newCurrency, decimal rate) method
        // This should return a NEW Money object with:
        // - Amount multiplied by the rate
        // - The new currency
        // Do NOT modify the current object!
        public Money Convert(string newCurrency, decimal rate) => new Money(Amount * rate, newCurrency);
        
        // TODO: Implement GetDisplay() method
        // Return a string in the format "{Amount} {Currency}"
        // Hint: Use Amount.ToString("0.00") for proper decimal formatting
        public string GetDisplay() => $"{Amount:F2} {Currency}";
    }
    
    public class StudentA
    {
        // TODO: Declare a public readonly field 'Name' (string)
        public readonly string Name;
        // TODO: Declare a private readonly field for student ID (string)
        private readonly string ID;
        // TODO: Declare a private list to store grades (integers)
        private List<int> grades;
        // TODO: Create a constructor that accepts name and studentId
        public StudentA(string name, string id)
        {
            Name = name;
            ID = id;
            grades = new List<int>();
        }
        // TODO: Create a public read-only property 'Average' that:
        // - Returns the average of all grades
        // - Returns 0 if no grades exist
        public double Average
        {
            get
            {
                double sum = 0;
                if(grades.Count == 0) return 0;
                foreach(double grade in grades) sum += grade;
                return sum / grades.Count;
            }
        }
        // TODO: Create a public method AddGrade(int grade) that:
        // - Only accepts grades between 0 and 100 (inclusive)
        // - Silently ignores invalid grades
        public void AddGrade(int grade)
        {
            if(grade >= 0 && grade <= 100) grades.Add(grade);
        }
        // TODO: Create a public method GetGradeCount() that:
        // - Returns how many valid grades have been recorded
        public int GetGradeCount() => grades.Count;
        // TODO: Create a public method GetStudentInfo() that:
        // - Returns a string in format "{Name} (ID: {last 4 characters of student ID})"
        public string GetStudentInfo() => $"{Name} (ID: {ID.Substring(ID.Length - 4)})";
    }
}