#include<iostream>
using namespace std;
class DateTime{
    int year,month,day;
    int hour,minute,second;
public:
DateTime(int y,int m,int d,int h,int mi,int s):year(y),month(m),day(d),hour(h),minute(mi),second(s){}
bool isLeapYear(int y){
    return(y%400==0||(y%4==0&&y%100!=0));
}
int leftday(int y,int m){
    if(m==2){
        if(isLeapYear(y)){
            return 29;
        }else{
            return 28;
        }
    }
    if(m==4||m==6||m==9||m==11){
        return 30;
    }
    return 31;
}
int days(){
    int days=0;
    for(int i=1;i<year;i++){
        if(isLeapYear(i))days+=366;
        else days+=365;
    }
    for(int i=1;i<month;i++)days+=leftday(year,i);
        days+=(day-1);
    return days;
}
int toSeconds(){
    return days()*86400+hour*3600+minute*60+second;
}
};
int main(){
    int y1,m1,d1,h1,mi1,s1;
    cin>>y1>>m1>>d1>>h1>>mi1>>s1;
    int y2,m2,d2,h2,mi2,s2;
    cin>>y2>>m2>>d2>>h2>>mi2>>s2;
    DateTime t1(y1,m1,d1,h1,mi1,s1);
    DateTime t2(y2,m2,d2,h2,mi2,s2);
    cout<<t2.toSeconds()-t1.toSeconds();
    return 0;
}