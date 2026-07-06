using System;
using System.Collections;

namespace MyUtilities
{
    public class Stack {
        public List<int> elements = new List<int>();
        public Stack() {}
        
        public void push(int element) {
            elements.Add(element);
        }
        public int pop() {
            int value = elements[elements.Count - 1];
            elements.RemoveAt(elements.Count - 1);
            return value;
        }

        public int top() => elements[elements.Count - 1];
        public int size() => elements.Count;
        public bool empty() => elements.Count == 0;

    }

}