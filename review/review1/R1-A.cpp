#include <bits/stdc++.h>
using namespace std;

class Time{
    int h,m,s;
public:
    Time(int h,int m,int s):h(h),m(m),s(s){}
    void timeadd(int x){
        s+=x;
        int m2=0,h2=0;
        if(s>=60){
            m2=s/60;
            s=s%60;
        }
        m+=m2;
        if(m>=60){
            h2=m/60;
            m=m%60;
        }
        h+=h2;
        h%=24;
        cout<<h<<" "<<m<<" "<<s;
    }
    void cout1(){
        cout<<h<<" "<<m<<" "<<s;
    }
};
int main(){
    int x,y,z;
    cin>>x>>y>>z;
    Time H(x,y,z);
    int m;
    cin>>m;
    H.timeadd(m);
    H.cout1();
    return 0;
}//2+6+6+7+8+5=34/6 6