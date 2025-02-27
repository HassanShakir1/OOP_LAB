#include<iostream>
using namespace std;
class Student{
    string studentId;
    string name;
    string location;
    int activeCard;
    int attendenceCount;
    int stop;
    public:
    Student(string id,string n,string l):studentId(id),name(n),location(l),activeCard(0),attendenceCount(0){
        cout<<"\n Student registered Card Inactive Pay fee: ";
    };
    void payFee(){
        activeCard=1;
        cout<<"\n Fee Paid Card Activated";
    };
    int getActiveCard(){
        return activeCard;
    }
    string getStop(){
        return location;
    }
    string getName(){
        return name;
    }
    void tap(){
        if(activeCard){
            attendenceCount++;
            cout<<"\n Student "<<name<<" tapped in";
        }else{
            cout<<"\n Card Inactive";
        }
    }
    void setStop(int s){
        stop=s;
    }
};
class Route{
    int routeNumber;
    string stop;
    public:
    Route(int r,string s):routeNumber(r),stop(s){
        cout<<"\n Route Created";
    };
    string getStop(){
        return stop;
    }
    int getRouteNumber(){
        return routeNumber;
    }
};
class Routes{
    Route** routes;
    int routeCount;
    int routeCapacity;
    Student** students;
    int studentCount;
    int studentCapacity;
    public:
    Routes():routeCount(0),routeCapacity(10),studentCount(0),studentCapacity(10){
        routes=new Route*[routeCapacity];
        students=new Student*[studentCapacity];
    };
    ~Routes(){
        for(int i=0;i<routeCount;i++){
            delete routes[i];
        }
        delete[] routes;
        for(int i=0;i<studentCount;i++){
            delete students[i];
        }
        delete[] students;
    };
    void storeStudent(Student* s){
        if(studentCount<studentCapacity){
            students[studentCount]=s;
            studentCount++;
            cout<<"\n Student Stored";
        }else{
            studentCapacity*=2;
            Student** temp = new Student*[studentCapacity];
            for(int i=0;i<studentCount;i++){
                temp[i]=students[i];
            }
            delete[] students;
            students=temp;
            students[studentCount]=s;
            studentCount++;
            cout<<"\n Student Stored";
        }
    };
    void storeRoute(Route* r){
        if(routeCount<routeCapacity){
            routes[routeCount]=r;
            routeCount++;
            cout<<"\n Route Stored";
        }else{
            routeCapacity*=2;
            Route** temp = new Route*[routeCapacity];
            for(int i=0;i<routeCount;i++){
                temp[i]=routes[i];
            }
            delete[] routes;
            routes=temp;
            routes[routeCount]=r;
            routeCount++;
            cout<<"\n Route Stored";
        }
    };
    void assignRoute(){
        for (int i = 0; i < routeCount; i++)
        {
            for (int j = 0; j < studentCount; j++)
            {
                if (students[j]->getActiveCard())
                {
                    if (students[j]->getStop()==routes[i]->getStop())
                    {
                        cout<<"\n Student "<<students[j]->getName()<<" assigned to Route "<<routes[i]->getRouteNumber();
                        students[j]->setStop(routes[i]->getRouteNumber());
                    }
                }else{
                   cout<<"\n Student's"<<students[j]->getName()<<" Card Inactive"; 
                }
                
            }
            
        }
        
    };
    Student* findStudent(string name) {
        for (int i = 0; i < studentCount; i++) {
            if (students[i]->getName() == name) return students[i];
        }
        return nullptr;
    }
};
int main() {
    Routes system;

    while (true) {
        cout << "\n--- Transport System Menu ---";
        cout << "\n1. Register Student";
        cout << "\n2. Pay Fee";
        cout << "\n3. Add Route";
        cout << "\n4. Assign Routes";
        cout << "\n5. Tap Card (Record Attendance)";
        cout << "\n6. Exit";
        cout << "\nEnter choice: ";
        int choice;
        cin >> choice;
        cin.ignore();

        if (choice == 1) {
            string id, name, loc;
            cout << "\nEnter Student ID: ";
            getline(cin, id);
            cout << "Enter Student Name: ";
            getline(cin, name);
            cout << "Enter Location (Stop): ";
            getline(cin, loc);
            system.storeStudent(new Student(id, name, loc));
        } else if (choice == 2) {
            string name;
            cout << "\nEnter Student Name to Pay Fee: ";
            getline(cin, name);
            
            Student* s = system.findStudent(name);
            if (s) s->payFee();
            else cout << "\nStudent not found!\n";
        } else if (choice == 3) {
            int number;
            string stop;
            cout << "\nEnter Route Number: ";
            cin >> number;
            cin.ignore();
            cout << "Enter Stop Name: ";
            getline(cin, stop);
            system.storeRoute(new Route(number, stop));
        } else if (choice == 4) {
            system.assignRoute();
        } else if (choice == 5) {
            string name;
            cout << "\nEnter Student Name to Tap Card: ";
            getline(cin, name);
            
            Student* s = system.findStudent(name);
            if (s) s->tap();
            else cout << "\nStudent not found!\n";
        } else if (choice == 6) {
            cout << "\nExiting System...\n";
            break;
        } else {
            cout << "\nInvalid Choice. Try Again!\n";
        }
    }

    return 0;
}