#include <bits/stdc++.h>

using namespace std;
using ll=long long;

int gcd(ll a,ll b){
    while(b!=0){
        ll temp=a%b;
        a=b;
        b=temp;
    }
    return a;
}

int main(){
    ll a,b;
    cin>>a>>b;
    ll tmp=gcd(a,b);
    if(tmp<2){
        cout<<0<<endl;
        return 0;
    }
    for(ll i=2;i<=tmp;i++){
        if(a%i==0&&b%i==0){
            cout<<(a/i)*(b/i)<<endl;
            break;       
        }
    }
    return 0;
}