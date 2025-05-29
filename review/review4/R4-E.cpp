#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    vector<bool> T(n+1,true);
    T[1]=false;
    T[0]=false;
    for(int i=0;i*i<n+1;i++){
        if(T[i]==true){
            for(int j=i*i;j<=n+1;j+=i){
                T[j]=false;
            }
        }
    }
    for(int i=2;i<n+1;i++){
        if(T[i]) cout<<i<<" ";
    }
    return 0;
}