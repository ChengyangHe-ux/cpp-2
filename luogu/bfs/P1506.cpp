#include <bits/stdc++.h>
using namespace std;
int dx[]={1,-1, 0, 0};
int dy[]={0, 0,-1, 1};
int main(){
    int x,y;
    cin>>x>>y;

    vector<vector<char>>M(x,vector<char>(y));
    vector<vector<int>>dist(x,vector<int>(y,1e9));
    int a=0;
    for(int i=0;i<x;i++){
        string s;
        cin>>s;
        for(int j=0;j<y;j++){
            M[i][j]=s[j];
            if(M[i][j]=='*')a++;
        }
    }
    int ei,ej;
    queue<pair<int,int>>q;
    for (int i = 0; i < x; i++){
        if(M[i][0]=='0'){
            dist[i][0] = 1;
            q.push({i, 0});
        }
        if(M[i][y-1]=='0'){
            dist[i][y-1] = 1;
            q.push({i, y-1});
        }
    }
    for (int j = 0; j < y; j++){
        if(M[0][j]=='0'){
            dist[0][j] = 1;
            q.push({0, j});
        }
        if(M[x-1][j]=='0'){
            dist[x-1][j] = 1;
            q.push({x-1, j});
        }
    }
     q.push({ei,ej});
     while(!q.empty()){
        auto [m,n]=q.front();q.pop();
        for(int k=0;k<4;k++){
            int x3=dx[k]+m;
            int y3=dy[k]+n;
            if(x3<0||x3>=x||y3<0||y3>=y)continue;
            if(M[x3][y3]=='*')continue;
            if(dist[x3][y3]!=1e9)continue;
            dist[x3][y3]=1;
            q.push({x3,y3});
        }
     }
     int count=0;
     for(int i=0;i<x;i++){
        for(int j=0;j<y;j++){
            if(dist[i][j]==1e9)count++;
        }
     }
     cout<<count-a<<endl;
    return 0;
}