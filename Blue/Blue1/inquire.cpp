#include <bits/stdc++.h>

using namespace std;

int main(){
    int T;
    cin>>T;

    while(T--){
        int l,r;
        cin>>l>>r;
        if(2*l > r){
            cout<<"0"<<endl;
            break;
        }
        long long M = (long long)r - 2LL*l;
        long long count = (M+1)*(M+2)/2;
        cout<<count<<endl;
    }
    return 0;
}