#include<bits/stdc++.h>
using namespace std;

class Date{
    int y,m,d;
public:
    Date(int y,int m,int d):y(y),m(m),d(d){}
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
};
int main(){
    int y,m,d;
    cin>>y>>m>>d;
    int num;
    cin>>num;
    Date date(y,m,d);
    date.addday(num);
    date.cout1();
    return 0;
}