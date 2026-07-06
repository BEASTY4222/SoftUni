using System;
using System.Collections;

namespace patterns
{
    public class PatternCatalog
    {
        // TODO: Create a private list to store patterns
        private List<Pattern> list;
        // TODO: Create a constructor to initialize the list
        public PatternCatalog()
        {
            list = new List<Pattern>();
        }
        // TODO: Implement AddPattern method to add a pattern to the catalog
        public void AddPattern(Pattern pattern)
        {
            // TODO: Add the pattern to the collection
            list.Add(pattern);
        }
        
        // TODO: Implement GetPatternsByCategory method
        // Returns a list of patterns matching the given category
        public List<Pattern> GetPatternsByCategory(string category)
        {
            List<Pattern> categorizedPatterns = new List<Pattern>();
            foreach(Pattern elem in list)
                if(elem.Category == category) categorizedPatterns.Add(elem);
            
            // TODO: Filter and return patterns by category
            return categorizedPatterns;
        }
        
        // TODO: Implement GetAllSummaries method
        // Returns a list of summary strings for all patterns
        public List<string> GetAllSummaries()
        {
            // TODO: Return summaries of all patterns
            List<string> summuries = new List<string>();
            foreach(Pattern elem in list) summuries.Add(elem.Description);
            return summuries;
        }
    }

    public class Pattern
    {
        // TODO: Define properties for Name, Category, and Description
        public string Name { get; set; }
        public string Category { get; set; }
        public string Description { get; set; }
        
        // TODO: Create a constructor to initialize the pattern
        public Pattern(string name, string category, string description)
        {
            this.Name = name;
            this.Category = category;
            this.Description = description;
        }
        // TODO: Implement GetSummary() method
        // Should return: [{Category}] {Name}: {Description}
        public string GetSummary()
        {
            // TODO: Return the formatted summary string
            return $"[{Category}] {Name}: {Description}";
        }
    }
}