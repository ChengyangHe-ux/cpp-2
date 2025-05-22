#include <bits/stdc++.h>
using namespace std;

class A{
    int x;
public:
    A(int x):x(x){cout<<"A构造了"<<endl;}
    ~A(){cout<<"A析构了"<<endl;}
};

class B:public A
{
    int y;
public:
    B(int x,int y):A(x),y(y){cout<<"B构造了"<<endl;}
    ~B(){cout<<"B析构了"<<endl;}
};

class C:public B
{
    int z;
public:
    C(int x,int y,int z):B(x,y),z(z){cout<<"C构造了"<<endl;}
    ~C(){cout<<"C析构了"<<endl;}
};

int main(){
    A a(1);
    B b(1,2);
    C c(1,2,3);
    return 0;
}