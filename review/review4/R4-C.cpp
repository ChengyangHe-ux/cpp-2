#include <bits/stdc++.h>
using namespace std;

class Date{
    int y,m,d;
public:
    Date(int y=0,int m=0,int d=0):y(y),m(m),d(d){
        cout<<"Date is Constructed: "<<y<<"-"<<m<<"-"<<d<<endl;
    }
    ~Date(){
        cout<<"Date is Deconstructed: "<<y<<"-"<<m<<"-"<<d<<endl;
    }
    friend ostream& operator<<(ostream& out,Date& obj){
        out<<obj.y<<"-"<<obj.m<<"-"<<obj.d;
        return out;
    }
    bool operator<(const Date &other) const{
        if(y!=other.y) return y<other.y;
        if(m!=other.m) return m<other.m;
        return d<other.d;
    }
};
class Person{
    string name;
    
    Date *leave;
public:
    Date *birth;
    Person(string name,int x1,int y1,int z1,int x2,int y2,int z2){
        this->name=name;
        birth=new Date(x1,y1,z1);
        leave=new Date(x2,y2,z2);
        cout<<"Person is Constructed: "<<name<<endl;
    }
    friend ostream& operator<<(ostream& out,Person& obj){
        out<<obj.name<<" "<<*(obj.birth)<<" "<<*(obj.leave)<<endl;
        return out;
    }
    ~Person(){
        cout<<"Person is Deconstructed: "<<name<<endl;
        delete leave;
        delete birth;
    
    }
};
int main(){
    string s1,s2;
    int y1,m1,d1,y2,m2,d2;
    int y3,m3,d3,y4,m4,d4;
    cin>>s1>>y1>>m1>>d1>>y2>>m2>>d2;
    cin>>s2>>y3>>m3>>d3>>y4>>m4>>d4;
    Person *p1=new Person(s1,y1,m1,d1,y2,m2,d2);
    Person *p2=new Person(s2,y3,m3,d3,y4,m4,d4);
    cout<<*p1;
    cout<<*p2;
    if(*(p1->birth)<*(p2->birth)){
        delete p2;
        delete p1;
    }else{
        delete p1;
        delete p2;
    }
    return 0;
}