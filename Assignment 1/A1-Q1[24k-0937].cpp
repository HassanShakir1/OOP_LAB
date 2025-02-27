#include<iostream>
#include<vector>
#include<string>
using namespace std;
class Mentor;

class Skill{
    int skillId;
    string skillName;
    string description;
    public:
    Skill(int skillId, string skillName, string description){
        this->skillId = skillId;
        this->skillName = skillName;
        this->description = description;
    };
    void showSkillDetails(){
        cout<<"\n Skill ID : "<<skillId;
        cout<<"\n Skill Name : "<<skillName;
        cout<<"\n Skill Description : "<<description;
    };
    void updateSkillDescription(string description){
        this->description=description;
        cout<<"\n Skill Description Updated Successfully";
        showSkillDetails();
    };
    int getSkillId(){
        return skillId;
    };
};
class Sport{
    int sportId;
    string name;
    string description;
    Skill **requiredSkills;
    int skillCount;
    int skillCapacity;
    public:
    Sport(int sportId,string name,string description,int skillCapacity):sportId(sportId),name(name),description(description),skillCapacity(skillCapacity){
        requiredSkills = new Skill*[skillCapacity];
        skillCount=0;
    };
    void addSkill(Skill *s){
        if(skillCount<skillCapacity){
            requiredSkills[skillCount]=s;
            skillCount++;
            cout<<"\n Skill Added ";
        }else{
            skillCapacity*=2;
            Skill** temp = new Skill*[skillCapacity];
            for(int i=0;i<skillCount;i++){
                temp[i]=requiredSkills[i];
            }
            delete[] requiredSkills;
            requiredSkills=temp;
            requiredSkills[skillCount]=s;
            skillCount++;
            cout<<"\n Skill Added ";
        }
    };
    void removeSkill(Skill *s){
        for(int i=0;i<skillCount;i++){
            if(requiredSkills[i]->getSkillId()==s->getSkillId()){
                for(int j=i;j<skillCount-1;j++){
                    requiredSkills[j]=requiredSkills[j+1];
                }
                skillCount--;
                cout<<"\n Skill Removed";
            }
        }
    };
    void showSportDetails(){
        cout<<"\n Sport ID : "<<sportId;
        cout<<"\n Sport Name : "<<name;
        cout<<"\n Sport Description : "<<description;
        cout<<"\n Required Skills : ";
        for(int i=0;i<skillCount;i++){
            requiredSkills[i]->showSkillDetails();
        }
    };
    string getSportName(){
        return name;
    };  
};
class Student{
    string studentId;;
    string name;
    int age;
    Sport** sportInterests;
    Mentor* mentorAssigned;
    int interestCapacty;
    int interestCount;
    public:
    Student(string id,string n,int a,int cap):studentId(id),name(n),age(a),interestCapacty(cap),interestCount(0),mentorAssigned(nullptr){
        sportInterests=new Sport*[interestCapacty];   
    };
    void registerForMentorship(Mentor* m);
    void viewMentorDetails();
    void updateSportInterest(Sport* s){
        if(interestCount<interestCapacty){
            sportInterests[interestCount]=s;
            interestCount++;
            cout<<"\n Sport Interest Added";
        }else{
            interestCapacty*=2;
            Sport** temp= new Sport*[interestCapacty];
            for(int i=0;i<interestCount;i++){
                temp[i]=sportInterests[i];
            }
            delete[] sportInterests;
            sportInterests=temp;
            sportInterests[interestCount]=s;
            interestCount++;
            cout<<"\n Sport Interest Added";
        }
    };
    string getStudentName(){
        return name;
    };
    string getStudentId(){
        return studentId;
    };
    void assignMentor(Mentor* m){
        mentorAssigned=m;
        cout<<"\n Mentor Assigned";
    };
    Mentor* getMentor(){
        return mentorAssigned;
    };
    void removeMentor(){
        mentorAssigned=nullptr;
        cout<<"\n Mentor removed";
    };
};
class Mentor{
    string mentorId;
    string name;
    Sport** sportExpertise;
    int expertiseLimit;
    int expertiseCount;
    int maxLearner;
    int learnerCount;
    Student** assignedLearner;
    public:
    Mentor(string id,string n,int limit,int num):mentorId(id),name(n),expertiseLimit(limit),expertiseCount(0),maxLearner(num),learnerCount(0){
        sportExpertise=new Sport*[expertiseLimit];
        assignedLearner=new Student*[maxLearner];
    };
    void assignlearner(Student* s){
        if(learnerCount<maxLearner){
            assignedLearner[learnerCount]=s;
            s->assignMentor(this);
            learnerCount++;
            cout<<"\n Learner Assigned";
        }else{
            cout<<"\n Maximum Learner Limit Reached";
        };
    }
    void removeLearner(Student* s){
        int flag=0;
        for (int i = 0; i < learnerCount; i++)
        {
            if (assignedLearner[i]->getStudentId()==s->getStudentId())
            {
                for (int j = i; j < learnerCount ; j++)
                {
                    assignedLearner[j]=assignedLearner[j+1];
                }
                flag=1;
                learnerCount--;
            }
            
        }
        if (flag)
        {
            cout<<"\n Learner Removed";
        }else{
            cout<<"\n Learner Not Found";   
        }
        
    };
    void viewAssignedLearner(){
        cout<<"\n Assigned Learners : ";
        for(int i=0;i<learnerCount;i++){
            cout<<assignedLearner[i]->getStudentName()<<"\n ";
        }
    }
    string getMentorName(){
        return name;
    };
};

