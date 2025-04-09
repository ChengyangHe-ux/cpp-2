#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    while(n--){
        int a,b,c,d,k;
        cin>>a>>b>>c>>d>>k;
        int count=0;
        for(int i=a;i<=b;i++){
            for(int j=c;j<=d;j++){
                if(__gcd(i,j)==k){
                    count++;
                }
            }
        }
    }
    return 0;
}