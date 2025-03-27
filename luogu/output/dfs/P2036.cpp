#include <bits/stdc++.h>
using namespace std;
int count1;
int min_diff=INT_MAX;
struct Node{
    int s;
    int b;
};
void dfs(int sums,int sumb,vector<Node>&a,vector<bool>&visited){
    if(count1>0){
        int diff=abs(sums-sumb);
        if(diff<min_diff){
            min_diff=diff;
        }
    }
    for(int i=0;i<a.size();i++){
        if(!visited[i]){
            visited[i]=true;
            count1++;
            int new_sums = sums * a[i].s;
            int new_sumb = sumb + a[i].b;
            dfs(new_sums, new_sumb, a, visited);
            visited[i] = false;
            count1--;
        }
    }
}
int main(){
    int n;
    cin>>n;
    vector<Node>a;
    vector<bool>visited(n,false);
    for(int i=0;i<n;i++){
        int si,bi;
        cin>>si>>bi;
        a.push_back({si,bi});
    }

    dfs(1,0,a,visited);
    cout<<min_diff<<endl;
    
    return 0;
}