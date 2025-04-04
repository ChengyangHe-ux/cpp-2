#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    
    vector<int> a(n);
    
    for(int i=0;i<n;i++){
        cin>>a[i];
    }

    stack<int> s;
    vector<int> ans(n);
    for(int i=0;i<n;i++){
        while(!s.empty()&&a[i]>a[s.top()]){
            ans[s.top()]=i-s.top();
            s.pop();
        }     
        s.push(i);
    }
    for(int i=0;i<n;i++){
        cout<<ans[i]<<" ";
    }
    return 0;
}