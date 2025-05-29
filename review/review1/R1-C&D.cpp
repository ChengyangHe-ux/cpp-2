#include <bits/stdc++.h>
using namespace std;

class Date{
    int y,m,d;
public:
    Date(int y,int m,int d):y(y),m(m),d(d){}
    bool isleapyear(){
        return (y%400==0||(y%4==0&&y%100!=0));
    }
    int monthday(int m){ 
        if (m==1||m==3||m==5||m==7||m==8||m==10||m==12) return 31;
        if(m==2){
            if(isleapyear()){
                return 29;
            }else return 28;
        }
        return 30;
    }
    void dayadd(int x){ 
        int rem=x;
        while(rem>0){
            int days=monthday(m);
            int leftdays=days-d;
            if(leftdays>=rem){
                d+=rem;
                rem=0;
            }else{
                rem-=(leftdays+1);
                d=1;
                m++;
                if(m>12){
                    m=1;
                    y++;
                }
            }
        }
        cout<<y<<" "<<m<<" "<<d;  
    }
    int sumdays(){
        int sumdays=0;
        for(int i=1;i<=y-1;i++){
            if(i%400==0||(i%4==0&&i%100!=0)){
                sumdays+=366;
            }else{
                sumdays+=365;
            }
        }
        for(int i=1;i<=m-1;i++){
            sumdays+=monthday(i);
        }
        sumdays+=d;
        return sumdays;
    }
    int diffdays(Date &obj){
        int d1=sumdays();
        int d2=obj.sumdays();
        return d2-d1;
    }
};

int main(){
    int x1,y1,z1;
    cin>>x1>>y1>>z1;
    Date D1(x1,y1,z1);
    int x2,y2,z2;
    cin>>x2>>y2>>z2;
    Date D2(x2,y2,z2);
    int days=D1.diffdays(D2);
    cout<<days<<endl;
    return 0;
}