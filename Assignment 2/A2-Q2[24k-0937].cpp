#include<iostream>
using namespace std;
class Ghost{
    protected:
    string name;
    int scareLevel;
    public:
    Ghost(string n,int s):name(n),scareLevel(s){}
    Ghost(){}
    virtual void haunt(){
        cout<<"\n Main class of ghost ";
    }
    string getName(){
        return name;
    }
    int getScareLevel(){
        return scareLevel;
    }
    void operator<<(const Ghost &g){
        cout<<"\n Ghost Played By : "<<g.name<<"\n Scare Level : "<<g.scareLevel;
    }
    Ghost operator+(Ghost&g){
        if(this->scareLevel+g.getScareLevel()>10){
            Ghost temp("Bigger Ghost",10);
            return temp;
        }else{
            Ghost temp("Bigger Ghost",this->scareLevel+g.getScareLevel());
            return temp;
        }
    }
    virtual ~Ghost() {}
};
class Poltergeists:virtual public Ghost{
    public:
    Poltergeists(string n,int s):Ghost(n,s){};
    void haunt(){
        cout<<name<<"\n is Poltergeist which moves objects mysteriously!\n";
    }
};
class Banshees:public Ghost{
    public:
    Banshees(string n,int s):Ghost(n,s){};
    void haunt(){
        cout<<name<<"\n is Banshees which scream loudly!\n";
    }
};
class ShadowGhosts:virtual public Ghost{
    public:
    ShadowGhosts(string n,int s):Ghost(n,s){};
    void haunt(){
        cout<<name<<"\n is ShadowGhost which whisper creepily!\n";
    }
};
class ShadowPoltergeist: public ShadowGhosts,public Poltergeists{
    public:
    ShadowPoltergeist(string n, int s) : Ghost(n, s), ShadowGhosts(n, s), Poltergeists(n, s) {}
    void haunt(){
        cout<<name<<"\n is ShadowPoltergeist which can whisper creepily and moves objects mysteriously!\n";
    }
};
class Visitor{
    string name;
    int bravery;
    public:
    Visitor(string n,int b):name(n),bravery(b){}
    string getName(){
        return name;
    }
    int getBravery(){return bravery;}
};
class HauntedHouse{
    string name;
    int ghostCount;
    int ghostLimit;
    public:
    Ghost** g;
    HauntedHouse(string n):name(n),ghostCount(0),ghostLimit(10){
        g=new Ghost*[ghostLimit];
    }
    void addGhost(Ghost *gNew){
        if(ghostCount<ghostLimit){
            g[ghostCount]=gNew;
            ghostCount++;
            cout<<"\n Ghost Added ";
        }else{
            ghostLimit*=2;
            Ghost **temp= new Ghost*[ghostLimit];
            for (int i = 0; i < ghostCount; i++)
            {
                temp[i]=g[i];
            }
            delete[] g;
            g=temp;
            g[ghostCount]=gNew;
            ghostCount++;
            cout<<"\n Ghost Added ";
        }
    }
    int getGhostCount(){return ghostCount;}
    ~HauntedHouse() {
        for (int i = 0; i < ghostCount; i++) {
            delete g[i];  
        }
        delete[] g;
    }
    friend void visit(Visitor *v,int visitorC,HauntedHouse &h);
};
void visit(Visitor *v,int visitorC,HauntedHouse &h){
    cout<<"\n Welcome to Haunted House";
    int braveryMin;
    int braveryMax;
    for (int i = 0; i < visitorC; i++)
    {
        cout<<endl<<v[i].getName()<<"is exploring";cout << endl << v[i].getName() << " is exploring" << endl;
        if(v[i].getBravery() >= 1 && v[i].getBravery() <= 4){
            braveryMin = 1;
            braveryMax = 4;
        }
        else if(v[i].getBravery() >= 5 && v[i].getBravery() <= 7){
            braveryMin = 5;
            braveryMax = 7;
        }
        else{
            braveryMin = 8;
            braveryMax = 10;
        }
        
        for (int j = 0; j < h.getGhostCount(); j++)
        {
            h.g[j]->haunt();
            if (h.g[j]->getScareLevel()<braveryMin)
            {
                cout << v[i].getName() << " laughs and taunts the ghost!\n";
            }else if (h.g[j]->getScareLevel()>braveryMax)
            {
                cout << v[i].getName() << " screams and runs away!\n";
            }else{
                cout << v[i].getName() << " has a shaky voice but stays!\n";
            }
            
            
        }
        
    }
    
}
int main() {
    HauntedHouse house("Haunted Mansion");

    house.addGhost(new Poltergeists("Polty", 3));
    house.addGhost(new Banshees("Banshee Queen", 7));
    house.addGhost(new ShadowGhosts("Dark Whisper", 5));
    house.addGhost(new ShadowPoltergeist("Shadow Terror", 9));

    Visitor visitors[] = {
        Visitor("Alice", 2),  
        Visitor("Bob", 6),    
        Visitor("Charlie", 8) 
    };

    int visitorCount = sizeof(visitors) / sizeof(visitors[0]);

    visit(visitors, visitorCount, house);

    return 0; 
}
