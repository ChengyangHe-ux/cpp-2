#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    unordered_map<string,int> freq;
    for(int i=0;i<n;i++){
        string s;
        cin>>s;
        bool p[26]={false};
        for(int j=0;j<s.size();j++){
            p[s[j]-'a']=true;
        }
        string key="";
        for(int j=0;j<26;j++){
            if(p[j]){
                key.push_back('a'+j);
            }
        }
        freq[key]++;
    }
    long long ans=0;
    for(auto it=freq.begin();it!=freq.end();it++){
        int count=it->second;
        ans+=1LL*count*(count-1)/2;
    }
    cout<<ans<<endl;
    return 0;
}