using System;
using System.Collections.Generic;
using ELearning.Models;

namespace ELearning.Services
{
    public class EnrollmentService
    {
        // TODO: Create private collections to store courses and track enrollments
        private Dictionary<string, Course> _courses;
        private Dictionary<int, List<string>> _enrolls;
        // TODO: Create a constructor to initialize the collections
        public EnrollmentService()
        {
            _courses = new Dictionary<string, Course>();
            _enrolls = new Dictionary<int, List<string>>();
        } 
        // TODO: Implement AddCourse(Course course) method
        public void AddCourse(Course course){
            _courses[course.Id] = course;
        }
        // TODO: Implement Enroll(Student student, string courseId) method
        // Returns true if enrollment succeeds, false if course doesn't exist or student already enrolled
        public bool Enroll(Student student, string courseId)
        {
            if(!_courses.ContainsKey(courseId)) return false;
            if (_enrolls.ContainsKey(student.Id))
            {
                if(_enrolls[student.Id].Contains(courseId)) return false;

                _enrolls[student.Id].Add(courseId);
                return true;
            } 

            _enrolls.Add(student.Id, new List<string>(){courseId});

            return true;
        }
        // TODO: Implement GetEnrolledCourses(Student student) method
        // Returns a list of course IDs the student is enrolled in
        public List<string> GetEnrolledCourses(Student student)
        {
            return _enrolls[student.Id];
        }
        // TODO: Implement GetCourse(string courseId) method
        // Returns the course or null if not found\
        public Course GetCourse(string courseId)
        {
            return _courses.ContainsKey(courseId) ? _courses[courseId] : null;
        }
    }
}
