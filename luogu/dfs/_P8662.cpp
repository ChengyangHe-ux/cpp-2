#include <bits/stdc++.h>
using namespace std;

int dx[]={1,-1, 0 ,0};
int dy[]={0, 0,-1 ,1};

int col=0;
bool flag;
void dfs(int n,vector<vector<char>>&MP,int x,int y){
    if(MP[x][y]='.')return;
    MP[x][y]='.';
    for(int k=0;k<4;k++){
        int x2=x+dx[k];
        int y2=y+dy[k];
        if(x2<0||x2>=n||y2<0||y2>=n)continue;
        if(MP[x2][y2]=='.'){
            flag=false;
        }
        dfs(n,MP,x2,y2);
        col++;
    }
}
void dfs2(vector<vector<char>>&MP){}
int main(){
    int n;
    cin>>n;
    vector<vector<char>>MP(n,vector<char>(n));
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>MP[i][j];
        }
    }
    vector<vector<char>>NP=MP;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            dfs1;
        }
    }

    return 0;
}