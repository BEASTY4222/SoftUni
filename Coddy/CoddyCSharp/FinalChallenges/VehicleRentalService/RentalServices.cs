using System;
using System.Collections.Generic;
using System.Numerics;
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
        private IPricingStrategy _strategy;
        private List<Vehicle> _fleet;
        // TODO: Implement constructor that accepts IPricingStrategy
        public RentalService(IPricingStrategy strategy)
        {
            _strategy = strategy;
            _fleet = new List<Vehicle>();
        }
        // TODO: Implement AddVehicle(Vehicle vehicle) - adds vehicle to fleet
        public void AddVehicle(Vehicle vehicle) => _fleet.Add(vehicle);
        // TODO: Implement RentVehicle(string customerName, string licensePlate, int days)
        // - Returns Rental object if vehicle exists and is available
        // - Returns null otherwise
        // - Mark vehicle as rented and calculate price using injected strategy
        public Rental.Models.Rental RentVehicle(string customerName, string licensePlate, int days)
        {
            Vehicle curVeh = GetVehicleByPlate(licensePlate);
            if(curVeh != null && curVeh.IsAvailable)
            {
                curVeh.MarkAsRented();
                return new Models.Rental(customerName, curVeh, days, _strategy.CalculatePrice(curVeh, days)); 
            }
            return null;
        }
        
        // TODO: Implement ReturnVehicle(string licensePlate)
        // - Marks vehicle as available
        // - Returns true if successful, false otherwise
        public bool ReturnVehicle(string licensePlate)
        {
            Vehicle veh = GetVehicleByPlate(licensePlate);
            if(veh != null && !veh.IsAvailable){ 
                veh.MarkAsReturned();
                return true;
            }
            return false;
        }
        // TODO: Implement GetAvailableVehicles()
        // - Returns list of all available vehicles
        public List<Vehicle> GetAvailableVehicles()
        {
            return _fleet.Where(t => t.IsAvailable).ToList();
        }

        public Vehicle GetVehicleByPlate(string licensePlate)
        {
            foreach(Vehicle veh in _fleet)
                if(licensePlate == veh.LicensePlate) return veh;
            return null;
        }
    }
}
