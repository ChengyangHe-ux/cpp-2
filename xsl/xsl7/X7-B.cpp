#include <bits/stdc++.h>
using namespace std;

int main(){
    int k;
    cin>>k;
    vector<int> arr(k);
    int max1=0;
    for(int i=0;i<k;i++){
        cin>>arr[i];
        max1=max(max1,arr[i]);
    }
    vector<bool> prime(max1+1,true);
    prime[0]=prime[1]=0;
    for(int i=2;i<sqrt(max1);i++){
        if(prime[i]){
            for(int j=i*i;j<=max1;j+=i){
                prime[j]=0;
            }
        }
    }
    vector<int> ans(max1+1,0);
    int tmp=0;
    for(int i=2;i<=max1;i++){
        if(prime[i]) tmp=i;
        ans[i]=tmp;
    }
    for(int i=0;i<k;i++){
        cout<<ans[arr[i]]<<" ";
    }
    return 0;
}