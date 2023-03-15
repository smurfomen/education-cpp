#include <string>
#include <vector>
#include <sstream>
#include <numeric>
#include <iostream>
#include <random>
using namespace std;

class Student {
protected:
    string m_name;
    int m_age;
    int m_course;
    vector<int> m_marks;

public:
    Student(string name, int age, int course) :
        m_name(name), m_age(age), m_course(course)
    {
        std::random_device rdev;
        std::uniform_int_distribution<uint32_t> mark_random(2, 5);
        std::uniform_int_distribution<uint32_t> count_random(5, 25);

        int size = count_random(rdev);
        for (int i = 0; i < size; ++i)
            m_marks.push_back(mark_random(rdev));
    }

    virtual ~Student() { }

    int age() const { return m_age; }

    int course() const { return m_course; }

    string name() const { return m_name; }

    virtual string description() const {
        stringstream ss;
        ss << "Student" << endl;
        ss << "Name: " << m_name << endl;
        ss << "Course: " << m_course << endl;
        ss << "Age: " << m_age << endl;
        ss << "Average Rating: " << avg_rate() << endl;
        ss << endl;
        return ss.str();
    }

    virtual double avg_rate() const {
        double avg = m_marks.size() ? accumulate(m_marks.begin(), m_marks.end(), 0.0) / m_marks.size() : 0.0;
        return round(avg * 100) / 100;
    }
};

class Aspirant : public Student {
    string m_theme;
public:
    Aspirant(string name, int age, int course, string graduate_theme) :
        Student(name, age, course), m_theme(graduate_theme) { }

    virtual string description() const {
        stringstream ss;
        ss << "Aspirant" << endl;
        ss << "Name: " << m_name << endl;
        ss << "Course: " << m_course << endl;
        ss << "Age: " << m_age << endl;
        ss << "Average Rating: " << (avg_rate() >= 3.5 ? "Good" : "Bad") << endl;
        ss << "Graduate Work Theme: " << m_theme << endl;
        return ss.str();
    }
};


vector<Student*> GetAllStudents() {
    /* like data base selected students */
    return {
        new Student("Mike", 22, 4),
        new Student("Jinn", 21, 3),
        new Student("John", 18, 1),
        new Aspirant("Frad", 24, 2, "Methaphisics at Earth"),
        new Aspirant("Rouse", 23, 1, "Supermeatbolls around us"),
        new Aspirant("Mary", 26, 2, "Love, Death and Robots"),
    };
}

int main()
{
    vector<Student*> studs = GetAllStudents();
    for (Student* it : studs) {
        cout << it->description();
        cout << "---------------------------" << endl;
    }

    return 0;
}