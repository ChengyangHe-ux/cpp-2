#include <bits/stdc++.h>
using namespace std;
const int dx[] = {-1, -1, -1, 0, 0, 1, 1, 1};
const int dy[] = {-1, 0, 1, -1, 1, -1, 0, 1};
void dfs(int i,int j,vector<vector<char>>&grid,vector<vector<bool>>&visited){
    visited[i][j]=true;
    for(int k=0;k<8;k++){
        int ni=i+dx[k];
        int nj=j+dy[k];
        if (ni >= 0 && ni < grid.size() && nj >= 0 && nj < grid[0].size()) {
            if (grid[ni][nj] == 'W' && !visited[ni][nj]) {
                dfs(ni, nj, grid, visited);
            }
        }
    }
}
int main(){
    int N,M;
    cin>>N>>M;
    vector<vector<char>>grid(N,vector<char>(M,0));
    vector<vector<bool>>visited(N,vector<bool>(M,false));
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            cin>>grid[i][j];
        }
    }
    int pondcount=0;
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            if(grid[i][j]=='W'&&!visited[i][j]){
                dfs(i,j,grid,visited);
                pondcount++;
            }
        }
    }
    cout<<pondcount<<endl;

    return 0;
}