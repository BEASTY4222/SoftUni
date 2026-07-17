using System;
using System.Numerics;

namespace Rental.Models
{
    // TODO: Create the Rental class to track rentals
    // - Read-only properties: CustomerName (string), Vehicle (Vehicle), Days (int), TotalPrice (decimal)
    // - All properties set through constructor
    public class Rental
    {
        // TODO: Implement properties
        public readonly string CustomerName;
        public readonly Vehicle Vehicle;
        public readonly int Days;
        public readonly decimal TotalPrice;
        // TODO: Implement constructor
        public Rental(string name, Vehicle vehicle, int days, decimal totalPrice)
        {
            CustomerName = name;
            Vehicle = vehicle;
            Days = days;
            TotalPrice = totalPrice;
        }
    }
}
