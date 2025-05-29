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
    int timesum(){
        int ans=0;
        ans+=(h*3600+m*60+s);
        return ans;
    }
    int difftime(Time &obj){
        int t1=timesum();
        int t2=obj.timesum();
        return t2-t1;
    }
    ~Time(){}
};
int main(){
    int x1,y1,z1;
    cin>>x1>>y1>>z1;
    int x2,y2,z2;
    cin>>x2>>y2>>z2;
    Time H1(x1,y1,z1);
    Time H2(x2,y2,z2);
    int ans=H1.difftime(H2);
    cout<<ans<<endl;
    return 0;
}