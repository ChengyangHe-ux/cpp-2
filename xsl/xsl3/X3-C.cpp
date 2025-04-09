#include <bits/stdc++.h>
using namespace std;

using ll=long long;
int main(){
    ll n,m,q;
    cin>>n>>m>>q;
    ll l=m,r=m;
    while(q--){
        ll s;
        cin>>s;
        if(s<l){
            l--;
        }else if(s>r){
            r++;
        }else{
            l--;r++;
        }
        cout<<(r-l+1)<<endl;
    }
    
    return 0;
}