#include <iostream>
#include <string>
#include <cmath>
using namespace std;

int main() {
    string s;
    cin>>s;
    for(int i=0;i<4;i++){
        int ans=0;
        for(int j=0;j<8;j++){
            if(s[i*8+j]=='1'){
               ans+=pow(2,7-j);
            }
        }
        cout<<ans;
        if(i!=3) cout<<".";
    }

    return 0;
}
