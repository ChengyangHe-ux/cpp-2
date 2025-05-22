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

int main(){
    string s1, s2;
    int y1,m1,d1,y2,m2,d2;
    int y3,m3,d3,y4,m4,d4;
    cin>>s1>>y1>>m1>>d1>>y2>>m2>>d2;
    cin>>s2>>y3>>m3>>d3>>y4>>m4>>d4;
    Person *p1=new Person(s1,y1,m1,d1,y2,m2,d2);
    Person *p2=new Person(s2,y3,m3,d3,y4,m4,d4);
    p1->cout1();
    p2->cout1();
    if(*(p1->birth)<*(p2->birth)){
        delete p2;
        delete p1;
    }else{
        delete p1;
        delete p2;
    }
    return 0;
}
