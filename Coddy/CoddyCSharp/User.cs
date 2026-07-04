using System.Collections.Generic;
using System;

public class User {

    public string username;
    public string email;
    private string location;
    public SortedDictionary<string, int> skills;

    public User(string username, string email) {
        this.username = username;
        this.email = email;
        this.location = "unset";
        this.skills = new SortedDictionary<string, int>();
    }

    public string getLocation() {
        return this.location;
    }

    public void setLocation(string location) {
        this.location = location;
    }

    public void info() {
        System.Console.WriteLine("Username: " + this.username);
        System.Console.WriteLine("Email: " + this.email);
        System.Console.WriteLine("Location: " + this.location);
    }

    public void learn(string skill) {
        if (!this.skills.ContainsKey(skill)) {
            this.skills[skill] = 0;
        }
        this.skills[skill] += 1;
    }

    public void showSkills() {
        foreach(var elem in skills) Console.WriteLine(elem.Key+": "+elem.Value);
    }

    public void clearSkill(string skill) {
        if(skills.ContainsKey(skill))
            skills.Remove(skill);
        return;
    }

    public int calculateSalary() {
        int sumOfAllLevels = 0;
        foreach(var skill in skills) sumOfAllLevels += skill.Value; 
        return sumOfAllLevels * 100;
    }
}
