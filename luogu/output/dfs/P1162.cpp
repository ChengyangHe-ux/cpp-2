#include <bits/stdc++.h>
using namespace std;
void dfs(int x,int y,vector<vector<int>>&grid,vector<vector<bool>>&visited,int n)
{   
    if(x<0||x>=n||y<0||y>=n||grid[x][y]!=0||visited[x][y]) return;
    visited[x][y]=true;
    dfs(x+1,y,grid,visited,n);
    dfs(x,y+1,grid,visited,n);
    dfs(x,y-1,grid,visited,n);
    dfs(x-1,y,grid,visited,n);
}
void solve(vector<vector<int>>&grid,int n){
    vector<vector<bool>>visited(n,vector<bool>(n,false));
    for(int i=0;i<n;i++){
        if(grid[i][0]==0&&!visited[i][0]){
            dfs(i,0,grid,visited,n);
        }
        if(grid[n-1][i]==0&&!visited[n-1][i]){
            dfs(n-1,i,grid,visited,n);
        }
        if(grid[0][i]==0&&!visited[0][i]){
            dfs(0,i,grid,visited,n);
        }
        if(grid[i][n-1]==0&&!visited[i][n-1]){
            dfs(i,n-1,grid,visited,n);
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(grid[i][j]==0&&!visited[i][j]){
                grid[i][j]=2;
            }
        }
}
}
int main(){
    int n;
    cin>>n;
    vector<vector<int>>grid(n,vector<int>(n,0));
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>grid[i][j];
        }
    }
    solve(grid,n);
    
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
           cout<<grid[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}