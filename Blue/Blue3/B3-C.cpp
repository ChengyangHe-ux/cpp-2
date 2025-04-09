#include <bits/stdc++.h>
using namespace std;
#define int long long 
int main(){
    int sum=1;
    for(int i=1;i<15;i++){
        sum*=i;
    }
    int a=0;
    a=(2*27*25*23*3*19*17)/(6);
    int ans=a*sum;
    cout<<ans<<endl;
    return 0;
}