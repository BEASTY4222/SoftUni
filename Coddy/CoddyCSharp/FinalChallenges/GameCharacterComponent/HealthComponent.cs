using System;

namespace Game.Components
{
    // TODO: Create HealthComponent class that implements IComponent
    public class HealthComponent : IComponent
    {
        // TODO: Add fields for current health and max health
        public int CurHealth{get; private set;}
        public readonly int MaxHealth;
        
        // TODO: Declare event Action<int> HealthChanged
        public event Action<int> HealthChanged;
        
        // TODO: Create constructor that takes maxHealth and sets current health to max
        public HealthComponent(int maxHealth)
        {
            // TODO: Initialize health values
            MaxHealth = maxHealth;
            CurHealth = MaxHealth;
        }
        
        // TODO: Implement TakeDamage(int amount) method
        // Health should never go below 0
        // Fire HealthChanged event when health changes
        public void TakeDamage(int amount)
        {
            // Subtract damage from CURRENT health, ensuring it doesn't drop below 0
            CurHealth = Math.Max(0, CurHealth - amount);
            
            // Invoke the event with the NEW remaining health
            HealthChanged?.Invoke(CurHealth);
        }
        
        // TODO: Implement Heal(int amount) method
        // Health should never go above max
        // Fire HealthChanged event when health changes
        public void Heal(int amount)
        {
            // Add healing to CURRENT health, ensuring it doesn't exceed max health
            CurHealth = Math.Min(MaxHealth, CurHealth + amount);
            
            // Invoke the event with the NEW current health
            HealthChanged?.Invoke(CurHealth);
        }
        
        // TODO: Implement Update() method
        // Should print: Health: {current}/{max}
        public void Update()
        {
            // TODO: Print health status
            Console.WriteLine($"Health: {CurHealth}/{MaxHealth}");
        }
    }
}
