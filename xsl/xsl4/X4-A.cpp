#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
    int t;
    cin>>t;
    while(t--){
        int x;
        cin>>x;
        int cnt=0;
        while(x){
            cnt+=x&1;
            x>>=1;
        }
        int ans=0;
        ans=cnt+(cnt-1)*100;
        cout<<ans<<endl;
    }
    

    return 0;
}