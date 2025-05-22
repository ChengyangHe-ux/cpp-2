#include <iostream>
using namespace std;

class Date{
    int y,m,d;
public:
    Date(int y,int m,int d):y(y),m(m),d(d){}
    bool isleapyear(int y){
        return(y%400==0||(y%4==0&&y%100!=0));
    }
    int leftday(){
        if(m==2){
            if(isleapyear(y)){
                return 29;
            }else{
                return 28;
            }
        }
        if(m==4||m==6|m==9|m==11) return 30; 
        return 31;
    }
    void Output(){
        cout<<y<<" "<<m<<" "<<d;
    }
};
int main(){




    return 0;
}