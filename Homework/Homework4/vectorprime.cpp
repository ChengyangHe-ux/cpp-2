#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;

    vector<bool> isprime(n+1,true);
    isprime[0]=false;
    isprime[1]=false;
    for(int i=2;i*i<n;i++){
        if(isprime[i]){
            for(int j=i*i;j<n;j+=i){
                isprime[j]=false;
            }
        }
    }
    for(int i=2;i<n;i++){
        if(isprime[i])cout<<i<<" ";
    }
    return 0;
}