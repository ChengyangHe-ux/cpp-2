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
    friend ostream& operator<<(ostream &out, const Complex &c) {
        out << c.x;
        if (c.y != 0) {
            out << (c.y > 0 ? "+" : "") << c.y << "i";
        }
        return out;
    }
};
int main(){
    int m1,n1,m2,n2,m3,n3;
    cin>>m1>>n1>>m2>>n2>>m3>>n3;
    Complex a(m1,n1);
    Complex b(m2,n2);
    Complex c(m3,n3);
    Complex d=a+b+c;
    Complex e=a*b*c;
    cout<<d<<endl;
    cout<<e<<endl;
    return 0;
}