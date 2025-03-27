#include <bits/stdc++.h>
using namespace std;
char a[]={'y','i','z','h','o','n','g'};
int xi[]={1,1, 1,0, 0,-1,-1,-1};
int yi[]={0,1,-1,1,-1, 0,-1, 1};
void dfs(int i,int j,vector<vector<char>>&grid,vector<vector<bool>>&visited,int k,int n){
    if(k==7){
        for(int p=0;p<7;p++){
            visited[i-p*xi[m]][j-p*yi[m]]=true;
        }
        return;
    }
    if(grid[i][j]==a[k]){
        for(int m=0;m<8;m++){
            int x=i+xi[m];
            int y=j+yi[m];
            if(x>=0&&x<n&&y>=0&&y<n&&grid[x][y]==a[k+1]){
                dfs(x,y,grid,visited,k+1,n);
            }
        }
    }
}
int main(){
    int n;
    cin>>n;
    vector<vector<char>>grid(n,vector<char>(n,0));
    vector<vector<bool>>visited(n,vector<bool>(n,false));
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>grid[i][j];
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(grid[i][j]=='y')
                dfs(i,j,grid,visited,0,n);
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(!visited[i][j]){
                cout<<'*';
            }else{
                cout<<grid[i][j];
            }
        }
        cout<<endl;
    }
    return 0;
}