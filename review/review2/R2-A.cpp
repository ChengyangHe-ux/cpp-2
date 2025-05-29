#include <bits/stdc++.h>
using namespace std;

class Complex{
    int x;
    int y;
public:
    Complex(int x,int y):x(x),y(y){}
    Complex():x(0),y(0){}
    Complex operator+(const Complex &obj){
        return Complex(x+obj.x,y+obj.y);
    }   
    Complex operator*(const Complex &obj){
       return Complex(x * obj.x - y * obj.y, y * obj.x + x * obj.y);
    }
    Complex& operator=(const Complex &obj){
        this->x=obj.x;
        this->y=obj.y;
        return *this;
    }
    void Output(){
        cout<<x;
        if(y>0){
            cout<<"+"<<y<<"i"<<endl;
        }else if(y<0){
            cout<<y<<"i"<<endl;
        }
    }
};
int main(){
    int x1,y1;
    cin>>x1>>y1;
    int x2,y2;
    cin>>x2>>y2;
    int x3,y3;
    cin>>x3>>y3;
    Complex a(x1,y1);
    Complex b(x2,y2);
    Complex c(x3,y3);
    Complex d;
    d=a+b+c;
    d.Output();
    Complex e;
    e=a*b*c;
    e.Output();   
    return 0;
}