void Student::registerForMentorship(Mentor* m){
    if(mentorAssigned==nullptr){
        m->assignlearner(this);
    }else{
        cout<<"\n Student already has a mentor";
    }
};

void Student::viewMentorDetails(){
    if(mentorAssigned!=nullptr){
        cout<<"\n Mentor Name : "<<mentorAssigned->getMentorName();
        mentorAssigned->viewAssignedLearner();
    }else{
        cout<<"\n No Mentor Assigned";
    }
}

int main() {
    // Create Skills
    Skill *dribbling = new Skill(1, "Dribbling", "Ability to control the ball while running.");
    Skill *shooting = new Skill(2, "Shooting", "Ability to shoot the ball accurately.");
    Skill *passing = new Skill(3, "Passing", "Ability to pass the ball effectively.");
    
    // Create Sports
    Sport *basketball = new Sport(101, "Basketball", "A team sport played on a court.", 2);
    Sport *football = new Sport(102, "Football", "A game played with a round ball.", 2);
    
    // Add Skills to Sports
    basketball->addSkill(dribbling);
    basketball->addSkill(shooting);
    
    football->addSkill(dribbling);
    football->addSkill(passing);
    
    // Show Sport Details
    cout << "\n--- Sport Details ---";
    basketball->showSportDetails();
    football->showSportDetails();
    
    // Create Students
    Student *john = new Student("S001", "John Doe", 18, 2);
    Student *alice = new Student("S002", "Alice Smith", 20, 2);
    
    // Add Sports Interests to Students
    john->updateSportInterest(basketball);
    john->updateSportInterest(football);
    
    alice->updateSportInterest(football);
    
    // Create Mentors
    Mentor *coachMike = new Mentor("M101", "Coach Mike", 2, 3);
    Mentor *coachEmma = new Mentor("M102", "Coach Emma", 2, 2);
    
    // Assign Students to Mentors
    john->registerForMentorship(coachMike);
    alice->registerForMentorship(coachMike);
    
    // Display Mentor's Assigned Students
    cout << "\n--- Mentor Details ---";
    coachMike->viewAssignedLearner();
    
    // View Student's Mentor
    cout << "\n--- John’s Mentor Details ---";
    john->viewMentorDetails();
    
    cout << "\n--- Alice’s Mentor Details ---";
    alice->viewMentorDetails();
    
    // Remove Student from Mentor
    coachMike->removeLearner(john);
    
    // View Mentor’s Learner List After Removal
    cout << "\n--- Mentor Details After Removing John ---";
    coachMike->viewAssignedLearner();
    
    // Assign New Mentor to John
    john->registerForMentorship(coachEmma);
    
    cout << "\n--- John's Mentor After Reassignment ---";
    john->viewMentorDetails();
    
    // Update Skill Description
    dribbling->updateSkillDescription("Improved ball control technique.");
    
    // Remove a Skill from Sport
    basketball->removeSkill(dribbling);
    
    cout << "\n--- Basketball Skills After Removing Dribbling ---";
    basketball->showSportDetails();
    
    // Clean Up Memory
    delete dribbling;
    delete shooting;
    delete passing;
    delete basketball;
    delete football;
    delete john;
    delete alice;
    delete coachMike;
    delete coachEmma;

    return 0;
}
