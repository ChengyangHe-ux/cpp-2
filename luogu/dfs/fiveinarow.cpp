#include <bits/stdc++.h>
using namespace std;
#define N 5
int cnt=0;
bool check(int x,int y,vector<vector<int>>&M){
    
}
void dfs(vector<vector<int>>&M,int w,int b,int step){
    if(step==26){
        cnt++;
        return;
    }
    int x=step/5;
    int y=step%5;
    dfs(M,w+1,b,step+1);

}
int main(){
    vector<vector<int>>M(5,vector<int>(5,2));

    return 0;
}