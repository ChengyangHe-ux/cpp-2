#include <bits/stdc++.h>
using namespace std;

class Time{
    int hour,minute,second;
public:
   Time(int hour,int minute,int second):hour(hour=0),minute(minute=0),second(second=0){}

   int toSecond(){
        return hour*3600+minute*60+second;
   }

   void fromsecond(int totalsecond){
    totalsecond %=86400;
    if(totalsecond<0) totalsecond+=86400;
    hour=totalsecond/3600;
    totalsecond%=3600;
    minute=totalsecond/60;
    second=totalsecond%60;
   }
   void addsecond(int s){
    int total=toSecond()+s;
    fromsecond(total);
   }
   void cout1(){
    cout<<hour<<" "<<minute<<" "<<second;
   }
};
int main(){
    int hour1,minute1,second1;
    cin>>hour1>>minute1>>second1;
    int hour2,minute2,second2;
    cin>>hour2>>minute2>>second2;
    Time t1(hour1,minute1,second1);
    Time t2(hour2,minute2,second2);
    cout<<t2.toSecond()-t1.toSecond();
    return 0;
}