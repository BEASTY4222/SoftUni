using System;
using System.Collections.Generic;

namespace Game.Components
{
    // TODO: Create InventoryComponent class that implements IComponent
    public class InventoryComponent : IComponent
    {
        // TODO: Add a list to store item names
        
        // TODO: Implement AddItem(string item) method
        // Should print: Added: {itemName}
        public void AddItem(string item)
        {
            // TODO: Add item to list and print message
        }
        
        // TODO: Implement RemoveItem(string item) method
        // Returns bool indicating success
        // Print: Removed: {itemName} or Item not found: {itemName}
        public bool RemoveItem(string item)
        {
            // TODO: Remove item and print appropriate message
            return false;
        }
        
        // TODO: Implement Update() method
        // Should print: Inventory: {item1}, {item2}, ... or Inventory: empty
        public void Update()
        {
            // TODO: Print inventory contents
        }
    }
}
