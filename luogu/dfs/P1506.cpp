#include <bits/stdc++.h>
using namespace std;
int dx[]={1,-1, 0, 0};
int dy[]={0, 0,-1, 1};
int x,y;
void dfs(vector<vector<char>>&M,vector<vector<bool>>&vis,int i,int j){
    if(M[i][j]=='0')M[i][j]='1';
    vis[i][j]=true;
    for(int k=0;k<4;k++){
        int x2=i+dx[k];
        int y2=j+dy[k];
        if(x2<0||x2>=x||y2<0||y2>=y||vis[x2][y2]||M[x2][y2]=='*')continue;
        dfs(M,vis,x2,y2);
    }
}
int main(){
    cin>>x>>y;
    vector<vector<char>>M(x,vector<char>(y));
    vector<vector<bool>>vis(x,vector<bool>(y,false));
    
    for(int i=0;i<x;i++){
        string s;
        cin>>s;
        for(int j=0;j<y;j++){
            M[i][j]=s[j];
        }
    }
    for (int i=0;i<x; i++) {
        if (M[i][0]=='0')dfs(M,vis,i,0);
        if (M[i][y-1]=='0')dfs(M,vis,i,y-1);
    }
    for (int j=0;j<y;j++) {
        if(M[0][j]=='0')dfs(M,vis,0,j);
        if(M[x-1][j]=='0')dfs(M,vis,x-1,j);
    }
    int count=0;
    for(int i=0;i<x;i++){
        for(int j=0;j<y;j++){
            if(M[i][j]=='0') count++;
        }
    }
    cout<<count<<endl;
    return 0;
}