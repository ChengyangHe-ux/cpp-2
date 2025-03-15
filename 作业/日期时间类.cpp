#include <iostream>
using namespace std;

class DateTime {
    int year, month, day;
    int hour, minute, second;
public:
    DateTime(int y,int m,int d,int h,int mi,int s):year(y),month(m),day(d),hour(h),minute(mi),second(s){}
    bool isLeapYear(int y) {
        return (y%400==0)||(y%4==0&&y%100!=0);
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
    void addSeconds(int s) {
        int total=hour*3600+minute*60+second+s;
        int extra=total/86400;
        int newS=total%86400;
        if(newS<0){
            newS+=86400;
            extra--;
        }
        hour=newS/3600;
        newS%=3600;
        minute=newS/60;
        second=newS%60;
        while(extra>0) {
            int current=leftday(year,month);
            if(extra>(current-day)) {
                extra-=(current-day+1);
                day=1;
                month++;
                if(month>12){
                    month=1;
                    year++;
                }
            } else {
                day+=extra;
                extra=0;
            }
        }
    }
    void cout1() {
        cout<<year<<" "<<month<<" "<<day<< " "<<hour<<" "<<minute<<" "<<second;
    }
};

int main(){
    int y,m,d,h,mi,s,addS;
    cin>>y>>m>>d>>h>>mi>>s;
    cin>>addS;
    DateTime dt(y,m,d,h,mi,s);
    dt.addSeconds(addS);
    dt.cout1();
    return 0;
}