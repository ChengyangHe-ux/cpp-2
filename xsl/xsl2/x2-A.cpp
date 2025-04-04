#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    cin>>s;
    bool flag=false;

    if(s.size()==1){
        cout<<""<<endl; 
        return 0;
    }

    for (int i=0;i<s.size()/2;i++) {
        if (s[i]!='a'){
            s[i]='a';
            flag=true;
            break;
        }
    }
    if(flag) {
        cout<<s<<endl;
    }else{
        s[s.size()-1]='b'; 
        cout<<s<<endl;
    }
    return 0;
}
