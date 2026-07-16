using System;
using System.Collections.Generic;

namespace ELearning.Models
{
    public class Course
    {
        // TODO: Create read-only properties for Id (string), Title (string), and Instructor (string)
        public string Id {get; private set;}
        public string Title {get; private set;}
        public string Instructor {get; private set;} 
        // TODO: Create a Lessons list property
        public List<Lesson> lessons;
        // TODO: Create a constructor that sets Id, Title, and Instructor, and initializes the Lessons list
        public Course(string id, string title, string instructor)
        {
            lessons = new List<Lesson>();
            Id = id;
            Title = title;
            Instructor = instructor;
        }
        // TODO: Implement AddLesson(Lesson lesson) method
        public void AddLesson(Lesson lesson) => lessons.Add(lesson);
        // TODO: Implement TotalDuration read-only property that calculates sum of all lesson durations
        public int TotalDuration{get
            {
                int sum = 0;
                foreach(Lesson lesson in lessons)
                    sum += lesson.DurationMinutes;
                return sum;
            }
        }
    }
}
