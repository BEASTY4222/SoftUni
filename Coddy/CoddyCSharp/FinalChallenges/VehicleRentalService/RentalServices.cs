using System;
using System.Collections.Generic;
using Rental.Models;
using Rental.Pricing;

namespace Rental.Services
{
    // TODO: Create RentalService class that manages the fleet
    // - Receives IPricingStrategy through constructor (dependency injection)
    // - Maintains a list of vehicles (fleet)
    public class RentalService
    {
        // TODO: Add private fields for the fleet and pricing strategy
        
        // TODO: Implement constructor that accepts IPricingStrategy
        
        // TODO: Implement AddVehicle(Vehicle vehicle) - adds vehicle to fleet
        
        // TODO: Implement RentVehicle(string customerName, string licensePlate, int days)
        // - Returns Rental object if vehicle exists and is available
        // - Returns null otherwise
        // - Mark vehicle as rented and calculate price using injected strategy
        
        // TODO: Implement ReturnVehicle(string licensePlate)
        // - Marks vehicle as available
        // - Returns true if successful, false otherwise
        
        // TODO: Implement GetAvailableVehicles()
        // - Returns list of all available vehicles
    }
}
