using System;
using System.Collections.Generic;

namespace Game.Components
{
    // TODO: Create InventoryComponent class that implements IComponent
    public class InventoryComponent : IComponent
    {
        // TODO: Add a list to store item names
        private List<string> _inventory;
        public InventoryComponent() => _inventory = new List<string>();

        // TODO: Implement AddItem(string item) method
        // Should print: Added: {itemName}
        public void AddItem(string item)
        {
            // TODO: Add item to list and print message
            _inventory.Add(item);
            Console.WriteLine($"Added: {item}");
        }
        
        // TODO: Implement RemoveItem(string item) method
        // Returns bool indicating success
        // Print: Removed: {itemName} or Item not found: {itemName}
        public bool RemoveItem(string item)
        {
            // TODO: Remove item and print appropriate message
            if(_inventory.Contains(item)){ 
                _inventory.Remove(item);
                Console.WriteLine($"Removed: {item}");
                return true;
            }

            Console.WriteLine($"Item not found: {item}");
            return false;
        }
        
        // TODO: Implement Update() method
        // Should print: Inventory: {item1}, {item2}, ... or Inventory: empty
        public void Update()
        {
            // TODO: Print inventory contents
            if(_inventory.Count == 0) Console.WriteLine("Inventory: empty");
            Console.WriteLine("Invetory: "+String.Join(", ",_inventory));
        }
    }
}
