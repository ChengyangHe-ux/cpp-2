#include<bits/stdc++.h>
using namespace std;

class Date{
    int y,m,d;
public:
    Date(int y,int m,int d): y(y),m(m),d(d){}
    bool isLeapYear(int y){
        return (y%400==0||y%4==0&&y%100!=0);
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
    void addday(int num){
        while(num > 0) {
            int d1=leftday(y,m);
            int remaining=d1-d;
            if(num>remaining) {
                num-=(remaining+1);
                d=1;
                m++;
                if(m>12) {
                    m=1;
                    y++;
                }
            }else{
                d+=num;
                break;
            }
        } 
    }
    void cout1(){
        cout<<y<<" "<<m<<" "<<d;
    }
    int days() {
        int days=0;
        
        for (int i=1;i<y;i++) {
            if(isLeapYear(i)){
                days+=366;
            }else{
                days+=365;
            }
        }
        int monthDays[13]={0,31,28,31,30,31,30,31,31,30,31,30,31};
        for (int i=1;i<m;i++) {
            if(i==2&&isLeapYear(y))
                days+=29;
            else
                days+=monthDays[i];
        }
        days+=(d-1);
        return days;
    }
};
int main(){
    int y1,m1,d1;
    cin>>y1>>m1>>d1;
    int y2,m2,d2;
    cin>>y2>>m2>>d2;
    Date date1(y1,m1,d1),date2(y2,m2,d2);
    cout<<date2.days()-date1.days();
    return 0;
}