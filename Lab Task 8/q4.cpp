#include <iostream>
#include <vector>
using namespace std;

class Person {
protected:
    string name;
    int id;
    string address;
    int phoneNumber;
    string email;

public:
    Person(string n, int i, string a, int p, string e)
        : name(n), id(i), address(a), phoneNumber(p), email(e) {}

    virtual void displayInfo() {
        cout << "\nName: " << name << "\nID: " << id << "\nAddress: " << address
             << "\nPhone Number: " << phoneNumber << "\nEmail: " << email << endl;
    }

    void updateInfo(string n, int i, string a, int p, string e) {
        name = n;
        id = i;
        address = a;
        phoneNumber = p;
        email = e;
        cout << "\nInfo Updated.\n";
    }

    virtual ~Person() {} // Virtual destructor for proper cleanup
};

// Student Class
class Student : public Person {
    vector<string> coursesEnrolled;
    float GPA;
    int enrollmentYear;

public:
    Student(string n, int i, string a, int p, string e, float gpa, int year)
        : Person(n, i, a, p, e), GPA(gpa), enrollmentYear(year) {}

    void enrollCourse(string course) {
        coursesEnrolled.push_back(course);
    }
    string getName(){
        return name;
    }
    void displayInfo() override {
        Person::displayInfo();
        cout << "GPA: " << GPA << "\nEnrollment Year: " << enrollmentYear << "\nCourses Enrolled: ";
        for (const auto &course : coursesEnrolled) {
            cout << course << " ";
        }
        cout << endl;
    }
};

// Professor Class
class Professor : public Person {
    string department;
    vector<string> coursesTaught;
    float salary;

public:
    Professor(string n, int i, string a, int p, string e, string dept, float sal)
        : Person(n, i, a, p, e), department(dept), salary(sal) {}

    void addCourse(string course) {
        coursesTaught.push_back(course);
    }

    void displayInfo() override {
        Person::displayInfo();
        cout << "Department: " << department << "\nSalary: $" << salary << "\nCourses Taught: ";
        for (const auto &course : coursesTaught) {
            cout << course << " ";
        }
        cout << endl;
    }
};

// Staff Class
class Staff : public Person {
    string department;
    string position;
    float salary;

public:
    Staff(string n, int i, string a, int p, string e, string dept, string pos, float sal)
        : Person(n, i, a, p, e), department(dept), position(pos), salary(sal) {}

    void displayInfo() override {
        Person::displayInfo();
        cout << "Department: " << department << "\nPosition: " << position << "\nSalary: $" << salary << endl;
    }
};

// Course Class
class Course {
    string courseId;
    string courseName;
    int credits;
    string instructor;
    string schedule;
    vector<Student *> enrolledStudents;

public:
    Course(string id, string name, int c, string inst, string sched)
        : courseId(id), courseName(name), credits(c), instructor(inst), schedule(sched) {}

    void registerStudent(Student *student) {
        enrolledStudents.push_back(student);
        student->enrollCourse(courseName);
        cout << student->getName() << " has been enrolled in " << courseName << endl;
    }

    void displayCourseInfo() {
        cout << "Course ID: " << courseId << "\nCourse Name: " << courseName
             << "\nCredits: " << credits << "\nInstructor: " << instructor
             << "\nSchedule: " << schedule << "\nEnrolled Students: ";
        for (const auto &student : enrolledStudents) {
            cout << student->getName() << " ";
        }
        cout << endl;
    }
};

int main() {
    Student s1("Alice", 101, "123 St", 1234567890, "alice@example.com", 3.8, 2022);
    Professor p1("Dr. Smith", 201, "456 St", 9876543210, "smith@example.com", "Computer Science", 80000);
    Staff staff1("Bob", 301, "789 St", 1122334455, "bob@example.com", "Admin", "Manager", 50000);

    s1.enrollCourse("Math 101");
    p1.addCourse("Math 101");

    cout << "\nStudent Info:\n";
    s1.displayInfo();

    cout << "\nProfessor Info:\n";
    p1.displayInfo();

    cout << "\nStaff Info:\n";
    staff1.displayInfo();

    Course c1("CSE101", "Intro to CS", 3, "Dr. Smith", "MWF 10-11 AM");
    c1.registerStudent(&s1);
    c1.displayCourseInfo();

    return 0;
}
