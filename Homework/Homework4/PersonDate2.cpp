#include <bits/stdc++.h>
using namespace std;

class Date{
public:
    int y,m,d;
    Date(int y,int m,int d):y(y),m(m),d(d){
        cout<<"Date is Constructed: "<<y<<"-"<<m<<"-"<<d<<endl;
    }
    ~Date(){
        cout<<"Date is Deconstructed: "<<y<<"-"<<m<<"-"<<d<<endl;
    }
    void cout1(){
        cout<<y<<"-"<<m<<"-"<<d;
    }
    bool operator<(const Date &other) const{
        if(y!=other.y) return y<other.y;
        if(m!=other.m) return m<other.m;
        return d<other.d;
    }
};
class Person{
public:
    string name;
    Date *birth;
    Date *leave;
    Person(string name,int y1,int m1,int d1,int y2,int m2,int d2):name(name){
        birth=new Date(y1,m1,d1);
        leave=new Date(y2,m2,d2);
        cout<<"Person is Constructed: "<<name<<endl;
    }
    ~Person(){
        cout<<"Person is Deconstructed: "<<name<<endl;
        delete leave;
        delete birth;
    }
    void cout1(){
        cout<<name<<" ";
        birth->cout1();
        cout<<" ";
        leave->cout1();
        cout<<endl;
    }
};
class Persons{
public:
    vector<Person*> vec;
    Persons(){
        cout<<"Persons is Constructed."<<endl;
    }
    void add(Person* p){
        vec.push_back(p);
    }
    void Output(){
        for(int i=0;i<vec.size();i++){
            vec[i]->cout1();
        }
    }
    ~Persons(){
        sort(vec.begin(),vec.end(),[](Person* a, Person* b){
            return *(a->birth)<*(b->birth);
        });
        for(int i=0;i<vec.size();i++){
            delete vec[i];
        }
        cout<<"Persons is Deconstructed."<<endl;
    }
};

int main(){
    int n;
    cin>>n;
    Persons *group=new Persons();
    for(int i=0;i<n;i++){
        string s;
        int y1,m1,d1,y2,m2,d2;
        cin>>s>>y1>>m1>>d1>>y2>>m2>>d2;
        group->add(new Person(s,y1,m1,d1,y2,m2,d2));
    }
    group->Output();
    delete group;
    return 0;
}
