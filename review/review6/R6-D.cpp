#include <bits/stdc++.h>
using namespace std;

class Time{
    int h,m,s;
public:
    Time(int h,int m,int s):h(h),m(m),s(s){
        cout<<"Time:"<<h<<":"<<m<<":"<<s<<endl;
    }
    ~Time(){cout<<"~Time:"<<h<<":"<<m<<":"<<s<<endl;}
    void Output(){
        cout<<h<<":"<<m<<":"<<s<<endl;
    }
};
int main(){
    int x1,y1,z1;
    int x2,y2,z2;
    cin>>x1>>y1>>z1;
    cin>>x2>>y2>>z2;
    Time T1(x1,y1,z1);
    T1.Output();
    Time T2(x2,y2,z2);
    T2.Output();
    return 0;
}