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
class ComplexArray{
    Complex* data;
    int size;
public:
    ComplexArray(int n):size(n){
        data=new Complex[n];
    }
    ~ComplexArray(){
        delete[] data;
    }
    void set(int index,const Complex &c){
        data[index]=c;
    }
    void sort() {
        for (int i = 0; i < size - 1; i++) {
            for (int j = 0; j < size - 1 - i; j++) {
                if (data[j].getans() > data[j + 1].getans()) {
                    swap(data[j], data[j + 1]);
                }
            }
        }
    }
    void print() {
        for (int i = 0; i < size; i++) {
            cout << data[i] << endl;
        }
    }
};
int main(){
    int n;
    cin >> n;
    ComplexArray arr(n);
    for(int i=0;i<n;i++){
        int x,y;
        cin>>x>>y;
        Complex a(x,y);
        arr.set(i,a);
    }
    arr.sort();
    arr.print();
    return 0;
}