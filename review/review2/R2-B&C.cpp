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
        }else{
            cout<<endl;
        }
    }
    bool operator<(const Complex &obj){
        return(x*x+y*y<obj.x*obj.x+obj.y*obj.y);
    }
};
class ComplexArray{
    vector<Complex> T;
public:
    ComplexArray(vector<Complex> &b){
        for(int i=0;i<b.size();i++){
            T.push_back(b[i]);
        }
    }
    void mysort(){
        for(int i=0;i<T.size()-1;i++){
            for(int j=0;j<T.size()-i-1;j++){
                if(T[j+1]<T[j]){
                    swap(T[j+1],T[j]);
                }
            }
        } 
    }
    void Output(){
        for(int i=0;i<T.size();i++){
            T[i].Output();
        }cout<<endl;
    }
};
int main(){
    int n;cin>>n;
    vector<Complex> T;
    for(int i=0;i<n;i++){
        int x,y;
        cin>>x>>y;
        Complex M1(x,y);
        T.push_back(M1);
    }
    ComplexArray M(T);
    M.mysort();
    M.Output();
    return 0;
}