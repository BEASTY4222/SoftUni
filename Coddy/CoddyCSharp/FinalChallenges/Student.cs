using System;
using System.Collections.Generic;

namespace ELearning.Models
{
    public class Student
    {
        // TODO: Create read-only properties for Id (int) and Name (string)
        public int Id {get; private set;}
        public string Name {get; private set;}
        // TODO: Create a private dictionary to track progress (maps course IDs to completed lesson count)
        private Dictionary<string,int> _progress;
        // TODO: Create a constructor that sets Id and Name, and initializes the progress dictionary
        public Student(int id, string name)
        {
            _progress = new Dictionary<string, int>();
            Id = id;
            Name = name;
        }
        // TODO: Implement CompleteLesson(string courseId) method to increment progress
        public void CompleteLesson(string courseId)
        {
           if(_progress.ContainsKey(courseId)) _progress[courseId]++;
           else _progress.Add(courseId, 1);
        }
        // TODO: Implement GetProgress(string courseId) method to return completed lessons count (or 0 if not enrolled)
        public int GetProgress(string courseId)
        {
            int count = 0;
            foreach(var a in _progress)
                if(a.Key == courseId)count += a.Value;
               
            return count;
        }
    }
}
