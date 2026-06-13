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
}