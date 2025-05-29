#include <bits/stdc++.h>
using namespace std;

int main(){
    set<string> T;
    vector<string> w;
    string s;
    while(cin>>s){
        w.push_back(s);
        T.insert(s);
    }
    for(auto it=T.begin();it!=T.end();it++){
        string a=*it;
        int count=0;
        for(int i=0;i<w.size();i++){
            if(a==w[i]){
                count++;
            }
        }
        cout<<*it<<" "<<count<<endl;
    }
    return 0;
}