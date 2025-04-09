#include<bits/stdc++.h>
using namespace std;
int minM=1e9;
void dfs(vector<int>&M,int x,int n,int depth){
    if(x==n) {
        minM=min(minM,depth);
        return;
    }
    
    if(x<1||x>n||M[x]) return;
    M[x]=1;
    dfs(M,x+1,n,depth+1);
    dfs(M,x-1,n,depth+1);
    dfs(M,2*x,n,depth+1);
    M[x]=0;
}
int main(){
    int n;
    cin>>n;
    vector<int> M(n+1,0);
    dfs(M,1,n,0);
    cout<<minM<<endl;
    return 0;
}