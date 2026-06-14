namespace Inheritance
{
    // TODO: Define the Vehicle base class
    // It should have:
    // - A Brand property (string)
    // - A Year property (int)
    // - A StartEngine() method that prints "{Brand} engine started."
    
    public class Vehicle
    {
        // TODO: Add properties here
        public string Brand{get; set;}
        public int Year{get; set;}
        // TODO: Add StartEngine() method here
        public void StartEngine() => Console.WriteLine($"{Brand} engine start.");
    }

    // TODO: Define the Car class that inherits from Vehicle
    // It should have:
    // - A NumberOfDoors property (int)
    // - A Honk() method that prints "{Brand} goes Beep Beep!"
    
    public class Car : Vehicle
    {
        // TODO: Add NumberOfDoors property here
        public int NumberOfDoors{get; set;}
        // TODO: Add Honk() method here
        public void Honk() => Console.WriteLine($"{Brand} goes Beep Beep!");
    }

    public class Product
    {
        // TODO: Define Name property (string)
        public string Name{get; set;}
        // TODO: Define Price property (decimal)
        public decimal Price{get; set;}
        // TODO: Create a constructor that accepts name and price
        public Product(string name, decimal price)
        {
            this.Name = name;
            this.Price = price;
        }
        // TODO: Create GetInfo() method that returns "{Name}: ${Price}"
        public void GetInfo() => Console.Write($"{Name}: ${Price}");
    }

    public class ElectronicProduct : Product
    {
        // TODO: Define WarrantyMonths property (int)
        public int WarrantyMonths{get; set;}
        // TODO: Create a constructor that accepts name, price, and warrantyMonths
        // Use 'base' keyword to pass name and price to the parent constructor
        public ElectronicProduct(string name, decimal price, int warrantyMonths) : base(name, price) => this.WarrantyMonths = warrantyMonths;
            
        // TODO: Create GetInfo() method that:
        // 1. Calls the parent's GetInfo() using 'base'
        // 2. Appends " (Warranty: {WarrantyMonths} months)" to extend the output
        public void GetInfo()
        {
            base.GetInfo();
            Console.Write($" (Warranty: {WarrantyMonths} months)");
        }
        
    }

    public class Notification
    {
        // TODO: Add Message property
        public string Message{set; get;} 
        // TODO: Add constructor
        public Notification(string message) => this.Message = message;
        // TODO: Add virtual Send() method
        public virtual string Send() => $"Sending notification: {Message}";
    }

    public class EmailNotification : Notification
    {
        // TODO: Add Recipient property
        public string Recipient{get; set;}
        // TODO: Add constructor using base keyword
        public EmailNotification(string message, string recipient) : base(message) => this.Recipient = recipient;
        // TODO: Override Send() method
        public override string Send() => $"Emailing {Recipient}: {Message}";
    }

    public class SmsNotification : Notification
    {
        // TODO: Add PhoneNumber property
        public string PhoneNumber{set; get;}    
        // TODO: Add constructor using base keyword
        public SmsNotification(string message, string phoneNumber) : base(message) => this.PhoneNumber = phoneNumber;
        // TODO: Override Send() method
        public override string Send() => $"SMS to {PhoneNumber}: {Message}";
    }

    public class Converter
    {
        // TODO: Implement three overloaded Convert methods
        // This demonstrates compile-time polymorphism (method overloading)

        // TODO: Convert(int value) - returns "Integer: {value}"
        public string Convert(int value) => $"Integer: {value}";
        // TODO: Convert(double value) - returns "Double: {value}"
        public string Convert(double value) => $"Double: {value}";
        // TODO: Convert(string value) - returns "String: {value}"
        public string Convert(string value) => $"String: {value}";
    }

    public class Shape
    {
        // TODO: Add a Name property (string)
        public string Name{get; set;} 
        // TODO: Create a constructor that sets the Name property
        public Shape(string name) => Name = name;
        // TODO: Create a virtual Describe() method
        // It should return "This is a {Name}"
        public virtual string Describe() => $"This is a {Name}";
    }

    public class Circle : Shape
    {
        // TODO: Add a Radius property (double)
        public double Radius{get; set;}
        // TODO: Create a constructor that accepts a radius
        // Pass "Circle" to the base constructor
        // Set the Radius property
        public Circle(double radius) : base("Circle") => Radius = radius;
        // TODO: Override the Describe() method
        // It should return "This is a Circle with radius {Radius}"
        public override string Describe() => $"This is a Circle with radius {Radius}"; 
    }

    public interface IPlayable
    {
        string Play();
    }
    // TODO: Define an abstract class called MediaFile
    // It should have:
    // - A Title property (string)
    // - A Duration property (int, representing seconds)
    // - A constructor that sets both values
    // - A concrete method GetInfo() that returns "{Title} ({Duration}s)"
    // - An abstract method GetType() that returns a string

    public abstract class MediaFile
    {
        public string Title{get; set;}
        public int Duration{get; set;}
        
        public MediaFile(string title, int duration)
        {
            Title = title;
            Duration = duration;
        }

        public string GetInfo() =>$"{Title} ({Duration}s)";
        public abstract string GetType();
    }

    // TODO: Define an AudioFile class that:
    // - Inherits from MediaFile
    // - Implements IPlayable
    // - Has an Artist property (string)
    // - Has a constructor accepting title, duration, and artist
    // - Overrides GetType() to return "Audio"
    // - Implements Play() to return "Playing audio: {Title} by {Artist}"
    public class AudioFile : MediaFile , IPlayable
    {
        public string Artist{get; set;}

        public AudioFile(string title, int duration, string artist) : base(title, duration) => Artist = artist;

        public override string GetType() => "Audio";
            
        public string Play() => $"Playing audio: {Title} by {Artist}";
    }

    // TODO: Define the IControllable interface
    // It should declare two methods:
    // - TurnOn() returning a string
    // - TurnOff() returning a string

    public interface IControllable
    {
        string TurnOn();
        string TurnOff();
    }
    // TODO: Define the INetworkConnected interface
    // It should declare one method:
    // - Connect(string network) returning a string
    public interface INetworkConnected
    {
        string Connect(string network);
    }

    // TODO: Define the SmartTV class that implements both IControllable and INetworkConnected
    // 
    // Properties needed:
    // - Brand (string)
    // - ScreenSize (int)
    //
    // Constructor:
    // - Accept brand and screenSize parameters
    //
    // Implement interface methods:
    // - TurnOn(): return "{Brand} {ScreenSize}-inch TV is now ON"
    // - TurnOff(): return "{Brand} {ScreenSize}-inch TV is now OFF"
    // - Connect(string network): return "{Brand} TV connected to {network}"
    public class SmartTv : IControllable, INetworkConnected
    {
        public string Brand{get; set;}
        public int ScreenSize{get; set;}

        public SmartTv(string brand, int screenSize)
        {
            Brand = brand;
            ScreenSize = screenSize;
        }

        public string TurnOn() => $"{Brand} {ScreenSize}-inch TV is now ON";
        public string TurnOff() => $"{Brand} {ScreenSize}-inch TV is now OFF";
        public string Connect(string network) => $"{Brand} TV connected to {network}";
    }

    // TODO: Define the IDisplayable interface
    // This interface represents content that can be shown on screen
    // It should declare a method Render() that returns a string
    public interface IDisplayable
    {
        string Render();
    }
    // TODO: Define the IPrintable interface
    // This interface represents content that can be sent to a printer
    // It should declare a method Render() that returns a string
    // Note: This creates a naming collision with IDisplayable!
    public interface IPrintable
    {
        string Render();
    }
    public class Report : IDisplayable, IPrintable
    {
        // TODO: Add Title property (string)
        public string Title{get; set;}
        // TODO: Add Content property (string)
        public string Content{get; set;}
        // TODO: Add constructor that sets both Title and Content
        public Report(string title, string content)
        {
            Title = title;
            Content = content;
        }
        // TODO: Implement IDisplayable.Render() explicitly
        // Format: "[SCREEN] {Title}: {Content}"
        string IDisplayable.Render()
        {
            return $"[SCREEN] {Title}: {Content}";
        }
        // TODO: Implement IPrintable.Render() explicitly
        // Format: "[PRINT] {Title} | {Content}"
        string IPrintable.Render()
        {
            return $"[PRINT] {Title} | {Content}";
        }
    }
}