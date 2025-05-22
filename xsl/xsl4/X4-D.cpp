#include <bits/stdc++.h>
using namespace std;
int main(){
    string s;
    cin>>s;
    vector<pair<char,int>>M;
    for(int i=0;i<s.length();i++){
        if(s[i]=='W')M.push_back({'W',0});
        if(s[i]=='A'){
            for(int j=0;j<M.size();j++){
                M[j].second++;
            }
        }
    }
    int sum=0;
    for(int i=0;i<M.size();i++){
        sum+=M[i].second;
    }
    cout<<sum<<endl;


    return 0;
}