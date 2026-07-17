using System;
using Rental.Models;

namespace Rental.Pricing
{
    // TODO: Implement StandardPricing class
    // - Implements IPricingStrategy
    // - CalculatePrice: returns vehicle.DailyRate * days
    public class StandardPricing : IPricingStrategy
    {
        // TODO: Implement CalculatePrice method
    }

    // TODO: Implement WeekendDiscountPricing class
    // - Implements IPricingStrategy
    // - CalculatePrice: applies 10% discount (multiply by 0.9) if days >= 2
    // - Otherwise uses standard calculation
    public class WeekendDiscountPricing : IPricingStrategy
    {
        // TODO: Implement CalculatePrice method
    }
}
