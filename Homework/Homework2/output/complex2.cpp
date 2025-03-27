#include <iostream>
using namespace std;

class Complex{
    int x,y;
public:
    Complex(int m=0,int n=0):x(m),y(n){}
    Complex& operator=(const Complex &other){
        if(this!=&other){
            x=other.x;
            y=other.y;
        }
        return *this;
    }
    friend Complex operator+(const Complex &a,const Complex &b){
        return Complex(a.x+b.x,a.y+b.y);
    }
    friend Complex operator*(const Complex &a,const Complex &b){
        return Complex(a.x*b.x-a.y*b.y,a.x*b.y+a.y*b.x);
    }
    friend ostream& operator<<(ostream &out,const Complex &c){
        if(c.y==0){
            out<<c.x;
        }else if(c.y>0){
            out<<c.x<<"+"<<c.y<<"i";
        }else{
            out<<c.x<<c.y<<"i";
        }
        return out;
    }
    int getans(){
        return x*x+y*y;
    }
};
int main(){
    int m1,n1,m2,n2,m3,n3;
    cin>>m1>>n1>>m2>>n2>>m3>>n3;
    Complex a(m1,n1);
    Complex b(m2,n2);
    Complex c(m3,n3);
    if(a.getans()>b.getans()){
        if(c.getans()>a.getans()){
            cout<<b<<endl;
            cout<<a<<endl;
            cout<<c<<endl;
        }else{
            //a>b,a>c,c>b;
            if(b.getans()>c.getans()){
                cout<<c<<endl;
                cout<<b<<endl;
                cout<<a<<endl;
            }else{
                cout<<b<<endl;
                cout<<c<<endl;
                cout<<a<<endl;
            }
        }
    }else{
        if(c.getans()>b.getans()){
            cout<<a<<endl;
            cout<<b<<endl;
            cout<<c<<endl;
        }else{
            if(a.getans()>c.getans()){
                cout<<c<<endl;
                cout<<a<<endl;
                cout<<b<<endl;
            }else{
                cout<<a<<endl;
                cout<<c<<endl;
                cout<<b<<endl;
            }
        }
    }
    return 0;
}