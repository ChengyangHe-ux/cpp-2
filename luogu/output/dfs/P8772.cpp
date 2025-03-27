#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    vector<long long>a(n,0);
    vector<long long>b(n,0);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }

    for(int i=1;i<n;i++){
        b[i]=b[i-1]+a[i];
    }

    long long sum=0;
    for(int i=0;i<n;i++){
        sum+=a[i]*(b[n-1]-b[i]);
    }
    cout<<sum<<endl;


    return 0;
}