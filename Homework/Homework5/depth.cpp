#include <bits/stdc++.h>
using namespace std;

int main(){
    string s;
    getline(cin,s);
    int mdepth=0;
    int cdepth=0;
    for(int i=0;i<s.size();i++){
        if(s[i]=='(') cdepth++;
        else if(s[i]==')'){
            mdepth=max(mdepth,cdepth);
            cdepth--;
        }
    }
    cout<<mdepth<<endl;
    return 0;
}