#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
    int n;
    cin>>n;
    vector<int>M(n,0);
    
    for(int i=0;i<n;i++){
        cin>>M[i];
    }

    vector<int>left(n);
    left[0]=M[0];
    for(int i=1;i<n;i++){
        left[i]=max(left[i-1],M[i]);
    }
    vector<int>right(n);
    right[n-1]=M[n-1];
    for(int i=n-2;i>=0;i--){
        right[i]=max(right[i+1],M[i]);
    }
    int ans=0;
    for(int i=1;i<n-1;i++){
        int a=left[i];
        int c=right[i];
        int b=M[i];
        ans=max(ans,(a-b)*c);
    }
    cout<<ans<<endl;
    return 0;
}