#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    queue<int> q;
    vector<int>dist(n+1,0);
    q.push(1);
    dist[1]=0;
    while(!q.empty()){
        int x=q.front();q.pop();
        if(dist[n]!=0){cout<<dist[n]<<endl;return 0;}
        if(x+1<dist.size()&&dist[x+1]==0){
            dist[x+1]=dist[x]+1;
            q.push(x+1);
        }
        if(x-1<dist.size()&&dist[x-1]==0){
            dist[x-1]=dist[x]+1;
            q.push(x-1);
        }
        if(2*x<dist.size()&&dist[2*x]==0){
            dist[2*x]=dist[x]+1;
            q.push(2*x);
        }
    }
    return 0;
}