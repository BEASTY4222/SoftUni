using System;

namespace Game.Components
{
    // TODO: Create HealthComponent class that implements IComponent
    public class HealthComponent : IComponent
    {
        // TODO: Add fields for current health and max health
        
        // TODO: Declare event Action<int> HealthChanged
        
        // TODO: Create constructor that takes maxHealth and sets current health to max
        public HealthComponent(int maxHealth)
        {
            // TODO: Initialize health values
        }
        
        // TODO: Implement TakeDamage(int amount) method
        // Health should never go below 0
        // Fire HealthChanged event when health changes
        public void TakeDamage(int amount)
        {
            // TODO: Implement damage logic
        }
        
        // TODO: Implement Heal(int amount) method
        // Health should never go above max
        // Fire HealthChanged event when health changes
        public void Heal(int amount)
        {
            // TODO: Implement healing logic
        }
        
        // TODO: Implement Update() method
        // Should print: Health: {current}/{max}
        public void Update()
        {
            // TODO: Print health status
        }
    }
}
