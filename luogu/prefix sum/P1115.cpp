#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    
    vector<int>a(n,0);
    
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    vector<int>b(n,0);
    b[0]=a[0];

    for(int i=1;i<n;i++){
        b[i]=a[i]+b[i-1];
    }

    int ans=b[0];
    int min1=0;
    for(int i=0;i<n;i++){
        ans=max(ans,b[i]-min1);
        min1=min(min1,b[i]);
    }
    
    cout<<ans<<endl;
    return 0;
}
