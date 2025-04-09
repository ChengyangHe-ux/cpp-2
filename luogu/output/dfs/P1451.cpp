#include <bits/stdc++.h>
using namespace std;
int dx[]={1,-1, 0, 0};
int dy[]={0, 0, 1,-1};
void dfs(vector<vector<int>>&MP,int x,int y,int n,int m){
    if(MP[x][y]==0)return;
    MP[x][y]=0;
    for(int k=0;k<4;k++){
        int x2=x+dx[k];
        int y2=y+dy[k];
        if(x2 < 0 || x2 >= n || y2 < 0 || y2 >= m || MP[x2][y2] == 0)continue;
        dfs(MP,x2,y2,n,m);
    }

}
int main(){
    int n,m;
    cin>>n>>m;
    vector<vector<int>>MP(n,vector<int>(m,0));
    for(int i=0;i<n;i++){
        string s;
        cin>>s;
        for(int j=0;j<m;j++){
            MP[i][j]=s[j]-'0';
        }
    }
    int cnt=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(MP[i][j]!=0){cnt++;dfs(MP,i,j,n,m);}
        }
    }
    cout<<cnt<<endl;


    return 0;
}