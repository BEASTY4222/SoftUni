using System;
using System.Collections.Generic;
using Game.Components;

namespace Game
{
    // TODO: Create Character class that holds a collection of components
    public class Character
    {
        // TODO: Add Name property
        public string Name { get; set; }
        
        // TODO: Add a list to store components
        private List<IComponent> _components;
        // TODO: Create constructor that takes character name
        public Character(string name)
        {
            // TODO: Initialize name and component list
            Name = name;
            _components = new List<IComponent>();
        }
        
        // TODO: Implement AddComponent(IComponent component) method
        public void AddComponent(IComponent component)
        {
            // TODO: Add component to the list
            _components.Add(component);
        }
        
        // TODO: Implement GetComponent<T>() where T : IComponent
        // Returns the first component of type T, or null if not found
        public T GetComponent<T>() where T : class, IComponent
        {
            // TODO: Find and return component of type T
            foreach(var component in _components)
                if(component is T) return (T)component;
            return null;
        }
        
        // TODO: Implement UpdateAll() method
        // Calls Update() on each attached component
        public void UpdateAll()
        {
            // TODO: Call Update on all components
            foreach(var component in _components)
                component.Update();
        }
    }
}
