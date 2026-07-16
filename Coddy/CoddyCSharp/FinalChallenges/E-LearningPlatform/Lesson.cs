using System;

namespace ELearning.Models
{
    public class Lesson
    {
        // TODO: Create read-only properties for Title (string) and DurationMinutes (int)
        public string Title {get; private set;}
        public int DurationMinutes {get; private set;}
        // TODO: Create a constructor that sets Title and DurationMinutes
        public Lesson(string title, int duration)
        {
            Title = title;
            DurationMinutes = duration;
        }
    }
}
