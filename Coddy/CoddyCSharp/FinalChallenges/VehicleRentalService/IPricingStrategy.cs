using System;
using Rental.Models;

namespace Rental.Pricing
{
    // TODO: Define the IPricingStrategy interface
    // - Should have a method: decimal CalculatePrice(Vehicle vehicle, int days)
    public interface IPricingStrategy
    {
        // TODO: Define the CalculatePrice method signature
        decimal CalculatePrice(Vehicle vehicle, int days);
    }
}
