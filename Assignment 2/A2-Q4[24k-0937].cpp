#include<iostream>
using namespace std;

// Function to generate hashed password
string generatePassword(string password){
    int hash = 5381;
    for (char c : password) {
        hash = hash * 33 + c;
    }
    return to_string(hash);
}

// Base User class
class User {
protected:
    string name;
    int Id;
    string* permissions;
    int permissionCount;
    int permissionCapacity;
    string email;
    string hashedPassword;

public:
    User(string n, int t, int p, string e, string pass)
        : name(n), Id(t), permissionCapacity(p), permissionCount(0), email(e), hashedPassword(generatePassword(pass)) {
        permissions = new string[permissionCapacity];
    };

    User() {}

    void addPermission(string p) {
        if (permissionCount < permissionCapacity) {
            permissions[permissionCount] = p;
            permissionCount++;
        } else {
            cout << "\nPermission capacity reached!";
        }
    }

    string* getPermissions() { return permissions; }

    int getPermissionCount() { return permissionCount; }

    bool authenticate(string pass) {
        return generatePassword(pass) == hashedPassword;
    }

    virtual void display() {
        cout << "\nName: " << name << "\nID: " << Id;
        cout << "\nPermissions: ";
        for (int i = 0; i < permissionCount; i++) {
            cout << permissions[i] << " ";
        }
        cout << "\nEmail: " << email << "\nHashed Password: " << hashedPassword << endl;
    }

    void isAccessLab() {
        bool canAccess = false;
        for (int i = 0; i < permissionCount; i++) {
            if (permissions[i] == "full_lab_access") {
                canAccess = true;
                break;
            }
        }
        cout << (canAccess ? name + " can access the lab.\n" : name + " cannot access the lab.\n");
    }

    virtual ~User() { delete[] permissions; }
};

// Student class
class Student : public User {
protected:
    int* assignmentList;
    int assignmentCapacity;

public:
    Student(string n, int t, int p, string e, string pass, int assign)
        : User(n, t, p, e, pass), assignmentCapacity(assign) {
        assignmentList = new int[assignmentCapacity]();
    }

    Student() {}

    void submitAssignment(int index) {
        if (index >= assignmentCapacity) {
            cout << "\nInvalid index!";
            return;
        }
        if (assignmentList[index] == 1) {
            cout << "\nAssignment already submitted!";
        } else {
            assignmentList[index] = 1;
            cout << "\nAssignment submitted!";
        }
    }

    void display() override {
        cout << "\nRole: Student";
        User::display();
        cout << "\nAssignments: ";
        for (int i = 0; i < assignmentCapacity; i++) {
            cout << "A" << i + 1 << " [" << (assignmentList[i] ? "Submitted" : "Not Submitted") << "] ";
        }
        cout << endl;
    }

    ~Student() { delete[] assignmentList; }
};

// TA class
class TA : public Student {
    Student* s[10];  // Array of pointers
    int studentCount;
    string project[2];
    int projectCount;

public:
    TA(string n, int t, int p, string e, string pass, int assign)
        : Student(n, t, p, e, pass, assign), studentCount(0), projectCount(0) {}

    void addStudent(Student* stu) {
        if (studentCount < 10) {
            s[studentCount++] = stu;
            cout << "\nStudent assigned to TA.";
        } else {
            cout << "\nTA cannot manage more than 10 students.";
        }
    }

    void addProject(string pro) {
        if (projectCount < 2) {
            project[projectCount++] = pro;
            cout << "\nProject added.";
        } else {
            cout << "\nTA cannot handle more than 2 projects.";
        }
    }

    void display() override {
        cout << "\nRole: TA";
        User::display();
        cout << "\nManaging Students: " << studentCount;
        cout << "\nProjects: ";
        for (int i = 0; i < projectCount; i++) {
            cout << project[i] << " ";
        }
        cout << endl;
    }

    void displayProject() {
        for (int i = 0; i < projectCount; i++) {
            cout << endl << (i+1) << ". Project Name: " << project[i];
        }
    }

    ~TA() {
        for (int i = 0; i < studentCount; i++) {
            delete s[i];
        }
    }
};

// Professor class
class Professor : public User {
public:
    Professor(string n, int id, int permCap, string e, string pass)
        : User(n, id, permCap, e, pass) {}

    void assignProject(TA& ta, string project) { ta.addProject(project); }

    void display() override {
        cout << "\nRole: Professor";
        User::display();
    }
};

// Authentication function
bool authenticateAndPerformAction(User* u, string action) {
    for (int i = 0; i < u->getPermissionCount(); i++) {
        if (u->getPermissions()[i] == action) {
            return true;
        }
    }
    return false;
}

// Main function to test functionality
int main() {
    // Creating objects
    Student s1("Alice", 101, 1, "alice@mail.com", "pass123", 5);
    TA ta1("Bob", 201, 2, "bob@mail.com", "pass456", 5);
    Professor prof("Dr. Smith", 301, 3, "smith@mail.com", "pass789");

    // Adding permissions
    s1.addPermission("submit_assignment");
    ta1.addPermission("view_projects");
    ta1.addPermission("manage_students");
    prof.addPermission("assign_projects");
    prof.addPermission("full_lab_access");

    // Display information
    s1.display();
    ta1.display();
    prof.display();

    // Assigning students and projects
    ta1.addStudent(&s1);
    prof.assignProject(ta1, "AI Research");

    // Testing authentication and actions
    if (s1.authenticate("pass123")) {
        if (authenticateAndPerformAction(&s1, "submit_assignment"))
            s1.submitAssignment(0);
    } else {
        cout << "\nAuthentication failed!";
    }

    if (ta1.authenticate("pass456")) {
        if (authenticateAndPerformAction(&ta1, "view_projects"))
            ta1.displayProject();
    } else {
        cout << "\nAuthentication failed!";
    }

    if (prof.authenticate("pass789")) {
        if (authenticateAndPerformAction(&prof, "assign_projects"))
            prof.assignProject(ta1, "Quantum Computing");
    } else {
        cout << "\nAuthentication failed!";
    }

    return 0;
}
