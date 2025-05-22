#include <bits/stdc++.h>
using namespace std;

int main(){
    int N,M;
    cin>>N>>M;
    vector<int>dis(M-1);
    vector<int>sum(M,0);
    for(int i=0;i<M-1;i++){
        cin>>dis[i];
        sum[i+1]=sum[i]+dis[i];
    }
    long long price=0; 
    while(N--){
        int Si,Ti,Wi;
        cin>>Si>>Ti>>Wi;
        int distance=sum[Ti-1]-sum[Si-1];
        price+=distance*Wi;
    }
    cout<<price<<endl;
    return 0;
}