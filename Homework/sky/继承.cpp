#include <bits/stdc++.h>
using namespace std;

class A{
    int x;
public:
    A(int x):x(x){cout<<"A������"<<endl;}
    ~A(){cout<<"A������"<<endl;}
};

class B:public A
{
    int y;
public:
    B(int x,int y):A(x),y(y){cout<<"B������"<<endl;}
    ~B(){cout<<"B������"<<endl;}
};

class C:public B
{
    int z;
public:
    C(int x,int y,int z):B(x,y),z(z){cout<<"C������"<<endl;}
    ~C(){cout<<"C������"<<endl;}
};

int main(){
    A a(1);
    B b(1,2);
    C c(1,2,3);
    return 0;
}