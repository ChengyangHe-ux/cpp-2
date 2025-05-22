#include <bits/stdc++.h>
using namespace std;

struct Task{
    int si,ei,wi;
};
bool cmp(Task &a,Task &b){
    return a.ei<b.ei;
}
int main(){
    int n,t;
    cin>>n>>t;
    vector<Task> m(n);
    for(int i=0;i<n;i++){
        cin>>m[i].si>>m[i].ei>>m[i].wi;
    }

    sort(m.begin(),m.end(),cmp);

    int now=1;
    int ans=0;
    for(int i=0;i<n;i++){
        int s=max(now,m[i].si);
        int e=m[i].ei;
        if(s+m[i].wi-1<=e&&s+m[i].wi-1<=t){
            now=s+m[i].wi;
            ans++;
        }
    }
    cout<<ans<<endl;

    return 0;
}