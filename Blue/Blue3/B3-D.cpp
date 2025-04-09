#include <bits/stdc++.h>
using namespace std;
using ll=long long;
int main(){
    int n;
    cin>>n;
    vector<int>a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    ll sum=0;
    for(int i=0;i<n;i++){
        int x=0;
        for(int j=i;j<n;j++){
            x^=a[j];
            sum+=x;
        }
    }
    cout<<sum<<endl;


    return 0;
}