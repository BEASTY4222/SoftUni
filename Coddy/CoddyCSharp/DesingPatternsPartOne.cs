using System;
using System.Collections;

namespace patternsPartOne
{
    public class PatternCatalog
    {
        // TODO: Create a private list to store patterns
        private List<Pattern> list;
        // TODO: Create a constructor to initialize the list
        public PatternCatalog()
        {
            list = new List<Pattern>();
        }
        // TODO: Implement AddPattern method to add a pattern to the catalog
        public void AddPattern(Pattern pattern)
        {
            // TODO: Add the pattern to the collection
            list.Add(pattern);
        }
        
        // TODO: Implement GetPatternsByCategory method
        // Returns a list of patterns matching the given category
        public List<Pattern> GetPatternsByCategory(string category)
        {
            List<Pattern> categorizedPatterns = new List<Pattern>();
            foreach(Pattern elem in list)
                if(elem.Category == category) categorizedPatterns.Add(elem);
            
            // TODO: Filter and return patterns by category
            return categorizedPatterns;
        }
        
        // TODO: Implement GetAllSummaries method
        // Returns a list of summary strings for all patterns
        public List<string> GetAllSummaries()
        {
            // TODO: Return summaries of all patterns
            List<string> summuries = new List<string>();
            foreach(Pattern elem in list) summuries.Add(elem.Description);
            return summuries;
        }
    }

    public class Pattern
    {
        // TODO: Define properties for Name, Category, and Description
        public string Name { get; set; }
        public string Category { get; set; }
        public string Description { get; set; }
        
        // TODO: Create a constructor to initialize the pattern
        public Pattern(string name, string category, string description)
        {
            this.Name = name;
            this.Category = category;
            this.Description = description;
        }
        // TODO: Implement GetSummary() method
        // Should return: [{Category}] {Name}: {Description}
        public string GetSummary()
        {
            // TODO: Return the formatted summary string
            return $"[{Category}] {Name}: {Description}";
        }
    }

    
    public class ConfigManager
    {
        // TODO: Create a private static field to hold the single instance
        // Use static initialization for thread safety
        private static readonly ConfigManager _configManager = new ConfigManager();       
        // TODO: Create a private string field _appName initialized to "MyApp"
        private static string _appName = "MyApp";
        // TODO: Create a private constructor to prevent external instantiation
        private ConfigManager(){ }
        // TODO: Create a public static Instance property that returns the single instance
        public static ConfigManager Instance{get => _configManager;} 
        // TODO: Implement SetAppName(string name) method to update the app name
        // TODO: Implement GetAppName() method that returns the current app name
        public static string AppName{get => _appName; set => _appName = value;}
    }

    // TODO: Define the INotification interface with a Send(string message) method that returns a string
    public interface INotification
    {
        string Send(string message);
    }
    // TODO: Create EmailNotification class that implements INotification
    // The Send method should return "Email: {message}"
    public class EmailNotification : INotification
    {
        public string Send(string message) => $"Email: {message}";
    }
    // TODO: Create SmsNotification class that implements INotification
    // The Send method should return "SMS: {message}"
    public class SmsNotification : INotification
    {
        public string Send(string message) => $"SMS: {message}";
    }
    // TODO: Create PushNotification class that implements INotification
    // The Send method should return "Push: {message}"
    public class PushNotification : INotification
    {
        public string Send(string message) => $"Push: {message}";
    }

    public class NotificationFactory
    {
        // TODO: Implement the Create(string type) method
        // It should return the appropriate INotification based on the type:
        // - "email" returns EmailNotification
        // - "sms" returns SmsNotification
        // - "push" returns PushNotification
        // - For any unrecognized type, return EmailNotification as default
        public INotification Create(string type)
        {
            switch (type)
            {
                case "email": return new EmailNotification();
                case "sms": return new SmsNotification();
                case "push": return new PushNotification();
                default:
                    throw new Exception("Wrong type");
            }
        }
    }

    // TODO: Define the IShippingStrategy interface with a CalculateCost method
    public interface IShippingStrategy
    {
        // TODO: Declare the CalculateCost method that takes weight and returns double
        double CalculateCost(double weight);
    }

    // TODO: Implement StandardShipping class
    // Cost formula: weight * 1.5
    public class StandardShipping : IShippingStrategy
    {
        // TODO: Implement CalculateCost method
        public double CalculateCost(double weight) => weight * 1.5d;
    }

    // TODO: Implement ExpressShipping class
    // Cost formula: weight * 3.0 + 5.0
    public class ExpressShipping : IShippingStrategy
    {
        // TODO: Implement CalculateCost method
        public double CalculateCost(double weight) => weight * 3.0d + 5.0d;
    }

    // TODO: Implement OvernightShipping class
    // Cost formula: weight * 5.0 + 10.0
    public class OvernightShipping : IShippingStrategy
    {
        // TODO: Implement CalculateCost method
        public double CalculateCost(double weight) => weight * 5.0d + 10.0d;
    }

    public class OrderProcessor
    {
        // TODO: Add a private field to hold the current IShippingStrategy
        private IShippingStrategy _IShippingStrategy;
        // TODO: Implement SetShippingMethod to change the shipping strategy
        public void SetShippingMethod(IShippingStrategy strategy)
        {
            // TODO: Set the strategy field
            _IShippingStrategy = strategy;
        }

        // TODO: Implement ProcessOrder to calculate shipping cost using current strategy
        public double ProcessOrder(double weight) => _IShippingStrategy.CalculateCost(weight);
    }
}