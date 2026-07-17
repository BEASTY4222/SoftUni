using System;
using System.Numerics;

namespace Rental.Models
{
    // TODO: Create the base Vehicle class with:
    // - Read-only properties: LicensePlate (string), Brand (string)
    // - DailyRate (decimal) property
    // - IsAvailable property with private setter
    // - MarkAsRented() method
    // - MarkAsReturned() method
    public class Vehicle
    {
        // TODO: Implement properties and constructor
        public readonly string LicensePlate;
        public readonly string Brand;
        public decimal DailyRate{get; set;}
        public bool IsAvailable{get; private set;} 
        public readonly string Type;
        public Vehicle(string licensePlate, string brand, decimal dailyRate, string type)
        {
            LicensePlate = licensePlate;
            Brand = brand;
            DailyRate = dailyRate;
            IsAvailable = true;
            Type = type;
        }
        // TODO: Implement MarkAsRented() method
        public void MarkAsRented() => IsAvailable = false;
        // TODO: Implement MarkAsReturned() method
        public void MarkAsReturned() => IsAvailable = true;
    }

    // TODO: Create Car class that inherits from Vehicle
    // - Add Seats (int) property
    public class Car : Vehicle
    {
        // TODO: Implement constructor and Seats property
        public int Seats {get; set;}
        public Car(string licensePlate, string brand, decimal dailyRate, int seats)
            : base(licensePlate,brand,dailyRate, "Car") => Seats = seats;

    }

    // TODO: Create Motorcycle class that inherits from Vehicle
    // - Add EngineCC (int) property
    public class Motorcycle : Vehicle
    {
        // TODO: Implement constructor and EngineCC property
        public int EngineCC {get; set;}
        public Motorcycle(string licensePlate, string brand, decimal dailyRate, int engineCC)
            : base(licensePlate,brand,dailyRate, "Motorcycle") => EngineCC = engineCC;
    }

    // TODO: Create Truck class that inherits from Vehicle
    // - Add CargoCapacity (decimal) property
    public class Truck : Vehicle
    {
        // TODO: Implement constructor and CargoCapacity property        
        public decimal CargoCapacity {get; set;}
        public Truck(string licensePlate, string brand, decimal dailyRate, decimal cargoCapacity)
            : base(licensePlate,brand,dailyRate, "Truck") => CargoCapacity = cargoCapacity;
    }
}
