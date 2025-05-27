#include <iostream>
#include <vector>
#include <map>
#include <string>

struct Student 
{

    std::pair<std::string, std::string> name; 

    std::map<std::string, int> grades;        
};


double average_grade(const Student& s)
{
    int sum = 0;

    for (const auto& subject : s.grades) 
    {
        sum += subject.second;
    }
    return s.grades.empty() ? 0.0 : (double)sum / s.grades.size();
}

double subject_average(const std::vector<Student>& group, const std::string& subject) 
{
    int sum = 0;
    int count = 0;

    for (const auto& student : group) {
        if (student.grades.count(subject)) {
            sum += student.grades.at(subject);
            count++;
        }
    }

    return count == 0 ? 0.0 : (double)sum / count;
}

int main() {
    
    std::vector<Student> group = 
    {
        { {"Ivan", "Shevchenko"}, { {"Math", 90}, {"Physics", 80}, {"English", 95} } },

        { {"Olena", "Kovalenko"}, { {"Math", 85}, {"Physics", 88}, {"English", 90} } },

        { {"Andriy", "Melnyk"},   { {"Math", 70}, {"Physics", 75}, {"English", 65} } }
    };

    std::cout << "Average grade: \n";

    for (const auto& student : group) 
    {
        std::cout << student.name.first << " " << student.name.second << ": " << average_grade(student) << "\n";
    }

    std::cout << "\nSubject average: \n";

    std::vector<std::string> subjects = { "Math", "Physics", "English" };

    for (const auto& subject : subjects)
    {
        std::cout << subject << ": " << subject_average(group, subject) << "\n";
    }

    return 0;
}