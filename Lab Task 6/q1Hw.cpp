#include<iostream>
using namespace std;
class Book{
    string genre;
    public:
    Book(string g):genre(g){}
    string getGenre(){return genre;}
};
class Novel: public Book{
    string title;
    string author;
    public:
    Novel( string t,string a):title(t),author(a),Book("Novel"){}
    void display(){
        cout<<"\n Title : "<<title<<"\n Author : "<<author<<"\n Genre : "<<getGenre();
    }
};
class Mystery: public Book{
    string title;
    string author;
    public:
    Mystery( string t,string a):title(t),author(a),Book("Mystery"){}
    void display(){
        cout<<"\n Title : "<<title<<"\n Author : "<<author<<"\n Genre : "<<getGenre();
    }
};
int main(int argc, char const *argv[])
{
    Novel n("the truth","hassan");
    Mystery m("Murder Mystry","hassan");
    n.display();
    m.display();
    return 0;
}
